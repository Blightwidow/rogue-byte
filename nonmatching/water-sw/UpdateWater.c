#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
s32 ClsgClipEdgeToObjects(s128, s128, s32, s32);    /* extern */
s32 CpartCollectAlo(void *, M2C_UNK *, M2C_UNK, s32); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FXfKindDynamic(s16);                            /* extern */
s32 GetSoNoXpsAll(void *);                          /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */
void *PxaAllocSw(M2C_UNK *);                        /* extern */
M2C_UNK SetAmbRange(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK SetAmbVolume(s32, f32);                     /* extern */
M2C_UNK SetEmitterUnpositioned(s32, void *);        /* extern */
f32 UGetWaterSubmerged(void *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK UpdateSwXaList__FP2SWPP2XA(void *, void *); /* extern */
M2C_UNK memset(s32 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK func_00229D60;
extern s128 g_2a2dc0;

void UpdateWater(void *arg0) {
    char sp[0x400];
    M2C_UNK sp18;
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 sp10;                                       /* compiler-managed */
    void *sp14;
    f32 sp28;
    f32 sp38;
    M2C_UNK sp40;
    s32 sp650;
    f32 sp658;
    s128 sp660;
    s32 sp690;
    void *sp694;
    s32 *sp698;
    M2C_UNK (*temp_a2)(void *, s32 *, M2C_UNK);
    M2C_UNK (*temp_a3)(void *, M2C_UNK, s32 *, M2C_UNK);
    f32 temp_f20;
    f32 temp_f21;
    f32 var_f2;
    s32 temp_v0;
    s32 temp_v0_6;
    s32 var_s3;
    s64 temp_v0_3;
    s64 temp_v0_8;
    void *temp_a0;
    void *temp_s0;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_7;
    void *temp_v1;
    void *temp_v1_2;
    void *var_s0;
    void *var_s0_2;
    void *var_s1;
    void *var_s5;
    void *var_t0;
    void *var_v1;

    UpdateSo();
    if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
        var_s0 = M2C_FIELD(arg0, void **, 0x150);
        sp698 = &sp10;
        sp694 = arg0 + 0x150;
        if (var_s0 != NULL) {
            var_v1 = M2C_FIELD(var_s0, void **, 4);
loop_3:
            M2C_FIELD(var_v1, s64 *, 0x148) = (s64) (M2C_FIELD(var_v1, s64 *, 0x148) | (0x8000 << 0x10));
            var_s0 = M2C_FIELD(var_s0, void **, 0xC);
            if (var_s0 != NULL) {
                var_v1 = M2C_FIELD(var_s0, void **, 4);
                goto loop_3;
            }
        }
        CStackFrame_Construct(sp);
        sp10 = M2C_FIELD(arg0, s32 *, 0xE0) * 4;
        M2C_FIELD(sp698, s32 *, 4) = 0x10;
        temp_v0 = PvAllocStackImpl__Fi(sp698);
        sp690 = CpartCollectAlo(arg0, &func_00229D60, 0, temp_v0);
        var_s5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x64);
        if (var_s5 != NULL) {
            var_s1 = M2C_FIELD(var_s5, void **, 0xC);
loop_8:
            temp_v0_2 = M2C_FIELD(var_s1, void **, 0xE8);
            if ((temp_v0_2 != NULL) && !(M2C_FIELD(temp_v0_2, f32 *, 0xD4) < 0.0001f) && (GetSoNoXpsAll(var_s1) == 0) && (FXfKindDynamic(M2C_FIELD(M2C_FIELD(var_s1, void **, 0x58), s16 *, 0x98)) != 0) && (UGetWaterSubmerged(arg0, var_s1, 0, 0) != 0.0f)) {
                temp_v0_3 = M2C_FIELD(var_s1, s64 *, 0x148) | (0x8000 << 0x11);
                M2C_FIELD(var_s1, s64 *, 0x148) = temp_v0_3;
                if (!(temp_v0_3 & (0x8000 << 0x10))) {
                    temp_v0_4 = PxaAllocSw(&B_003DD490);
                    M2C_FIELD(temp_v0_4, void **, 0) = arg0;
                    M2C_FIELD(temp_v0_4, void **, 4) = var_s1;
                    M2C_FIELD(temp_v0_4, void **, 0xC) = (void *) M2C_FIELD(arg0, void **, 0x150);
                    M2C_FIELD(arg0, void **, 0x150) = temp_v0_4;
                    if (M2C_FIELD(arg0, void **, 0x170) != NULL) {
                        temp_v1 = M2C_FIELD(var_s1, void **, 0xC);
                        sp10 = M2C_FIELD(temp_v1, s128 (**)(void *), 0x10C)(var_s1 + M2C_FIELD(temp_v1, s16 *, 0x108));
                        if (sp18 < -100.0f) {
                            var_s3 = 0;
                            if (M2C_FIELD(var_s1, s32 *, 0xE0) > 0) {
                                do {
                                    temp_s0 = M2C_FIELD(var_s1, s32 *, 0xE4) + (var_s3 * 0xB0);
                                    if (!(M2C_FIELD(temp_s0, s64 *, 0x10) & (0xA000 << 0x23))) {
                                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($fp) */);
                                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x640($sp) */);
                                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($s0) */);
                                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
                                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
                                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
                                        if (FIsBasicDerivedFrom(var_s1, 0x33) == 0) {
                                            var_f2 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0xEC), f32 *, 8) - M2C_FIELD(M2C_FIELD(temp_s0, void **, 0), f32 *, 0x78);
                                        } else {
                                            var_f2 = M2C_FIELD(var_s1, f32 *, 0x248);
                                        }
                                        sp28 += var_f2;
                                        sp38 += var_f2;
                                        if (ClsgClipEdgeToObjects(sp20, sp30, sp690, temp_v0) > 0) {
                                            temp_v0_5 = M2C_FIELD(var_s1, void **, 0xEC);
                                            temp_f20 = M2C_ERROR(/* unknown instruction: min.s $f20, $f20, $f22 */) * 0.0016666667f;
                                            temp_f21 = ((M2C_FIELD(temp_v0_5, f32 *, 0x10) - M2C_FIELD(temp_v0_5, f32 *, 0)) + (M2C_FIELD(temp_v0_5, f32 *, 0x14) - M2C_FIELD(temp_v0_5, f32 *, 4))) * 0.5f;
                                            temp_v0_6 = NewEmitter(0x13);
                                            SetEmitterUnpositioned(temp_v0_6, var_s1);
                                            SetAmbRange(temp_v0_6, 0x42C80000, 0x447A0000);
                                            SetAmbVolume(temp_v0_6, temp_f20);
                                            memset(&sp650, 0, 0x40);
                                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
                                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x640($sp) */);
                                            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                                            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x670($sp) */);
                                            sp650 = 0xE;
                                            sp658 = temp_f21 * temp_f20;
                                            sp660 = g_2a2dc0;
                                            temp_a0 = M2C_FIELD(arg0, void **, 0x170);
                                            temp_v0_7 = M2C_FIELD(temp_a0, void **, 0xC);
                                            temp_a2 = M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x19C);
                                            temp_a2(temp_a0 + M2C_FIELD(temp_v0_7, s16 *, 0x198), &sp650, temp_a2);
                                        }
                                    }
                                    var_s3 += 1;
                                } while (var_s3 < M2C_FIELD(var_s1, s32 *, 0xE0));
                            }
                        }
                    }
                }
            }
            var_s5 = M2C_FIELD(var_s5, void **, 4);
            if (var_s5 != NULL) {
                var_s1 = M2C_FIELD(var_s5, void **, 0xC);
                goto loop_8;
            }
        }
        var_s0_2 = M2C_FIELD(arg0, void **, 0x150);
        if (var_s0_2 != NULL) {
            var_t0 = M2C_FIELD(var_s0_2, void **, 4);
loop_32:
            temp_v0_8 = M2C_FIELD(var_t0, s64 *, 0x148);
            if ((((s64) (temp_v0_8 * 2) >> 0x20) & 1) != ((temp_v0_8 >> 0x20) & 1)) {
                sp10 = arg0;
                sp14 = var_t0;
                temp_v1_2 = M2C_FIELD(var_t0, void **, 0xC);
                temp_a3 = M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, s32 *, M2C_UNK), 0x24);
                temp_a3(var_t0 + M2C_FIELD(temp_v1_2, s16 *, 0x20), (M2C_FIELD(var_t0, s64 *, 0x148) & (0x8000 << 0x10)) ? 5 : 4, sp698, temp_a3);
            }
            var_s0_2 = M2C_FIELD(var_s0_2, void **, 0xC);
            if (var_s0_2 != NULL) {
                var_t0 = M2C_FIELD(var_s0_2, void **, 4);
                goto loop_32;
            }
        }
        UpdateSwXaList__FP2SWPP2XA(arg0, sp694);
        CStackFrame_Destructor(sp, 2);
    }
}
