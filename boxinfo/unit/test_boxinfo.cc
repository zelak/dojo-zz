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


    // just call FUSE static interfaces
    Boxinfo::init(NULL);
    Boxinfo::access(NULL, 0);
    Boxinfo::getattr(NULL, NULL);
    Boxinfo::read(NULL, NULL, 0, 0, NULL);
    Boxinfo::write(NULL, NULL, 0, 0, NULL);
    Boxinfo::open(NULL, NULL);
    Boxinfo::release(NULL, NULL);
    Boxinfo::readdir(NULL, NULL, fuse_fill_dir_t(), 0, NULL);
    Boxinfo::truncate(NULL, 0);

    delete manager;
    delete boxinfo;

    return 0;
}
