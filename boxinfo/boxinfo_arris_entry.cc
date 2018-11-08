#include <pthread.h>

#include "bsp-drop/arris_board_support.c"

#include "boxinfo_arris_entry.h"

BoxinfoArrisEntry::BoxinfoArrisEntry(string path, mode_t mode, size_t nlink,
                                     size_t size, size_t offset, int tlfkey,
                                     string rdname, string wrname)
    : BoxinfoEntry(path, mode, nlink, size, offset, tlfkey, rdname, wrname)
{
}

BoxinfoArrisEntry::~BoxinfoArrisEntry()
{
}

int BoxinfoArrisEntry::read( char *buf, size_t size, off_t offset)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    char buffer[STR_BUFF];
    uint16_t bsize = sizeof(buffer);
    int res, bytesread;

    memset(buffer, 0, sizeof(buffer));

    pthread_mutex_lock(&mutex);
    res = get_ipc_parameter(entry->rdname(), buffer, &bsize);
    pthread_mutex_unlock(&mutex);

    bytesread = min(bsize, entry->size());
    memcpy(buf, buffer + entry->offset() + offset, bytesread);

    return bytesread;
}

int BoxinfoArrisEntry::write(const char *buf, size_t size, off_t offset)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int res;

    pthread_mutex_lock(&mutex);
    res = set_ipc_parameter(entry->wrname(), (char*)buf, (uint16_t*)&size);
    pthread_mutex_unlock(&mutex);

    return size;
}