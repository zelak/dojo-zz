#ifndef __BOXINFO_ARRIS_WRITE_STRATEGY_H__
#define __BOXINFO_ARRIS_WRITE_STRATEGY_H__

#include "boxinfo_write_strategy.h"

class BoxinfoArrisWriteStrategy : public BoxinfoWriteStrategy
{
public:
    BoxinfoArrisWriteStrategy() {}
    ~BoxinfoArrisWriteStrategy() {}

    virtual int run(const char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override;
};

#endif // __BOXINFO_ARRIS_WRITE_STRATEGY_H__