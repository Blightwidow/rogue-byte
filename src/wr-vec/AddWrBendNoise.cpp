#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK AddOnzOnze__FP3ONZffff(s32, f32, f32, f32, f32); /* extern */
s32 PwreGetWrBend__FP2WR4ENSK(s32, M2C_UNK);             /* extern */

void AddWrBendNoise(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    AddOnzOnze__FP3ONZffff(PwreGetWrBend__FP2WR4ENSK(arg0, 1) + 0x30, fparg0, fparg1, fparg2, fparg3);
}

}
