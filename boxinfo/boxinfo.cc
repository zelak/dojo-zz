#include "boxinfo.h"
#include "boxinfo_manager.h"
#include "boxinfo_arris_entry.h"
#include <sys/stat.h>
#include <iostream>

using std::cout;
using std::endl;

Boxinfo::Boxinfo(BoxinfoManager *manager)
    : m_manager(manager)
{
    initArrisEntries();
}

Boxinfo::~Boxinfo()
{
}

void* Boxinfo::init(struct fuse_conn_info *conn)
{
    return NULL;
}

void Boxinfo::initArrisEntries()
{
    if (m_manager == NULL) {
        return;
    }
    m_manager->insert(new BoxinfoArrisEntry("/HttpAttempts", S_IFREG | 0444, 1, 256, 0, 0, "get-http-attempts", ""));
    m_manager->insert(new BoxinfoArrisEntry("/HttpServer"  , S_IFREG | 0666, 1, 256, 0, 0, "get-http-server", "set-http-server"));
    m_manager->insert(new BoxinfoArrisEntry("/HttpPort"    , S_IFREG | 0666, 1, 256, 0, 0, "get-http-port", "set-http-port"));
}

int Boxinfo::access(const char *path, int mask)
{
    return 0;
}

int Boxinfo::getattr(const char *path, struct stat *stat)
{
    return 0;
}

int Boxinfo::read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
    return 0;
}

int Boxinfo::write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
    return 0;
}

int Boxinfo::open(const char *path, struct fuse_file_info *info)
{
    return 0;
}

int Boxinfo::release(const char *path, struct fuse_file_info *info)
{
    return 0;
}

int Boxinfo::readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *info)
{
    return 0;
}

int Boxinfo::truncate(const char *path, off_t offset)
{
    return 0;
}
