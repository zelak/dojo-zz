#include <iostream>

using std::cout;
using std::endl;

/*
 * Chapter 1 - Arrays and Strings
 * 1.3 URLify:
 *  Write a method to replace all spaces in a string with '%20'.
 *  You may assume that the string has sufficient space at the end to hold
 *  the additional characters, and that you are given the "true" length of
 *  the string.
 */ 
#define MAX_URL_LENGTH 2048

char* URLify(char *str, int size)
{
    char *newURL = new char[MAX_URL_LENGTH];
    memset(newURL, 0, (sizeof(char) * MAX_URL_LENGTH));

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            newURL[index] = '%';
            newURL[++index] = '2';
            newURL[++index] = '0';
        } else {
            newURL[index] = str[i];
        }
        index++;
    }
    return newURL;
}

void compare(char *str, char *expected, int size)
{
    if (strncmp(str, expected, size) == 0) {
        cout << "OK" << endl;
    } else {
        cout << "ERROR" << endl;
    }
}

void test()
{
    cout << "***** Exercise 1.3: URLify *****" << endl;

    cout << "> Test 1 - Positive case: ";
    {
        char str[] = "Mr John Smith      ";
        char *retStr = URLify(str, 13); 
        char expectedStr[] = "Mr%20John%20Smith";
        compare(retStr, expectedStr, strlen(expectedStr));
        delete [] retStr;
    }

    cout << "> Test 2 - Positive case: ";
    {
        char str[] = "a        bcde xy";
        char *retStr = URLify(str, 16); 
        char expectedStr[] = "a%20%20%20%20%20%20%20%20bcde%20xy";
        compare(retStr, expectedStr, strlen(expectedStr));
        delete [] retStr;
    }
}

int main (int argc, char ** argv)
{
    cout << endl;
    test();
    cout << endl;
    return 0;
}