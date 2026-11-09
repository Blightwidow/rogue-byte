#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_eh_context_static {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK B_00450258;
extern s32 B_00450268;
extern M2C_UNK B_00450270;
M2C_UNK *eh_context_static(void) {
    if (B_00450268 == 0) {
        B_00450268 = 1;
        memset(&B_00450258, 0, 0x10);
        M2C_FIELD(&B_00450258, M2C_UNK **, 4) = &B_00450270;
    }
    return &B_00450258;
}
}
