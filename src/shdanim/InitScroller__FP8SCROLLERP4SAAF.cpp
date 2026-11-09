#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void InitSaa(s8 *, s8 *);

void InitScroller__FP8SCROLLERP4SAAF(s8 *arg0, s8 *arg1) {
    InitSaa(arg0, arg1);
    M2C_FIELD(arg0, f32 *, 0x50) = M2C_FIELD(arg1, f32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 0x54) = M2C_FIELD(arg1, f32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 0x58) = M2C_FIELD(arg1, f32 *, 0x14);
    M2C_FIELD(arg0, f32 *, 0x5C) = M2C_FIELD(arg1, f32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x64) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x60) = 1.0f;
}

}
