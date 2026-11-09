#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s8 *PjsgeAllocJsg(s32, s32, s32);

void func_001E1B10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 0x5A, arg3);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x18) = 0;
}

}
