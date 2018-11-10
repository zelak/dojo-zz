#ifndef BOXINFO_MANAGER_H
#define BOXINFO_MANAGER_H

#include <map>
#include <string>
#include <functional>

using std::map;
using std::string;

// Forward declaration
class BoxinfoEntry;

using EntryCallback = std::function<void(BoxinfoEntry *entry)>;

class BoxinfoManager {

public:
    BoxinfoManager();
    ~BoxinfoManager();

    void insert(BoxinfoEntry *entry);
    BoxinfoEntry *find(string key);
    int size();

    inline void getEntries(EntryCallback callback)
    {
        for (auto entry : m_entries) {
            callback(entry.second);
        }
    }

private:
    map<string, BoxinfoEntry*> m_entries;
};

#endif // BOXINFO_MANAGER_H