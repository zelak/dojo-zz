#ifndef BOXINFO_H
#define BOXINFO_H

class BoxinfoManager;

class Boxinfo {

public:
    Boxinfo(BoxinfoManager *manager);
    ~Boxinfo();

    void init();

private:
    void initTlfLib();
    void initTlfEntries();
    void initArrisEntries();

    BoxinfoManager *m_manager;
};

#endif // BOXINFO_H
