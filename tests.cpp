#include <gtest/gtest.h>
#include <string>
#include "mymap.h"
#include "myrandom.h"
#include <sstream>
#include <map>

using namespace std;

TEST(mymap, defaultConstructor) {
    // cout << "Testing default constructor" << endl;

    mymap<int, int> intToInt;
    mymap<int, string> intToString;
    mymap<int, double> intToDouble;
    mymap<int, char> intToChar;

    // Int to other tests
    ASSERT_EQ(intToInt.Size(),  0);
    ASSERT_EQ(intToString.Size(),  0);
    ASSERT_EQ(intToDouble.Size(),  0);
    ASSERT_EQ(intToChar.Size(),  0);
    ASSERT_NE(intToInt.Size(), 1);
    ASSERT_NE(intToString.Size(), 1);
    ASSERT_NE(intToDouble.Size(), 1);
    ASSERT_NE(intToChar.Size(), 1);

    mymap<char, char> charToChar;
    mymap<char, int> charToInt;
    mymap<char, double> charToDouble;
    mymap<char, string> charToString;

    // Char to other tests
    ASSERT_EQ(charToChar.Size(),  0);
    ASSERT_EQ(charToInt.Size(),  0);
    ASSERT_EQ(charToDouble.Size(),  0);
    ASSERT_EQ(charToString.Size(),  0);
    ASSERT_NE(charToString.Size(), 1);
    ASSERT_NE(charToChar.Size(), 1);
    ASSERT_NE(charToDouble.Size(), 1);
    ASSERT_NE(charToInt.Size(), 1);

    mymap<string, string> stringToString;
    mymap<string, char> stringToChar;
    mymap<string, double> stringToDouble;
    mymap<string, int> stringToInt;

    // String to other tests
    ASSERT_EQ(stringToString.Size(),  0);
    ASSERT_EQ(stringToChar.Size(),  0);
    ASSERT_EQ(stringToDouble.Size(),  0);
    ASSERT_EQ(stringToInt.Size(),  0);
    ASSERT_NE(stringToInt.Size(), 1);
    ASSERT_NE(stringToString.Size(), 1);
    ASSERT_NE(stringToDouble.Size(), 1);
    ASSERT_NE(stringToChar.Size(), 1);

    mymap<double, double> doubleToDouble;
    mymap<double, string> doubleToString;
    mymap<double, int> doubleToInt;
    mymap<double, char> doubleToChar;

    // Double to other tests
    ASSERT_EQ(doubleToString.Size(),  0);
    ASSERT_EQ(doubleToDouble.Size(),  0);
    ASSERT_EQ(doubleToInt.Size(),  0);
    ASSERT_EQ(doubleToChar.Size(),  0);
    ASSERT_NE(doubleToChar.Size(), 1);
    ASSERT_NE(doubleToInt.Size(), 1);
    ASSERT_NE(doubleToDouble.Size(), 1);
    ASSERT_NE(doubleToString.Size(), 1);

    // cout << "Finished testing default constructor" << endl;
}

TEST(mymap, put) {

    // cout << "Testing put function" << endl;

    mymap<int, int> intToInt;
    mymap<int, string> intToString;
    mymap<int, double> intToDouble;
    mymap<int, char> intToChar;

    // Int to other tests
    for(int x = 0; x < 10; ++x) {
        intToInt.put(x, x);
        intToString.put(x, "Gabagool");
        intToChar.put(x, 'G');
        intToDouble.put(x, 2.2);
    }

    // Inserted 10 elements, so expect a size of 10
    ASSERT_EQ(intToInt.Size(), 10);
    ASSERT_EQ(intToString.Size(), 10);
    ASSERT_EQ(intToChar.Size(), 10);
    ASSERT_EQ(intToDouble.Size(), 10);
    
    // Int to int
    ASSERT_TRUE(intToInt.contains(0));
    ASSERT_TRUE(intToInt.contains(1));
    ASSERT_TRUE(intToInt.contains(2));
    ASSERT_TRUE(intToInt.contains(3));
    ASSERT_TRUE(intToInt.contains(4));
    ASSERT_TRUE(intToInt.contains(5));
    ASSERT_TRUE(intToInt.contains(6));
    ASSERT_TRUE(intToInt.contains(7));
    ASSERT_TRUE(intToInt.contains(8));
    ASSERT_TRUE(intToInt.contains(9));
   
    // Int to char
    ASSERT_TRUE(intToChar.contains(0));
    ASSERT_TRUE(intToChar.contains(1));
    ASSERT_TRUE(intToChar.contains(2));
    ASSERT_TRUE(intToChar.contains(3));
    ASSERT_TRUE(intToChar.contains(4));
    ASSERT_TRUE(intToChar.contains(5));
    ASSERT_TRUE(intToChar.contains(6));
    ASSERT_TRUE(intToChar.contains(7));
    ASSERT_TRUE(intToChar.contains(8));
    ASSERT_TRUE(intToChar.contains(9));

    // Int to string
    ASSERT_TRUE(intToString.contains(0));
    ASSERT_TRUE(intToString.contains(1));
    ASSERT_TRUE(intToString.contains(2));
    ASSERT_TRUE(intToString.contains(3));
    ASSERT_TRUE(intToString.contains(4));
    ASSERT_TRUE(intToString.contains(5));
    ASSERT_TRUE(intToString.contains(6));
    ASSERT_TRUE(intToString.contains(7));
    ASSERT_TRUE(intToString.contains(8));
    ASSERT_TRUE(intToString.contains(9));

    // Int to double
    ASSERT_TRUE(intToDouble.contains(0));
    ASSERT_TRUE(intToDouble.contains(1));
    ASSERT_TRUE(intToDouble.contains(2));
    ASSERT_TRUE(intToDouble.contains(3));
    ASSERT_TRUE(intToDouble.contains(4));
    ASSERT_TRUE(intToDouble.contains(5));
    ASSERT_TRUE(intToDouble.contains(6));
    ASSERT_TRUE(intToDouble.contains(7));
    ASSERT_TRUE(intToDouble.contains(8));
    ASSERT_TRUE(intToDouble.contains(9));
    

    // Char to something maps
    mymap<char, char> charToChar;
    mymap<char, int> charToInt;
    mymap<char, double> charToDouble;
    mymap<char, string> charToString;

    // Char to other tests
    ASSERT_EQ(charToChar.Size(), 0);
    charToChar.put('a', 'a');
    ASSERT_EQ(charToChar.Size(), 1);
    charToChar.put('b', 'a');
    ASSERT_EQ(charToChar.Size(), 2);
    charToChar.put('c', 'a');
    ASSERT_EQ(charToChar.Size(), 3);
    charToChar.put('d', 'a');
    ASSERT_EQ(charToChar.Size(), 4);
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    ASSERT_FALSE(charToChar.Size() >= 5);

    ASSERT_EQ(charToInt.Size(), 0);
    charToInt.put('a', 1);
    ASSERT_EQ(charToInt.Size(), 1);
    charToInt.put('b', 2);
    ASSERT_EQ(charToInt.Size(), 2);
    charToInt.put('c', 3);
    ASSERT_EQ(charToInt.Size(), 3);
    charToInt.put('d', 4);
    ASSERT_EQ(charToInt.Size(), 4);
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    ASSERT_FALSE(charToInt.Size() >= 5);

    ASSERT_EQ(charToString.Size(), 0);
    charToString.put('a', "1.0");
    ASSERT_EQ(charToString.Size(), 1);
    charToString.put('b', "2.0");
    ASSERT_EQ(charToString.Size(), 2);
    charToString.put('c', "3.0");
    ASSERT_EQ(charToString.Size(), 3);
    charToString.put('d', "4.0");
    ASSERT_EQ(charToString.Size(), 4);
    charToString.put('a', "1.0");
    charToString.put('a', "Gabagool");
    charToString.put('a', "Oh Marone!");
    ASSERT_FALSE(charToString.Size() >= 5);

    ASSERT_EQ(charToDouble.Size(), 0);
    charToDouble.put('a', 1.0);
    ASSERT_EQ(charToDouble.Size(), 1);
    charToDouble.put('b', 2.0);
    ASSERT_EQ(charToDouble.Size(), 2);
    charToDouble.put('c', 3.0);
    ASSERT_EQ(charToDouble.Size(), 3);
    charToDouble.put('d', 4.0);
    ASSERT_EQ(charToDouble.Size(), 4);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    ASSERT_FALSE(charToDouble.Size() >= 5);

    // Expect a size of only 4
    ASSERT_EQ(charToChar.Size(), 4);
    ASSERT_EQ(charToInt.Size(), 4);
    ASSERT_EQ(charToString.Size(), 4);
    ASSERT_EQ(charToDouble.Size(), 4);

    // These all had the same thing inserted, so these keys should be present
    ASSERT_TRUE(charToChar.contains('c'));
    ASSERT_TRUE(charToInt.contains('a'));
    ASSERT_TRUE(charToDouble.contains('d'));
    ASSERT_TRUE(charToString.contains('b'));

    // String keys
    mymap<string, string> stringToString;
    mymap<string, char> stringToChar;
    mymap<string, double> stringToDouble;
    mymap<string, int> stringToInt;

    // String to other tests
    ASSERT_EQ(stringToString.Size(), 0);
    stringToString.put("Oh Marone!", "Paulie");
    ASSERT_EQ(stringToString.Size(), 1);
    stringToString.put("Stugots", "Tony");
    ASSERT_EQ(stringToString.Size(), 2);
    stringToString.put("Gabagool", "Silvio");
    ASSERT_EQ(stringToString.Size(), 3);
    stringToString.put("Let's get back to that Gabagool", "Melfi");
    ASSERT_EQ(stringToString.Size(), 4);
    stringToString.put("Christopher", "Adriana");
    ASSERT_EQ(stringToString.Size(), 5);
    stringToString.put("Stugots", "Carmela");
    ASSERT_EQ(stringToString.Size(), 5);
    ASSERT_FALSE(stringToString.Size() >= 6);

    ASSERT_EQ(stringToChar.Size(), 0);
    stringToChar.put("Oh Marone!", 'P');
    ASSERT_EQ(stringToChar.Size(), 1);
    stringToChar.put("Stugots", 'T');
    ASSERT_EQ(stringToChar.Size(), 2);
    stringToChar.put("Gabagool", 'S');
    ASSERT_EQ(stringToChar.Size(), 3);
    stringToChar.put("Let's get back to that Gabagool", 'M');
    ASSERT_EQ(stringToChar.Size(), 4);
    stringToChar.put("Christopher", 'A');
    ASSERT_EQ(stringToChar.Size(), 5);
    stringToChar.put("Stugots", 'C');
    ASSERT_EQ(stringToChar.Size(), 5);
    ASSERT_FALSE(stringToChar.Size() >= 6);

    ASSERT_EQ(stringToInt.Size(), 0);
    stringToInt.put("Oh Marone!", 1);
    ASSERT_EQ(stringToInt.Size(), 1);
    stringToInt.put("Stugots", 2);
    ASSERT_EQ(stringToInt.Size(), 2);
    stringToInt.put("Gabagool", 3);
    ASSERT_EQ(stringToInt.Size(), 3);
    stringToInt.put("Let's get back to that Gabagool", 4);
    ASSERT_EQ(stringToInt.Size(), 4);
    stringToInt.put("Christopher", 5);
    ASSERT_EQ(stringToInt.Size(), 5);
    stringToInt.put("Stugots", 6);
    ASSERT_EQ(stringToInt.Size(), 5);
    ASSERT_FALSE(stringToInt.Size() >= 6);

    ASSERT_EQ(stringToDouble.Size(), 0);
    stringToDouble.put("Oh Marone!", 1.0);
    ASSERT_EQ(stringToDouble.Size(), 1);
    stringToDouble.put("Stugots", 2.0);
    ASSERT_EQ(stringToDouble.Size(), 2);
    stringToDouble.put("Gabagool", 3.0);
    ASSERT_EQ(stringToDouble.Size(), 3);
    stringToDouble.put("Let's get back to that Gabagool", 4.0);
    ASSERT_EQ(stringToDouble.Size(), 4);
    stringToDouble.put("Christopher", 5.0);
    ASSERT_EQ(stringToDouble.Size(), 5);
    stringToDouble.put("Stugots", 6.0);
    ASSERT_EQ(stringToDouble.Size(), 5);
    ASSERT_FALSE(stringToDouble.Size() >= 6);


    // Double keys
    mymap<double, double> doubleToDouble;
    mymap<double, string> doubleToString;
    mymap<double, int> doubleToInt;
    mymap<double, char> doubleToChar;

    // Double to other tests
    for(int x = 0; x < 10; ++x) {
        doubleToInt.put((double)(x + 1), x);
        doubleToString.put((double)(x + 2), "Gabagool");
        doubleToChar.put((double)(x + 3), 'G');
        doubleToDouble.put((double)(x + 4), 2.2);
    }

    // Sizes
    ASSERT_EQ(doubleToDouble.Size(), 10);
    ASSERT_EQ(doubleToInt.Size(), 10);
    ASSERT_EQ(doubleToString.Size(), 10);
    ASSERT_EQ(doubleToChar.Size(), 10);

    // Contains stuff
    ASSERT_TRUE(doubleToInt.contains(1.0));
    ASSERT_TRUE(doubleToInt.contains(2.0));
    ASSERT_TRUE(doubleToInt.contains(3.0));
    ASSERT_TRUE(doubleToInt.contains(4.0));
    ASSERT_TRUE(doubleToInt.contains(5.0));
    ASSERT_TRUE(doubleToInt.contains(6.0));
    ASSERT_TRUE(doubleToInt.contains(7.0));
    ASSERT_TRUE(doubleToInt.contains(8.0));
    ASSERT_TRUE(doubleToInt.contains(9.0));
    ASSERT_TRUE(doubleToInt.contains(10.0));

    ASSERT_TRUE(doubleToString.contains(2.0));
    ASSERT_TRUE(doubleToString.contains(3.0));
    ASSERT_TRUE(doubleToString.contains(4.0));
    ASSERT_TRUE(doubleToString.contains(5.0));
    ASSERT_TRUE(doubleToString.contains(6.0));
    ASSERT_TRUE(doubleToString.contains(7.0));
    ASSERT_TRUE(doubleToString.contains(8.0));
    ASSERT_TRUE(doubleToString.contains(9.0));
    ASSERT_TRUE(doubleToString.contains(10.0));
    ASSERT_TRUE(doubleToString.contains(11.0));

    ASSERT_TRUE(doubleToChar.contains(3.0));
    ASSERT_TRUE(doubleToChar.contains(4.0));
    ASSERT_TRUE(doubleToChar.contains(5.0));
    ASSERT_TRUE(doubleToChar.contains(6.0));
    ASSERT_TRUE(doubleToChar.contains(7.0));
    ASSERT_TRUE(doubleToChar.contains(8.0));
    ASSERT_TRUE(doubleToChar.contains(9.0));
    ASSERT_TRUE(doubleToChar.contains(10.0));
    ASSERT_TRUE(doubleToChar.contains(11.0));
    ASSERT_TRUE(doubleToChar.contains(12.0));

    ASSERT_TRUE(doubleToDouble.contains(4.0));
    ASSERT_TRUE(doubleToDouble.contains(5.0));
    ASSERT_TRUE(doubleToDouble.contains(6.0));
    ASSERT_TRUE(doubleToDouble.contains(7.0));
    ASSERT_TRUE(doubleToDouble.contains(8.0));
    ASSERT_TRUE(doubleToDouble.contains(9.0));
    ASSERT_TRUE(doubleToDouble.contains(10.0));
    ASSERT_TRUE(doubleToDouble.contains(11.0));
    ASSERT_TRUE(doubleToDouble.contains(12.0));
    ASSERT_TRUE(doubleToDouble.contains(13.0));

    // cout <<"Finished testing put function" << endl;
}

TEST(mymap, contains) {

    mymap<int, int> intToInt;
    mymap<int, string> intToString;
    mymap<int, double> intToDouble;
    mymap<int, char> intToChar;

    // Int to other tests
    for(int x = 0; x < 10; ++x) {
        intToInt.put(x, x);
        intToString.put(x, "Gabagool");
        intToChar.put(x, 'G');
        intToDouble.put(x, 2.2);
    }

    // Inserted 10 elements, so expect a size of 10
    ASSERT_EQ(intToInt.Size(), 10);
    ASSERT_EQ(intToString.Size(), 10);
    ASSERT_EQ(intToChar.Size(), 10);
    ASSERT_EQ(intToDouble.Size(), 10);
    
    // Int to int
    ASSERT_TRUE(intToInt.contains(0));
    ASSERT_TRUE(intToInt.contains(1));
    ASSERT_TRUE(intToInt.contains(2));
    ASSERT_TRUE(intToInt.contains(3));
    ASSERT_TRUE(intToInt.contains(4));
    ASSERT_TRUE(intToInt.contains(5));
    ASSERT_TRUE(intToInt.contains(6));
    ASSERT_TRUE(intToInt.contains(7));
    ASSERT_TRUE(intToInt.contains(8));
    ASSERT_TRUE(intToInt.contains(9));
   
    // Int to char
    ASSERT_TRUE(intToChar.contains(0));
    ASSERT_TRUE(intToChar.contains(1));
    ASSERT_TRUE(intToChar.contains(2));
    ASSERT_TRUE(intToChar.contains(3));
    ASSERT_TRUE(intToChar.contains(4));
    ASSERT_TRUE(intToChar.contains(5));
    ASSERT_TRUE(intToChar.contains(6));
    ASSERT_TRUE(intToChar.contains(7));
    ASSERT_TRUE(intToChar.contains(8));
    ASSERT_TRUE(intToChar.contains(9));

    // Int to string
    ASSERT_TRUE(intToString.contains(0));
    ASSERT_TRUE(intToString.contains(1));
    ASSERT_TRUE(intToString.contains(2));
    ASSERT_TRUE(intToString.contains(3));
    ASSERT_TRUE(intToString.contains(4));
    ASSERT_TRUE(intToString.contains(5));
    ASSERT_TRUE(intToString.contains(6));
    ASSERT_TRUE(intToString.contains(7));
    ASSERT_TRUE(intToString.contains(8));
    ASSERT_TRUE(intToString.contains(9));

    // Int to double
    ASSERT_TRUE(intToDouble.contains(0));
    ASSERT_TRUE(intToDouble.contains(1));
    ASSERT_TRUE(intToDouble.contains(2));
    ASSERT_TRUE(intToDouble.contains(3));
    ASSERT_TRUE(intToDouble.contains(4));
    ASSERT_TRUE(intToDouble.contains(5));
    ASSERT_TRUE(intToDouble.contains(6));
    ASSERT_TRUE(intToDouble.contains(7));
    ASSERT_TRUE(intToDouble.contains(8));
    ASSERT_TRUE(intToDouble.contains(9));
    

    // Char to something maps
    mymap<char, char> charToChar;
    mymap<char, int> charToInt;
    mymap<char, double> charToDouble;
    mymap<char, string> charToString;

    // Char to other tests
    charToChar.put('a', 'a');
    ASSERT_TRUE(charToChar.contains('a'));
    charToChar.put('b', 'a');
    ASSERT_TRUE(charToChar.contains('b'));
    charToChar.put('c', 'a');
    ASSERT_TRUE(charToChar.contains('c'));
    charToChar.put('d', 'a');
    ASSERT_TRUE(charToChar.contains('d'));
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    ASSERT_FALSE(charToChar.Size() >= 5);

    charToInt.put('a', 1);
    ASSERT_TRUE(charToInt.contains('a'));
    charToInt.put('b', 2);
    ASSERT_TRUE(charToInt.contains('b'));
    charToInt.put('c', 3);
    ASSERT_TRUE(charToInt.contains('c'));
    charToInt.put('d', 4);
    ASSERT_TRUE(charToInt.contains('d'));
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    ASSERT_FALSE(charToInt.Size() >= 5);

    charToString.put('a', "1.0");
    ASSERT_TRUE(charToString.contains('a'));
    charToString.put('b', "2.0");
    ASSERT_TRUE(charToString.contains('b'));
    charToString.put('c', "3.0");
    ASSERT_TRUE(charToString.contains('c'));
    charToString.put('d', "4.0");
    ASSERT_TRUE(charToString.contains('d'));
    charToString.put('a', "1.0");
    charToString.put('a', "Gabagool");
    charToString.put('a', "Oh Marone!");
    ASSERT_FALSE(charToString.Size() >= 5);

    charToDouble.put('a', 1.0);
    ASSERT_TRUE(charToDouble.contains('a'));
    charToDouble.put('b', 2.0);
    ASSERT_TRUE(charToDouble.contains('b'));
    charToDouble.put('c', 3.0);
    ASSERT_TRUE(charToDouble.contains('c'));
    charToDouble.put('d', 4.0);
    ASSERT_TRUE(charToDouble.contains('d'));
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    ASSERT_FALSE(charToDouble.Size() >= 5);

    // Expect a size of only 4
    ASSERT_EQ(charToChar.Size(), 4);
    ASSERT_EQ(charToInt.Size(), 4);
    ASSERT_EQ(charToString.Size(), 4);
    ASSERT_EQ(charToDouble.Size(), 4);

    // These all had the same thing inserted, so these keys should be present
    ASSERT_TRUE(charToChar.contains('c'));
    ASSERT_TRUE(charToInt.contains('a'));
    ASSERT_TRUE(charToDouble.contains('d'));
    ASSERT_TRUE(charToString.contains('b'));

    // String keys
    mymap<string, string> stringToString;
    mymap<string, char> stringToChar;
    mymap<string, double> stringToDouble;
    mymap<string, int> stringToInt;

    // String to other tests
    stringToString.put("Oh Marone!", "Paulie");
    ASSERT_TRUE(stringToString.contains("Oh Marone!"));
    stringToString.put("Stugots", "Tony");
    ASSERT_TRUE(stringToString.contains("Stugots"));
    stringToString.put("Gabagool", "Silvio");
    ASSERT_TRUE(stringToString.contains("Gabagool"));
    stringToString.put("Let's get back to that Gabagool", "Melfi");
    ASSERT_TRUE(stringToString.contains("Let's get back to that Gabagool"));
    stringToString.put("Christopher", "Adriana");
    ASSERT_TRUE(stringToString.contains("Christopher"));
    stringToString.put("Stugots", "Carmela");
    ASSERT_TRUE(stringToString.contains("Stugots"));
    ASSERT_FALSE(stringToString.Size() >= 6);

    stringToChar.put("Oh Marone!", 'P');
    ASSERT_TRUE(stringToChar.contains("Oh Marone!"));
    stringToChar.put("Stugots", 'T');
    ASSERT_TRUE(stringToChar.contains("Stugots"));
    stringToChar.put("Gabagool", 'S');
    ASSERT_TRUE(stringToChar.contains("Gabagool"));
    stringToChar.put("Let's get back to that Gabagool", 'M');
    ASSERT_TRUE(stringToChar.contains("Let's get back to that Gabagool"));
    stringToChar.put("Christopher", 'A');
    ASSERT_TRUE(stringToChar.contains("Christopher"));
    stringToChar.put("Stugots", 'C');
    ASSERT_TRUE(stringToChar.contains("Stugots"));
    ASSERT_FALSE(stringToChar.Size() >= 6);

    stringToInt.put("Oh Marone!", 1);
    ASSERT_TRUE(stringToInt.contains("Oh Marone!"));
    stringToInt.put("Stugots", 2);
    ASSERT_TRUE(stringToInt.contains("Stugots"));
    stringToInt.put("Gabagool", 3);
    ASSERT_TRUE(stringToInt.contains("Gabagool"));
    stringToInt.put("Let's get back to that Gabagool", 4);
    ASSERT_TRUE(stringToInt.contains("Let's get back to that Gabagool"));
    stringToInt.put("Christopher", 5);
    ASSERT_TRUE(stringToInt.contains("Christopher"));
    stringToInt.put("Stugots", 6);
    ASSERT_TRUE(stringToInt.contains("Stugots"));
    ASSERT_FALSE(stringToInt.Size() >= 6);

    stringToDouble.put("Oh Marone!", 1.0);
    ASSERT_TRUE(stringToDouble.contains("Oh Marone!"));
    stringToDouble.put("Stugots", 2.0);
    ASSERT_TRUE(stringToDouble.contains("Stugots"));
    stringToDouble.put("Gabagool", 3.0);
    ASSERT_TRUE(stringToDouble.contains("Gabagool"));
    stringToDouble.put("Let's get back to that Gabagool", 4.0);
    ASSERT_TRUE(stringToDouble.contains("Let's get back to that Gabagool"));
    stringToDouble.put("Christopher", 5.0);
    ASSERT_TRUE(stringToDouble.contains("Christopher"));
    stringToDouble.put("Stugots", 6.0);
    ASSERT_TRUE(stringToDouble.contains("Stugots"));
    ASSERT_FALSE(stringToDouble.Size() >= 6);

    // Double keys
    mymap<double, double> doubleToDouble;
    mymap<double, string> doubleToString;
    mymap<double, int> doubleToInt;
    mymap<double, char> doubleToChar;

    // Double to other tests
    for(int x = 0; x < 10; ++x) {
        doubleToInt.put((double)(x + 1), x);
        doubleToString.put((double)(x + 2), "Gabagool");
        doubleToChar.put((double)(x + 3), 'G');
        doubleToDouble.put((double)(x + 4), 2.2);
    }

    // Sizes
    ASSERT_EQ(doubleToDouble.Size(), 10);
    ASSERT_EQ(doubleToInt.Size(), 10);
    ASSERT_EQ(doubleToString.Size(), 10);
    ASSERT_EQ(doubleToChar.Size(), 10);

    // Contains stuff
    ASSERT_TRUE(doubleToInt.contains(1.0));
    ASSERT_TRUE(doubleToInt.contains(2.0));
    ASSERT_TRUE(doubleToInt.contains(3.0));
    ASSERT_TRUE(doubleToInt.contains(4.0));
    ASSERT_TRUE(doubleToInt.contains(5.0));
    ASSERT_TRUE(doubleToInt.contains(6.0));
    ASSERT_TRUE(doubleToInt.contains(7.0));
    ASSERT_TRUE(doubleToInt.contains(8.0));
    ASSERT_TRUE(doubleToInt.contains(9.0));
    ASSERT_TRUE(doubleToInt.contains(10.0));

    ASSERT_TRUE(doubleToString.contains(2.0));
    ASSERT_TRUE(doubleToString.contains(3.0));
    ASSERT_TRUE(doubleToString.contains(4.0));
    ASSERT_TRUE(doubleToString.contains(5.0));
    ASSERT_TRUE(doubleToString.contains(6.0));
    ASSERT_TRUE(doubleToString.contains(7.0));
    ASSERT_TRUE(doubleToString.contains(8.0));
    ASSERT_TRUE(doubleToString.contains(9.0));
    ASSERT_TRUE(doubleToString.contains(10.0));
    ASSERT_TRUE(doubleToString.contains(11.0));

    ASSERT_TRUE(doubleToChar.contains(3.0));
    ASSERT_TRUE(doubleToChar.contains(4.0));
    ASSERT_TRUE(doubleToChar.contains(5.0));
    ASSERT_TRUE(doubleToChar.contains(6.0));
    ASSERT_TRUE(doubleToChar.contains(7.0));
    ASSERT_TRUE(doubleToChar.contains(8.0));
    ASSERT_TRUE(doubleToChar.contains(9.0));
    ASSERT_TRUE(doubleToChar.contains(10.0));
    ASSERT_TRUE(doubleToChar.contains(11.0));
    ASSERT_TRUE(doubleToChar.contains(12.0));

    ASSERT_TRUE(doubleToDouble.contains(4.0));
    ASSERT_TRUE(doubleToDouble.contains(5.0));
    ASSERT_TRUE(doubleToDouble.contains(6.0));
    ASSERT_TRUE(doubleToDouble.contains(7.0));
    ASSERT_TRUE(doubleToDouble.contains(8.0));
    ASSERT_TRUE(doubleToDouble.contains(9.0));
    ASSERT_TRUE(doubleToDouble.contains(10.0));
    ASSERT_TRUE(doubleToDouble.contains(11.0));
    ASSERT_TRUE(doubleToDouble.contains(12.0));
    ASSERT_TRUE(doubleToDouble.contains(13.0));
}

TEST(mymap, size) {

    // cout << "Testing size function" << endl;

    // Integer keys
    mymap<int, int> intToInt;
    mymap<int, string> intToString;
    mymap<int, double> intToDouble;
    mymap<int, char> intToChar;

    // Int to other tests
    for(int x = 0; x < 10; ++x) {
        intToInt.put(x, x);
        intToString.put(x, "Gabagool");
        intToChar.put(x, 'G');
        intToDouble.put(x, 2.2);
    }

    // Inserted 10 elements, so expect a size of 10
    ASSERT_EQ(intToInt.Size(), 10);
    ASSERT_EQ(intToString.Size(), 10);
    ASSERT_EQ(intToChar.Size(), 10);
    ASSERT_EQ(intToDouble.Size(), 10);
    
    // Char to something maps
    mymap<char, char> charToChar;
    mymap<char, int> charToInt;
    mymap<char, double> charToDouble;
    mymap<char, string> charToString;

    // Char to other tests
    ASSERT_EQ(charToChar.Size(), 0);
    charToChar.put('a', 'a');
    ASSERT_EQ(charToChar.Size(), 1);
    charToChar.put('b', 'a');
    ASSERT_EQ(charToChar.Size(), 2);
    charToChar.put('c', 'a');
    ASSERT_EQ(charToChar.Size(), 3);
    charToChar.put('d', 'a');
    ASSERT_EQ(charToChar.Size(), 4);
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    ASSERT_FALSE(charToChar.Size() >= 5);

    ASSERT_EQ(charToInt.Size(), 0);
    charToInt.put('a', 1);
    ASSERT_EQ(charToInt.Size(), 1);
    charToInt.put('b', 2);
    ASSERT_EQ(charToInt.Size(), 2);
    charToInt.put('c', 3);
    ASSERT_EQ(charToInt.Size(), 3);
    charToInt.put('d', 4);
    ASSERT_EQ(charToInt.Size(), 4);
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    ASSERT_FALSE(charToInt.Size() >= 5);

    ASSERT_EQ(charToString.Size(), 0);
    charToString.put('a', "1.0");
    ASSERT_EQ(charToString.Size(), 1);
    charToString.put('b', "2.0");
    ASSERT_EQ(charToString.Size(), 2);
    charToString.put('c', "3.0");
    ASSERT_EQ(charToString.Size(), 3);
    charToString.put('d', "4.0");
    ASSERT_EQ(charToString.Size(), 4);
    charToString.put('a', "1.0");
    charToString.put('a', "Gabagool");
    charToString.put('a', "Oh Marone!");
    ASSERT_FALSE(charToString.Size() >= 5);

    ASSERT_EQ(charToDouble.Size(), 0);
    charToDouble.put('a', 1.0);
    ASSERT_EQ(charToDouble.Size(), 1);
    charToDouble.put('b', 2.0);
    ASSERT_EQ(charToDouble.Size(), 2);
    charToDouble.put('c', 3.0);
    ASSERT_EQ(charToDouble.Size(), 3);
    charToDouble.put('d', 4.0);
    ASSERT_EQ(charToDouble.Size(), 4);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    ASSERT_FALSE(charToDouble.Size() >= 5);

    // Expect a size of only 4
    ASSERT_EQ(charToChar.Size(), 4);
    ASSERT_EQ(charToInt.Size(), 4);
    ASSERT_EQ(charToString.Size(), 4);
    ASSERT_EQ(charToDouble.Size(), 4);


    // String keys
    mymap<string, string> stringToString;
    mymap<string, char> stringToChar;
    mymap<string, double> stringToDouble;
    mymap<string, int> stringToInt;

    // String to other tests
    ASSERT_EQ(stringToString.Size(), 0);
    stringToString.put("Oh Marone!", "Paulie");
    ASSERT_EQ(stringToString.Size(), 1);
    stringToString.put("Stugots", "Tony");
    ASSERT_EQ(stringToString.Size(), 2);
    stringToString.put("Gabagool", "Silvio");
    ASSERT_EQ(stringToString.Size(), 3);
    stringToString.put("Let's get back to that Gabagool", "Melfi");
    ASSERT_EQ(stringToString.Size(), 4);
    stringToString.put("Christopher", "Adriana");
    ASSERT_EQ(stringToString.Size(), 5);
    stringToString.put("Stugots", "Carmela");
    ASSERT_EQ(stringToString.Size(), 5);
    ASSERT_FALSE(stringToString.Size() >= 6);

    ASSERT_EQ(stringToChar.Size(), 0);
    stringToChar.put("Oh Marone!", 'P');
    ASSERT_EQ(stringToChar.Size(), 1);
    stringToChar.put("Stugots", 'T');
    ASSERT_EQ(stringToChar.Size(), 2);
    stringToChar.put("Gabagool", 'S');
    ASSERT_EQ(stringToChar.Size(), 3);
    stringToChar.put("Let's get back to that Gabagool", 'M');
    ASSERT_EQ(stringToChar.Size(), 4);
    stringToChar.put("Christopher", 'A');
    ASSERT_EQ(stringToChar.Size(), 5);
    stringToChar.put("Stugots", 'C');
    ASSERT_EQ(stringToChar.Size(), 5);
    ASSERT_FALSE(stringToChar.Size() >= 6);

    ASSERT_EQ(stringToInt.Size(), 0);
    stringToInt.put("Oh Marone!", 1);
    ASSERT_EQ(stringToInt.Size(), 1);
    stringToInt.put("Stugots", 2);
    ASSERT_EQ(stringToInt.Size(), 2);
    stringToInt.put("Gabagool", 3);
    ASSERT_EQ(stringToInt.Size(), 3);
    stringToInt.put("Let's get back to that Gabagool", 4);
    ASSERT_EQ(stringToInt.Size(), 4);
    stringToInt.put("Christopher", 5);
    ASSERT_EQ(stringToInt.Size(), 5);
    stringToInt.put("Stugots", 6);
    ASSERT_EQ(stringToInt.Size(), 5);
    ASSERT_FALSE(stringToInt.Size() >= 6);

    ASSERT_EQ(stringToDouble.Size(), 0);
    stringToDouble.put("Oh Marone!", 1.0);
    ASSERT_EQ(stringToDouble.Size(), 1);
    stringToDouble.put("Stugots", 2.0);
    ASSERT_EQ(stringToDouble.Size(), 2);
    stringToDouble.put("Gabagool", 3.0);
    ASSERT_EQ(stringToDouble.Size(), 3);
    stringToDouble.put("Let's get back to that Gabagool", 4.0);
    ASSERT_EQ(stringToDouble.Size(), 4);
    stringToDouble.put("Christopher", 5.0);
    ASSERT_EQ(stringToDouble.Size(), 5);
    stringToDouble.put("Stugots", 6.0);
    ASSERT_EQ(stringToDouble.Size(), 5);
    ASSERT_FALSE(stringToDouble.Size() >= 6);
    
    // Double keys
    mymap<double, double> doubleToDouble;
    mymap<double, string> doubleToString;
    mymap<double, int> doubleToInt;
    mymap<double, char> doubleToChar;

    // Double to other tests
    for(int x = 0; x < 10; ++x) {
        doubleToInt.put((double)(x + 1), x);
        doubleToString.put((double)(x + 2), "Gabagool");
        doubleToChar.put((double)(x + 3), 'G');
        doubleToDouble.put((double)(x + 4), 2.2);
    }

    // Sizes
    ASSERT_EQ(doubleToDouble.Size(), 10);
    ASSERT_EQ(doubleToInt.Size(), 10);
    ASSERT_EQ(doubleToString.Size(), 10);
    ASSERT_EQ(doubleToChar.Size(), 10);

    // cout <<"Finished testing size function" << endl;
}

TEST(mymap, get) {

    // cout << "Testing get function" << endl;

    // Integer keys
    mymap<int, int> intToInt;
    mymap<int, string> intToString;
    mymap<int, double> intToDouble;
    mymap<int, char> intToChar;

    ASSERT_EQ(intToInt.get(0), 0);
    ASSERT_EQ(intToString.get(0), "");
    ASSERT_EQ(intToDouble.get(0), 0.0);
    ASSERT_EQ(intToChar.get(0), '\0');


    // Int to other tests
    for(int x = 0; x < 10; ++x) {
        intToInt.put(x, x);
        intToString.put(x, "Gabagool");
        intToChar.put(x, 'G');
        intToDouble.put(x, 2.2);
    }

    // Expected values
    ASSERT_EQ(intToInt.get(0), 0);
    ASSERT_EQ(intToInt.get(0), 0);
    ASSERT_EQ(intToInt.get(1), 1);
    ASSERT_EQ(intToInt.get(2), 2);
    ASSERT_EQ(intToInt.get(3), 3);
    ASSERT_EQ(intToInt.get(4), 4);
    ASSERT_EQ(intToInt.get(5), 5);
    ASSERT_EQ(intToInt.get(6), 6);
    ASSERT_EQ(intToInt.get(7), 7);
    ASSERT_EQ(intToInt.get(8), 8);
    ASSERT_EQ(intToInt.get(9), 9);

    ASSERT_EQ(intToString.get(0), "Gabagool");
    ASSERT_EQ(intToString.get(1), "Gabagool");
    ASSERT_EQ(intToString.get(2), "Gabagool");
    ASSERT_EQ(intToString.get(3), "Gabagool");
    ASSERT_EQ(intToString.get(4), "Gabagool");
    ASSERT_EQ(intToString.get(5), "Gabagool");
    ASSERT_EQ(intToString.get(6), "Gabagool");
    ASSERT_EQ(intToString.get(7), "Gabagool");
    ASSERT_EQ(intToString.get(8), "Gabagool");
    ASSERT_EQ(intToString.get(9), "Gabagool");

    ASSERT_EQ(intToChar.get(0), 'G');
    ASSERT_EQ(intToChar.get(1), 'G');
    ASSERT_EQ(intToChar.get(2), 'G');
    ASSERT_EQ(intToChar.get(3), 'G');
    ASSERT_EQ(intToChar.get(4), 'G');
    ASSERT_EQ(intToChar.get(5), 'G');
    ASSERT_EQ(intToChar.get(6), 'G');
    ASSERT_EQ(intToChar.get(7), 'G');
    ASSERT_EQ(intToChar.get(8), 'G');
    ASSERT_EQ(intToChar.get(9), 'G');

    ASSERT_EQ(intToDouble.get(0), 2.2);
    ASSERT_EQ(intToDouble.get(1), 2.2);
    ASSERT_EQ(intToDouble.get(2), 2.2);
    ASSERT_EQ(intToDouble.get(3), 2.2);
    ASSERT_EQ(intToDouble.get(4), 2.2);
    ASSERT_EQ(intToDouble.get(5), 2.2);
    ASSERT_EQ(intToDouble.get(6), 2.2);
    ASSERT_EQ(intToDouble.get(7), 2.2);
    ASSERT_EQ(intToDouble.get(8), 2.2);
    ASSERT_EQ(intToDouble.get(9), 2.2);


    // Char to something maps
    mymap<char, char> charToChar;
    mymap<char, int> charToInt;
    mymap<char, double> charToDouble;
    mymap<char, string> charToString;

    ASSERT_EQ(charToChar.get('a'), '\0');
    ASSERT_EQ(charToInt.get('a'), 0);
    ASSERT_EQ(charToDouble.get('a'), 0.0);
    ASSERT_EQ(charToString.get('a'), "");

    // Char to other tests
    charToChar.put('a', 'a');
    charToChar.put('b', 'a');
    charToChar.put('c', 'a');
    charToChar.put('d', 'a');
    charToChar.put('a', 'a');
    charToChar.put('a', 'a');
    ASSERT_EQ(charToChar.get('a'), 'a');
    charToChar.put('a', 'x');
 
    ASSERT_EQ(charToChar.get('b'), 'a');
    ASSERT_EQ(charToChar.get('c'), 'a');
    ASSERT_EQ(charToChar.get('d'), 'a');
    ASSERT_EQ(charToChar.get('a'), 'x');

    charToInt.put('a', 1);
    ASSERT_EQ(charToInt.get('a'), 1);
    charToInt.put('b', 2);
    charToInt.put('c', 3);
    charToInt.put('d', 4);
    charToInt.put('a', 1);
    charToInt.put('a', 1);
    charToInt.put('a', 7);
    
    ASSERT_EQ(charToInt.get('b'), 2);
    ASSERT_EQ(charToInt.get('c'), 3);
    ASSERT_EQ(charToInt.get('d'), 4);
    ASSERT_EQ(charToInt.get('a'), 7);

    charToString.put('a', "1.0");
    ASSERT_EQ(charToString.get('a'), "1.0");
    charToString.put('b', "2.0");
    charToString.put('c', "3.0");
    charToString.put('d', "4.0");
    charToString.put('a', "1.0");
    charToString.put('a', "Gabagool");
    charToString.put('a', "Oh Marone!");
    
    ASSERT_EQ(charToString.get('b'), "2.0");
    ASSERT_EQ(charToString.get('c'), "3.0");
    ASSERT_EQ(charToString.get('d'), "4.0");
    ASSERT_EQ(charToString.get('a'), "Oh Marone!");

    charToDouble.put('a', 1.0);
    ASSERT_EQ(charToDouble.get('a'), 1.0);
    charToDouble.put('b', 2.0);
    charToDouble.put('c', 3.0);
    charToDouble.put('d', 4.0);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 1.0);
    charToDouble.put('a', 65.0);
    
    ASSERT_EQ(charToDouble.get('b'), 2.0);
    ASSERT_EQ(charToDouble.get('c'), 3.0);
    ASSERT_EQ(charToDouble.get('d'), 4.0);
    ASSERT_EQ(charToDouble.get('a'), 65.0);


    // String keys
    mymap<string, string> stringToString;
    mymap<string, char> stringToChar;
    mymap<string, double> stringToDouble;
    mymap<string, int> stringToInt;

    ASSERT_EQ(stringToString.get("a"), "");
    ASSERT_EQ(stringToChar.get("a"), '\0');
    ASSERT_EQ(stringToDouble.get("a"), 0.0);
    ASSERT_EQ(stringToInt.get("a"), 0);

    // String to other tests
    stringToString.put("Oh Marone!", "Paulie");
    stringToString.put("Stugots", "Tony");
    ASSERT_EQ(stringToString.get("Stugots"), "Tony");
    stringToString.put("Gabagool", "Silvio");
    stringToString.put("Let's get back to that Gabagool", "Melfi");
    stringToString.put("Christopher", "Adriana");
    stringToString.put("Stugots", "Carmela");
    
    ASSERT_EQ(stringToString.get("Oh Marone!"), "Paulie");
    ASSERT_EQ(stringToString.get("Gabagool"), "Silvio");
    ASSERT_EQ(stringToString.get("Let's get back to that Gabagool"), "Melfi");
    ASSERT_EQ(stringToString.get("Stugots"), "Carmela");

    stringToChar.put("Oh Marone!", 'P');
    stringToChar.put("Stugots", 'T');
    ASSERT_EQ(stringToChar.get("Stugots"), 'T');
    stringToChar.put("Gabagool", 'S');
    stringToChar.put("Let's get back to that Gabagool", 'M');
    stringToChar.put("Christopher", 'A');
    stringToChar.put("Stugots", 'C');

    ASSERT_EQ(stringToChar.get("Oh Marone!"), 'P');
    ASSERT_EQ(stringToChar.get("Gabagool"), 'S');
    ASSERT_EQ(stringToChar.get("Let's get back to that Gabagool"), 'M');
    ASSERT_EQ(stringToChar.get("Stugots"), 'C');

    stringToInt.put("Oh Marone!", 1);
    stringToInt.put("Stugots", 2);
    ASSERT_EQ(stringToInt.get("Stugots"), 2);
    stringToInt.put("Gabagool", 3);
    stringToInt.put("Let's get back to that Gabagool", 4);
    stringToInt.put("Christopher", 5);
    stringToInt.put("Stugots", 6);

    ASSERT_EQ(stringToInt.get("Oh Marone!"), 1);
    ASSERT_EQ(stringToInt.get("Gabagool"), 3);
    ASSERT_EQ(stringToInt.get("Let's get back to that Gabagool"), 4);
    ASSERT_EQ(stringToInt.get("Stugots"), 6);

    stringToDouble.put("Oh Marone!", 1.0);
    stringToDouble.put("Stugots", 2.0);
    ASSERT_EQ(stringToDouble.get("Stugots"), 2.0);
    stringToDouble.put("Gabagool", 3.0);
    stringToDouble.put("Let's get back to that Gabagool", 4.0);
    stringToDouble.put("Christopher", 5.0);
    stringToDouble.put("Stugots", 6.0);

    ASSERT_EQ(stringToDouble.get("Oh Marone!"), 1.0);
    ASSERT_EQ(stringToDouble.get("Gabagool"), 3.0);
    ASSERT_EQ(stringToDouble.get("Let's get back to that Gabagool"), 4.0);
    ASSERT_EQ(stringToDouble.get("Stugots"), 6.0);
    
    // Double keys
    mymap<double, double> doubleToDouble;
    mymap<double, string> doubleToString;
    mymap<double, int> doubleToInt;
    mymap<double, char> doubleToChar;

    ASSERT_EQ(doubleToDouble.get(0.0), 0.0);
    ASSERT_EQ(doubleToString.get(0.0), "");
    ASSERT_EQ(doubleToInt.get(0.0), 0);
    ASSERT_EQ(doubleToChar.get(0.0), '\0'); 

    // Double to other tests
    for(int x = 0; x < 10; ++x) {
        doubleToInt.put((double)(x + 1), x);
        doubleToString.put((double)(x + 2), "Gabagool");
        doubleToChar.put((double)(x + 3), 'G');
        doubleToDouble.put((double)(x + 4), 2.2);
    }

    // Expected values
    ASSERT_EQ(doubleToInt.get(1.0), 0);
    ASSERT_EQ(doubleToInt.get(2.0), 1);
    ASSERT_EQ(doubleToInt.get(3.0), 2);
    ASSERT_EQ(doubleToInt.get(4.0), 3);
    ASSERT_EQ(doubleToInt.get(5.0), 4);
    ASSERT_EQ(doubleToInt.get(6.0), 5);
    ASSERT_EQ(doubleToInt.get(7.0), 6);
    ASSERT_EQ(doubleToInt.get(8.0), 7);
    ASSERT_EQ(doubleToInt.get(9.0), 8);
    ASSERT_EQ(doubleToInt.get(10.0), 9);

    ASSERT_EQ(doubleToString.get(2.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(3.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(4.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(5.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(6.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(7.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(8.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(9.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(10.0), "Gabagool");
    ASSERT_EQ(doubleToString.get(11.0), "Gabagool");

    ASSERT_EQ(doubleToChar.get(3.0), 'G');
    ASSERT_EQ(doubleToChar.get(4.0), 'G');
    ASSERT_EQ(doubleToChar.get(5.0), 'G');
    ASSERT_EQ(doubleToChar.get(6.0), 'G');
    ASSERT_EQ(doubleToChar.get(7.0), 'G');
    ASSERT_EQ(doubleToChar.get(8.0), 'G');
    ASSERT_EQ(doubleToChar.get(9.0), 'G');
    ASSERT_EQ(doubleToChar.get(10.0), 'G');
    ASSERT_EQ(doubleToChar.get(11.0), 'G');
    ASSERT_EQ(doubleToChar.get(12.0), 'G');

    ASSERT_EQ(doubleToDouble.get(4.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(5.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(6.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(7.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(8.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(9.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(10.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(11.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(12.0), 2.2);
    ASSERT_EQ(doubleToDouble.get(13.0), 2.2);

    // cout << "Finished testing get function" << endl;
}

TEST(mymap, toString) {

    // Int to int test
    mymap<int, int> testing;
    testing.put(5, 42);
    testing.put(3, 81);
    testing.put(4, 62);
    testing.put(2, -7426589);
    string result = testing.toString();
    string soln = "key: 2 value: -7426589\nkey: 3 value: 81\nkey: 4 value: 62\nkey: 5 value: 42\n";
    ASSERT_EQ(result, soln);

    // int to int map with more nodes
    mymap<int, int> bigOne;
    stringstream dump("");

    int n = randomInteger(0, 100);
    for(int x = 0; x < n; ++x) {
        bigOne.put(x, x);
        dump << "key: " << x << " value: " << x << "\n";
    }
    ASSERT_EQ(bigOne.toString(), dump.str());

    // String to int map with many nodes
    mymap<string, int> strtoi;
    string blah = "a";
    stringstream dumpTwo("");
    for(int x = 0; x < n; ++x) {
        strtoi.put(blah, x);
        dumpTwo << "key: " << blah << " value: " << x << "\n";
        blah.append("a");
    }
    ASSERT_EQ(strtoi.toString(), dumpTwo.str());
}

TEST(mymap, bracketOperator) {

    mymap<int, int> testing;
    ASSERT_EQ(testing[0], 0);
    testing.put(1, 437);
    ASSERT_EQ(testing[1], 437);

    mymap<double, int> testingTwo;
    for(int x = 0; x < 5000; ++x) {
        int n = randomInteger(0,10000);
        testingTwo.put((double) n, n);
        ASSERT_EQ(testingTwo[(double) n], n);
    }

    mymap<int, char> anotherOne;
    for(int x = 0; x < 10000; ++x) {
        ASSERT_EQ(anotherOne[x], '\0');
    }
    anotherOne.put(5000, 'q');
    ASSERT_EQ(anotherOne[5000], 'q');

    map<int, int> standardMap;
    mymap<int, int> parallelMap;
    for(int x = 0; x < 15; ++x) {
        int n = randomInteger(0,10000);
        standardMap[(double) n] =  n;
        parallelMap.put((double) n, n);
    }

    //cout << parallelMap.toString() << endl;

    map<int, int>::iterator iter = standardMap.begin();
    for(auto key : parallelMap) {
        //cout << iter->first << ", " << parallelMap[key] << endl;
        // ASSERT_EQ(iter->second, parallelMap[key]);
        ++iter;
    }

}

TEST(mymap, iteratorBeginAndOperatorPlusPlus) {

    // Trivial case test
    mymap<int, int> testing;
    testing.put(2, 2);
    testing.put(1, 1);
    testing.put(3, 3);
    testing.put(0, 0);

    int order[] = {0, 1, 2, 3};

    int i = 0;

    for(auto key : testing) {
        ASSERT_EQ(order[i++], key);
    }

    // Larger maps of trivial data types
    mymap<int, int> bigOne;
    map<int, int> correctBigOne;

    // Insert elements
    for(int x = 0; x < 10000; ++x) {
        int n = randomInteger(0, 10000);
        bigOne.put(n, n);
        correctBigOne[n] = n;
    }

    // Traverse and verify.
    map<int, int>::iterator iter = correctBigOne.begin();
    for(auto key : bigOne) {
        ASSERT_EQ(iter->second, bigOne.get(key));
        ++iter;
    }

    // A map with string as the key
    mymap<string, int> strToInt;
    map<string, int> correctStrToInt;
    strToInt.put("Bob", 1);
    strToInt.put("Max", 1);
    strToInt.put("Sam", 1);
    strToInt.put("David", 1);
    strToInt.put("Alex", 1);
    correctStrToInt["Bob"] = 1;
    correctStrToInt["Max"] = 1;
    correctStrToInt["Sam"] = 1;
    correctStrToInt["David"] = 1;
    correctStrToInt["Alex"] = 1;

    // Traverse and verify
    map<string, int>::iterator iter2 = correctStrToInt.begin();
    for(auto key : strToInt) {
        ASSERT_EQ(iter2->second, strToInt.get(key));
        ++iter2;
    }

    // Check the beginning of the mymap
    ASSERT_EQ("Alex", *strToInt.begin());
    auto x = correctStrToInt.begin();
    ASSERT_EQ("Alex", x->first);
}

TEST (mymap, copyAssignmentOperator) {

    // Small initial test of a trivial case.
    mymap<int, int> original;
    original.put(2,2);
    original.put(1,1);
    original.put(3,3);

    // Use the copy assignment operator to bring in a new mymap
    mymap<int, int> clone = original;

    // Make sure all of the keys match
    for(int x = 0; x < clone.Size(); ++x) {
        ASSERT_EQ(original[x], clone[x]);
    }

    // Another map but with doubles as the keys
    mymap<double, int> another;

    // 100 elements into a tree
    for(int x = 0; x < 1000; ++x) {
        int n = randomInteger(0, 1000);
        another.put((double) n, n);
    }

    // Verify the larger tree
    mymap<double, int> anotherClone = another;
    for(int x = 0; x < anotherClone.Size(); ++x) {
        ASSERT_EQ(anotherClone[x], another[x]);
    }

    // Make sure that updates aren't sabotaging the maps or making extra copies of things
    mymap<int, double> anotherOne;
    for(int x = 0; x < 1000; ++x) {
        int n = randomInteger(0, 5);
        anotherOne.put(n,(double) n);
    }
    //ASSERT_EQ(anotherOne.Size(), 5);
    mymap<int, double> miniMe = anotherOne;
    for(int x = 0; x < miniMe.Size(); ++x) {
        ASSERT_EQ(miniMe[x], anotherOne[x]);
    }

    // Check that empty copies don't tank us
    mymap<string, char> emptyOnPurpose;
    mymap<string, char> emptyClone = emptyOnPurpose;

    // Characters as strings
    mymap<char, string> charAsKey;
    charAsKey.put('q', "Gabagool");
    charAsKey.put('a', "Gabagool");
    charAsKey.put('t', "Gabagool");
    charAsKey.put('s', "Gabagool");
    charAsKey.put('x', "Gabagool");
    charAsKey.put('b', "Gabagool");
    charAsKey.put('m', "Gabagool");
    charAsKey.put('z', "Gabagool");
    charAsKey.put('y', "Gabagool");
    
    // make the copy and verify the contents
    mymap<char, string> charClone = charAsKey;
    ASSERT_EQ(charAsKey.toString(), charAsKey.toString());

    // Time to make one that's MASSIF
    mymap<double, double> bigKahuna;
    for(int x = 0; x < 1000000; ++x) {
        int n = randomInteger(0,1000000);
        bigKahuna.put((double) n, (double) n);
    }

    // The copy
    mymap<double, double> sonOfBigKahuna = bigKahuna;

    //index
    int i = 0;

    // Highly irresponsible syntax
    for(auto key : sonOfBigKahuna) {
        ASSERT_EQ(sonOfBigKahuna[i], bigKahuna[i]);
        ++i;
    }
}

TEST(mymap, copyConstructor) {

    // Same tests as above, just with the copy constructor instead

    // Small initial test of a trivial case.
    mymap<int, int> original;
    original.put(2,2);
    original.put(1,1);
    original.put(3,3);

    // Use the copy assignment operator to bring in a new mymap
    mymap<int, int> clone(original);

    // Make sure all of the keys match
    for(int x = 0; x < clone.Size(); ++x) {
        ASSERT_EQ(original[x], clone[x]);
    }

    // Another map but with doubles as the keys
    mymap<double, int> another;

    // 100 elements into a tree
    for(int x = 0; x < 1000; ++x) {
        int n = randomInteger(0, 1000);
        another.put((double) n, n);
    }

    // Verify the larger tree
    mymap<double, int> anotherClone = another;
    for(int x = 0; x < anotherClone.Size(); ++x) {
        ASSERT_EQ(anotherClone[x], another[x]);
    }

    // Make sure that updates aren't sabotaging the maps or making extra copies of things
    mymap<int, double> anotherOne;
    for(int x = 0; x < 1000; ++x) {
        int n = randomInteger(0, 5);
        anotherOne.put(n,(double) n);
    }
    //ASSERT_EQ(anotherOne.Size(), 5);
    mymap<int, double> miniMe(anotherOne);
    for(int x = 0; x < miniMe.Size(); ++x) {
        ASSERT_EQ(miniMe[x], anotherOne[x]);
    }

    // Check that empty copies don't tank us
    mymap<string, char> emptyOnPurpose;
    mymap<string, char> emptyClone(emptyOnPurpose);

    // Characters as strings
    mymap<char, string> charAsKey;
    charAsKey.put('q', "Gabagool");
    charAsKey.put('a', "Gabagool");
    charAsKey.put('t', "Gabagool");
    charAsKey.put('s', "Gabagool");
    charAsKey.put('x', "Gabagool");
    charAsKey.put('b', "Gabagool");
    charAsKey.put('m', "Gabagool");
    charAsKey.put('z', "Gabagool");
    charAsKey.put('y', "Gabagool");
    
    // make the copy and verify the contents
    mymap<char, string> charClone(charAsKey);
    ASSERT_EQ(charAsKey.toString(), charAsKey.toString());

    // Time to make one that's MASSIF
    mymap<double, double> bigKahuna;
    for(int x = 0; x < 1000000; ++x) {
        int n = randomInteger(0,1000000);
        bigKahuna.put((double) n, (double) n);
    }

    // The copy
    mymap<double, double> sonOfBigKahuna(bigKahuna);

    //index
    int i = 0;

    // Highly irresponsible syntax
    for(auto key : sonOfBigKahuna) {
        ASSERT_EQ(sonOfBigKahuna[i], bigKahuna[i]);
        ++i;
    }
}

TEST(mymap, toVector) {
    mymap<int, int> a;
    a.put(2, 2);
    a.put(1, 1);
    a.put(3, 3);
    //cout << a.checkBalance() << endl;
    vector<pair<int, int> > pairs = a.toVector();
    for(pair<int, int>& p : pairs) {
        //cout << "key: " << p.first << " value: " << p.second << endl;
    }

    mymap<int, double> large;
    for(int x = 0; x < 25; ++x) {
        int n = randomInteger(0, 25);
        large.put(n, (double) n);
    }
    vector<pair<int, double> > pairsTwo = large.toVector();
    for(pair<int, double>& p : pairsTwo) {
        cout << "key: " << p.first << " value: " << p.second << endl;
    }
}

// TEST(mymap, balancing) {
//     mymap<int, int> a;
//     a.put(2, 2);
//     a.put(1, 1);
//     a.put(3, 3);
//     a.put(4, 4);
//     a.put(5, 5);
//     cout << a.checkBalance() << endl;

// }