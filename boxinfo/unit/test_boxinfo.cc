/**
 * Boxinfo unit tests
 **/

#include <string>
#include <cassert>
#include <iostream>

#include "../boxinfo.h"
#include "../boxinfo_manager.h"
#include "../boxinfo_zanon.h"

using std::cout;
using std::endl;

int main (int argc, char ** argv)
{

    Boxinfo        *boxinfo = new Boxinfo();
    BoxinfoManager *manager = new BoxinfoManager();
    BoxinfoZanon   *zanon   = new BoxinfoZanon(manager);

    cout << "test_boxinfo: check boxinfo list size (0): ";
    assert(boxinfo->size() == 0);
    cout << "OK" << endl;

    cout << "test_boxinfo: add new vendor to boxinfo and check its size (1): ";
    boxinfo->set(zanon);
    assert(boxinfo->size() == 1);
    cout << "OK" << endl;

    cout << "test_boxinfo: check manager size (0): ";
    assert(manager->size() == 0);
    cout << "OK" << endl;

    // init boxinfo vendors
    // it should update manager with all vendors entries
    boxinfo->init();

    cout << "test_boxinfo: check manager size (3): ";
    assert(manager->size() == 3);
    cout << "OK" << endl;

    delete zanon;
    delete manager;
    delete boxinfo;

    return 0;
}
