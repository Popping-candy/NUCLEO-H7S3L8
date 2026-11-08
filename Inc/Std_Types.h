#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

#define STD_LOW  0x00U
#define STD_HIGH 0x01U
#define STD_OFF  0x00U
#define STD_ON   0x01U

typedef struct {
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;

#endif
