#include "m2c_macros.h"

M2C_UNK AddDmaCall__4DMASP2QW(s32, M2C_UNK *);      /* extern */
M2C_UNK AddDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK AddPrimList__4GIFSiUl(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifBaseOffset__4VIFSii(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifFlush__4VIFS(s32);                    /* extern */
M2C_UNK AddVifFlusha__4VIFS(s32);                   /* extern */
M2C_UNK AddVifMscal__4VIFSPv(s32, M2C_UNK);         /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, u32, s32); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK EndPrim__4GIFSi(void *, M2C_UNK);           /* extern */
M2C_UNK EnsureVu1Code__FP4VIFSPvT1(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK GIFS_ListXYZ(void *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PackAD__4GIFSll(void *, M2C_UNK, s64);      /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK __4GIFS(void *);                            /* extern */
M2C_UNK func_0016D698(M2C_UNK, void *, s32 *);      /* extern */
M2C_UNK func_0016D6C8(void *, M2C_UNK, s32 *);      /* extern */
extern M2C_UNK B_002DF800;
extern s32 B_003E12C8;
extern M2C_UNK RO_0025C1C0;
extern M2C_UNK RO_0025E040;
extern M2C_UNK g_2deb70;

void func_0016DA48(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp4;
    M2C_UNK spC;
    M2C_UNK sp30;
    s32 sp1030;
    s32 sp1034;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    EnsureVu1Code__FP4VIFSPvT1(&RO_0025C1C0, &RO_0025E040);
    AddDmaCnt__4DMAS(arg0);
    if ((arg2 != 7) && (B_003E12C8 != 0)) {
        AddVifFlush__4VIFS(arg0);
        AddDmaCall__4DMASP2QW(arg0, &B_002DF800);
        AddVifBaseOffset__4VIFSii(arg0, 0x32, 0x1E7);
    }
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 5, 5, 0x1B);
    sp1034 = sp1030;
    __4GIFS(sp);
    AllocStatic__4DMASiP2QW(sp, 0x100, &sp30);
    if (arg2 != 7) {
        func_0016D6C8(sp, 0x299, &sp1034);
    }
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    func_0016D698(0, sp, &sp1034);
    if ((arg1 == 7) || (arg2 != 7)) {
        PackAD__4GIFSll(sp, 0x4C, 0x807F8000 << 0x11);
    } else {
        PackAD__4GIFSll(sp, 0x4C, 0x80FF0000 << 0x10);
    }
    PackAD__4GIFSll(sp, 0x46, 0);
    PackAD__4GIFSll(sp, 0x47, 0x31001);
    if (arg1 == 7) {
        PackAD__4GIFSll(sp, 1, (0x8000 << 0x11) | 0x7E00);
    } else {
        PackAD__4GIFSll(sp, 1, (0x8000 << 0x11) | 0x3E00);
    }
    PackAD__4GIFSll(sp, 0, 6);
    var_s2 = 0x7200;
    var_s1 = 0x7000;
    AddPrimList__4GIFSiUl(sp, 2, 0x55);
    var_s0 = 0x1E0;
    do {
        GIFS_ListXYZ(sp, var_s1, 0x7900, 0);
        var_s1 += 0x200;
        GIFS_ListXYZ(sp, var_s2, 0x8700, 0);
        var_s0 -= 0x20;
        var_s2 += 0x200;
    } while (var_s0 >= 0);
    if ((arg1 == 8) && (arg2 == 7)) {
        AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
        func_0016D698(0, sp, &sp1034);
        PackAD__4GIFSll(sp, 0x4C, 0x807F8000 << 0x11);
    }
    EndPrim__4GIFSi(sp, 1);
    func_0016D698(-1, sp, &sp1034);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, (u32) (spC - sp4) >> 4, sp4);
    AddVifFlusha__4VIFS(arg0);
    AddVifMscal__4VIFSPv(arg0, 0x1AA0);
    AddVifFlusha__4VIFS(arg0);
    EndDmaCnt__4DMAS(arg0);
    *((((arg1 ^ 8) != 0) ? 0 : 4) + &g_2deb70) = 1;
}
