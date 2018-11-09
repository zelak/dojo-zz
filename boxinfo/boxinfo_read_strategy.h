#ifndef __BOXINFO_READ_STRATEGY_H__
#define __BOXINFO_READ_STRATEGY_H__

#include "boxinfo_entry.h"

class BoxinfoReadStrategy
{
public:
    BoxinfoReadStrategy() {}
    ~BoxinfoReadStrategy() {}

    virtual int run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry) = 0;
};

#endif // __BOXINFO_READ_STRATEGY_H__