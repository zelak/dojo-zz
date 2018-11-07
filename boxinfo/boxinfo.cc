#include <sys/stat.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "boxinfo.h"
#include "boxinfo_manager.h"
#include "boxinfo_arris_entry.h"
#include "boxinfo_tlf_entry.h"

extern "C" {
#include "TLFBootloaderAPI.h"
}


using std::cout;
using std::endl;

Boxinfo::Boxinfo(BoxinfoManager *manager)
    : m_manager(manager)
{
}

Boxinfo::~Boxinfo()
{
}

void Boxinfo::init()
{
    if (m_manager == NULL) {
        return;
    }

    initTlfEntries();
    // initArrisEntries();
}

void Boxinfo::initTlfEntries()
{
    m_manager->insert(new BoxinfoTlfEntry("/", S_IFDIR | 0755, 2, 0, 0, 0, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/ManufacturerName", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_MANUFACTURER_NAME, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/ModelName", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_STB_MODEL_NAME, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/SerialNumber", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_SERIAL_NUMBER, "get-custom-serial-number", ""));
    m_manager->insert(new BoxinfoTlfEntry("/Oui", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_OUI, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/HwModel", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_HW_MODEL, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/HwVersion", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_HW_VERSION, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/SwBootVersion", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_SW_BOOT_VERSION, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/SwBootloaderVersion", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_SW_BOOTLOADER_VERSION, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/SwDownloaderVersion", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_SW_DOWNLOADER_VERSION, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/SwSplashVersion", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_SW_SPLASH_VERSION, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/SwMiddlewareVersion", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_SW_MIDDLEWARE_VERSION, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/EthernetMacAddress", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_ETHERNET_MAC_ADDRESS, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/WifiMacAddress", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_WIFI_MAC_ADDRESS, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/HpnaMacAddress", S_IFREG | 0444, 1, 255, 0,
                                          TLV_STBINFO_HPNA_MAC_ADDRESS, "", ""));
}

void Boxinfo::initArrisEntries()
{
    m_manager->insert(new BoxinfoArrisEntry("/HttpAttempts", S_IFREG | 0444, 1, 256, 0, 0, "get-http-attempts", ""));
    m_manager->insert(new BoxinfoArrisEntry("/HttpServer"  , S_IFREG | 0666, 1, 256, 0, 0, "get-http-server", "set-http-server"));
    m_manager->insert(new BoxinfoArrisEntry("/HttpPort"    , S_IFREG | 0666, 1, 256, 0, 0, "get-http-port", "set-http-port"));
}
