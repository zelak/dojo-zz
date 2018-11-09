#ifndef __BOXINFO_ARRIS_READ_STRATEGY_H__
#define __BOXINFO_ARRIS_READ_STRATEGY_H__

#include "boxinfo_read_strategy.h"

class BoxinfoArrisReadStrategy : public BoxinfoReadStrategy
{
public:
    BoxinfoArrisReadStrategy() {}
    ~BoxinfoArrisReadStrategy() {}

    virtual int run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override;
};

#endif // __BOXINFO_ARRIS_READ_STRATEGY_H__