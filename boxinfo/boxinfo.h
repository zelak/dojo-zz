#ifndef BOXINFO_H
#define BOXINFO_H

#include <iostream>
#include <fuse.h>

class BoxinfoManager;

class Boxinfo {

public:
    Boxinfo(BoxinfoManager *manager);
    ~Boxinfo();

    void init();

private:
    void initTlfEntries();
    void initArrisEntries();

    BoxinfoManager *m_manager;
};

#endif // BOXINFO_H
