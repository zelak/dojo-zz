#include <cassert>
#include <sys/stat.h>

#include "boxinfo.h"
#include "boxinfo_manager.h"
#include "boxinfo_arris_entry.h"
#include "boxinfo_tlf_entry.h"
#include "boxinfo_casn_entry.h"
#include "boxinfo_csc_entry.h"

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

    initTlfLib();
    initTlfEntries();
    // initArrisEntries();
}

void Boxinfo::initTlfLib()
{
    tlf_result_t res = tlf_init();
    assert(res == TLF_OK);
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
    m_manager->insert(new BoxinfoTlfEntry("/Hdcp14Key", S_IFREG | 0444, 1, 1128, 0,
                                          TLV_VARIABLE_HDCP14, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/Hdcp22Key", S_IFREG | 0444,1, 1088, 20,
                                          TLV_VARIABLE_HDCP22, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/NetflixESN", S_IFREG | 0444, 1, 256, 0,
                                          TLV_VARIABLE_NETFLIX_ESN, "", ""));
    m_manager->insert(new BoxinfoTlfEntry("/NetflixDRM", S_IFREG | 0444, 1, 608, 0,
                                          TLV_VARIABLE_NETFLIX_DRM_BIN, "", ""));

    m_manager->insert(new BoxinfoCASNEntry("/CASN", S_IFREG | 0444, 1, 10, 0,
                                           TLV_STBINFO_NAGRA_SERIAL_NUMBER, "", ""));

    m_manager->insert(new BoxinfoCSCEntry("/CSC", S_IFREG | 0444, 1, 10, 0,
                                          TLV_STBINFO_NAGRA_CSC_DATA, "", ""));
}

void Boxinfo::initArrisEntries()
{
    m_manager->insert(new BoxinfoArrisEntry("/HttpServer"  , S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-http-server", "set-http-server"));

    m_manager->insert(new BoxinfoArrisEntry("/HttpPort"    , S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-http-port", "set-http-port"));

    m_manager->insert(new BoxinfoArrisEntry("/Bootcast", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-bootcast", "set-bootcast"));

    m_manager->insert(new BoxinfoArrisEntry("/BootcastID", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-bootcast-id", "set-bootcast-id"));

    m_manager->insert(new BoxinfoArrisEntry("/BootOrder", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-boot-order", "set-boot-order"));

    m_manager->insert(new BoxinfoArrisEntry("/SplashOrder", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-splash-order", "set-splash-order"));

    m_manager->insert(new BoxinfoArrisEntry("/DirectDownloadBootImageUrl", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-direct-download-boot-image-url", "set-direct-download-boot-image-url"));

    m_manager->insert(new BoxinfoArrisEntry("/KernelFilename", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-kernel-filename", "set-kernel-filename"));

    m_manager->insert(new BoxinfoArrisEntry("/TftpServer", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-tftp-server", "set-tftp-server"));

    m_manager->insert(new BoxinfoArrisEntry("/TftpBlockSize", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-tftp-block-size", "set-tftp-block-size"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiAuthentication", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-authentication", "set-wifi-authentication"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiBSSID", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-bss-id", "set-wifi-bss-id"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiEncryption", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-encryption", "set-wifi-encryption"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiKey", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-key", "set-wifi-key"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiRegulatoryDomain", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-regulatory-domain", "set-wifi-regulatory-domain"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiSSID", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-ssid", "set-wifi-ssid"));

    m_manager->insert(new BoxinfoArrisEntry("/WifiWizardDisabled", S_IFREG | 0666, 1, 256, 0, 0,
                                            "get-wifi-wizard-disabled", "set-wifi-wizard-disabled"));
}
