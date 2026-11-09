#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void SetXfKind(void *, s32, M2C_UNK);
void func_00174B28();

void func_00175090(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;

    func_00174B28();
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    SetXfKind(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x58), 2);
    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
        SetXfKind(temp_a0_2, M2C_FIELD(temp_a0_2, s32 *, 0x5C), 2);
    }
}

}
