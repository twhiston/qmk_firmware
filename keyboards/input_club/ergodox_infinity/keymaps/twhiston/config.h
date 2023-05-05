#ifndef CONFIG_USER_H
#define CONFIG_USER_H



#include "../../config.h"

#define usb_lld_disconnect_bus(usbp) do {} while(0)
#define SPLIT_LAYER_STATE_ENABLE

#ifndef ST7565_ENABLE
#define ST7565_ENABLE
#endif



#endif
