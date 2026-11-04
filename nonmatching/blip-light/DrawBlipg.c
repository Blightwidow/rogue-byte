#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddVifFlush__4VIFS(M2C_UNK *);              /* extern */
M2C_UNK AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK AddVifStcycl__4VIFSii(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifUnpackRefs__4VIFS3UPKiPviPPPv(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(M2C_UNK *, M2C_UNK, M2C_UNK, u16 *); /* extern */
s32 CPvDl__FP2DL(s32);                              /* extern */
M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
s32 FInsideCmFrustrum(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
s32 FInsideCmMrd(M2C_UNK *, M2C_UNK, M2C_UNK *, f32); /* extern */
s32 FIsDlEmpty__FP2DL(s32);                         /* extern */
s32 FIsLoInWorld(void *);                           /* extern */
void *OnGameLoad__FP4GAME(s32);                     /* extern */
void *PmatLoWorld(void *);                          /* extern */
s128 PosLoWorld(void *);                            /* extern */
u16 *PvAllocStackImpl__Fi(s32 *);                   /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(u16 *, s128);      /* extern */
M2C_UNK func_0013A688(void *);                      /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK RO_002A2D00;
extern u16 RO_002A2D30;
extern M2C_UNK g_2dea28;

void DrawBlipg(void *arg0) {
    char sp[0x400];
    M2C_UNK unksp12;
    s32 sp10;                                       /* compiler-managed */
    u16 sp14;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    M2C_UNK sp50;
    s32 sp54;
    u16 *sp58;
    s128 sp60;
    void *sp70;
    s32 sp74;
    s32 temp_v1;
    s32 var_s2_2;
    s32 var_s7;
    s32 var_v0;
    s32 var_v1;
    u16 *temp_v0;
    u16 *var_s1;
    u16 *var_s3;
    void **temp_s0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s4;
    void *temp_v0_2;
    void *var_a0;
    void *var_s1_2;
    void *var_s2;

    CStackFrame_Construct(sp);
    temp_a0 = M2C_FIELD(arg0, void **, 0xE0);
    if (temp_a0 == NULL) {
        goto block_19;
    }
    if (FIsDlEmpty__FP2DL(temp_a0 + 0x11C) != 0) {
block_19:
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xf0($s5) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($a0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
        sp10 = (s128) M2C_FIELD(arg0, s32 *, 0x100);
        if (FInsideCmFrustrum(&B_002DDF40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */)) != 0) {
            sp54 = 1;
            sp58 = &RO_002A2D30;
            goto block_21;
        }
        goto block_23;
    }
    sp54 = 0;
    sp10 = CPvDl__FP2DL(M2C_FIELD(arg0, void **, 0xE0) + 0x11C) << 6;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackImpl__Fi(&sp10);
    sp58 = temp_v0;
    var_s2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xE0), void **, 0x11C);
    var_s1 = temp_v0;
    if (var_s2 != NULL) {
        do {
            if (FIsLoInWorld(var_s2) != 0) {
                temp_s0 = M2C_FIELD(M2C_FIELD(var_s2, void **, 0xE4), void ***, 8);
                temp_a0_2 = *temp_s0;
                if (temp_a0_2 != NULL) {
                    var_a0 = *temp_s0;
                    sp60 = PosLoWorld(temp_a0_2);
                    goto block_12;
                }
                var_a0 = M2C_FIELD(var_s2, void **, 0x10);
                sp60 = PosLoWorld(var_s2);
                if (var_a0 != NULL) {
block_12:
                    temp_v0_2 = PmatLoWorld(var_a0);
                    sp20 = M2C_FIELD(temp_v0_2, s128 *, 0);
                    sp30 = M2C_FIELD(temp_v0_2, s128 *, 0x10);
                    sp40 = M2C_FIELD(temp_v0_2, s128 *, 0x20);
                } else {
                    sp20 = M2C_FIELD(&RO_002A2D00, s128 *, 0);
                    sp30 = M2C_FIELD(&RO_002A2D00, s128 *, 0x10);
                    sp40 = M2C_FIELD(&RO_002A2D00, s128 *, 0x20);
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xf0($s5) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf2z */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($s0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf1 */);
                sp10 = (s128) M2C_FIELD(arg0, s32 *, 0x100);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x80($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
                if ((FInsideCmFrustrum(&B_002DDF40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */)) != 0) && (FInsideCmMrd(&B_002DDF40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), &sp50, M2C_FIELD(var_s2, f32 *, 0x38)) != 0)) {
                    __as__6VECTORG9VU_VECTOR(var_s1 + 0x30, sp60);
                    sp54 += 1;
                    M2C_FIELD(var_s1, s128 *, 0) = sp20;
                    M2C_FIELD(var_s1, s128 *, 0x10) = sp30;
                    M2C_FIELD(var_s1, f32 *, 0x3C) = 1.0f;
                    M2C_FIELD(var_s1, s128 *, 0x20) = sp40;
                    M2C_FIELD(var_s1, s32 *, 0x2C) = 0;
                    M2C_FIELD(var_s1, s32 *, 0x1C) = 0;
                    M2C_FIELD(var_s1, s32 *, 0xC) = 0;
                    var_s1 += 0x40;
                }
            }
            var_s2 = M2C_FIELD(var_s2, void **, 0x128);
        } while (var_s2 != NULL);
    } else {
block_21:
    }
    if (sp54 == 0) {
block_23:
        CStackFrame_Destructor(sp, 2);
        return;
    }
    var_s7 = 0;
    sp70 = OnGameLoad__FP4GAME(sp54);
    M2C_FIELD(sp70, s32 *, 0) = 0xC;
    M2C_FIELD(sp70, s32 *, 4) = 0;
    sp74 = M2C_FIELD(&g_2dea28, s32 *, 0xC);
    AddDmaCnt__4DMAS(&g_2dea28);
    var_s1_2 = M2C_FIELD(arg0, void **, 0x448);
    if (var_s1_2 != NULL) {
        var_v1 = M2C_FIELD(var_s1_2, s32 *, 0x1080);
loop_26:
        temp_s4 = (var_v1 * 0x840) + var_s1_2;
        if (sp54 > 0) {
            var_s3 = sp58;
            var_s2_2 = sp54;
            var_v0 = var_s7 < 2;
            do {
                if (var_v0 != 0) {
                    var_s7 += 1;
                    func_0013A688(arg0);
                }
                sp10 = 0x34;
                unksp12 = (M2C_FIELD(var_s1_2, s32 *, 0x1084) * 0xA) + 0x34;
                sp14 = (u16) M2C_FIELD(var_s1_2, s32 *, 0x1084);
                AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 9, 1, &sp10);
                AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xC, 4, var_s3);
                AddVifStcycl__4VIFSii(&g_2dea28, 1, 0xA);
                if (M2C_FIELD(arg0, s32 *, 0x43C) == 1) {
                    AddVifUnpackRefs__4VIFS3UPKiPviPPPv(&g_2dea28, 0xC, M2C_FIELD(var_s1_2, s32 *, 0x1084), temp_s4 + 0x2B0);
                }
                AddVifUnpackRefs__4VIFS3UPKiPviPPPv(&g_2dea28, 0xC, M2C_FIELD(var_s1_2, s32 *, 0x1084), temp_s4 + 0x560);
                AddVifUnpackRefs__4VIFS3UPKiPviPPPv(&g_2dea28, 0xC, M2C_FIELD(var_s1_2, s32 *, 0x1084), temp_s4);
                AddVifStcycl__4VIFSii(&g_2dea28, 1, 1);
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x43C);
                switch (temp_v1) {                  /* irregular */
                case 0:
                    AddVifMscal__4VIFSPv(&g_2dea28, 0);
                    break;
                case 1:
                    AddVifMscal__4VIFSPv(&g_2dea28, 0x390);
                    break;
                case 2:
                    AddVifMscal__4VIFSPv(&g_2dea28, 0x870);
                    break;
                }
                var_s3 += 0x40;
                AddVifFlush__4VIFS(&g_2dea28);
                var_s2_2 -= 1;
                var_v0 = var_s7 < 2;
            } while (var_s2_2 != 0);
        }
        var_s1_2 = M2C_FIELD(var_s1_2, void **, 0x1090);
        if (var_s1_2 != NULL) {
            var_v1 = M2C_FIELD(var_s1_2, s32 *, 0x1080);
            goto loop_26;
        }
    }
    EndDmaCnt__4DMAS(&g_2dea28);
    AddDmaRet__4DMAS(&g_2dea28);
    M2C_FIELD(sp70, s32 *, 8) = sp74;
    CStackFrame_Destructor(sp, 2);
}
