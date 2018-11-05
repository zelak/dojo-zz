#include <iostream>

#include "boxinfo_arris_entry.h"

using std::cout;
using std::endl;

BoxinfoArrisEntry::BoxinfoArrisEntry(string path, mode_t mode, size_t nlink,
                                     size_t size, size_t offset, int tlfkey,
                                     string rdname, string wrname)
    : BoxinfoEntry(path, mode, nlink, size, offset, tlfkey, rdname, wrname)
{
}

BoxinfoArrisEntry::~BoxinfoArrisEntry()
{
}

int BoxinfoArrisEntry::read(char *buf, size_t size, off_t offset)
{
    return 0;
}

int BoxinfoArrisEntry::write(char *buf, size_t size, off_t offset)
{
    return 0;
}