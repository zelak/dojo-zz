#include <cassert>
#include <sys/stat.h>

#include "boxinfo.h"
#include "boxinfo_manager.h"

#include "boxinfo_tlf_read_strategy.h"
#include "boxinfo_tlf_casn_read_strategy.h"
#include "boxinfo_tlf_csc_read_strategy.h"
#include "boxinfo_denied_write_strategy.h"
#include "boxinfo_arris_read_strategy.h"
#include "boxinfo_arris_write_strategy.h"

extern "C" {
#include "TLFBootloaderAPI.h"
}

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

    initTlf();
    initArris();
}

void Boxinfo::initTlf()
{
    tlf_result_t res = tlf_init();
    assert(res == TLF_OK);

    m_manager->insert(new BoxinfoEntry("/", S_IFDIR | 0755, 2, 0, 0, 0, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/ManufacturerName", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_MANUFACTURER_NAME, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/ModelName", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_STB_MODEL_NAME, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/SerialNumber", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_SERIAL_NUMBER, "get-custom-serial-number", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/Oui", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_OUI, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/HwModel", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_HW_MODEL, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/HwVersion", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_HW_VERSION, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/SwBootVersion", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_SW_BOOT_VERSION, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/SwBootloaderVersion", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_SW_BOOTLOADER_VERSION, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/SwDownloaderVersion", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_SW_DOWNLOADER_VERSION, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/SwSplashVersion", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_SW_SPLASH_VERSION, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/SwMiddlewareVersion", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_SW_MIDDLEWARE_VERSION, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/EthernetMacAddress", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_ETHERNET_MAC_ADDRESS, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/WifiMacAddress", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_WIFI_MAC_ADDRESS, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/HpnaMacAddress", S_IFREG | 0444, 1, 255, 0,
                                       TLV_STBINFO_HPNA_MAC_ADDRESS, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/Hdcp14Key", S_IFREG | 0444, 1, 1128, 0,
                                       TLV_VARIABLE_HDCP14, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/Hdcp22Key", S_IFREG | 0444,1, 1088, 20,
                                       TLV_VARIABLE_HDCP22, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/NetflixESN", S_IFREG | 0444, 1, 256, 0,
                                       TLV_VARIABLE_NETFLIX_ESN, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));
    m_manager->insert(new BoxinfoEntry("/NetflixDRM", S_IFREG | 0444, 1, 608, 0,
                                       TLV_VARIABLE_NETFLIX_DRM_BIN, "", "",
                                       new BoxinfoTlfReadStrategy(), new BoxinfoDeniedWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/CASN", S_IFREG | 0444, 1, 10, 0,
                                       TLV_STBINFO_NAGRA_SERIAL_NUMBER, "", "",
                                       new BoxinfoTlfCASNReadStrategy(), new BoxinfoDeniedWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/CSC", S_IFREG | 0444, 1, 10, 0,
                                       TLV_STBINFO_NAGRA_CSC_DATA, "", "",
                                       new BoxinfoTlfCSCReadStrategy(), new BoxinfoDeniedWriteStrategy()));
}

void Boxinfo::initArris()
{
    m_manager->insert(new BoxinfoEntry("/HttpServer" , S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-http-server", "set-http-server",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/HttpPort" , S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-http-port", "set-http-port",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/Bootcast", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-bootcast", "set-bootcast",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/BootcastID", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-bootcast-id", "set-bootcast-id",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/BootOrder", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-boot-order", "set-boot-order",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/SplashOrder", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-splash-order", "set-splash-order",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/DirectDownloadBootImageUrl", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-direct-download-boot-image-url",
                                       "set-direct-download-boot-image-url",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/KernelFilename", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-kernel-filename", "set-kernel-filename",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/TftpServer", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-tftp-server", "set-tftp-server",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/TftpBlockSize", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-tftp-block-size", "set-tftp-block-size",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiAuthentication", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-authentication", "set-wifi-authentication",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiBSSID", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-bss-id", "set-wifi-bss-id",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiEncryption", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-encryption", "set-wifi-encryption",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiKey", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-key", "set-wifi-key",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiRegulatoryDomain", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-regulatory-domain", "set-wifi-regulatory-domain",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiSSID", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-ssid", "set-wifi-ssid",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));

    m_manager->insert(new BoxinfoEntry("/WifiWizardDisabled", S_IFREG | 0666, 1, 256, 0, 0,
                                       "get-wifi-wizard-disabled", "set-wifi-wizard-disabled",
                                       new BoxinfoArrisReadStrategy(), new BoxinfoArrisWriteStrategy()));
}
