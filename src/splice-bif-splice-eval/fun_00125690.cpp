#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK CRef_CopyConstruct(s32, s8 *);            /* extern */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK CRef_SetBasic(s8 *, M2C_UNK *);      /* extern */
extern M2C_UNK B_003DA0C0;

s32 func_00125690(s32 arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));

    *(s32 *)sp = -1;
    CRef_SetBasic(sp, &B_003DA0C0);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}

}
