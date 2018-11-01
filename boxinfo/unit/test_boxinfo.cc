/**
 * Boxinfo unit tests
 **/

#include <string>
#include <cassert>
#include <iostream>

#include "../boxinfo.h"

using std::cout;
using std::endl;

int main (int argc, char ** argv)
{
    Boxinfo::init(NULL);
    Boxinfo::access(NULL, 0);
    Boxinfo::getattr(NULL, NULL);
    Boxinfo::read(NULL, NULL, 0, 0, NULL);
    Boxinfo::write(NULL, NULL, 0, 0, NULL);
    Boxinfo::open(NULL, NULL);
    Boxinfo::release(NULL, NULL);
    Boxinfo::readdir(NULL, NULL, fuse_fill_dir_t(), 0, NULL);
    Boxinfo::truncate(NULL, 0);
    return 0;
}
