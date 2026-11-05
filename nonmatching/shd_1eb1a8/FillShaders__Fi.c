#include "m2c_macros.h"

M2C_UNK AddPrimBulk__4GIFSiiiUlPP2QW(); /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW();  /* extern */
M2C_UNK Clear__4DMAS();                       /* extern */
M2C_UNK EndDmaCnt__4DMAS();                   /* extern */
M2C_UNK EndPrim__4GIFSi();           /* extern */
M2C_UNK GIFS_AddPrimTag(); /* extern */
M2C_UNK PackAD__4GIFSll(); /* extern */
M2C_UNK PackRGBA__4GIFSUi();             /* extern */
M2C_UNK PackSTQ__4GIFSfff(); /* extern */
M2C_UNK __4GIFS();                            /* extern */
M2C_UNK func_001EA750();        /* extern */
extern u32 B_002DE18C;
extern s32 B_003DCFE8;
extern s32 B_003DCFEC;

void FillShaders__Fi(void) {
    char sp[0x400];
    M2C_UNK sp41;
    M2C_UNK sp42;
    M2C_UNK sp43;
    s8 sp30;
    s8 sp31;
    s8 sp32;
    s8 sp33;
    u8 sp40;
    M2C_UNK var_a1;
    s32 *var_s3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u32 var_a2_3;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 temp_v1_2;
    void *temp_s3;
    void *temp_s3_2;
    void *temp_s4;

    var_s5 = 0;
    if (B_003DCFE8 > 0) {
        do {
            temp_s4 = B_003DCFEC + (var_s5 * 0x2C);
            temp_v1 = M2C_FIELD(temp_s4, u8 *, 4);
            var_s3 = M2C_FIELD(temp_s4, s32 **, 0x20);
            switch (temp_v1) {
            case 0:
            case 4:
            case 5:
            case 6:
                __4GIFS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 0), M2C_FIELD(var_s3, s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 0, sp);
                temp_a0 = M2C_FIELD(temp_s4, u8 *, 5);
                if (temp_a0 & 0x20) {
                    var_v0 = 0x60000;
                    if (M2C_FIELD(temp_s4, u8 *, 4) != 0) {
                        var_v0 = 0x20000;
                    }
                    PackAD__4GIFSll(sp, 0x47, ((temp_a0 & 4) ? 0x13001 : 0x11001) | var_v0);
                    PackAD__4GIFSll(sp, 0x42, 0U);
                } else if (temp_a0 & 0x10) {
                    temp_v0 = M2C_FIELD(temp_s4, u8 *, 4);
                    temp_a1 = (temp_v0 == 0) ? 0x7EB : 0x7E1;
                    var_a2 = temp_a1 | 0x11000;
                    if (temp_a0 & 4) {
                        var_a2 = temp_a1 | 0x13000;
                    }
                    var_v0_2 = 0x60000;
                    if (temp_v0 != 0) {
                        var_v0_2 = 0x20000;
                    }
                    PackAD__4GIFSll(sp, 0x47, var_a2 | var_v0_2);
                    PackAD__4GIFSll(sp, 0x42, ((M2C_FIELD(temp_s4, u8 *, 5) & 1) * 8) | 1);
                } else if (!(temp_a0 & 0x80)) {
                    temp_v0_2 = M2C_FIELD(temp_s4, u8 *, 4);
                    temp_a1_2 = (temp_v0_2 == 0) ? 0x7EB : 0x7E1;
                    var_a2_2 = temp_a1_2 | 0x11000;
                    if (temp_a0 & 4) {
                        var_a2_2 = temp_a1_2 | 0x13000;
                    }
                    var_v0_3 = 0x60000;
                    if (temp_v0_2 != 0) {
                        var_v0_3 = 0x20000;
                    }
                    PackAD__4GIFSll(sp, 0x47, var_a2_2 | var_v0_3);
                    PackAD__4GIFSll(sp, 0x42, (((M2C_FIELD(temp_s4, u8 *, 5) & 1) ? 2 : 1) * 4) | 0x40, 0x40);
                } else {
                    PackAD__4GIFSll(sp, 0x47, 0x77000U);
                    PackAD__4GIFSll(sp, 0x42, 0x54U);
                }
                var_a2_3 = B_002DE18C;
                var_a1 = 0x3D;
block_45:
                PackAD__4GIFSll(sp, var_a1, var_a2_3);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                break;
            case 3:
                __4GIFS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 0), M2C_FIELD(var_s3, s32 *, 4));
                if (M2C_FIELD(temp_s4, u8 *, 5) & 2) {
                    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                    func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 0, sp);
                    PackAD__4GIFSll(sp, 0x47, 0x71001U);
                    PackAD__4GIFSll(sp, 0x42, (((M2C_FIELD(temp_s4, u8 *, 5) & 1) ? 2 : 1) * 4) | 0x40, 0x40);
                    PackAD__4GIFSll(sp, 0x3D, B_002DE18C);
                } else {
                    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x4C, 0, 4);
                    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x4D, 0, 4);
                    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                    PackAD__4GIFSll(sp, 0x47, 0x71001U);
                    PackAD__4GIFSll(sp, 0x42, 0x6AU);
                    PackAD__4GIFSll(sp, 1, (0x8000 << 0x11) | 0x20);
                }
                EndPrim__4GIFSi(sp, 1);
                temp_s3 = var_s3 + 8;
                EndDmaCnt__4DMAS(sp);
                Clear__4DMAS(sp);
                temp_s3_2 = temp_s3 + 8;
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 8), M2C_FIELD(temp_s3, s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x4C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x4D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                PackAD__4GIFSll(sp, 0x47, 0x71001U);
                PackAD__4GIFSll(sp, 0x42, 0x6AU);
                PackAD__4GIFSll(sp, 1, (0xC000 << 0x11) | 0x2000);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                Clear__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(temp_s3, s32 *, 8), M2C_FIELD(temp_s3_2, s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x6C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x6D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 5, 0x12EEE);
                PackAD__4GIFSll(sp, 0x47, 0x75001U);
                PackAD__4GIFSll(sp, 0x42, (((M2C_FIELD(temp_s4, u8 *, 5) & 1) ? 2 : 1) * 4) | 0x40);
                PackAD__4GIFSll(sp, 0x3D, B_002DE18C);
                PackSTQ__4GIFSfff(sp, 0, 0, 0x3F800000);
                sp30 = (s8) ((s32) (M2C_FIELD(temp_s4, u8 *, 0xC) + 1) >> 1);
                sp31 = (s8) ((s32) (M2C_FIELD(temp_s4, u8 *, 0xD) + 1) >> 1);
                sp32 = (s8) ((s32) (M2C_FIELD(temp_s4, u8 *, 0xE) + 1) >> 1);
                sp33 = (s8) ((s32) (M2C_FIELD(temp_s4, u8 *, 0xF) + 1) >> 1);
                PackRGBA__4GIFSUi(sp, (s32) sp30);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                Clear__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(temp_s3_2, s32 *, 8), M2C_FIELD((temp_s3_2 + 8), s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x4D, 0, 1);
                sp40 = M2C_UNALIGNED32(M2C_FIELD(temp_s4, M2C_UNK *, 0x10));
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                PackAD__4GIFSll(sp, 0x42, (((M2C_FIELD(temp_s4, u8 *, 5) & 1) ? 2 : 1) * 4) | 0x40);
                temp_a1_3 = sp40 | ((s64) sp41 << 8) | ((s64) sp42 << 0x10);
                if (M2C_FIELD(temp_s4, u8 *, 5) & 2) {
                    var_a2_3 = temp_a1_3 | ((s64) sp43 << 0x18) | (0x8000 << 0x11);
                } else {
                    var_a2_3 = temp_a1_3 | (0x8000 << 0x11);
                }
                var_a1 = 1;
                goto block_45;
            case 2:
                __4GIFS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 0), M2C_FIELD(var_s3, s32 *, 4));
                GIFS_AddPrimTag(sp, 0x44, 0, 2);
                GIFS_AddPrimTag(sp, 0x45, 0, 2);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                if (M2C_FIELD(temp_s4, u8 *, 5) & 8) {
                    PackAD__4GIFSll(sp, 0x47, 0x71001U);
                } else {
                    PackAD__4GIFSll(sp, 0x47, 0x75001U);
                }
                PackAD__4GIFSll(sp, 0x42, (0x8000 << 0x18) | 0x62);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                Clear__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 8), M2C_FIELD((var_s3 + 8), s32 *, 4));
                GIFS_AddPrimTag(sp, 0x44, 0, 2);
                GIFS_AddPrimTag(sp, 0x45, 0, 2);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                if (M2C_FIELD(temp_s4, u8 *, 5) & 8) {
                    PackAD__4GIFSll(sp, 0x47, 0x31001U);
                } else {
                    PackAD__4GIFSll(sp, 0x47, 0x35001U);
                }
                var_a2_3 = (0x8000 << 0x18) | 0x68;
                var_a1 = 0x42;
                goto block_45;
            case 1:
                __4GIFS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 0), M2C_FIELD(var_s3, s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 1, sp);
                temp_v1_2 = M2C_FIELD(temp_s4, u8 *, 5);
                if (temp_v1_2 & 0x80) {
                    PackAD__4GIFSll(sp, 0x47, 0x77000U);
                    PackAD__4GIFSll(sp, 0x42, 0x54U);
                } else {
                    PackAD__4GIFSll(sp, 0x47, !(temp_v1_2 & 4) ? 0x717EBU : 0x737EBU);
                    PackAD__4GIFSll(sp, 0x42, (((M2C_FIELD(temp_s4, u8 *, 5) & 1) ? 2 : 1) * 4) | 0x40, 0x40);
                }
                PackAD__4GIFSll(sp, 0x3D, B_002DE18C);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                Clear__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 8), M2C_FIELD((var_s3 + 8), s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 0, sp);
                if (M2C_FIELD(temp_s4, u8 *, 5) & 0x80) {
                    PackAD__4GIFSll(sp, 0x47, 0x57000U);
                    PackAD__4GIFSll(sp, 0x42, 0x58U);
                } else {
                    PackAD__4GIFSll(sp, 0x47, 0x51001U);
                    PackAD__4GIFSll(sp, 0x42, 0x48U);
                }
                var_a1 = 0x3D;
                var_a2_3 = 0;
                goto block_45;
            case 7:
                __4GIFS(sp);
                var_a1_2 = M2C_FIELD(var_s3, s32 *, 0);
                if (!(M2C_FIELD(temp_s4, u8 *, 5) & 0x20)) {
                    temp_a2 = M2C_FIELD(var_s3, s32 *, 4);
                    var_s3 += 8;
                    AllocStatic__4DMASiP2QW(sp, var_a1_2, temp_a2);
                    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                    func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 2, sp);
                    PackAD__4GIFSll(sp, 0x47, 0x5000DU);
                    PackAD__4GIFSll(sp, 0x42, 0x40U);
                    PackAD__4GIFSll(sp, 0x3D, 0U);
                    EndPrim__4GIFSi(sp, 1);
                    EndDmaCnt__4DMAS(sp);
                    Clear__4DMAS(sp);
                    var_a1_2 = *var_s3;
                }
                AllocStatic__4DMASiP2QW(sp, var_a1_2, M2C_FIELD(var_s3, s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 1, sp);
                PackAD__4GIFSll(sp, 0x47, 0x53001U);
                PackAD__4GIFSll(sp, 0x42, (((M2C_FIELD(temp_s4, u8 *, 5) & 1) ? 2 : 1) * 4) | 0x40, 0x40);
                PackAD__4GIFSll(sp, 0x3D, B_002DE18C);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                Clear__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, M2C_FIELD(var_s3, s32 *, 8), M2C_FIELD((var_s3 + 8), s32 *, 4));
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7C, 0, 4);
                AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x7D, 0, 4);
                AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                func_001EA750(M2C_FIELD(temp_s4, s32 *, 0x18), 0, sp);
                PackAD__4GIFSll(sp, 0x47, 0x53001U);
                PackAD__4GIFSll(sp, 0x42, 0x48U);
                PackAD__4GIFSll(sp, 0x3D, 0U);
                EndPrim__4GIFSi(sp, 1);
                EndDmaCnt__4DMAS(sp);
                break;
            }
            var_s5 += 1;
        } while (var_s5 < B_003DCFE8);
    }
}
