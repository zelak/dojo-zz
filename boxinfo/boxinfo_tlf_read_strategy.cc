#include <algorithm>
#include <cstring>
#include <cerrno>

#include "boxinfo_tlf_read_strategy.h"

extern "C" {
#include "TLFBootloaderAPI.h"
}

using std::min;

int BoxinfoTlfReadStrategy::run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry)
{
    char buffer[4096];
    tlf_tlv_t element;
    int res = -ENOSYS;

    memset(buffer, 0, sizeof(buffer));
    element.length = sizeof(buffer);
    element.type   = entry->tlfkey();
    element.value  = (uint8_t*)buffer;

    if (TLF_OK == tlf_getInfo(&element)) {
        res = min(entry->size(), size);
        memcpy(buf, element.value + entry->offset() + offset, res);
    }

    return res;
}
