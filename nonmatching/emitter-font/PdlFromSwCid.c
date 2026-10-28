#include "m2c_macros.h"

s32 PdlFromSwCid(s32 arg0, s32 arg1) {
    return arg0 + ((arg1 * 0xC) + 0x3038);
}
