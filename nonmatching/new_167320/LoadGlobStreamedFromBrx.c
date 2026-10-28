#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK AddVifStcycl__4VIFSii(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifStmask__4VIFSUi(M2C_UNK *, s32);      /* extern */
M2C_UNK AddVifStrow__4VIFSP2QW(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, void *, M2C_UNK *, void *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
void *PshdFromIndex(s32);                           /* extern */
s32 PvAllocSwClearImpl__Fi(s32 *, s32 *, M2C_UNK);  /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 S32Read__18CBinaryInputStream(s32);             /* extern */
s32 U16Read__18CBinaryInputStream(s32);             /* extern */
s8 U8Read__18CBinaryInputStream(s32);               /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK VIFS_AddVifUnpackFromStream(M2C_UNK *, s32, s8, s32); /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
M2C_UNK func_001699E8(void *, void *, void *, s32, s32); /* extern */
s32 func_001EC688(void *, s32, u16, M2C_UNK *);     /* extern */
M2C_UNK memset(u16 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK B_002DEB60;
extern M2C_UNK D_002BE540;
extern M2C_UNK D_002BE558;

void LoadGlobStreamedFromBrx(void *arg0, void *arg1, void *arg2) {
    M2C_UNK sp10;
    M2C_UNK sp40;
    s32 sp50;
    M2C_UNK sp60;
    u16 *sp64;
    M2C_UNK sp68;
    void *sp6C;
    void *sp70;
    s32 sp74;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    M2C_UNK *sp84;
    M2C_UNK *sp88;
    void *sp8C;
    void *sp90;
    s16 temp_s2;
    s16 temp_s2_2;
    s16 temp_s2_3;
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s2_2;
    s8 temp_s5;
    s8 temp_v0;
    s8 temp_v0_5;
    s8 temp_v0_6;
    u16 *temp_a1;
    u16 var_v0;
    void *temp_s0;
    void *temp_v0_3;

    var_s2 = 0;
    temp_s4 = M2C_ERROR(/* Read from unset register $t2 */);
    sp6C = arg0;
    sp70 = arg2;
    sp74 = M2C_ERROR(/* Read from unset register $t0 */);
    sp78 = M2C_ERROR(/* Read from unset register $t1 */);
    M2C_FIELD(arg0, s64 *, 0x50) = (s64) (M2C_FIELD(arg0, s64 *, 0x50) | (0x8000 << 0x12));
    __4VIFS(&sp10);
    CStackFrame_Construct(&sp40);
    AllocStack__4DMASi(&sp10, 0x2000);
    AddDmaCnt__4DMAS(&sp10);
    temp_v0 = U8Read__18CBinaryInputStream(temp_s4);
    M2C_FIELD(arg1, s8 *, 1) = temp_v0;
    sp50 = temp_v0 * 0x50;
    M2C_FIELD(&sp50, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocSwClearImpl__Fi(&sp50, &sp50, 0x10);
    sp88 = &sp68;
    M2C_FIELD(sp70, s32 *, 0x18) = temp_v0_2;
    var_s1 = 0;
    if (M2C_FIELD(arg1, s8 *, 1) > 0) {
        do {
            var_s2 += 1;
            temp_s0 = M2C_FIELD(sp70, s32 *, 0x18) + var_s1;
            var_s1 += 0x50;
            M2C_FIELD(temp_s0, s32 *, 0) = S32Read__18CBinaryInputStream(temp_s4);
            M2C_FIELD(temp_s0, s32 *, 8) = S16Read__18CBinaryInputStream(temp_s4);
        } while (var_s2 < M2C_FIELD(arg1, s8 *, 1));
    }
    sp7C = 0x1B;
    if (M2C_FIELD(arg1, s8 *, 1) != 0) {
        M2C_FIELD(arg1, s32 *, 0xC) = 0x1B;
        sp7C = (M2C_FIELD(arg1, s8 *, 1) * 4) + 0x1B;
    }
    var_s1_2 = 0;
    sp80 = S16Read__18CBinaryInputStream(temp_s4);
    sp8C = arg1 + 0x10;
    sp90 = sp70 + 0x10;
    if (sp80 > 0) {
        sp84 = &sp60;
        do {
            CStackFrame_Construct(&sp60);
            UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xD, 4, 0xA);
            memset(sp64, 0, 0x20);
            switch (var_s1_2) {                     /* irregular */
            case 0:
                M2C_FIELD(sp64, u16 *, 0) |= 1;
                if (sp80 == 1) {
                    var_v0 = M2C_FIELD(sp64, u16 *, 0) | 8;
block_14:
                    M2C_FIELD(sp64, u16 *, 0) = var_v0;
                }
                break;
            case 1:
                var_v0 = M2C_FIELD(sp64, u16 *, 0) | 2;
                goto block_14;
            }
            if (M2C_FIELD(arg1, s8 *, 1) != 0) {
                M2C_FIELD(sp64, u16 *, 0) |= 4;
            }
            var_s2_2 = sp7C;
            var_s0 = 0;
            M2C_FIELD(sp64, s16 *, 2) = (s16) var_s2_2;
            temp_v0_3 = PshdFromIndex(U16Read__18CBinaryInputStream(temp_s4));
            if (M2C_FIELD(temp_v0_3, s32 *, 0x1C) > 0) {
                do {
                    M2C_FIELD(&sp64[var_s0], s16 *, 0x14) = (s16) var_s2_2;
                    temp_v0_4 = func_001EC688(temp_v0_3, var_s0, (u16) var_s2_2, &sp10);
                    var_s0 += 1;
                    var_s2_2 += temp_v0_4;
                } while (var_s0 < M2C_FIELD(temp_v0_3, s32 *, 0x1C));
            }
            temp_s5 = U8Read__18CBinaryInputStream(temp_s4);
            AddVifStcycl__4VIFSii(&sp10, 1, 2);
            VIFS_AddVifUnpackFromStream(&sp10, 8, temp_s5, temp_s4);
            M2C_FIELD(sp64, u16 *, 8) = (u16) var_s2_2;
            temp_s2 = var_s2_2 + (temp_s5 * 2);
            M2C_FIELD(sp64, s16 *, 0xA) = temp_s2;
            if (M2C_FIELD(arg1, s8 *, 1) != 0) {
                var_s0_2 = 0;
                temp_v0_5 = U8Read__18CBinaryInputStream(temp_s4);
                if (temp_v0_5 > 0) {
                    do {
                        temp_a1 = &sp64[var_s0_2];
                        var_s0_2 += 1;
                        M2C_FIELD(temp_a1, s16 *, 0x18) = (s16) ((u16) M2C_FIELD(arg1, s32 *, 0xC) + (U8Read__18CBinaryInputStream(temp_s4) * 4));
                    } while (var_s0_2 < temp_v0_5);
                }
                temp_s3 = temp_v0_5 * 4;
                temp_s1 = temp_v0_5 < 4;
                if (var_s0_2 < 4) {
                    do {
                        temp_a0 = var_s0_2 * 2;
                        var_s0_2 += 1;
                        M2C_FIELD((sp64 + temp_a0), u16 *, 0x18) = (u16) M2C_FIELD(sp64, u16 *, 0x18);
                    } while (var_s0_2 < 4);
                }
                if (temp_s1 != 0) {
                    AddVifStrow__4VIFSP2QW(&sp10, &B_002DEB60);
                    AddVifStmask__4VIFSUi(&sp10, *(temp_s3 + &D_002BE540));
                }
                VIFS_AddVifUnpackFromStream(&sp10, *(temp_s3 + &D_002BE558), temp_s5, temp_s4);
                if (temp_s1 != 0) {
                    AddVifStmask__4VIFSUi(&sp10, 0);
                }
            }
            var_s1_2 += 1;
            AddVifStcycl__4VIFSii(&sp10, 1, 1);
            temp_v0_6 = U8Read__18CBinaryInputStream(temp_s4);
            VIFS_AddVifUnpackFromStream(&sp10, 0xE, temp_v0_6, temp_s4);
            M2C_FIELD(sp64, s16 *, 0xC) = temp_s2;
            temp_s2_2 = temp_s2 + temp_v0_6;
            M2C_FIELD(sp64, s16 *, 0xE) = temp_s2_2;
            temp_s2_3 = temp_s2_2 + 1;
            M2C_FIELD(sp64, s16 *, 0x10) = temp_s2_3;
            M2C_FIELD(sp64, s16 *, 0x12) = temp_s2_3;
            AddVifMscal__4VIFSPv(&sp10, 0);
            AddVifMscal__4VIFSPv(&sp10, 0x1910);
            AddVifMscal__4VIFSPv(&sp10, 0x1A68);
            CStackFrame_Destructor(sp84, 2);
        } while (var_s1_2 < sp80);
    }
    EndDmaCnt__4DMAS(&sp10);
    AddDmaRet__4DMAS(&sp10);
    DMAS_DetachCopyPermanent(&sp10, sp8C, sp88, sp90);
    func_001699E8(sp6C, arg1, sp70, sp74, temp_s4);
    CStackFrame_Destructor(&sp40, 2);
}
