#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void SetMurrayState(void *, M2C_UNK);
void func_00131B60(s32, void *, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_002C09F8;

void EndMurrayAttack(void *arg0) {
    s32 temp_v0;

    func_00131B60(M2C_FIELD(arg0, s32 *, 0x1030), arg0, 5, &D_002C09F8);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1030);
    M2C_FIELD(arg0, s32 *, 0x1030) = 0;
    M2C_FIELD(arg0, s32 *, 0x190C) = temp_v0;
    SetMurrayState(arg0, 0);
}

}
