#ifndef __BOXINFO_VENDOR_H__
#define __BOXINFO_VENDOR_H__

class BoxinfoManager;

class BoxinfoVendor {

public:
    BoxinfoVendor(BoxinfoManager *manager);
    ~BoxinfoVendor();

    virtual void init() = 0;

    BoxinfoManager *manager();

private:
    BoxinfoManager *m_manager;
};

#endif // __BOXINFO_VENDOR_H__