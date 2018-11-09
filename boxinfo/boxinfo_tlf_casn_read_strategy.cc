#include <cinttypes>

#include "boxinfo_tlf_casn_read_strategy.h"

int BoxinfoTlfCASNReadStrategy::run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry)
{
    char input[4];
    uint32_t casn;
    int len = BoxinfoTlfReadStrategy::run(input, sizeof(input), offset, entry);

    if (len > 0) {
        casn = (input[0] << 24) | (input[1] << 16) | (input[2] << 8) | input[3];
        len = sprintf(buf, "%010" PRIu32, casn);
    }

    return len;
}
