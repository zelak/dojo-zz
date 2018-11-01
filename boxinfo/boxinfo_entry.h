#ifndef BOXINFO_ENTRY_H
#define BOXINFO_ENTRY_H

#include <string>

using std::string;

class BoxinfoEntry {

public:
    BoxinfoEntry(string path, int tlfkey);
    ~BoxinfoEntry();

    string path();
    mode_t mode();
    size_t nlink();
    size_t offset();
    int tlfkey();
    string rdname();
    string wrname();

    virtual int read(char *buf, size_t size, off_t offset);
    virtual int write(char *buf, size_t size, off_t offset);

private:
    string m_path;
    mode_t m_mode;
    size_t m_nlink;
    size_t m_size;
    size_t m_offset;
    int    m_tlfkey;
    string m_rdname;
    string m_wrname;
};

#endif // BOXINFO_ENTRY_H