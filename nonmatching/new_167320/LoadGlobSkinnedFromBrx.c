#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK AddVifStmask__4VIFSUi(M2C_UNK *, s32);      /* extern */
M2C_UNK AddVifStrow__4VIFSP2QW(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(M2C_UNK *, M2C_UNK, u32, s32); /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK BuildCmFgfn__FP2CMfP4FGFN(M2C_UNK *, s32, f32); /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, void *, M2C_UNK *, void *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK EndPrim__4GIFSi(M2C_UNK *, M2C_UNK);        /* extern */
M2C_UNK PackAD__4GIFSll(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PackRGBA__4GIFSUi(M2C_UNK *, s32);          /* extern */
M2C_UNK PackXYZF__4GIFSiiii(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 PvAllocSwClearImpl__Fi(s32 *, s32 *, M2C_UNK);  /* extern */
M2C_UNK Reset__4DMAS(M2C_UNK *);                    /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 S32Read__18CBinaryInputStream(s32);             /* extern */
s8 U8Read__18CBinaryInputStream(s32);               /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK VIFS_AddVifUnpackFromStream(M2C_UNK *, s32, s8, s32); /* extern */
M2C_UNK __4GIFS(M2C_UNK *);                         /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
M2C_UNK func_001699E8(s32, void *, void *, s32, s32); /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DEB60;
extern M2C_UNK D_002BE540;
extern M2C_UNK D_002BE558;
extern s32 g_2deb50;

void LoadGlobSkinnedFromBrx(s32 arg0, void *arg1, void *arg2, f32 *arg3) {
    M2C_UNK sp64;
    M2C_UNK sp6C;
    M2C_UNK sp10;
    M2C_UNK sp40;
    s32 sp50;
    M2C_UNK sp60;
    M2C_UNK sp90;
    s32 sp94;
    void *sp98;
    M2C_UNK sp9C;
    s32 spA0;
    void *spA4;
    s32 spA8;
    s32 spAC;
    s32 spB0;
    s32 spB4;
    void *spB8;
    void *spBC;
    M2C_UNK *spC0;
    M2C_UNK *spC4;
    s16 var_s1;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s5;
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
    void *temp_a1;
    void *temp_s0;

    temp_s5 = M2C_ERROR(/* Read from unset register $t2 */);
    spA0 = arg0;
    spA4 = arg2;
    spA8 = M2C_ERROR(/* Read from unset register $t0 */);
    spAC = M2C_ERROR(/* Read from unset register $t1 */);
    var_s3 = 0;
    __4VIFS(&sp10);
    CStackFrame_Construct(&sp40);
    AllocStack__4DMASi(&sp10, 0x2000);
    AddDmaCnt__4DMAS(&sp10);
    UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xC, 1, 9);
    BuildCmFgfn__FP2CMfP4FGFN(&B_002DDF40, sp94, *arg3);
    temp_v0 = U8Read__18CBinaryInputStream(temp_s5);
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
            temp_s0 = M2C_FIELD(spA4, s32 *, 0x18) + var_s2;
            var_s2 += 0x50;
            M2C_FIELD(temp_s0, s32 *, 0) = S32Read__18CBinaryInputStream(temp_s5);
            M2C_FIELD(temp_s0, s32 *, 8) = S16Read__18CBinaryInputStream(temp_s5);
        } while (var_s3 < M2C_FIELD(arg1, s8 *, 1));
    }
    spB0 = 0x22;
    __4GIFS(&sp60);
    AllocStack__4DMASi(&sp60, 8);
    AddPrimPack__4GIFSiiUl(&sp60, 0, 2, 0x1E);
    PackAD__4GIFSll(&sp60, 0x42, 0x44);
    PackRGBA__4GIFSUi(&sp60, g_2deb50);
    EndPrim__4GIFSi(&sp60, 1);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, (u32) (sp6C - sp64) >> 4, sp64);
    Reset__4DMAS(&sp60);
    AddPrimPack__4GIFSiiUl(&sp60, 0xC1, 3, 0x44E);
    PackAD__4GIFSll(&sp60, 0x47, 0x73001);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0);
    EndPrim__4GIFSi(&sp60, 0);
    AddPrimPack__4GIFSiiUl(&sp60, 1, 3, 0x44E);
    PackAD__4GIFSll(&sp60, 0x47, 0x72001);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0);
    PackXYZF__4GIFSiiii(&sp60, 0, 0, 0);
    EndPrim__4GIFSi(&sp60, 1);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64 + 0x40);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64);
    AddVifUnpack__4VIFS3UPKiPvi(&sp10, 0xC, 2U, sp64 + 0x40);
    temp_v0_3 = M2C_FIELD(arg1, s8 *, 1);
    if (temp_v0_3 != 0) {
        M2C_FIELD(arg1, s32 *, 0xC) = spB0;
        spB0 = (temp_v0_3 * 4) + 0x22;
    }
    var_s2_2 = 0;
    spB4 = S16Read__18CBinaryInputStream(temp_s5);
    spB8 = arg1 + 0x10;
    spBC = spA4 + 0x10;
    if (spB4 > 0) {
        spC0 = &sp90;
        do {
            CStackFrame_Construct(&sp90);
            UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xD, 3, 0xA);
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
            temp_v0_4 = U8Read__18CBinaryInputStream(temp_s5);
            VIFS_AddVifUnpackFromStream(&sp10, 8, temp_v0_4, temp_s5);
            M2C_FIELD(sp98, s16 *, 8) = (s16) spB0;
            var_s1 = (s16) spB0 + temp_v0_4;
            M2C_FIELD(sp98, s16 *, 0xA) = var_s1;
            if (M2C_FIELD(arg1, s8 *, 1) != 0) {
                var_s0 = 0;
                temp_v0_5 = U8Read__18CBinaryInputStream(temp_s5);
                if (temp_v0_5 > 0) {
                    do {
                        temp_a1 = sp98 + (var_s0 * 2);
                        var_s0 += 1;
                        M2C_FIELD(temp_a1, s16 *, 0x10) = (s16) ((u16) M2C_FIELD(arg1, s32 *, 0xC) + (U8Read__18CBinaryInputStream(temp_s5) * 4));
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
                VIFS_AddVifUnpackFromStream(&sp10, *(temp_s3 + &D_002BE558), temp_v0_4, temp_s5);
                M2C_FIELD(sp98, s16 *, 4) = var_s1;
                var_s1 += temp_v0_4;
                if (temp_s2 != 0) {
                    AddVifStmask__4VIFSUi(&sp10, 0);
                }
            }
            var_s2_2 += 1;
            temp_v0_6 = U8Read__18CBinaryInputStream(temp_s5);
            VIFS_AddVifUnpackFromStream(&sp10, 0xE, temp_v0_6, temp_s5);
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
    func_001699E8(spA0, arg1, spA4, spA8, temp_s5);
    CStackFrame_Destructor(&sp40, 2);
}
