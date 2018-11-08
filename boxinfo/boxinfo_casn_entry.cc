#include <iostream>
#include <algorithm>
#include <cinttypes>

#include "boxinfo_casn_entry.h"

extern "C" {
#include "TLFBootloaderAPI.h"
}

using std::min;

BoxinfoCASNEntry::BoxinfoCASNEntry(string path, mode_t mode, size_t nlink,
                                   size_t size, size_t offset, int tlfkey,
                                   string rdname, string wrname)
    : BoxinfoTlfEntry(path, mode, nlink, size, offset, tlfkey, rdname, wrname)
{
}

BoxinfoCASNEntry::~BoxinfoCASNEntry()
{
}

int BoxinfoCASNEntry::CASNRead(char *buf, size_t size, off_t offset)
{
    char input[4];
    uint32_t casn;
    int len = tlfReadInfo(input, sizeof(input), offset);

        if (len > 0) {
        casn = (input[0] << 24) | (input[1] << 16) | (input[2] << 8) | input[3];
        len = sprintf(buf, "%010" PRIu32, casn);
    }

    return len;
}

int BoxinfoCASNEntry::read(char *buf, size_t size, off_t offset)
{
    return CASNRead(buf, size, offset);
}

int BoxinfoCASNEntry::write(const char *buf, size_t size, off_t offset)
{
    return -EPERM;
}