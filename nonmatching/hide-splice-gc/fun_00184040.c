#include "m2c_macros.h"

void func_00184040(void *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 0x37:
        M2C_FIELD(arg0, s32 *, 0xFC) = (s32) (M2C_FIELD(arg0, s32 *, 0xFC) | 2);
        return;
    case 0x34:
        M2C_FIELD(arg0, s32 *, 0xFC) = 7;
        return;
    case 0x35:
        M2C_FIELD(arg0, s32 *, 0xFC) = (s32) (M2C_FIELD(arg0, s32 *, 0xFC) | 1);
        return;
    case 0x36:
        M2C_FIELD(arg0, s32 *, 0xFC) = (s32) (M2C_FIELD(arg0, s32 *, 0xFC) | 4);
        return;
    }
}
