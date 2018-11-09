#ifndef __BOXINFO_WRITE_STRATEGY_H__
#define __BOXINFO_WRITE_STRATEGY_H__

#include "boxinfo_entry.h"

class BoxinfoWriteStrategy
{
public:
    BoxinfoWriteStrategy() {}
    ~BoxinfoWriteStrategy() {}

    virtual int run(const char *buf, size_t size, off_t offset, BoxinfoEntry *entry) = 0;
};

#endif // __BOXINFO_WRITE_STRATEGY_H__