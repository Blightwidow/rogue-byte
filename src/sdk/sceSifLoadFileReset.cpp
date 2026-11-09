#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sceSifLoadFileReset {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK B_0044C268;
extern s32 D_002C4A98;
s32 sceSifLoadFileReset(void) {
    D_002C4A98 = -1;
    memset(&B_0044C268, 0, 4);
    return 0;
}
}
