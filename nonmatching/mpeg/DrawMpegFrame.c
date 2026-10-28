#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(void *);                   /* extern */
M2C_UNK AddDmaEnd__4DMAS(void *);                   /* extern */
M2C_UNK AddPrimEnd__4GIFS(void *);                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, M2C_UNK, s32); /* extern */
f32 CRichText_DyWrap(M2C_UNK *, M2C_UNK);           /* extern */
M2C_UNK CTextBox_SetHorizontalJust(f32 *, M2C_UNK); /* extern */
M2C_UNK CTextBox_SetPos(f32 *, f32, f32);           /* extern */
M2C_UNK CTextBox_SetSize(f32 *, f32, f32);          /* extern */
M2C_UNK CTextBox_SetTextColor(f32 *, s32 *);        /* extern */
M2C_UNK CTextBox_SetVerticalJust(f32 *, M2C_UNK);   /* extern */
M2C_UNK Detach__4DMASPiPP2QW(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK Draw__9CRichTextP8CTextBoxT1P4GIFS(M2C_UNK *, f32 *, M2C_UNK, void *); /* extern */
f32 DxMaxLine__9CRichText(M2C_UNK *);               /* extern */
M2C_UNK FillScreenRect__FiiiiffffP4GIFS(M2C_UNK *, void *, f32, f32, f32, f32); /* extern */
M2C_UNK PackAD__4GIFSll(void *, M2C_UNK, s32);      /* extern */
M2C_UNK PackUV__4GIFSii(void *, s32, s32);          /* extern */
M2C_UNK PackXYZF__4GIFSiiii(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 PchzFromStringTable(M2C_UNK *, s32);            /* extern */
M2C_UNK PopScaling__5CFont(s32);                    /* extern */
M2C_UNK PushScaling__5CFontff(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK __4GIFS(void *);                            /* extern */
M2C_UNK __9CRichTextPcP5CFont(M2C_UNK *, s32, s32); /* extern */
extern s32 B_002DE760;
extern M2C_UNK B_003E1C20;

void DrawMpegFrame(void *arg0) {
    char sp[0x400];
    M2C_UNK sp1A4;
    M2C_UNK sp1A8;
    M2C_UNK sp1AC;
    M2C_UNK sp30;
    f32 sp1A0;
    s32 sp1C0;
    M2C_UNK sp1D0;
    f32 temp_f0;
    f32 temp_f21;

    __4GIFS(sp);
    AllocStatic__4DMASiP2QW(sp, 0x200, M2C_FIELD(arg0, s32 *, 0x110) + 0x41BC00);
    AddDmaCnt__4DMAS(sp);
    AddPrimPack__4GIFSiiUl(sp, 6, 1, 0xE);
    PackAD__4GIFSll(sp, 6, ((0xAA80 << 0x12) | 0xC600) * 4);
    PackAD__4GIFSll(sp, 0x14, 0x61);
    PackAD__4GIFSll(sp, 8, 5);
    PackAD__4GIFSll(sp, 0x42, 0x44);
    PackAD__4GIFSll(sp, 0x47, 0x31001);
    AddPrimPack__4GIFSiiUl(sp, 0x116, 4, 0x4343);
    PackUV__4GIFSii(sp, 8, 8);
    PackXYZF__4GIFSiiii(sp, 0x7000, 0x7900, 0);
    PackUV__4GIFSii(sp, (M2C_FIELD(arg0, s32 *, 0x118) * 0x10) | 8, (M2C_FIELD(arg0, s32 *, 0x11C) * 0x10) | 8);
    PackXYZF__4GIFSiiii(sp, 0x9000, 0x8700, 0);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 0x61, 0);
    AddPrimEnd__4GIFS(sp);
    AddDmaEnd__4DMAS(sp);
    Detach__4DMASPiPP2QW(sp, 0, 0);
    if (M2C_FIELD(arg0, void **, 0x104) != NULL) {
        AllocStatic__4DMASiP2QW(sp, 0x200, M2C_FIELD(arg0, s32 *, 0x110) + 0x41DC00);
        AddDmaCnt__4DMAS(sp);
        PushScaling__5CFontff(B_002DE760, 0x3F4CCCCD, 0x3F4CCCCD);
        __9CRichTextPcP5CFont(&sp30, PchzFromStringTable(&B_003E1C20, M2C_FIELD(M2C_FIELD(arg0, void **, 0x104), s32 *, 4)), B_002DE760);
        temp_f21 = CRichText_DyWrap(&sp30, 0x43A00000);
        temp_f0 = DxMaxLine__9CRichText(&sp30);
        CTextBox_SetPos(&sp1A0, 320.0f - (temp_f0 * 0.5f), 476.80002f - temp_f21);
        CTextBox_SetSize(&sp1A0, temp_f0, temp_f21);
        sp1C0 = 0xFFC0C0C0;
        CTextBox_SetTextColor(&sp1A0, &sp1C0);
        CTextBox_SetHorizontalJust(&sp1A0, 0);
        CTextBox_SetVerticalJust(&sp1A0, 0);
        M2C_FIELD(&sp1A0, s32 *, 0x14) = 1;
        sp1C0 = 0x80000000;
        sp1D0 = M2C_UNALIGNED32(sp1C0);
        FillScreenRect__FiiiiffffP4GIFS(&sp1D0, sp, sp1A0, sp1A4, sp1A0 + sp1A8, sp1A4 + sp1AC);
        Draw__9CRichTextP8CTextBoxT1P4GIFS(&sp30, &sp1A0, 0, sp);
        PopScaling__5CFont(B_002DE760);
        AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
        PackAD__4GIFSll(sp, 0x61, 0);
        AddPrimEnd__4GIFS(sp);
        AddDmaEnd__4DMAS(sp);
        Detach__4DMASPiPP2QW(sp, 0, 0);
    }
}
