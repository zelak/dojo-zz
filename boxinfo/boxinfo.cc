#include "boxinfo.h"
#include "boxinfo_manager.h"
#include "boxinfo_arris_entry.h"
#include <sys/stat.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;

Boxinfo::Boxinfo(BoxinfoManager *manager)
    : m_manager(manager)
{
}

Boxinfo::~Boxinfo()
{
    if (m_manager->size() > 0) {
        // TODO: delete each entry before deleting manager
    }
    delete m_manager;
}

void Boxinfo::init()
{
    if (m_manager == NULL) {
        return;
    }

    initArrisEntries();
}

void Boxinfo::initArrisEntries()
{
    m_manager->insert(new BoxinfoArrisEntry("/", S_IFDIR | 0755, 2, 0, 0, 0, "", ""));

    m_manager->insert(new BoxinfoArrisEntry("/HttpAttempts", S_IFREG | 0444, 1, 256, 0, 0, "get-http-attempts", ""));
    m_manager->insert(new BoxinfoArrisEntry("/HttpServer"  , S_IFREG | 0666, 1, 256, 0, 0, "get-http-server", "set-http-server"));
    m_manager->insert(new BoxinfoArrisEntry("/HttpPort"    , S_IFREG | 0666, 1, 256, 0, 0, "get-http-port", "set-http-port"));
}
