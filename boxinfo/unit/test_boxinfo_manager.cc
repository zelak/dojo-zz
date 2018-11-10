/**
 * Boxinfo manager unit tests
 **/

#include <string>
#include <cassert>
#include <iostream>

#include "../boxinfo_manager.h"
#include "../boxinfo_entry.h"

using std::cout;
using std::endl;

int main (int argc, char ** argv)
{
    BoxinfoManager *manager = new BoxinfoManager();
    BoxinfoEntry *entry  = new BoxinfoEntry("/HttpServer" , 0666, 1, 256, 0, 0, "get-http-server", "set-http-server", NULL, NULL);
    BoxinfoEntry *entry2 = new BoxinfoEntry("/HttpPort"   , 0666, 1, 256, 0, 0, "get-http-port", "set-http-port", NULL, NULL);

    // insert first entry
    cout << "Test manager: insert a new entry with path: " << entry->path() << " and key: " << entry->tlfkey() << endl;
    manager->insert(entry);

    // check manager hash table size
    cout << "Test manager: number of entries " << manager->size() << endl;
    assert(manager->size() == 1);

    // compare find result with the recently added entry
    cout << "Test manager: search for an entry with path: " << entry->path() << endl;
    BoxinfoEntry *entryResp = manager->find(entry->path());
    assert(entry->path() == entryResp->path());
    assert(entry->tlfkey() == entryResp->tlfkey());

    // search for an entry that doesn't exist
    cout << "Test manager: search for an entry that doesn't exist" << endl;
    entryResp = manager->find("/PathQueNaoExiste");
    assert(entryResp == NULL);

    // insert second entry
    manager->insert(entry2);

    // check manager hash table size
    cout << "Test manager: number of entries " << manager->size() << endl;
    assert(manager->size() == 2);

    cout << "Test manager: search for an entry with path: " << entry2->path() << endl;
    entryResp = manager->find(entry2->path());
    assert(entry2->path() == entryResp->path());
    assert(entry2->tlfkey() == entryResp->tlfkey());

    cout << "Test manager: trying to insert a NULL entry" << endl;
    manager->insert(NULL);
    assert(manager->size() == 2);

    delete manager;

    return 0;
}
