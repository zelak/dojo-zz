/**
 * 
 **/

#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

using std::map;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::vector;

int main (int argc, char ** argv)
{
    vector<int> input(50000);
    srand(std::time(0));
    map<int,int> output;

    for (auto it = input.begin(); it != input.end(); ++it) {
        *it = rand()%256;
        cout << *it << " ";
    }

    cout << endl;

    for (auto n : input) {
        output[n] += 1;
    }

    for (auto it = output.begin(); it != output.end(); ++it) {
        cout << it->first << " "<<it->second << " | ";
    }
    cout << endl;
    return 0;
}