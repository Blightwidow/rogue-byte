#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK InitAmbBase(s8 *);                              /* extern */
M2C_UNK SetAmbGrf(s8 *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK D_002D9C70;

s8 *InitAmb(s8 *arg0, s32 arg1) {
    InitAmbBase(arg0);
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D9C70;
    SetAmbGrf(arg0, 1, 1);
    return arg0;
}

}
