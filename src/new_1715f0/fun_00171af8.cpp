#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void GetScriptPose(s32, s128, s32, s32, s32);
s128 PosLoWorld(s32);
void func_00171AF8(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    GetScriptPose(M2C_FIELD(arg0, s32 *, 0x30), PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10)), arg1, arg2, arg3);
}
}
