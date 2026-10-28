#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 ClsgClipEdgeToObjectPruned(void *, s32, s128, s128); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 FIsDlEmpty__FP2DL(void **);                     /* extern */
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(s32, M2C_UNK, s128, s32 *, f32); /* extern */
s32 PvAllocStackImpl__Fi(s32 *, s32, s32);          /* extern */
extern s32 *g_2dd2fc;
extern f32 g_2dded0;

void BounceRipgRips__FP4RIPG(void *arg0) {
    char sp[0x400];
    void **sp4;
    s32 sp8;
    s32 *spC;
    M2C_UNK sp10;
    s32 sp20;                                       /* compiler-managed */
    void **sp24;
    s32 sp28;
    s32 *sp2C;
    M2C_UNK sp30;
    s32 sp1B0;
    s32 sp1B4;
    s32 sp1B8;
    void **sp1BC;
    M2C_UNK *var_s1;
    s32 *temp_a0_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v1_2;
    s32 var_s2;
    s32 var_v1;
    void **temp_v0;
    void *temp_a0;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1;
    void *temp_v1_3;
    void *var_s4;
    void *var_s6;
    void *var_v0;

    if (M2C_FIELD(arg0, s32 *, 0x150) == 1) {
        sp1BC = arg0 + 0x15C;
        var_s6 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x64);
        if (var_s6 != NULL) {
            do {
                temp_v1 = M2C_FIELD(M2C_FIELD(var_s6, void **, 0xC), void **, 0xEC);
                if (!(M2C_FIELD(temp_v1, s64 *, 0x70) & 4)) {
                    sp1B8 = FIsBasicDerivedFrom(M2C_FIELD(temp_v1, s32 *, 0x60), 0x59);
                    temp_a0 = M2C_FIELD(M2C_FIELD(var_s6, void **, 0xC), void **, 0xEC);
                    temp_v0 = temp_a0 + 0x34;
                    sp4 = temp_v0;
                    temp_v1_2 = M2C_FIELD(temp_v0, s32 *, 8);
                    spC = g_2dd2fc;
                    sp8 = temp_v1_2;
                    g_2dd2fc = sp;
                    temp_v0_2 = M2C_FIELD(temp_a0, void **, 0x34);
                    var_s4 = temp_v0_2;
                    sp4 = temp_v0_2 + temp_v1_2;
                    if (var_s4 != NULL) {
                        do {
                            if (!(M2C_FIELD(var_s4, s64 *, 0x10) & (0x8000 << 0x21)) || (sp1B8 != 0)) {
                                CStackFrame_Construct(&sp10);
                                sp1B4 = 0;
                                if (!(M2C_FIELD(var_s4, s64 *, 0x10) & (0x8000 << 0x22))) {
                                    temp_a2 = M2C_FIELD(var_s4, s32 *, 0x6C);
                                    temp_v0_3 = (temp_a2 <= 0x1554) ? temp_a2 : 0x1555;
                                    sp1B0 = temp_v0_3;
                                    temp_a1 = temp_v0_3 * 0xC;
                                    sp20 = temp_a1;
                                    M2C_FIELD(&sp20, s32 *, 4) = 0x10;
                                    sp1B4 = PvAllocStackImpl__Fi(&sp20, temp_a1, temp_a2);
                                    temp_v0_4 = M2C_FIELD(arg0, void **, 0xEC);
                                    if (PruneBsp__FP3BSPP6VECTORfPP3BSP(M2C_FIELD(var_s4, s32 *, 0x74), 0x7FFFFFFF, M2C_FIELD(temp_v0_4, s128 *, 0x20), &sp1B0, M2C_FIELD(temp_v0_4, f32 *, 0x30)) != 2) {
                                        CStackFrame_Destructor(&sp10, 2);
                                    } else {
                                        sp1B4 -= 0xC;
                                        goto block_11;
                                    }
                                } else {
block_11:
                                    sp24 = sp1BC;
                                    sp20 = sp1BC;
                                    temp_a0_2 = g_2dd2fc;
                                    var_v1 = M2C_FIELD(sp1BC, s32 *, 8);
                                    g_2dd2fc = &sp20;
                                    sp2C = temp_a0_2;
                                    var_v0 = M2C_FIELD(arg0, void **, 0x15C);
                                    sp28 = var_v1;
loop_20:
                                    sp24 = var_v0 + var_v1;
                                    if (var_v0 != NULL) {
                                        if (!(g_2dded0 <= M2C_FIELD(var_v0, f32 *, 0x14))) {
                                            var_s2 = 0;
                                            temp_v0_5 = ClsgClipEdgeToObjectPruned(var_s4, sp1B4, M2C_FIELD(var_v0, s128 *, 0x80), M2C_FIELD(var_v0, s128 *, 0x70));
                                            if (temp_v0_5 > 0) {
                                                var_s1 = &sp30;
loop_15:
                                                if ((M2C_FIELD(var_s1, f32 *, 0x40) == 0.0f) || (temp_v1_3 = M2C_FIELD(var_v0, void **, 0xEC), (M2C_FIELD(temp_v1_3, s32 (**)(void *, void *, s128, s128), 0x44)(var_v0 + M2C_FIELD(temp_v1_3, s16 *, 0x40), var_s4, M2C_FIELD(var_s1, s128 *, 0), M2C_FIELD(var_s1, s128 *, 0x20)) == 0))) {
                                                    var_s2 += 1;
                                                    var_s1 += 0x60;
                                                    if (var_s2 < temp_v0_5) {
                                                        goto loop_15;
                                                    }
                                                }
                                            }
                                        }
                                        var_v1 = sp28;
                                        var_v0 = *sp24;
                                        goto loop_20;
                                    }
                                    g_2dd2fc = sp2C;
                                    CStackFrame_Destructor(&sp10, 2);
                                }
                            }
                            temp_v0_6 = *sp4;
                            var_s4 = temp_v0_6;
                            sp4 = temp_v0_6 + sp8;
                        } while (var_s4 != NULL);
                    }
                    g_2dd2fc = spC;
                }
                var_s6 = M2C_FIELD(var_s6, void **, 4);
            } while (var_s6 != NULL);
        }
        if (FIsDlEmpty__FP2DL(sp1BC) != 0) {
            temp_v0_7 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *), 0x4C)(arg0 + M2C_FIELD(temp_v0_7, s16 *, 0x48));
        }
    }
}
