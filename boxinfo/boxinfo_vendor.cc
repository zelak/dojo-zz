#include "boxinfo_vendor.h"
#include "boxinfo_manager.h"

BoxinfoVendor::BoxinfoVendor(BoxinfoManager *manager)
    : m_manager(manager)
{
}

BoxinfoVendor::~BoxinfoVendor()
{
}

BoxinfoManager * BoxinfoVendor::manager()
{
    return m_manager;
}