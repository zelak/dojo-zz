#include <cerrno>
#include <iostream>
#include "boxinfo_zanon_read_strategy.h"

using std::cout;
using std::endl;

int BoxinfoZanonReadStrategy::run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry)
{
    cout << __PRETTY_FUNCTION__ << " - Called" << endl;
    return -ENOSYS;
}
