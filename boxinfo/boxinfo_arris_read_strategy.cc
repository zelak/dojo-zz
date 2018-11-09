#include <algorithm>
#include <pthread.h>

#include "bsp-drop/arris_board_support.h"

#include "boxinfo_arris_read_strategy.h"

using std::min;

const int STR_BUFF = 128;

int BoxinfoArrisReadStrategy::run(char *buf, size_t size, off_t offset, BoxinfoEntry *entry)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    char buffer[STR_BUFF];
    uint16_t bsize = sizeof(buffer);
    int res, bytesread;

    memset(buffer, 0, sizeof(buffer));

    pthread_mutex_lock(&mutex);
    res = get_ipc_parameter(entry->rdname().c_str(), buffer, &bsize);
    pthread_mutex_unlock(&mutex);

    bytesread = min(static_cast<size_t>(bsize), entry->size());
    memcpy(buf, buffer + entry->offset() + offset, bytesread);

    return bytesread;
}
