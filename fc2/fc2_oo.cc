/*
Find a 9 letter string of characters that contains only letters from

acdegilmnoprstuw

such that the hash(the_string) is

956446786872726

if hash is defined by the following pseudo-code:

Int64 hash (String s) {
    Int64 h = 7
    String letters = "acdegilmnoprstuw"
    for(Int32 i = 0; i < s.length; i++) {
        h = (h * 37 + letters.indexOf(s[i]))
    }
    return h
}
For example, if we were trying to find the 7 letter string where hash(the_string) was 680131659347, the answer would be "leepadg".)
*/

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

static int8_t hash_c1   = 7;
static int8_t hash_c2   = 37;
static string g_letters = "acdegilmnoprstuw";

int64_t hash(string s)
{
    int64_t h = hash_c1;
    for (auto c : s) {
        h = (h * hash_c2 + g_letters.find(c));
    }
    return h;
}

string reverse_hash(int64_t value)
{
    return "";
}

int main (int argc, char ** argv)
{
    uint64_t test_hash   = 680131659347;
    string   test_string = "leepadg";
    cout << "Testing hash and reverse hash" << endl << endl;
    cout << "String: " << test_string << " Hash: " << test_hash << endl << endl;

    if (hash(test_string) == test_hash) {
        cout << "OK";
    } else {
        cout << "NOK";
    }
    cout << " - Hash method!" << endl;

    if (reverse_hash(test_hash).compare(test_string) == 0) {
        cout << "OK";
    } else {
        cout << "NOK";
    }
    cout << " - Reverse method!" << endl;

    return 0;
}