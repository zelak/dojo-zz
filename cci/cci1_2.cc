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
 * 1.2 Check Permutation:
 *  Given two strings, write a method to decide if one is a permutation of the other.
 */ 
bool isPermutationCounting(const string &s1, const string &s2)
{
    // Considering both strings should be the same size
    if (s1.size() != s2.size()) {
        return false;
    }

    map<char,int> s1Map;
    map<char,int> s2Map;

    for (auto c : s1) {
        s1Map[c] += 1;
    }

    for (auto c : s2) {
        s2Map[c] += 1;
    }

    // check permutations
    for (auto c : s1) {
        if (s1Map[c] != s2Map[c]) {
            return false;
        }
    }

    return true;
}

bool isPermutationSort(string s1, string s2)
{
    // Considering both strings should be the same size
    if (s1.size() != s2.size()) {
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return (s1 == s2);
}

void testExercise1_2()
{
    cout << "***** Exercise 1.2: Check Permutation *****" << endl;

    /*********************************/
    /* testing using counting method */
    /*********************************/
    // sizes
    cout << "Using isPermutationCounting()" << endl;
    cout << "> Test 1 - Negative case - Different sizes: ";
    if (isPermutationCounting("pauloa", "oluapbaa") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
    // different strings
    cout << "> Test 2 - Negative case - Different strings: ";
    if (isPermutationCounting("pauloABC", "oluapDEF") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
    // permutation
    cout << "> Test 3 - Positive case - Small string permutation: ";
    if (isPermutationCounting("paulo", "oluap") == true) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    cout << "> Test 4 - Positive case - Big string permutation: ";
    if (isPermutationCounting("paulopaulopaulopaulopaulopaulopaulopaulo", "oluapoluapoluapoluapoluapoluapoluapoluap") == true) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    /**********************/
    /* testing using sort */
    /**********************/
    cout << "Using isPermutationSort()" << endl;
    cout << "> Test 1 - Negative case - Different sizes: ";   
    if (isPermutationSort("pauloa", "oluapbaa") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
    // different strings
    cout << "> Test 2 - Negative case - Different strings: ";
    if (isPermutationSort("pauloABC", "oluapDEF") == false) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
    // permutation
    cout << "> Test 3 - Positive case - Small string permutation: ";
    if (isPermutationSort("paulo", "oluap") == true) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    cout << "> Test 4 - Positive case - Big string permutation: ";
    if (isPermutationSort("paulopaulopaulopaulopaulopaulopaulopaulo", "oluapoluapoluapoluapoluapoluapoluapoluap") == true) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
}

int main (int argc, char ** argv)
{
    cout << endl;
    testExercise1_2();
    cout << endl;
    return 0;
}