#ifndef BOXINFO_ENTRY_H
#define BOXINFO_ENTRY_H

#include <string>

using std::string;

class BoxinfoEntry {

public:
    BoxinfoEntry(string path, mode_t mode, size_t nlink,
                 size_t size, size_t offset, int tlfkey,
                 string rdname, string wrname);
    virtual ~BoxinfoEntry();

    string path();
    mode_t mode();
    size_t nlink();
    size_t size();
    size_t offset();
    int tlfkey();
    string rdname();
    string wrname();

    // TODO: rmeove return 0 and make it pure virtual
    virtual int read(char *buf, size_t size, off_t offset) { return 0; };
    virtual int write(char *buf, size_t size, off_t offset) {return 0; };

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