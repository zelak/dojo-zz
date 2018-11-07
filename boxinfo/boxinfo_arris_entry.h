#ifndef BOXINFO_ARRIS_ENTRY_H
#define BOXINFO_ARRIS_ENTRY_H

#include <string>
#include  "boxinfo_entry.h"

using std::string;

class BoxinfoArrisEntry : public BoxinfoEntry {

public:
    BoxinfoArrisEntry(string path, mode_t mode, size_t nlink,
                      size_t size, size_t offset, int tlfkey,
                      string rdname, string wrname);
    ~BoxinfoArrisEntry();

    int read( char *buf, size_t size, off_t offset) override;
    int write(const char *buf, size_t size, off_t offset) override;
};

#endif // BOXINFO_ARRIS_ENTRY_H