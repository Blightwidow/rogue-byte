typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadGlobIndexedFromBrx {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x30];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x10];
    /* 0x050 */ s32 sp50;                           /* inferred */
    /* 0x054 */ char pad54[0xC];                    /* maybe part of sp50[4]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[4];
    /* 0x064 */ u16 *sp64;                          /* inferred */
    /* 0x068 */ u16 *sp68;                          /* inferred */
    /* 0x06C */ u16 *sp6C;                          /* inferred */
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[4];
    /* 0x074 */ s32 sp74;                           /* inferred */
    /* 0x078 */ s8 *sp78;                         /* inferred */
    /* 0x07C */ s8 *sp7C;                         /* inferred */
    /* 0x080 */ s8 *sp80;                         /* inferred */
    /* 0x084 */ s32 sp84;                           /* inferred */
    /* 0x088 */ s32 sp88;                           /* inferred */
    /* 0x08C */ s32 sp8C;                           /* inferred */
    /* 0x090 */ s32 sp90;                           /* inferred */
    /* 0x094 */ s32 *sp94;                          /* inferred */
    /* 0x098 */ s32 *sp98;                          /* inferred */
    /* 0x09C */ s32 *sp9C;                          /* inferred */
    /* 0x0A0 */ s32 spA0;                           /* inferred */
    /* 0x0A4 */ s32 *spA4;                          /* inferred */
    /* 0x0A8 */ M2C_UNK *spA8;                      /* inferred */
    /* 0x0AC */ u16 **spAC;                         /* inferred */
    /* 0x0B0 */ M2C_UNK *spB0;                      /* inferred */
    /* 0x0B4 */ s8 *spB4;                         /* inferred */
    /* 0x0B8 */ s8 *spB8;                         /* inferred */
    /* 0x0BC */ s32 spBC;                           /* inferred */
    /* 0x0C0 */ s32 spC0;                           /* inferred */
    /* 0x0C4 */ char padC4[0xCC];
};                                                  /* size = 0x190 */
M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK AddVifStcycl__4VIFSii(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifStmask__4VIFSUi(M2C_UNK *, s32);      /* extern */
M2C_UNK AddVifStrow__4VIFSP2QW(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK CBinaryInputStream_Read_thunk(s32, s32, s32 *); /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK CopyAb__FPvT0Ui(s8 *, s8 *, s32);       /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, s8 *, M2C_UNK *, s8 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
s8 *PshdFromIndex(s32);                           /* extern */
s32 *PvAllocStackImpl__Fi(...);            /* extern */
s32 PvAllocSwClearImpl__Fi(s32 *, s32 *, M2C_UNK);  /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, s32 *); /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 S32Read__18CBinaryInputStream(s32);             /* extern */
s32 U16Read__18CBinaryInputStream(s32);             /* extern */
s8 U8Read__18CBinaryInputStream(s32);               /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK *, s32, s8, u16, M2C_UNK, u16 **); /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
M2C_UNK func_001699E8(s32, s8 *, s8 *, s32, s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_001EC688(s8 *, s32, s16, M2C_UNK *);     /* extern */
f32 func_002599D8(s32 *);                           /* extern */
f32 func_002599E0(s128 *);                          /* extern */
f32 func_002599E8(s128 *);                          /* extern */
M2C_UNK memset(u16 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK B_002DEB60;
extern M2C_UNK D_002BE540;
extern M2C_UNK D_002BE558;
void LoadGlobIndexedFromBrx(s32 arg0, s8 *arg1, s8 *arg2, s8 *arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_UNK sp10;
    M2C_UNK sp40;
    s32 sp50;                                       /* compiler-managed */
    M2C_UNK sp60;
    u16 *sp64;
    u16 *sp68;
    u16 *sp6C;
    M2C_UNK sp70;
    s32 sp74;
    s8 *sp78;
    s8 *sp7C;
    s8 *sp80;
    s32 sp84;
    s32 sp88;
    s32 sp8C;
    s32 sp90;
    s32 *sp94;
    s32 *sp98;
    s32 *sp9C;
    s32 spA0;
    s32 *spA4;
    M2C_UNK *spA8;
    u16 **spAC;
    M2C_UNK *spB0;
    s8 *spB4;
    s8 *spB8;
    s32 spBC;
    s32 spC0;
    f32 temp_f20;
    f32 temp_f21;
    s32 *temp_v0_5;
    s32 *temp_v0_6;
    s32 *temp_v0_7;
    s32 *temp_v0_8;
    s32 *var_s0_2;
    s32 *var_s5_2;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_v0_2;
    s32 temp_v0_9;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s1;
    s32 var_s1_3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;
    s32 var_s3;
    s32 var_s5;
    s8 temp_s4;
    s8 temp_v0;
    s8 temp_v0_3;
    s8 temp_v0_4;
    s8 temp_v1;
    s8 var_s1_2;
    u16 *temp_a1;
    u16 temp_s2;
    u16 var_v0;
    u8 temp_s1;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_s0_5;
    s8 *temp_s6;
    sp74 = arg0;
    sp78 = arg1;
    sp7C = arg2;
    var_s2 = 0;
    sp80 = arg3;
    sp84 = arg4;
    sp88 = arg5;
    __4VIFS(&sp10);
    CStackFrame_Construct(&sp40);
    AllocStack__4DMASi(&sp10, 0x2000);
    AddDmaCnt__4DMAS(&sp10);
    temp_v0 = U8Read__18CBinaryInputStream(arg6);
    M2C_FIELD(sp78, s8 *, 1) = temp_v0;
    sp50 = temp_v0 * 0x50;
    M2C_FIELD(&sp50, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocSwClearImpl__Fi(&sp50, &sp50, 0x10);
    spB0 = &sp70;
    M2C_FIELD(sp7C, s32 *, 0x18) = temp_v0_2;
    if (M2C_FIELD(sp78, s8 *, 1) > 0) {
        var_s1 = 0;
        do {
            var_s2 += 1;
            temp_s0 = (s8 *)(M2C_FIELD(sp7C, s32 *, 0x18) + var_s1);
            var_s1 += 0x50;
            M2C_FIELD(temp_s0, s32 *, 0) = S32Read__18CBinaryInputStream(arg6);
            M2C_FIELD(temp_s0, s32 *, 8) = S16Read__18CBinaryInputStream(arg6);
        } while (var_s2 < M2C_FIELD(sp78, s8 *, 1));
    }
    temp_v0_3 = M2C_FIELD(sp78, s8 *, 1);
    sp8C = 0x1B;
    if (temp_v0_3 != 0) {
        M2C_FIELD(sp78, s32 *, 0xC) = 0x1B;
        sp8C = (temp_v0_3 * 4) + 0x1B;
    }
    var_s0 = 0;
    sp90 = S16Read__18CBinaryInputStream(arg6);
    spB4 = sp78 + 0x10;
    spB8 = sp7C + 0x10;
    if (sp90 > 0) {
        sp98 = &sp50;
        spA8 = &sp60;
        do {
            CStackFrame_Construct(&sp60);
            UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xD, 4, 0xAU, 0, &sp64);
            memset(sp64, 0, 0x20);
            switch (var_s0) {                       /* irregular */
            case 0:
                M2C_FIELD(sp64, u16 *, 0) = 1;
                if (sp90 == 1) {
                    M2C_FIELD(sp64, u16 *, 0) |= 8;
                }
                if (M2C_FIELD(sp80, s32 *, 8) == 2) {
                    var_v0 = M2C_FIELD(sp64, u16 *, 0) | 0x400;
block_15:
                    M2C_FIELD(sp64, u16 *, 0) = var_v0;
                }
                break;
            case 1:
                var_v0 = 2;
                goto block_15;
            }
            spBC = var_s0 + 1;
            M2C_FIELD(sp64, s16 *, 2) = (s16) sp8C;
            temp_s6 = PshdFromIndex(U16Read__18CBinaryInputStream(arg6));
            temp_s4 = U8Read__18CBinaryInputStream(arg6);
            temp_v0_4 = U8Read__18CBinaryInputStream(arg6);
            sp50 = temp_v0_4 * 0x10;
            M2C_FIELD(sp98, s32 *, 4) = 0x10;
            temp_v0_5 = PvAllocStackImpl__Fi(sp98);
            sp94 = temp_v0_5;
            spAC = &sp6C;
            if (temp_v0_4 > 0) {
                var_s0_2 = temp_v0_5;
                var_s1_2 = temp_v0_4;
                do {
                    ReadVector__18CBinaryInputStreamP6VECTOR(arg6, var_s0_2);
                    var_s1_2 -= 1;
                    var_s0_2 += 0x10;
                } while (var_s1_2 != 0);
            }
            temp_v1 = M2C_FIELD(sp78, s8 *, 1);
            spA0 = (s32) ((temp_v1 <= 3) ? temp_v1 : 4);
            if (temp_v1 != 0) {
                var_s0_3 = 0;
                spC0 = temp_s4 * 2;
                var_s5 = temp_s4 + 0x1F;
                var_s1_3 = temp_s4 + 0x3E;
                do {
                    temp_a1 = &sp64[var_s0_3];
                    var_s0_3 += 1;
                    M2C_FIELD(temp_a1, s16 *, 0x18) = (s16) ((u16) M2C_FIELD(sp78, s32 *, 0xC) + (U8Read__18CBinaryInputStream(arg6) * 4));
                } while (var_s0_3 < 4);
                temp_s0_2 = spA0 * temp_v0_4;
                sp50 = temp_s0_2;
                M2C_FIELD(sp98, s32 *, 4) = 0x10;
                temp_v0_6 = PvAllocStackImpl__Fi(sp98, temp_a1);
                sp9C = temp_v0_6;
                CBinaryInputStream_Read_thunk(arg6, temp_s0_2, temp_v0_6);
            } else {
                sp9C = NULL;
                spC0 = temp_s4 * 2;
                var_s5 = temp_s4 + 0x1F;
                var_s1_3 = temp_s4 + 0x3E;
            }
            sp50 = (s32) temp_s4;
            var_fp = 1;
            M2C_FIELD(sp98, s32 *, 4) = 0x10;
            var_s3 = 0;
            temp_v0_7 = PvAllocStackImpl__Fi(sp98);
            spA4 = temp_v0_7;
            var_s2_2 = sp8C;
            CBinaryInputStream_Read_thunk(arg6, (s32) temp_s4, temp_v0_7);
            temp_s0_3 = ((s32) ((var_s5 > -1) ? var_s5 : var_s1_3) >> 5) * 4;
            sp50 = temp_s0_3;
            M2C_FIELD(sp98, s32 *, 4) = 0x10;
            temp_v0_8 = PvAllocStackImpl__Fi(sp98);
            CBinaryInputStream_Read_thunk(arg6, temp_s0_3, temp_v0_8);
            var_s5_2 = temp_v0_8;
            if (M2C_FIELD(temp_s6, s32 *, 0x1C) > 0) {
                do {
                    M2C_FIELD(&sp64[var_s3], s16 *, 0x14) = (s16) var_s2_2;
                    temp_v0_9 = func_001EC688(temp_s6, var_s3, (s16) var_s2_2, &sp10);
                    var_s3 += 1;
                    var_s2_2 += temp_v0_9;
                } while (var_s3 < M2C_FIELD(temp_s6, s32 *, 0x1C));
            }
            temp_s2 = var_s2_2 + 1;
            M2C_FIELD(sp64, u16 *, 0x10) = temp_s2;
            M2C_FIELD(sp64, s16 *, 0x12) = (s16) (temp_s2 + spC0);
            M2C_FIELD(sp64, s16 *, 4) = (s16) temp_s4;
            AddVifStcycl__4VIFSii(&sp10, 1, 2);
            if (M2C_FIELD(sp78, s8 *, 1) != 0) {
                temp_s2_2 = spA0 < 4;
                temp_s0_4 = spA0 * 4;
                if (temp_s2_2 != 0) {
                    AddVifStrow__4VIFSP2QW(&sp10, &B_002DEB60);
                    AddVifStmask__4VIFSUi(&sp10, *(temp_s0_4 + &D_002BE540));
                }
                UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, *(temp_s0_4 + &D_002BE558), temp_s4, M2C_FIELD(sp64, u16 *, 0x10), 0, &sp68);
                if (temp_s2_2 != 0) {
                    AddVifStmask__4VIFSUi(&sp10, 0);
                }
            }
            var_s2_3 = 0;
            UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xC, temp_s4, M2C_FIELD(sp64, u16 *, 0x10) + 1, 0, spAC);
            AddVifStcycl__4VIFSii(&sp10, 1, 1);
            if (temp_s4 > 0) {
                do {
                    temp_s3 = var_s2_3 * 0x10;
                    temp_s0_5 = (s8 *)(temp_s3 + sp6C);
                    sp50 = *((*(spA4 + var_s2_3) * 0x10) + sp94);
                    temp_f21 = func_002599D8(&sp50);
                    temp_f20 = func_002599E0((s128 *)(&sp50));
                    M2C_FIELD(temp_s0_5, f32 *, 8) = func_002599E8((s128 *)(&sp50));
                    M2C_FIELD(temp_s0_5, f32 *, 0) = temp_f21;
                    M2C_FIELD(temp_s0_5, f32 *, 4) = temp_f20;
                    if (*var_s5_2 & var_fp) {
                        M2C_FIELD((temp_s3 + sp6C), f32 *, 0xC) = 8.421376e6f;
                    } else {
                        M2C_FIELD((temp_s3 + sp6C), f32 *, 0xC) = 8.41728e6f;
                    }
                    var_fp *= 2;
                    var_s2_3 += 1;
                    if (var_fp == 0) {
                        var_s5_2 += 4;
                        var_fp = 1;
                    }
                } while (var_s2_3 < temp_s4);
            }
            if (M2C_FIELD(sp78, s8 *, 1) != 0) {
                var_s2_4 = 0;
                if (temp_s4 > 0) {
                    var_s0_4 = 0;
                    do {
                        temp_s1 = *(spA4 + var_s2_4);
                        var_s2_4 += 1;
                        temp_a0 = (s8 *)(sp68 + var_s0_4);
                        var_s0_4 += spA0;
                        CopyAb__FPvT0Ui(temp_a0, (s8 *)(sp9C + (temp_s1 * spA0)), spA0);
                    } while (var_s2_4 < temp_s4);
                }
            }
            AddVifMscal__4VIFSPv(&sp10, 0);
            var_s0 = spBC;
            AddVifMscal__4VIFSPv(&sp10, 0x1910);
            AddVifMscal__4VIFSPv(&sp10, 0x1A68);
            CStackFrame_Destructor(spA8, 2);
        } while (var_s0 < sp90);
    }
    EndDmaCnt__4DMAS(&sp10);
    AddDmaRet__4DMAS(&sp10);
    DMAS_DetachCopyPermanent(&sp10, spB4, spB0, spB8);
    func_001699E8(sp74, sp78, sp7C, sp84, sp88, 0, 0, 0, arg6);
    CStackFrame_Destructor(&sp40, 2);
}
}
