#ifndef __BOXINFO_ZANON_READ_STRATEGY_H__
#define __BOXINFO_ZANON_READ_STRATEGY_H__

#include "boxinfo_read_strategy.h"

class BoxinfoZanonReadStrategy : public BoxinfoReadStrategy
{
public:
    BoxinfoZanonReadStrategy() {}
    ~BoxinfoZanonReadStrategy() {}

    virtual int run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override;
};

#endif // __BOXINFO_ZANON_READ_STRATEGY_H__