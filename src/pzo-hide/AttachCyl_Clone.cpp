#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AttachCyl_Clone {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
struct Bytes8 { u8 bytes[8]; };
void CloneXfm(s8 *);
void AttachCyl_Clone(s8 *arg0) {
    Bytes8 saved;
    saved = M2C_FIELD(arg0, Bytes8 *, 0x104);
    CloneXfm(arg0);
    M2C_FIELD(arg0, Bytes8 *, 0x104) = saved;
}
}
