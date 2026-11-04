#include "m2c_macros.h"

M2C_UNK BlendPrevFrame__Fv();                       /* extern */
M2C_UNK ClearPendingFrame__FP3FRM(u32);             /* extern */
M2C_UNK RenderFrame__FP3FRMi(void *, M2C_UNK);      /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK SwapGsBuffers__Fv();                        /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK func_001C2BA8(M2C_UNK);                     /* extern */
extern M2C_UNK B_002DEA50;
extern void *g_2deb14;
extern s32 g_2deb1c;
extern s32 g_2deb20;
extern s32 g_2dedbc;

void FlushFrames__Fi(s32 arg0) {
    M2C_UNK *var_s0_4;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_s0_3;
    u32 var_s0;
    u32 var_s0_2;
    void *temp_a0_3;

    var_s0 = 0;
    temp_a0 = g_2deb1c;
    do {
        var_s0 += 1;
        WaitSema(temp_a0);
        temp_a0_2 = g_2deb1c;
    } while (var_s0 < 2U);
    var_s0_2 = 0;
    do {
        var_s0_2 += 1;
        SignalSema(temp_a0_2);
    } while (var_s0_2 < 2U);
    do {

    } while (g_2deb20 == 0);
    if (arg0 != 0) {
        if (g_2deb14 != NULL) {
            var_s0_3 = 2;
            temp_a0_3 = g_2deb14;
            do {
                RenderFrame__FP3FRMi(temp_a0_3, 1);
                if (M2C_FIELD(g_2deb14, s32 *, 0x30) & 1) {
                    BlendPrevFrame__Fv();
                }
                var_s0_3 -= 1;
                SwapGsBuffers__Fv();
            } while (var_s0_3 >= 0);
            g_2dedbc = 3;
        }
        if (arg0 != 0) {
            var_s0_4 = &B_002DEA50;
            do {
                ClearPendingFrame__FP3FRM((u32) var_s0_4);
                var_s0_4 += 0x50;
            } while ((u32) var_s0_4 < (u32) (&B_002DEA50 + 0xA0));
        }
    }
    func_001C2BA8(3);
    g_2deb14 = NULL;
}
