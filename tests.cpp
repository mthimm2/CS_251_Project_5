#include <gtest/gtest.h>
#include <string>
#include "mymap.h"
#include "myrandom.h"

using namespace std;

TEST(mymap, defaultConstructor) {
    cout << "Testing default constructor" << endl;

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

    cout << "Finished testing default constructor" << endl;
}

TEST(mymap, put) {

    cout << "Testing put function" << endl;

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

    cout <<"Finished testing put function" << endl;
}

TEST(mymap, size) {

    cout << "Testing size function" << endl;

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

    cout <<"Finished testing size function" << endl;

}
