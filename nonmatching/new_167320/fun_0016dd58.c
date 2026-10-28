#include "m2c_macros.h"

M2C_UNK AddDmaCall__4DMASP2QW(s32, M2C_UNK *);      /* extern */
M2C_UNK AddDmaCnt__4DMAS();                         /* extern */
M2C_UNK AddPrimList__4GIFSiUl(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifBaseOffset__4VIFSii(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifFlusha__4VIFS(s32);                   /* extern */
M2C_UNK AddVifMscal__4VIFSPv(s32, M2C_UNK);         /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, u32, s32); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK EndPrim__4GIFSi(void *, M2C_UNK);           /* extern */
M2C_UNK GIFS_ListXYZ(void *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK ListUV__4GIFSii(void *, s32, M2C_UNK);      /* extern */
M2C_UNK PackAD__4GIFSll(void *, M2C_UNK, s64);      /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK __4GIFS(void *);                            /* extern */
M2C_UNK func_0016D698(M2C_UNK, void *, s32 *);      /* extern */
M2C_UNK func_0016D6C8(void *, M2C_UNK, s32 *);      /* extern */
extern M2C_UNK B_002DEA50;
extern M2C_UNK B_002DF940;
extern M2C_UNK B_002DFA80;
extern M2C_UNK B_003DD490;
extern s64 B_003E1330;
extern s32 g_2dea4c;
extern M2C_UNK g_2deb70;
extern s32 g_2deb74;

void func_0016DD58(s32 arg0, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp4;
    M2C_UNK spC;
    M2C_UNK sp30;
    s32 sp2030;
    s32 sp2034;
    s32 temp_a1;
    s32 temp_s0;
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    u32 temp_a2;

    AddDmaCnt__4DMAS();
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 5, 8, 0x1B);
    sp2034 = sp2030;
    __4GIFS(sp);
    AllocStatic__4DMASiP2QW(sp, 0x200, &sp30);
    if (arg2 != 8) {
        if (g_2deb74 != 0) {
            AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
            var_s3 = 0x7200;
            var_s1 = 0x7000;
            func_0016D698(0, sp, &sp2034);
            var_s0 = 0x1E0;
            PackAD__4GIFSll(sp, 0x4C, 0xBFC00000 << 0xA);
            PackAD__4GIFSll(sp, 0x47, 0x31001);
            PackAD__4GIFSll(sp, 0x42, (0x8000 << 0x12) | 0xA9);
            PackAD__4GIFSll(sp, 1, 0x8000 << 0x11);
            PackAD__4GIFSll(sp, 0, 0x46);
            AddPrimList__4GIFSiUl(sp, 2, 0x55);
            do {
                GIFS_ListXYZ(sp, var_s1, 0x7900, 0);
                var_s1 += 0x200;
                GIFS_ListXYZ(sp, var_s3, 0x8700, 0);
                var_s0 -= 0x20;
                var_s3 += 0x200;
            } while (var_s0 >= 0);
        }
        func_0016D6C8(sp, 0x810095, &sp2034);
        func_0016D6C8(sp, 0x266, &sp2034);
    }
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    func_0016D698(0, sp, &sp2034);
    PackAD__4GIFSll(sp, 0x4C, 0);
    PackAD__4GIFSll(sp, 0x46, 1);
    if (arg2 != 8) {
        var_s1_2 = 0;
        func_0016D698(2, sp, &sp2034);
        PackAD__4GIFSll(sp, 6, 0xD500 << 0x13);
        PackAD__4GIFSll(sp, 0x14, 1);
        PackAD__4GIFSll(sp, 0x16, B_003E1330);
        PackAD__4GIFSll(sp, 0x3F, 0);
        PackAD__4GIFSll(sp, 0x47, 0x31001);
        PackAD__4GIFSll(sp, 1, (0xC040 << 0x11) | 0x8080);
        PackAD__4GIFSll(sp, 0x42, 0x44);
        PackAD__4GIFSll(sp, 0, 0x156);
        AddPrimList__4GIFSiUl(sp, 4, 0x5353);
        var_a1 = 0 * 0x10;
        do {
            ListUV__4GIFSii(sp, var_a1 | 8, 8);
            temp_s0 = var_s1_2 + 0x20;
            GIFS_ListXYZ(sp, (var_s1_2 + 0x700) * 0x10, 0x7900, 0);
            ListUV__4GIFSii(sp, (temp_s0 * 0x10) | 8, 0xE08);
            temp_a1 = (var_s1_2 + 0x720) * 0x10;
            var_s1_2 = temp_s0;
            GIFS_ListXYZ(sp, temp_a1, 0x8700, 0);
            var_a1 = var_s1_2 * 0x10;
        } while (var_s1_2 < 0x200);
    }
    EndPrim__4GIFSi(sp, 1);
    func_0016D698(-1, sp, &sp2034);
    temp_a2 = (u32) (spC - sp4) >> 4;
    if ((s32) temp_a2 >= 0x100) {
        AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 0xFFU, sp4);
        AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, ((u32) (spC - sp4) >> 4) - 0xFF, sp4 + 0xFF0);
    } else {
        AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, temp_a2, sp4);
    }
    AddVifFlusha__4VIFS(arg0);
    AddVifMscal__4VIFSPv(arg0, 0x1C48);
    AddVifFlusha__4VIFS(arg0);
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3E38) != 0) {
        if (g_2dea4c == &B_002DEA50) {
            AddDmaCall__4DMASP2QW(arg0, &B_002DF940);
        } else {
            AddDmaCall__4DMASP2QW(arg0, &B_002DFA80);
        }
        AddVifBaseOffset__4VIFSii(arg0, 0x32, 0x1E7);
    }
    EndDmaCnt__4DMAS(arg0);
    if (arg2 != 8) {
        M2C_FIELD(&g_2deb70, s32 *, 0) = 0;
        M2C_FIELD(&g_2deb70, s32 *, 4) = 0;
    }
}
