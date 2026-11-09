#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
extern s8 B_003DD490;
extern s32 B_003E19E4;

void func_001A3B38(s8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x160) == 0) {
        s8 *block = &B_003DD490;
        M2C_FIELD(block, s32 *, 0x3D5C) = (s32) (M2C_FIELD(block, s32 *, 0x3D5C) + 1);
    }
    if ((M2C_FIELD(arg0, s32 *, 0x15C) == 0) && (M2C_FIELD(arg0, s32 *, 0xE0) != 0)) {
        B_003E19E4 = 1;
    }
}

}
