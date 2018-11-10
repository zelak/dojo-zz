#ifndef __BOXINFO_ZANON_H__
#define __BOXINFO_ZANON_H__

#include "boxinfo_vendor.h"

class BoxinfoZanon : public BoxinfoVendor {

public:
    BoxinfoZanon(BoxinfoManager *manager);
    ~BoxinfoZanon();

    virtual void init();
};

#endif // __BOXINFO_TLF_H__