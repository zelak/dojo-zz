#ifndef BOXINFO_ENTRY_H
#define BOXINFO_ENTRY_H

#include <string>

using std::string;

class BoxinfoReadStrategy;
class BoxinfoWriteStrategy;

class BoxinfoEntry {

public:
    BoxinfoEntry(string path, mode_t mode, size_t nlink,
                 size_t size, size_t offset, int tlfkey,
                 string rdname, string wrname,
                 BoxinfoReadStrategy *read,
                 BoxinfoWriteStrategy *write);

    virtual ~BoxinfoEntry();

    string path();
    mode_t mode();
    size_t nlink();
    size_t size();
    size_t offset();
    int tlfkey();
    string rdname();
    string wrname();

    int read(char *buf, size_t size, off_t offset);
    int write(const char *buf, size_t size, off_t offset);

private:
    string m_path;
    mode_t m_mode;
    size_t m_nlink;
    size_t m_size;
    size_t m_offset;
    int    m_tlfkey;
    string m_rdname;
    string m_wrname;

    BoxinfoReadStrategy * m_read;
    BoxinfoWriteStrategy * m_write;
};

#endif // BOXINFO_ENTRY_H