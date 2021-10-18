#include <gtest/gtest.h>
#include "mymap.h"
#include <string>
using namespace std;

TEST(mymap, defaultConstructor) {
    
    cout << "Testing default constructor" << endl;

    mymap<int, int> intToInt;
    mymap<int, string> intToString;
    mymap<int, double> intToDouble;
    mymap<int, char> intToChar;

    // Int to other tests
    ASSERT_EQ(intToInt.Size(), -1);
    ASSERT_EQ(intToString.Size(), -1);
    ASSERT_EQ(intToDouble.Size(), -1);
    ASSERT_EQ(intToChar.Size(), -1);
    ASSERT_NE(intToInt.Size(), 0);
    ASSERT_NE(intToString.Size(), 0);
    ASSERT_NE(intToDouble.Size(), 0);
    ASSERT_NE(intToChar.Size(), 0);

    mymap<char, char> charToChar;
    mymap<char, int> charToInt;
    mymap<char, double> charToDouble;
    mymap<char, string> charToString;
    
    // Char to other tests
    ASSERT_EQ(charToChar.Size(), -1);
    ASSERT_EQ(charToInt.Size(), -1);
    ASSERT_EQ(charToDouble.Size(), -1);
    ASSERT_EQ(charToString.Size(), -1);
    ASSERT_NE(charToString.Size(), 0);
    ASSERT_NE(charToChar.Size(), 0);
    ASSERT_NE(charToDouble.Size(), 0);
    ASSERT_NE(charToInt.Size(), 0);

    mymap<string, string> stringToString;
    mymap<string, char> stringToChar;
    mymap<string, double> stringToDouble;
    mymap<string, int> stringToInt;

    // String to other tests
    ASSERT_EQ(stringToString.Size(), -1);
    ASSERT_EQ(stringToChar.Size(), -1);
    ASSERT_EQ(stringToDouble.Size(), -1);
    ASSERT_EQ(stringToInt.Size(), -1);
    ASSERT_NE(stringToInt.Size(), 0);
    ASSERT_NE(stringToString.Size(), 0);
    ASSERT_NE(stringToDouble.Size(), 0);
    ASSERT_NE(stringToChar.Size(), 0);

    mymap<double, double> doubleToDouble;
    mymap<double, string> doubleToString;
    mymap<double, int> doubleToInt;
    mymap<double, char> doubleToChar;

    // Double to other tests
    ASSERT_EQ(doubleToString.Size(), -1);
    ASSERT_EQ(doubleToDouble.Size(), -1);
    ASSERT_EQ(doubleToInt.Size(), -1);
    ASSERT_EQ(doubleToChar.Size(), -1);
    ASSERT_NE(doubleToChar.Size(), 0);
    ASSERT_NE(doubleToInt.Size(), 0);
    ASSERT_NE(doubleToDouble.Size(), 0);
    ASSERT_NE(doubleToString.Size(), 0);

    cout << "Finished testing default constructor" << endl;
}
