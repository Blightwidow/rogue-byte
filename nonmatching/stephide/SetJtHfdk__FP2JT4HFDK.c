#include "m2c_macros.h"

extern f32 g_2dded0;

void SetJtHfdk__FP2JT4HFDK(void *arg0, s32 arg1) {
    if ((arg1 != M2C_FIELD(arg0, s32 *, 0x2C)) && (M2C_FIELD(arg0, s32 *, 0x2C) = arg1, M2C_FIELD(arg0, s32 *, 0x50) = 0, M2C_FIELD(arg0, f32 *, 0x30) = (f32) g_2dded0, (arg1 > 0))) {
        if (arg1 < 3) {
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1024) != M2C_FIELD(arg0, s32 *, 0x68)) {
                M2C_FIELD(arg0, s32 *, 0x34) = 0;
                return;
            }
            M2C_FIELD(arg0, s32 *, 0x34) = 2;
            return;
        }
        if (arg1 == 3) {
            M2C_FIELD(arg0, s32 *, 0x34) = 1;
        }
    }
}
