typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadGlobSkinnedFromBrx {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x30];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x10];
    /* 0x050 */ s32 sp50;                           /* inferred */
    /* 0x054 */ char pad54[0xC];                    /* maybe part of sp50[4]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[4];
    /* 0x064 */ s32 sp64;                           /* inferred */
    /* 0x068 */ char pad68[4];
    /* 0x06C */ s32 sp6C;                           /* inferred */
    /* 0x070 */ char pad70[0x20];                   /* maybe part of sp6C[9]? */
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[4];
    /* 0x094 */ s8 *sp94;                         /* inferred */
    /* 0x098 */ s8 *sp98;                         /* inferred */
    /* 0x09C */ M2C_UNK sp9C;                       /* inferred */
    /* 0x09C */ char pad9C[4];
    /* 0x0A0 */ s32 spA0;                           /* inferred */
    /* 0x0A4 */ s8 *spA4;                         /* inferred */
    /* 0x0A8 */ s32 spA8;                           /* inferred */
    /* 0x0AC */ s32 spAC;                           /* inferred */
    /* 0x0B0 */ s32 spB0;                           /* inferred */
    /* 0x0B4 */ s32 spB4;                           /* inferred */
    /* 0x0B8 */ s8 *spB8;                         /* inferred */
    /* 0x0BC */ s8 *spBC;                         /* inferred */
    /* 0x0C0 */ M2C_UNK *spC0;                      /* inferred */
    /* 0x0C4 */ M2C_UNK *spC4;                      /* inferred */
    /* 0x0C8 */ char padC8[0xA8];
};                                                  /* size = 0x170 */
#define sp64 (*(s32 *)(sp + 0x064))
#define sp6C (*(s32 *)(sp + 0x06C))
M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK AddVifStmask__4VIFSUi(M2C_UNK *, s32);      /* extern */
M2C_UNK AddVifStrow__4VIFSP2QW(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(M2C_UNK *, M2C_UNK, u32, s32, M2C_UNK); /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK BuildCmFgfn__FP2CMfP4FGFN(M2C_UNK *, s8 *, f32); /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, s8 *, M2C_UNK *, s8 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK EndPrim__4GIFSi(M2C_UNK *, M2C_UNK);        /* extern */
M2C_UNK PackAD__4GIFSll(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PackRGBA__4GIFSUi(M2C_UNK *, s32);          /* extern */
M2C_UNK PackXYZF__4GIFSiiii(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 PvAllocSwClearImpl__Fi(s32 *, s32 *, M2C_UNK);  /* extern */
M2C_UNK Reset__4DMAS(M2C_UNK *);                    /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 S32Read__18CBinaryInputStream(s32);             /* extern */
s8 U8Read__18CBinaryInputStream(s32);               /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 **); /* extern */
M2C_UNK VIFS_AddVifUnpackFromStream(M2C_UNK *, s32, s8, s32, s16); /* extern */
M2C_UNK __4GIFS(M2C_UNK *);                         /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
M2C_UNK func_001699E8(s32, s8 *, s8 *, s32, s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DEB60;
extern M2C_UNK D_002BE540;
extern M2C_UNK D_002BE558;
extern s32 g_2deb50;
void LoadGlobSkinnedFromBrx(s32 arg0, s8 *arg1, s8 *arg2, f32 *arg3, s32 arg4, s32 arg5, s32 arg6) {
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK sp40;
    s32 sp50;
    M2C_UNK sp60;
    M2C_UNK sp90;
    s8 *sp94;
    s8 *sp98;
    M2C_UNK sp9C;
    s32 spA0;
    s8 *spA4;
    s32 spA8;
    s32 spAC;
    s32 spB0;
    s32 spB4;
    s8 *spB8;
    s8 *spBC;
    M2C_UNK *spC0;
    M2C_UNK *spC4;
    s16 var_s1;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    s8 temp_v0;
    s8 temp_v0_3;
    s8 temp_v0_4;
    s8 temp_v0_5;
    s8 temp_v0_6;
    u16 var_v0;
    s8 *temp_a1;
    s8 *temp_s0;
    spA0 = arg0;
    spA4 = arg2;
    spA8 = arg4;
    spAC = arg5;
    var_s3 = 0;
    __4VIFS(&sp10);
    CStackFrame_Construct(&sp40);
    AllocStack__4DMASi(&sp10, 0x2000);
    AddDmaCnt__4DMAS(&sp10);
    UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xC, 1, 9, 0, &sp94);
    BuildCmFgfn__FP2CMfP4FGFN(&B_002DDF40, sp94, *arg3);
    temp_v0 = U8Read__18CBinaryInputStream(arg6);
    M2C_FIELD(arg1, s8 *, 1) = temp_v0;
    sp50 = temp_v0 * 0x50;
    M2C_FIELD(&sp50, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocSwClearImpl__Fi(&sp50, &sp50, 0x10);
    spC4 = &sp9C;
    M2C_FIELD(spA4, s32 *, 0x18) = temp_v0_2;
    if (M2C_FIELD(arg1, s8 *, 1) > 0) {
        var_s2 = 0;
        do {
            var_s3 += 1;
            temp_s0 = (s8 *)(M2C_FIELD(spA4, s32 *, 0x18) + var_s2);
            var_s2 += 0x50;
            M2C_FIELD(temp_s0, s32 *, 0) = S32Read__18CBinaryInputStream(arg6);
            M2C_FIELD(temp_s0, s32 *, 8) = S16Read__18CBinaryInputStream(arg6);
        } while (var_s3 < M2C_FIELD(arg1, s8 *, 1));
    }
    spB0 = 0x22;
    __4GIFS(&sp60);
    AllocStack__4DMASi(&sp60, 8);
    AddPrimPack__4GIFSiiUl(&sp60, 0, 2, 0x1E);
    PackAD__4GIFSll(&sp60, 0x42, 0x44);
    PackRGBA__4GIFSUi(&sp60, g_2deb50);
    EndPrim__4GIFSi(&sp60, 1);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, (u32) (sp6C - sp64) >> 4, sp64, 0xD);
    Reset__4DMAS(&sp60);
    AddPrimPack__4GIFSiiUl(&sp60, 0xC1, 3, 0x44E);
    PackAD__4GIFSll(&sp60, 0x47, 0x73001);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0, 0);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0, 0);
    EndPrim__4GIFSi(&sp60, 0);
    AddPrimPack__4GIFSiiUl(&sp60, 1, 3, 0x44E);
    PackAD__4GIFSll(&sp60, 0x47, 0x72001);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0, 0);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0, 0);
    EndPrim__4GIFSi(&sp60, 1);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64, 0x12);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64 + 0x40, 0x16);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64, 0x1A);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64 + 0x40, 0x1E);
    temp_v0_3 = M2C_FIELD(arg1, s8 *, 1);
    if (temp_v0_3 != 0) {
        M2C_FIELD(arg1, s32 *, 0xC) = spB0;
        spB0 = (temp_v0_3 * 4) + 0x22;
    }
    var_s2_2 = 0;
    spB4 = S16Read__18CBinaryInputStream(arg6);
    spB8 = arg1 + 0x10;
    spBC = spA4 + 0x10;
    if (spB4 > 0) {
        spC0 = &sp90;
        do {
            CStackFrame_Construct(&sp90);
            UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xD, 3, 0xA, 0, &sp98);
            memset(sp98, 0, 0x18);
            switch (var_s2_2) {                     /* irregular */
            case 0:
                var_v0 = M2C_FIELD(sp98, u16 *, 0) | 1;
block_12:
                M2C_FIELD(sp98, u16 *, 0) = var_v0;
                break;
            case 1:
                var_v0 = M2C_FIELD(sp98, u16 *, 0) | 2;
                goto block_12;
            }
            M2C_FIELD(sp98, s16 *, 2) = (s16) spB0;
            temp_v0_4 = U8Read__18CBinaryInputStream(arg6);
            VIFS_AddVifUnpackFromStream(&sp10, 8, temp_v0_4, arg6, (s16) spB0);
            M2C_FIELD(sp98, s16 *, 8) = (s16) spB0;
            var_s1 = (s16) spB0 + temp_v0_4;
            M2C_FIELD(sp98, s16 *, 0xA) = var_s1;
            if (M2C_FIELD(arg1, s8 *, 1) != 0) {
                var_s0 = 0;
                temp_v0_5 = U8Read__18CBinaryInputStream(arg6);
                if (temp_v0_5 > 0) {
                    do {
                        temp_a1 = sp98 + (var_s0 * 2);
                        var_s0 += 1;
                        M2C_FIELD(temp_a1, s16 *, 0x10) = (s16) ((u16) M2C_FIELD(arg1, s32 *, 0xC) + (U8Read__18CBinaryInputStream(arg6) * 4));
                    } while (var_s0 < temp_v0_5);
                }
                temp_s3 = temp_v0_5 * 4;
                temp_s2 = temp_v0_5 < 4;
                if (var_s0 < 4) {
                    do {
                        temp_a0 = var_s0 * 2;
                        var_s0 += 1;
                        M2C_FIELD((sp98 + temp_a0), u16 *, 0x10) = (u16) M2C_FIELD(sp98, u16 *, 0x10);
                    } while (var_s0 < 4);
                }
                if (temp_s2 != 0) {
                    AddVifStrow__4VIFSP2QW(&sp10, &B_002DEB60);
                    AddVifStmask__4VIFSUi(&sp10, *(temp_s3 + &D_002BE540));
                }
                VIFS_AddVifUnpackFromStream(&sp10, *(temp_s3 + &D_002BE558), temp_v0_4, arg6, var_s1);
                M2C_FIELD(sp98, s16 *, 4) = var_s1;
                var_s1 += temp_v0_4;
                if (temp_s2 != 0) {
                    AddVifStmask__4VIFSUi(&sp10, 0);
                }
            }
            var_s2_2 += 1;
            temp_v0_6 = U8Read__18CBinaryInputStream(arg6);
            VIFS_AddVifUnpackFromStream(&sp10, 0xE, temp_v0_6, arg6, var_s1);
            M2C_FIELD(sp98, s16 *, 0xC) = var_s1;
            M2C_FIELD(sp98, s16 *, 0xE) = (s16) (var_s1 + temp_v0_6);
            AddVifMscal__4VIFSPv(&sp10, 0);
            AddVifMscal__4VIFSPv(&sp10, 0x738);
            AddVifMscal__4VIFSPv(&sp10, 0x7F0);
            CStackFrame_Destructor(spC0, 2);
        } while (var_s2_2 < spB4);
    }
    EndDmaCnt__4DMAS(&sp10);
    AddDmaRet__4DMAS(&sp10);
    DMAS_DetachCopyPermanent(&sp10, spB8, spC4, spBC);
    func_001699E8(spA0, arg1, spA4, spA8, spAC, 0, 0, 0, arg6);
    CStackFrame_Destructor(&sp40, 2);
}
}
