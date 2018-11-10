#include "boxinfo_manager.h"
#include "boxinfo_entry.h"

using std::pair;

BoxinfoManager::BoxinfoManager()
{
}

BoxinfoManager::~BoxinfoManager()
{
    if (size() > 0) {
        // TODO: delete each entry before deleting manager
    }
}

void BoxinfoManager::insert(BoxinfoEntry *entry)
{
    m_entries.insert(pair<string, BoxinfoEntry*>(entry->path(), entry));
}

int BoxinfoManager::size()
{
    return m_entries.size();
}

BoxinfoEntry* BoxinfoManager::find(string key)
{
    map<string, BoxinfoEntry*>::iterator it;

    it = m_entries.find(key);

    if (it == m_entries.end())
        return NULL;

    return it->second;
}
