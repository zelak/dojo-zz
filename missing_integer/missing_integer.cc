
/*
Missing Integer - Find the smallest positive integer that does not occur in a given sequence.

Description:

Given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

void printVector(vector<int> &V)
{
    cout << "[ ";
    for (auto v : V) {
        cout << v << " ";

    }
    cout << "]" << endl;
}

void printResult(int missingValue, int expectedValue)
{
    if (missingValue == expectedValue) {
        cout << "--> OK";
    } else {
        cout << "--> NOK";
    }
    cout << " -- Missing Integer = " << missingValue << endl;
}

void printTestResult(int testNumber, vector<int> &A, int missingValue, int expectedValue)
{
    cout << "Test " << testNumber << " ";
    printVector(A);
    printResult(missingValue, expectedValue);
}

int missingInteger(vector<int> &A) {
    auto smallest = 1;
    sort(A.begin(), A.end());
    A.erase( unique( A.begin(), A.end() ), A.end() );

    for (auto i : A) {
        if (smallest == i) {
            smallest = i+1;
        }
    }
    
    return smallest;
}

int main (int argc, char ** argv)
{
    cout << "Missing Integer Test" << endl;
    int missingValue = 0;
    vector<int> testVector;

    testVector = {1,3,6,4,1,2};
    missingValue = missingInteger(testVector);
    printTestResult(1, testVector, missingValue, 5);

    testVector = {-1,-3,-6,1};
    missingValue = missingInteger(testVector);
    printTestResult(2, testVector, missingValue, 2);

    testVector = {-1,-3,-6};
    missingValue = missingInteger(testVector);
    printTestResult(3, testVector, missingValue, 1);
    
    testVector = {1,2,3};
    missingValue = missingInteger(testVector);
    printTestResult(4, testVector, missingValue, 4);

    return 0;
}