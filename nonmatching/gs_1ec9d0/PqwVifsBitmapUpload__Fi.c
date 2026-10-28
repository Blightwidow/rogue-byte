#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddPrimEnd__4GIFS(void *);                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifDirectRefs__4VIFSiP2QWi(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK AddVifDirect__4VIFSiP2QWi(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK AddVifFlush__4VIFS(M2C_UNK *);              /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, M2C_UNK, M2C_UNK *); /* extern */
s32 AllocZpr(void *, u16);                          /* extern */
M2C_UNK BuildBmpGifs__FP3BMPiP4GIFS(void *, s32, void *); /* extern */
M2C_UNK BuildBmpTex0__FP3BMPi(void *, s32);         /* extern */
M2C_UNK BuildClutGifs__FP4CLUTiP4GIFS(void *, s32, void *); /* extern */
M2C_UNK BuildClutTex2__FP4CLUTi(void *, s32);       /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, M2C_UNK, M2C_UNK, s32 *); /* extern */
M2C_UNK Detach__4DMASPiPP2QW(void *, s32 *, s32 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK PackAD__4GIFSll(void *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK Reset__4DMAS(void *);                       /* extern */
M2C_UNK __4GIFS(void *);                            /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
extern s32 B_003DCF98;
extern s32 B_003DCF9C;
extern s32 B_003DCFF0;
extern s32 B_003DCFF4;
extern s32 B_003DCFF8;
extern s32 B_003DCFFC;

s32 PqwVifsBitmapUpload__Fi(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK spC;
    M2C_UNK sp30;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s32 sp110;
    s32 sp114;
    s32 sp118;
    s32 sp11C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s4;
    void *temp_s1;
    void *temp_s1_2;

    var_s2 = 0;
    __4GIFS(sp);
    sp118 = 0;
    __4VIFS(&sp30);
    sp11C = M2C_FIELD(arg0, s32 *, 4);
    CStackFrame_Construct(&sp60);
    AllocStack__4DMASi(&sp30, (((B_003DCF9C * 3) + B_003DCF98) * 0xA) + 4, B_003DCF9C, 0xA);
    AddDmaCnt__4DMAS(&sp30);
    AddVifFlush__4VIFS(&sp30);
    if (B_003DCFF8 > 0) {
        temp_v0 = B_003DCFFC;
        do {
            temp_s1 = temp_v0 + (var_s2 << 5);
            if (M2C_FIELD(temp_s1, u8 *, 4) == arg1) {
                Reset__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, 0xA, &sp70);
                temp_v0_2 = AllocZpr(arg0, M2C_FIELD(temp_s1, u16 *, 0xA));
                BuildClutTex2__FP4CLUTi(temp_s1, temp_v0_2);
                BuildClutGifs__FP4CLUTiP4GIFS(temp_s1, temp_v0_2, sp);
                M2C_FIELD(spC, s64 *, -0x10) = (s64) (M2C_FIELD(spC, s64 *, -0x10) | 0x8000);
                Detach__4DMASPiPP2QW(sp, &sp110, &sp114);
                AddVifDirect__4VIFSiP2QWi(&sp30, sp110, sp114, 0);
                AddVifDirectRefs__4VIFSiP2QWi(&sp30, M2C_FIELD(temp_s1, s32 *, 0x10), M2C_FIELD(temp_s1, s32 *, 0xC), 0);
            }
            var_s2 += 1;
        } while (var_s2 < B_003DCFF8);
    }
    var_s2_2 = 0;
    if (B_003DCFF0 > 0) {
        var_s4 = 0;
        do {
            temp_s1_2 = B_003DCFF4 + var_s4;
            if (arg1 == M2C_FIELD(temp_s1_2, u8 *, 4)) {
                Reset__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, 0xA, &sp70);
                temp_v0_3 = AllocZpr(arg0, M2C_FIELD(temp_s1_2, u16 *, 0xE));
                BuildBmpTex0__FP3BMPi(temp_s1_2, temp_v0_3);
                BuildBmpGifs__FP3BMPiP4GIFS(temp_s1_2, temp_v0_3, sp);
                M2C_FIELD(spC, s64 *, -0x10) = (s64) (M2C_FIELD(spC, s64 *, -0x10) | 0x8000);
                Detach__4DMASPiPP2QW(sp, &sp110, &sp114);
                AddVifDirect__4VIFSiP2QWi(&sp30, sp110, sp114, 0);
                AddVifDirectRefs__4VIFSiP2QWi(&sp30, M2C_FIELD(temp_s1_2, s32 *, 0x18), M2C_FIELD(temp_s1_2, s32 *, 0x14), 0);
            }
            var_s2_2 += 1;
            var_s4 += 0x28;
        } while (var_s2_2 < B_003DCFF0);
    }
    if (sp11C < M2C_FIELD(arg0, s32 *, 4)) {
        Reset__4DMAS(sp);
        AllocStatic__4DMASiP2QW(sp, 0xA, &sp70);
        AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
        PackAD__4GIFSll(sp, 0x3F, 0);
        AddPrimEnd__4GIFS(sp);
        Detach__4DMASPiPP2QW(sp, &sp110, &sp114);
        AddVifDirect__4VIFSiP2QWi(&sp30, sp110, sp114, 0);
        AddVifFlush__4VIFS(&sp30);
        EndDmaCnt__4DMAS(&sp30);
        AddDmaRet__4DMAS(&sp30);
        DMAS_DetachCopyPermanent(&sp30, 0, 0, &sp118);
    }
    CStackFrame_Destructor(&sp60, 2);
    return sp118;
}
