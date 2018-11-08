#ifndef BOXINFO_TLF_ENTRY_H
#define BOXINFO_TLF_ENTRY_H

#include <string>
#include "boxinfo_entry.h"

using std::string;

class BoxinfoTlfEntry : public BoxinfoEntry {

public:
    BoxinfoTlfEntry(string path, mode_t mode, size_t nlink,
                    size_t size, size_t offset, int tlfkey,
                    string rdname, string wrname);
    ~BoxinfoTlfEntry();

    int read(char *buf, size_t size, off_t offset) override;
    int write(const char *buf, size_t size, off_t offset) override;

    int tlfReadInfo(char *buf, size_t size, off_t offset);
};

#endif // BOXINFO_TLF_ENTRY_H