#include "boxinfo.h"

using std::cout;
using std::endl;

Boxinfo::Boxinfo()
{
}

Boxinfo::~Boxinfo()
{
}

void* Boxinfo::init(struct fuse_conn_info *conn)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return NULL;
}

int Boxinfo::access(const char *path, int mask)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::getattr(const char *path, struct stat *stat)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::open(const char *path, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::release(const char *path, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}

int Boxinfo::truncate(const char *path, off_t offset)
{
    cout << __FUNCTION__ << "() -> start" << endl;
    return 0;
}
