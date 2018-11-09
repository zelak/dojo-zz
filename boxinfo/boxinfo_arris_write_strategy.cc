#include <pthread.h>

#include "bsp-drop/arris_board_support.h"

#include "boxinfo_arris_write_strategy.h"

int BoxinfoArrisWriteStrategy::run(const char *buf, size_t size, off_t offset, BoxinfoEntry *entry)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int res;

    pthread_mutex_lock(&mutex);
    res = set_ipc_parameter(entry->wrname(), (char*)buf, (uint16_t*)&size);
    pthread_mutex_unlock(&mutex);

    return size;
}
