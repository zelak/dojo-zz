#ifndef __BOXINFO_TLF_CSC_READ_STRATEGY_H__
#define __BOXINFO_TLF_CSC_READ_STRATEGY_H__

#include "boxinfo_tlf_read_strategy.h"

class BoxinfoTlfCSCReadStrategy : public BoxinfoTlfReadStrategy
{
public:
    BoxinfoTlfCSCReadStrategy() {}
    ~BoxinfoTlfCSCReadStrategy() {}

    virtual int run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry) override;
};

#endif // __BOXINFO_TLF_CSC_READ_STRATEGY_H__