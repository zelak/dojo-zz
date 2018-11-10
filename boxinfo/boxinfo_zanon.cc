#include <sys/stat.h>

#include "boxinfo_zanon.h"
#include "boxinfo_manager.h"
#include "boxinfo_entry.h"

#include "boxinfo_zanon_read_strategy.h"
#include "boxinfo_zanon_write_strategy.h"

const int ZANON_MANUFACTURER_NAME = 1;
const int ZANON_MODEL_NAME = 2;

BoxinfoZanon::BoxinfoZanon(BoxinfoManager *manager)
    : BoxinfoVendor(manager)
{
}

BoxinfoZanon::~BoxinfoZanon()
{
}

void BoxinfoZanon::init()
{
    manager()->insert(new BoxinfoEntry("/", S_IFDIR | 0755, 2, 0, 0, 0, "", "",
                                       new BoxinfoZanonReadStrategy(), new BoxinfoZanonWriteStrategy()));
    manager()->insert(new BoxinfoEntry("/ManufacturerName", S_IFREG | 0444, 1, 255, 0,
                                       ZANON_MANUFACTURER_NAME, "", "",
                                       new BoxinfoZanonReadStrategy(), new BoxinfoZanonWriteStrategy()));
    manager()->insert(new BoxinfoEntry("/ModelName", S_IFREG | 0444, 1, 255, 0,
                                       ZANON_MODEL_NAME, "", "",
                                       new BoxinfoZanonReadStrategy(), new BoxinfoZanonWriteStrategy()));
}