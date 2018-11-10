#include "boxinfo.h"
#include "boxinfo_vendor.h"

void Boxinfo::init()
{
    // init registered vendors
    for(auto vendor : m_vendors) {
        vendor->init();
    }
}

void Boxinfo::set(BoxinfoVendor *vendor)
{
    m_vendors.push_back(vendor);
}

int Boxinfo::size()
{
    return m_vendors.size();
}