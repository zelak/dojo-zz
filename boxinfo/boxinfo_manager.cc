#include <iostream>
#include "boxinfo_manager.h"
#include "boxinfo_entry.h"

using std::cout;
using std::endl;
using std::pair;

using BoxinfoMap = map<string, BoxinfoEntry*>;

BoxinfoManager::BoxinfoManager()
{
}

BoxinfoManager::~BoxinfoManager()
{
    // delete remaining entries in map
    for (auto entry : m_entries) {
        delete entry.second;
    }
}

void BoxinfoManager::insert(BoxinfoEntry *entry)
{
    if (entry == nullptr) {
        return;
    }

    m_entries.insert(pair<string, BoxinfoEntry*>(entry->path(), entry));
}

int BoxinfoManager::size()
{
    return m_entries.size();
}

BoxinfoEntry* BoxinfoManager::find(string key)
{
    BoxinfoMap::iterator it;

    it = m_entries.find(key);

    if (it == m_entries.end())
        return NULL;

    return it->second;
}
