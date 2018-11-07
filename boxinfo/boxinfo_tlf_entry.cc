#include <iostream>
#include <algorithm>
#include <string.h>

#include "boxinfo_tlf_entry.h"

extern "C" {
#include "TLFBootloaderAPI.h"
}

using std::cout;
using std::endl;
using std::min;

BoxinfoTlfEntry::BoxinfoTlfEntry(string path, mode_t mode, size_t nlink,
                                     size_t size, size_t offset, int tlfkey,
                                     string rdname, string wrname)
    : BoxinfoEntry(path, mode, nlink, size, offset, tlfkey, rdname, wrname)
{
}

BoxinfoTlfEntry::~BoxinfoTlfEntry()
{
}

int BoxinfoTlfEntry::read(char *buf, size_t size, off_t offset)
{
    char buffer[4096];
    tlf_tlv_t element;
    int res = -ENOSYS;

    memset(buffer, 0, sizeof(buffer));
    element.length = sizeof(buffer);
    element.type   = this->tlfkey();
    element.value  = (uint8_t*) buffer;

    if (TLF_OK == tlf_getInfo(&element)) {
        res = min(this->size(), size);
        memcpy(buf, element.value + this->offset() + offset, res);
    }

    return res;
}

int BoxinfoTlfEntry::write(const char *buf, size_t size, off_t offset)
{
    return -EPERM;
}