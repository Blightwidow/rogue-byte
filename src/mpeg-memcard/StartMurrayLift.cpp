#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void SetMurrayState(s8 *, M2C_UNK);
void func_002046F0(s8 *, s32);

void StartMurrayLift(s8 *arg0, s8 *arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x13EC) != 0) {
        M2C_FIELD(arg0, s8 **, 0x13F0) = arg1;
        M2C_FIELD(arg0, s32 *, 0x144C) = 0;
        SetMurrayState(arg0, 4);
        func_002046F0(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x13F0), s32 *, 0x180));
    }
}

}
