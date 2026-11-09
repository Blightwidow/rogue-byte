#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_StopSound__FP3AMBi {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK snd_AutoVol(s32, M2C_UNK, s32, M2C_UNK);    /* extern */
M2C_UNK snd_StopSound(s32);                /* extern */
void StopSound__FP3AMBi(s8 *arg0) {
    f32 temp_f1;
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x48);
    if (temp_f1 > 0.0f) {
        snd_AutoVol(M2C_FIELD(arg0, s32 *, 0x40), -4, (s32) (temp_f1 * 240.0f), 2);
        return;
    }
    snd_StopSound(M2C_FIELD(arg0, s32 *, 0x40));
}
}
