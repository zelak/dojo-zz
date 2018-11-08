#include "boxinfo_entry.h"

BoxinfoEntry::BoxinfoEntry(string path, mode_t mode, size_t nlink,
                           size_t size, size_t offset, int tlfkey,
                           string rdname, string wrname)
    : m_path(path),
      m_mode(mode),
      m_nlink(nlink),
      m_size(size),
      m_offset(offset),
      m_tlfkey(tlfkey),
      m_rdname(rdname),
      m_wrname(wrname)
{
}

BoxinfoEntry::~BoxinfoEntry()
{
}

string BoxinfoEntry::path()
{
    return m_path;
}

mode_t BoxinfoEntry::mode()
{
    return m_mode;
}

size_t BoxinfoEntry::nlink()
{
    return m_nlink;
}

size_t BoxinfoEntry::size()
{
    return m_size;
}

size_t BoxinfoEntry::offset()
{
    return m_offset;
}

int BoxinfoEntry::tlfkey()
{
    return m_tlfkey;
}

string BoxinfoEntry::rdname()
{
    return m_rdname;
}

string BoxinfoEntry::wrname()
{
    return m_wrname;
}