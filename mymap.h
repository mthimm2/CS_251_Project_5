// mymap.h
//
// TODO: write this file header comment.
#pragma once

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

template <typename keyType, typename valueType>
class mymap {
 private:
  struct NODE {
    keyType key;      // used to build BST
    valueType value;  // stored data for the map
    NODE* left;       // links to left child
    NODE* right;      // links to right child
    int nL;           // number of nodes in left subtree
    int nR;           // number of nodes in right subtree
    bool isThreaded;
  };
  NODE* root;  // pointer to root node of the BST
  int size;    // # of key/value pairs in the mymap

  /*
    toStringRecurse:

    Helper function for toString.

    Prints the tree recursively, in key order.
    Corresponding values are also printed, alongside the keys.

    Time Complexity: O(n), where n is total number of nodes in the tree.
  */
  void toStringRecurse(stringstream& stringSoFar, NODE* cur) {
    // If the node is a nullptr, return.
    if (cur == nullptr) {
      return;
    }

    // Walk as far left as we can on for the current subtree
    if (cur->left != nullptr) {
      toStringRecurse(stringSoFar, cur->left);
    }

    // Once we're as far down as we can go, append the key and value substring
    // to the mother string
    stringSoFar << "key: " << cur->key << " value: " << cur->value << "\n";
    // stringSoFar.append("value: ");
    // stringSoFar.append(cur->value);
    // stringSoFar.append("\n");

    // Then, walk as far right as we can.
    // However, we now need to beware of threads walking us in a circle.
    // Therefore, we should check if the node is threaded and stop recursing if
    // that's the case.
    if (cur->right != nullptr && cur->isThreaded == false) {
      toStringRecurse(stringSoFar, cur->right);
    }
  }

  void _clear(NODE* cur) {
    // Only leaves should be deleted from the bottom up.
    if (cur->left != nullptr) {
      _clear(cur->left);
    }
    if (cur->right != nullptr && cur->isThreaded == false) {
      _clear(cur->right);
    }

    // After we walk to a leaf, delete it
    delete cur;
  }

  NODE* _copyNode(const NODE* otherCur) {
    // Generic node copy of all attributes
    NODE* cur = new NODE();
    cur->key = otherCur->key;
    cur->value = otherCur->value;
    cur->nL = otherCur->nL;
    cur->nR = otherCur->nR;
    cur->left = nullptr;
    cur->right = nullptr;
    cur->isThreaded = otherCur->isThreaded;

    // Return that the newly constructed node
    return cur;
  }

  void _copyRecurse(NODE*& cur, const NODE* otherCur) {
    // Start by copying the node we're at.
    cur = _copyNode(otherCur);

    // Then see what kind of walk we need to do.
    if (otherCur->left != nullptr) {
      // Valid walk left
      _copyRecurse(cur->left, otherCur->left);
    }
    if (otherCur->right != nullptr && !otherCur->isThreaded) {
      // Valid, non-threaded walk right.
      _copyRecurse(cur->right, otherCur->right);
    }
    if (otherCur->right != nullptr && otherCur->isThreaded) {
      // Threaded nodes run the risk of walking in a loop.
      // So just return at this point.
      return;
    }
  }

  void _copyData(const mymap& other) {
    // Establish a pointer to the root of the other tree.
    NODE* otherCur = other.root;

    // Case where the other tree is empty too.
    if(otherCur == nullptr) {
      this->root = nullptr;
      return;
    }

    // Begin the process of preorder copying the other tree.
    _copyRecurse(this->root, otherCur);
  }

  //
  // iterator:
  // This iterator is used so that mymap will work with a foreach loop.
  //
  struct iterator {
   private:
    NODE* curr;  // points to current in-order node for begin/end

   public:
    iterator(NODE* node) { curr = node; }

    keyType operator*() { return curr->key; }

    bool operator==(const iterator& rhs) { return curr == rhs.curr; }

    bool operator!=(const iterator& rhs) { return curr != rhs.curr; }

    bool isDefault() { return !curr; }

    //
    // operator++:
    //
    // This function should advance curr to the next in-order node.
    // O(logN)
    //
    iterator operator++() {
      if (curr == nullptr) {
        return iterator(nullptr);
        // If the current node is threaded and has a valid right pointer, walk
        // right
      } else if (curr->isThreaded && curr->right != nullptr) {
        curr = curr->right;
        return iterator(curr);

        // If the current node isn't threaded and has a right node...
      } else if (!curr->isThreaded && curr->right != nullptr) {
        // Walk right by one.
        curr = curr->right;

        // However, now we need to walk all the way left to use our threads.
        while (curr->left != nullptr) {
          curr = curr->left;
        }
        return iterator(curr);
        // Lastly, if we're back at the true last node in the tree, bow out.
      } else {  //(curr->isThreaded && curr->right != nullptr) {
        curr = nullptr;
        return iterator(curr);
      }
    }
  };

 public:
  //
  // default constructor:
  //
  // Creates an empty mymap.
  // Time complexity: O(1)
  //
  mymap() {
    // Basis of the tree is the root, but no node exists there for the default
    // constructor
    this->root = nullptr;

    // No nodes means a size of -1 by convention
    this->size = 0;
  }

  //
  // copy constructor:
  //
  // Constructs a new mymap which is a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(nlogn), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap(const mymap& other) {
    // Just copy the other mymap.
    _copyData(other);
    this->size = other.size;
  }

  //
  // operator=:
  //
  // Clears "this" mymap and then makes a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(nlogn), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap& operator=(const mymap& other) {
    // Are we assigning to ourselves?
    if (this == &other) {
      return *this;
    }

    // Clear the memory of the current tree
    clear();

    // Copy over the data, preorder
    _copyData(other);

    // Copy the size
    this->size = other.size;

    // Return the copied
    return *this;
  }

  // clear:
  //
  // Frees the memory associated with the mymap; can be used for testing.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  void clear() {
    // Call the _clear helper function if the tree isn't empty
    if (this->root != nullptr) {
      _clear(this->root);
    }
    this->size = 0;
    this->root = nullptr;
  }

  //
  // destructor:
  //
  // Frees the memory associated with the mymap.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  ~mymap() {
    // If the map isn't empty, we can clear the memory it occupies
    clear();
  }

  //
  // put:
  //
  // Inserts the key/value into the threaded, self-balancing BST based on
  // the key.
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-tree that needs to be re-balanced.
  // Space complexity: O(1)
  //
  void put(keyType key, valueType value) {
    // Set up the new node with a default configuration
    NODE* toPut = new NODE();
    toPut->key = key;
    toPut->value = value;
    toPut->left = nullptr;
    toPut->right = nullptr;
    toPut->isThreaded = false;

    // Base case, tree is totally empty
    if (this->root == nullptr) {
      // The root should be the only node
      this->root = toPut;
      this->root->isThreaded = true;

      // size should = 1
      ++this->size;

      // Then return
      return;
    }

    // Nodes to keep track of where we are.
    NODE* cur = this->root;
    NODE* prev = nullptr;

    // If the tree isn't empty, walk to the node's insertion location
    while (cur != nullptr) {
      // Tree is in order of keys, not values
      if (key < cur->key) {
        // If the key is smaller than the key at the current node, walk left
        prev = cur;
        cur = cur->left;
      } else if (key > cur->key) {
        // If the key is larger than the key at the current node, walk right
        prev = cur;
        cur = (cur->isThreaded) ? nullptr : cur->right;
      } else {
        // If the key is equal to the key at the current node, stop
        // No duplicates allowed.
        cur->value = value;
        delete toPut;
        return;
      }
    }
    // If we made it to a new leaf location, increment size.
    ++this->size;

    // Insert the node to the correct side of the former leaf.
    if (key < prev->key) {
      toPut->right = prev;
      prev->left = toPut;
      toPut->isThreaded = true;
    } else {
      toPut->right = prev->right;
      prev->right = toPut;
      toPut->isThreaded = true;
      prev->isThreaded = false;
    }
  }

  //
  // contains:
  // Returns true if the key is in mymap, return false if not.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  bool contains(keyType key) {
    // Start from the beginning
    NODE* cur = this->root;

    // If the tree is empty
    if (cur == nullptr) {
      return false;
    }

    // Walk until we fall out of the tree
    while (cur != nullptr) {
      if (key < cur->key) {
        cur = cur->left;
      } else if (key > cur->key) {
        cur = (cur->isThreaded) ? nullptr : cur->right;
      } else {
        // If the key is equal, return true
        return true;
      }
    }

    // If we made it here, we fell out of the tree.
    return false;
  }

  //
  // get:
  //
  // Returns the value for the given key; if the key is not found, the
  // default value, valueType(), is returned (but not added to mymap).
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  valueType get(keyType key) {
    // Start from the beginning
    NODE* cur = this->root;

    // If the tree is empty
    if (cur == nullptr) {
      return valueType();
    }

    // Walk until we fall out of the tree
    while (cur != nullptr) {
      if (key < cur->key) {
        cur = cur->left;
      } else if (key > cur->key) {
        cur = (cur->isThreaded) ? nullptr : cur->right;
      } else {
        // If the key is equal, return the value at that node
        return cur->value;
      }
    }
    // If we made it here, we fell out of the tree.
    return valueType();
  }

  //
  // operator[]:
  //
  // Returns the value for the given key; if the key is not found,
  // the default value, valueType(), is returned (and the resulting new
  // key/value pair is inserted into the map).
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-trees that need to be re-balanced.
  // Space complexity: O(1)
  //
  valueType operator[](keyType key) {
    // Check if the key is in the map
    if (!contains(key)) {
      // If it isn't insert the key with the default value for the given type
      put(key, valueType());
      return valueType();
    } else {
      // If the key is in the map, return its value.
      return get(key);
    }
  }

  //
  // Size:
  //
  // Returns the # of key/value pairs in the mymap, 0 if empty.
  // O(1)
  //
  int Size() {
    // Return the size member variable
    return this->size;
  }

  //
  // begin:
  //
  // returns an iterator to the first in order NODE.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  iterator begin() {
    // Start from the root
    NODE* cur = this->root;

    // Smallest thing in the tree, in terms of key order, is all the way to the
    // left Walk down to the leftmost node
    while (cur->left != nullptr) {
      cur = cur->left;
    }

    // Return the iterator to that lower left node
    return iterator(cur);
  }

  //
  // end:
  //
  // returns an iterator to the last in order NODE.
  // this function is given to you.
  //
  // Time Complexity: O(1)
  //
  iterator end() { return iterator(nullptr); }

  //
  // toString:
  //
  // Returns a string of the entire mymap, in order.
  // Format for 8/80, 15/150, 20/200:
  // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  string toString() {
    // Start with an empty string.
    string mymapAsString = "";

    // Turn the string into a stringstream
    stringstream ss(mymapAsString);

    toStringRecurse(ss, this->root);
    mymapAsString = ss.str();

    return mymapAsString;
  }

  //
  // toVector:
  //
  // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
  // {{8, 80}, {15, 150}, {20, 200}}
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  vector<pair<keyType, valueType> > toVector() {
    // TODO: write this function.

    return {};  // TODO: Update this return.
  }

  //
  // checkBalance:
  //
  // Returns a string of mymap that verifies that the tree is properly
  // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
  // function should return a string in this format (in pre-order):
  // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  string checkBalance() {
    // TODO: write this function.

    return {};  // TODO: Update this return.
  }
};
