#include "boxinfo.h"
#include "boxinfo_vendor.h"

Boxinfo::Boxinfo()
{
}

Boxinfo::~Boxinfo()
{
    for(auto vendor : m_vendors) {
        delete vendor;
    }
}

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