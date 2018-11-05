#ifndef BOXINFO_H
#define BOXINFO_H

#include <iostream>

// TODO: Remove MOCK STRUCTS
struct fuse_conn_info { int foo; int fighters; };
struct fuse_file_info { int foo; int fighters; };
class fuse_fill_dir_t { public: fuse_fill_dir_t() {} };

class BoxinfoManager;

class Boxinfo {

public:
    Boxinfo(BoxinfoManager *manager);
    ~Boxinfo();

    static void* init(struct fuse_conn_info *conn);
    static int access(const char *path, int mask);
    static int getattr(const char *path, struct stat *stat);
    static int read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *info);
    static int write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info);
    static int open(const char *path, struct fuse_file_info *info);
    static int release(const char *path, struct fuse_file_info *info);
    static int readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *info);
    static int truncate(const char *path, off_t offset);

    void initArrisEntries();

private:
    BoxinfoManager *m_manager;
};

#endif // BOXINFO_H
