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
using std::move;
using std::srand;
using std::vector;

template<typename T>
vector<T> randomize(const int size, const int random_max)
{
    vector<T> vec(size);
    srand(std::time(0));    
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        *it = rand()%random_max;
    }
    return move(vec);
}

template<typename T>
void print_values(const T& value)
{
    for (auto v : value) {
        cout << v << " ";
    }
    cout << endl;
}

template<typename T>
void print_map_values(const T& value)
{
    for (auto it = value.begin(); it != value.end(); ++it) {
        cout << it->first << " " << it->second << " | ";
    }
    cout << endl;
}

int main (int argc, char ** argv)
{
    auto input = randomize<int>(10, 5);
    map<int,int> output;

    print_values<vector<int>>(input);

    for (auto n : input) {
        output[n] += 1;
    }

    print_map_values<map<int,int>>(output);

    return 0;
}