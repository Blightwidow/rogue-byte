typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_DrawBlipg {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s32 sp10;                           /* inferred */
    /* 0x014 */ u16 sp14;                           /* inferred */
    /* 0x016 */ char pad16[0xA];                    /* maybe part of sp14[6]? */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ M2C_UNK sp50;                       /* inferred */
    /* 0x050 */ char pad50[4];
    /* 0x054 */ s32 sp54;                           /* inferred */
    /* 0x058 */ u16 *sp58;                          /* inferred */
    /* 0x05C */ char pad5C[4];
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s8 *sp70;                         /* inferred */
    /* 0x074 */ s32 sp74;                           /* inferred */
    /* 0x078 */ char pad78[0xB8];
};                                                  /* size = 0x130 */
s32 AddDmaCnt__4DMAS(M2C_UNK *);
void AddDmaRet__4DMAS(M2C_UNK *);
s32 AddVifFlush__4VIFS(M2C_UNK *);
s32 AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);
s32 AddVifStcycl__4VIFSii(M2C_UNK *, M2C_UNK, M2C_UNK);
void AddVifUnpackRefs__4VIFS3UPKiPviPPPv(M2C_UNK *, M2C_UNK, s32, s8 *);
void AddVifUnpack__4VIFS3UPKiPvi(M2C_UNK *, M2C_UNK, M2C_UNK, u16 *);
s32 CPvDl__FP2DL(s32);
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
void EndDmaCnt__4DMAS(M2C_UNK *);
s32 FInsideCmFrustrum(M2C_UNK *, M2C_UNK, M2C_UNK);
s32 FInsideCmMrd(M2C_UNK *, M2C_UNK, M2C_UNK *, f32);
s32 FIsDlEmpty__FP2DL(s32);
s32 FIsLoInWorld(s8 *);
s32 *OnGameLoad__FP4GAME(s32);
s32 *PmatLoWorld(s8 *);
s32 PosLoWorld(s8 *);
s32 *PvAllocStackImpl__Fi(s32 *);
f32 __as__6VECTORG9VU_VECTOR(u16 *, s128);
void func_0013A688(s8 *);
extern M2C_UNK B_002DDF40;
extern M2C_UNK RO_002A2D00;
extern u16 RO_002A2D30;
extern M2C_UNK g_2dea28;
#define sp10 (*(s32 *)(sp + 0x10))
#define sp14 (*(u16 *)(sp + 0x14))
#define unksp12 (*(s16 *)(sp + 0x12))
#define sp20 (*(s128 *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(s128 *)(sp + 0x40))
#define sp50 (*(M2C_UNK *)(sp + 0x50))
#define sp54 (*(s32 *)(sp + 0x54))
#define sp58 (*(u16 **)(sp + 0x58))
#define sp60 (*(s128 *)(sp + 0x60))
#define sp70 (*(s8 **)(sp + 0x70))
#define sp74 (*(s32 *)(sp + 0x74))
void DrawBlipg(s8 *arg0) {
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK temp_a2;
    M2C_UNK temp_a2_2;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_s2_2;
    s32 var_s7;
    s32 var_v0;
    s32 var_v1;
    u16 *temp_v0_2;
    u16 *var_s1;
    u16 *var_s3;
    s8 **temp_s0;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_s4;
    s8 *temp_v0_3;
    s8 *var_a0;
    s8 *var_s1_2;
    s8 *var_s2;
    CStackFrame_Construct(sp);
    temp_a0 = M2C_FIELD(arg0, s8 **, 0xE0);
    if (temp_a0 == NULL || FIsDlEmpty__FP2DL((int)(temp_a0 + 0x11C)) != 0) {
        asm volatile("lqc2 vf2, 0xf0(%0)" : : "r"(arg0));
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x100);
        asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(&B_002DDF40));
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
        temp_a2 = vu_1;
        asm volatile("vsub.xyzw vf3, vf2, vf1");
        sp10 = (s128) temp_v0;
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
        if (FInsideCmFrustrum(&B_002DDF40, vu_2, temp_a2) != 0) {
            sp54 = 1;
            sp58 = &RO_002A2D30;
            goto block_21;
        }
        goto block_23;
    }
    sp54 = 0;
    sp10 = CPvDl__FP2DL((int)(M2C_FIELD(arg0, s8 **, 0xE0) + 0x11C)) << 6;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0_2 = (u16 *)(PvAllocStackImpl__Fi(&sp10));
    sp58 = temp_v0_2;
    var_s2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE0), s8 **, 0x11C);
    var_s1 = temp_v0_2;
    if (var_s2 != NULL) {
        do {
            if (FIsLoInWorld(var_s2) != 0) {
                temp_s0 = M2C_FIELD(M2C_FIELD(var_s2, s8 **, 0xE4), s8 ***, 8);
                temp_a0_2 = *temp_s0;
                if (temp_a0_2 != NULL) {
                    var_a0 = *temp_s0;
                    sp60 = PosLoWorld(temp_a0_2);
                    goto block_12;
                }
                var_a0 = M2C_FIELD(var_s2, s8 **, 0x10);
                sp60 = PosLoWorld(var_s2);
                if (var_a0 != NULL) {
block_12:
                    temp_v0_3 = (s8 *)(PmatLoWorld(var_a0));
                    sp20 = M2C_FIELD(temp_v0_3, s128 *, 0);
                    sp30 = M2C_FIELD(temp_v0_3, s128 *, 0x10);
                    sp40 = M2C_FIELD(temp_v0_3, s128 *, 0x20);
                } else {
                    sp20 = M2C_FIELD(&RO_002A2D00, s128 *, 0);
                    sp30 = M2C_FIELD(&RO_002A2D00, s128 *, 0x10);
                    sp40 = M2C_FIELD(&RO_002A2D00, s128 *, 0x20);
                }
                asm volatile("lqc2 vf2, 0xf0(%0)" : : "r"(arg0));
                asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(sp));
                temp_v0_4 = M2C_FIELD(arg0, s32 *, 0x100);
                asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
                s64 vu_3;
                asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_v0_4));
                temp_a2_2 = vu_3;
                asm volatile("vmulax.xyz ACC, vf5, vf2x");
                asm volatile("vmadday.xyz ACC, vf4, vf2y");
                asm volatile("vmaddz.xyz vf2, vf1, vf2z");
                asm volatile("lqc2 vf3, 0x90(%0)" : : "r"(&B_002DDF40));
                asm volatile("lqc2 vf1, 0x60(%0)" : : "r"(sp));
                asm volatile("vadd.xyzw vf2, vf2, vf1");
                sp10 = (s128) temp_v0_4;
                asm volatile("vsub.xyzw vf1, vf2, vf3");
                asm volatile("sqc2 vf1, 0x80(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(sp));
                s32 vu_4;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
                s32 vu_5;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_5));
                if ((FInsideCmFrustrum(&B_002DDF40, vu_5, temp_a2_2) != 0) && (FInsideCmMrd(&B_002DDF40, vu_4, &sp50, M2C_FIELD(var_s2, f32 *, 0x38)) != 0)) {
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
            var_s2 = M2C_FIELD(var_s2, s8 **, 0x128);
        } while (var_s2 != NULL);
    } else {
block_21:;
    }
    if (sp54 == 0) {
block_23:
        CStackFrame_Destructor(sp, 2);
        return;
    }
    var_s7 = 0;
    sp70 = (s8 *)OnGameLoad__FP4GAME(sp54);
    M2C_FIELD(sp70, s32 *, 0) = 0xC;
    M2C_FIELD(sp70, s32 *, 4) = 0;
    sp74 = M2C_FIELD(&g_2dea28, s32 *, 0xC);
    AddDmaCnt__4DMAS(&g_2dea28);
    var_s1_2 = M2C_FIELD(arg0, s8 **, 0x448);
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
                AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 9, 1, (u16 *)&sp10);
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
        var_s1_2 = M2C_FIELD(var_s1_2, s8 **, 0x1090);
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
}
