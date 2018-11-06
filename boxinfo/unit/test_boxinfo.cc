/**
 * Boxinfo unit tests
 **/

#include <string>
#include <cassert>
#include <iostream>

#include "../boxinfo.h"
#include "../boxinfo_entry.h"
#include "../boxinfo_arris_entry.h"
#include "../boxinfo_manager.h"

using std::cout;
using std::endl;

int main (int argc, char ** argv)
{

    BoxinfoManager *manager = new BoxinfoManager();
    Boxinfo *boxinfo = new Boxinfo(manager);

    // size of manager
    assert(manager->size() == 3);

    // check first entry
    BoxinfoEntry *entryResp = manager->find("/HttpAttempts");
    assert(entryResp != NULL);
    assert("/HttpAttempts" == entryResp->path());
    assert(0 == entryResp->tlfkey());

    // check second entry
    entryResp = manager->find("/HttpServer");
    assert(entryResp != NULL);
    assert("/HttpServer" == entryResp->path());
    assert(0 == entryResp->tlfkey());

    // check third entry
    entryResp = manager->find("/HttpPort");
    assert(entryResp != NULL);
    assert("/HttpPort" == entryResp->path());
    assert(0 == entryResp->tlfkey());

    entryResp = manager->find("/InvalidPath");
    assert(entryResp == NULL);

    delete manager;
    delete boxinfo;

    return 0;
}
