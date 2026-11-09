#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CBinaryInputStream_ReadMatrix4 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

M2C_UNK CBinaryInputStream_ReadMatrix();            /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, s32); /* extern */

void CBinaryInputStream_ReadMatrix4(s32 arg0, s8 *arg1) {
    CBinaryInputStream_ReadMatrix();
    ReadVector__18CBinaryInputStreamP6VECTOR(arg0, (int)(arg1 + 0x30));
    M2C_FIELD(arg1, s32 *, 0xC) = 0;
    M2C_FIELD(arg1, s32 *, 0x1C) = 0;
    M2C_FIELD(arg1, s32 *, 0x2C) = 0;
    M2C_FIELD(arg1, f32 *, 0x3C) = 1.0f;
}

}
