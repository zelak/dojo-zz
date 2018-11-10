#ifndef __BOXINFO_ZANON_WRITE_STRATEGY_H__
#define __BOXINFO_ZANON_WRITE_STRATEGY_H__

#include <cerrno>
#include <iostream>
#include "boxinfo_write_strategy.h"

class BoxinfoZanonWriteStrategy : public BoxinfoWriteStrategy
{
public:
    BoxinfoZanonWriteStrategy() {}
    ~BoxinfoZanonWriteStrategy() {}

    virtual int run(const char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override
    {
        std::cout << __PRETTY_FUNCTION__ << " - Called" << std::endl;
        return -EPERM;
    }
};

#endif // __BOXINFO_ZANON_WRITE_STRATEGY_H__