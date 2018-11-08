#include <iostream>
#include <algorithm>

#include "boxinfo_csc_entry.h"

extern "C" {
#include "TLFBootloaderAPI.h"
}

using std::min;

BoxinfoCSCEntry::BoxinfoCSCEntry(string path, mode_t mode, size_t nlink,
                                 size_t size, size_t offset, int tlfkey,
                                 string rdname, string wrname)
    : BoxinfoTlfEntry(path, mode, nlink, size, offset, tlfkey, rdname, wrname)
{
}

BoxinfoCSCEntry::~BoxinfoCSCEntry()
{
}

int BoxinfoCSCEntry::CSCRead(char *buf, size_t size, off_t offset)
{
    int len = tlfReadInfo(buf, size, offset);
    int i;

    // padding for even boundaries
    len += len % 2;

    int sizeInt = static_cast<int>(size);

    for (i = 0; i < min(sizeInt, len); i+=2) {
        char swap = buf[i];
        buf[i] = buf[i + 1];
        buf[i + 1] = swap;
    }

    return min(sizeInt, len);
}

int BoxinfoCSCEntry::read(char *buf, size_t size, off_t offset)
{
    return CSCRead(buf, size, offset);
}

int BoxinfoCSCEntry::write(const char *buf, size_t size, off_t offset)
{
    return -EPERM;
}