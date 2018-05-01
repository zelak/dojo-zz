#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;

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

void testExercise1_1()
{
    // test empty string
    if (isUnique("") == false) {
        cout << "Empty string: OK" << endl;
    } else {
        cout << "Empty string: ERROR" << endl;
    }

    // test empty string
    if (isUnique("abcdefghijklmnopqrstuvwxyz1234567890abcdefghijklmnopqrstuvwxyz1234567890abcdefghijklmnopqrstuvwxyz1234567890abcdefghijklmnopqrstuvwxyz1234567890") == false) {
        cout << "Big string: OK" << endl;
    } else {
        cout << "Big string: ERROR" << endl;
    }

    // test unique string
    if (isUnique("abcdefghij") == true) {
        cout << "Unique string: OK" << endl;
    } else {
        cout << "Unique string: ERROR" << endl;
    }

    // test not unique string
    if (isUnique("aaaabcdefghij") == false) {
        cout << "Not Unique string: OK" << endl;
    } else {
        cout << "Not Unique string: ERROR" << endl;
    }

    // test not unique string
    if (isUnique("abcdefghija") == false) {
        cout << "Not Unique string: OK" << endl;
    } else {
        cout << "Not Unique string: ERROR" << endl;
    }

    // test not unique string
    if (isUnique("abcdefgfhij") == false) {
        cout << "Not Unique string: OK" << endl;
    } else {
        cout << "Not Unique string: ERROR" << endl;
    }
}

int main (int argc, char ** argv)
{
    testExercise1_1();
    return 0;
}