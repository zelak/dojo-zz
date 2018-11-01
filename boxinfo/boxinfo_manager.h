#ifndef BOXINFO_MANAGER_H
#define BOXINFO_MANAGER_H

#include <map>
#include <string>

using std::map;
using std::string;

// Forward declaration
class BoxinfoEntry;

class BoxinfoManager {

public:
    BoxinfoManager();
    ~BoxinfoManager();

    void insert(BoxinfoEntry *entry);
    BoxinfoEntry *find(string key);
    int size();

private:
    map<string, BoxinfoEntry*> m_entries;
};

#endif // BOXINFO_MANAGER_H