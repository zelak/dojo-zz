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
#include <list>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::list;

static int8_t constHash1 = 7;
static int8_t constHash2 = 37;
static string g_letters = "acdegilmnoprstuw";

int64_t hash(string s)
{
    int64_t h = constHash1;
    for (auto c : s) {
        h = (h * constHash2 + g_letters.find(c));
    }
    return h;
}

string unhash(int64_t hashValue)
{
    string unhashedString;
    list<int64_t> unhashValueList;

    unhashedString.clear();

    // populate the list
    while (hashValue > constHash1) {
        unhashValueList.push_front(hashValue);
        hashValue = hashValue / constHash2;
    }

    int64_t globalStringIndex = 0;
    int64_t lastValue = constHash1;
    for (auto unhashValue : unhashValueList) {
        globalStringIndex = unhashValue - (lastValue * constHash2);
        lastValue = unhashValue;
        unhashedString += g_letters[globalStringIndex];
    }

    return unhashedString;
}

int main (int argc, char ** argv)
{
    int64_t test_hash   = 680131659347;
    string  test_string = "leepadg";
    cout << endl;
    cout << "Testing hash and unhash" << endl;
    cout << "String: " << test_string << " Hash: " << test_hash << endl;

    if (hash(test_string) == test_hash) {
        cout << "OK";
    } else {
        cout << "NOK";
    }
    cout << " - Hash method!" << endl;

    if (unhash(test_hash).compare(test_string) == 0) {
        cout << "OK";
    } else {
        cout << "NOK";
    }
    cout << " - Unhash method!" << endl;

    cout << endl;
    return 0;
}