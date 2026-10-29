// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s8 *PjsgeAllocJsg(void *arg0, s32 arg1, s32 arg2);

void func_001E1A90(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 0x58, arg3);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg2;
}

}
