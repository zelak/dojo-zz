#include "boxinfo.h"
#include "boxinfo_entry.h"
#include "boxinfo_manager.h"

#include <fuse.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

static BoxinfoManager *manager = NULL;

static struct fuse_operations operations;

static void* do_init(struct fuse_conn_info *conn)
{
    return NULL;
}

static int do_access(const char *path, int mask)
{
    cout << __FUNCTION__ << endl;

    BoxinfoEntry *entry = manager->find(path);
    if (!entry) {
        return -ENOENT;
    }

    if (entry->mode() & mask) {
        cout << path << endl;
        return 0;
    }

    return -EPERM;
}

static int do_getattr(const char *path, struct stat *stat)
{
    cout << __FUNCTION__ << endl;

    memset(stat, 0, sizeof(*stat));

    BoxinfoEntry *entry = manager->find(path);
    if (!entry) {
        return -ENOENT;
    }

    stat->st_mode  = entry->mode();
    stat->st_nlink = entry->nlink();
    stat->st_size  = entry->size();

    cout << path << endl;

    return 0;
}

static int do_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << endl;

    BoxinfoEntry *entry = manager->find(path);
    if (!entry) {
        return -ENOENT;
    }

    return entry->read(buf, size, offset);
}

static int do_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << endl;

    BoxinfoEntry *entry = manager->find(path);
    if (!entry) {
        return -ENOENT;
    }

    if (!(entry->mode() & 0222)) {
        return -EPERM;
    }

    return entry->write(buf, size, offset);
}

static int do_open(const char *path, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << endl;
    BoxinfoEntry *entry = manager->find(path);
    if (!entry) {
        return -ENOENT;
    }
    return 0;
}

static int do_release(const char *path, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << endl;
    return 0;
}

static int do_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *info)
{
    cout << __FUNCTION__ << endl;

    BoxinfoEntry *entry = manager->find(path);
    if ( !entry || !S_ISDIR(entry->mode()) ) {
        return -ENOENT;
    }

    filler(buf, ".", 0, 0);
    filler(buf, "..", 0, 0);

    cout << entry->path() << endl;

    manager->getEntries([&](BoxinfoEntry *entry){
        cout << entry->path() << endl;
        if ( ! S_ISDIR(entry->mode()) ) {
            filler(buf, entry->path().c_str() + 1, 0, 0);
        }
    });

    return 0;
}

static int do_truncate(const char *path, off_t offset)
{
    cout << __FUNCTION__ << endl;
    return 0;
}

static void load_fuse_operations()
{
    operations.getattr  = do_getattr;
    operations.truncate = do_truncate;
    operations.open     = do_open;
    operations.read     = do_read;
    operations.write    = do_write;
    operations.release  = do_release;
    operations.readdir  = do_readdir;
    operations.init     = do_init;
    operations.access   = do_access;
}

int main (int argc, char ** argv)
{
    cout << ">> Init Boxinfo modules" << endl;
    manager = new BoxinfoManager();
    Boxinfo *boxinfo = new Boxinfo(manager);
    boxinfo->init();

    cout << ">> Init FUSE operations" << endl;
    memset(&operations, 0, sizeof(struct fuse_operations));
    load_fuse_operations();

    cout << ">> Starting FUSE ..." << endl;
    return fuse_main(argc, argv, &operations, NULL);

    return 0;
}