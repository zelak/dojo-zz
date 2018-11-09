#include <algorithm>

#include "boxinfo_tlf_csc_read_strategy.h"

using std::min;

int BoxinfoTlfCSCReadStrategy::run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry)
{
    int len = BoxinfoTlfReadStrategy::run(buf, size, offset, entry);
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
