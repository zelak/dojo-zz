#ifndef __BOXINFO_TLF_READ_STRATEGY_H__
#define __BOXINFO_TLF_READ_STRATEGY_H__

#include "boxinfo_read_strategy.h"

class BoxinfoTlfReadStrategy : public BoxinfoReadStrategy
{
public:
    BoxinfoTlfReadStrategy() {}
    ~BoxinfoTlfReadStrategy() {}

    virtual int run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override;
};

#endif // __BOXINFO_TLF_READ_STRATEGY_H__