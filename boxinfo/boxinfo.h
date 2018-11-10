#ifndef __BOXINFO_H__
#define __BOXINFO_H__

#include <list>

using std::list;

class BoxinfoVendor;

class Boxinfo {

public:
    Boxinfo() {}
    ~Boxinfo() {}

    void init();

    void set(BoxinfoVendor *vendor);

    int size();

private:
    list<BoxinfoVendor*> m_vendors;
};

#endif // __BOXINFO_H__
