#ifndef __BOXINFO_DENIED_WRITE_STRATEGY_H__
#define __BOXINFO_DENIED_WRITE_STRATEGY_H__

#include <cerrno>

#include "boxinfo_write_strategy.h"

class BoxinfoDeniedWriteStrategy : public BoxinfoWriteStrategy
{
public:
    BoxinfoDeniedWriteStrategy() {}
    ~BoxinfoDeniedWriteStrategy() {}

    virtual int run(const char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override
    {
        return -EPERM;
    }
};

#endif // __BOXINFO_DENIED_WRITE_STRATEGY_H__