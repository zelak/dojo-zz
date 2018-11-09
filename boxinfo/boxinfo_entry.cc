#include "boxinfo_entry.h"
#include "boxinfo_read_strategy.h"
#include "boxinfo_write_strategy.h"

BoxinfoEntry::BoxinfoEntry(string path, mode_t mode, size_t nlink,
                           size_t size, size_t offset, int tlfkey,
                           string rdname, string wrname,
                           BoxinfoReadStrategy *read,
                           BoxinfoWriteStrategy *write)
    : m_path(path),
      m_mode(mode),
      m_nlink(nlink),
      m_size(size),
      m_offset(offset),
      m_tlfkey(tlfkey),
      m_rdname(rdname),
      m_wrname(wrname),
      m_read(read),
      m_write(write)
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

int BoxinfoEntry::read(char *buf, size_t size, off_t offset) {
    return m_read->run(buf, size, offset, this);
}

int BoxinfoEntry::write(const char *buf, size_t size, off_t offset) {
    return m_write->run(buf, size, offset, this);
}