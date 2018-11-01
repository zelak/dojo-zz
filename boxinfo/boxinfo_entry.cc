#include <iostream>

#include "boxinfo_entry.h"

using std::cout;
using std::endl;

BoxinfoEntry::BoxinfoEntry(string path, int tlfkey)
{
    m_path = path;
    m_tlfkey = tlfkey;
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

int BoxinfoEntry::read(char *buf, size_t size, off_t offset)
{
    cout << __func__ << "(): Called!" << endl;
    return 0;
}

int BoxinfoEntry::write(char *buf, size_t size, off_t offset)
{
    cout << __func__ << "(): Called!" << endl;
    return 0;
}