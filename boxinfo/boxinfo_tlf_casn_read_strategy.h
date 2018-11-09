#ifndef __BOXINFO_TLF_CASN_READ_STRATEGY_H__
#define __BOXINFO_TLF_CASN_READ_STRATEGY_H__

#include "boxinfo_tlf_read_strategy.h"

class BoxinfoTlfCASNReadStrategy : public BoxinfoTlfReadStrategy
{
public:
    BoxinfoTlfCASNReadStrategy() {}
    ~BoxinfoTlfCASNReadStrategy() {}

    virtual int run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override;
};

#endif // __BOXINFO_TLF_CASN_READ_STRATEGY_H__