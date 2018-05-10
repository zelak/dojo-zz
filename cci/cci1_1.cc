#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::sort;

/*
 * Chapter 1 - Arrays and Strings
 * 1.1 Is Unique:
 *  Implement an algorithm to determine if a string has all unique characters.
 *  What If you cannot use additional data structures?
 *
 *  Solution tips:
 *   We should know if the string will be an ASCII or Unicode.
 *   Possible ways to solve: hash map or bit vector (faster)
 */ 
bool isUnique(string str)
{
    // empty string
    if (str.length() == 0)
        return false;

    // Assuming that we are handling an ASCII string
    if (str.length() > 128)
        return false;

    map<char, bool> charMap;
    for (auto c : str) {
        if (!charMap[c]) {
            charMap[c] = true;
        } else {
            return false;
        }
    }
    return true;
}

// this method only consider lowercase letters [a-z] 
bool isUniqueBitMask(string str)
{
    // empty string
    if (str.length() == 0)
        return false;

    int checker = 0;
    for (auto c : str) {
        int val = (int)(c - 'a');
        if ( (checker & (1 << val)) > 0) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

void testExercise1_1()
{
    cout << "***** Exercise 1.1: Is Unique *****" << endl;

    // test empty string
    cout << "> Test 1 - Negative Case - Empty string: ";
    if (isUnique("") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    // test big string
    cout << "> Test 2 - Positive Case - Big string: ";
    if (isUnique("abcdefghijklmnopqrstuvwxyz1234567890abcdefghijklmnopqrstuvwxyz1234567890abcdefghijklmnopqrstuvwxyz1234567890abcdefghijklmnopqrstuvwxyz1234567890") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    // test unique string
    cout << "> Test 3 - Positive Case - Unique: ";
    if (isUnique("abcdefghij") == true) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    // test not unique string
    cout << "> Test 4 - Negative Case - Not unique 1: ";
    if (isUnique("aaaabcdefghij") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    // test not unique string
    cout << "> Test 5 - Negative Case - Not unique 2: ";
    if (isUnique("abcdefghija") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    // test not unique string
    cout << "> Test 6 - Negative Case - Not unique 3: ";
    if (isUnique("abcdefgfhij") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    // test with bit mask
    cout << "> Test 7 - Positive Case - Unique Bit Mask: ";
    if (isUniqueBitMask("abcdefghi") == true) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    cout << "> Test 8 - Negative Case - Not Unique Bit Mask: ";
    if (isUniqueBitMask("abcdefa") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
}

int main (int argc, char ** argv)
{
    cout << endl;
    testExercise1_1();
    cout << endl;
    return 0;
}