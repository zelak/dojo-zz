#ifndef BOXINFO_CASN_ENTRY_H
#define BOXINFO_CASN_ENTRY_H

#include <string>
#include "boxinfo_tlf_entry.h"

using std::string;

class BoxinfoCASNEntry : public BoxinfoTlfEntry {

public:
    BoxinfoCASNEntry(string path, mode_t mode, size_t nlink,
                     size_t size, size_t offset, int tlfkey,
                     string rdname, string wrname);
    ~BoxinfoCASNEntry();

    int read( char *buf, size_t size, off_t offset) override;
    int write(const char *buf, size_t size, off_t offset) override;

private:
    int CASNRead(char *buf, size_t size, off_t offset);
};

#endif // BOXINFO_CASN_ENTRY_H