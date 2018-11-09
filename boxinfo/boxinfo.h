#ifndef BOXINFO_H
#define BOXINFO_H

class BoxinfoManager;

class Boxinfo {

public:
    Boxinfo(BoxinfoManager *manager);
    ~Boxinfo();

    void init();

private:
    void initTlf();
    void initArris();

    BoxinfoManager *m_manager;
};

#endif // BOXINFO_H
