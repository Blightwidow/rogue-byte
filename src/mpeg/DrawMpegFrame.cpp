// SPDX-License-Identifier: GPL-3.0-or-later
struct GIFS { char pad[0x30]; };
struct QW;
struct CFont;
struct RGBA {
    unsigned char r, g, b, a;
    RGBA() {}
    RGBA(unsigned int rgba) { *(unsigned int *)this = rgba; }
};
struct CRichText { char pad[0x170]; };
struct CTextBox;
struct SUBTITLE { int unk0; int istring; };
struct CMpeg { char pad0[0x104]; SUBTITLE *psubtitle; char pad108[0x110 - 0x108]; int ibDma; char pad114[0x118 - 0x114]; int uFrame; int vFrame; };
extern "C" {
GIFS *__4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
void AddDmaCnt__4DMAS(GIFS *);
void AddDmaEnd__4DMAS(GIFS *);
void Detach__4DMASPiPP2QW(GIFS *, int *, QW **);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void AddPrimEnd__4GIFS(GIFS *);
void PackAD__4GIFSll(GIFS *, long, long);
void PackUV__4GIFSii(GIFS *, int, int);
void PackXYZF__4GIFSiiii(GIFS *, int, int, int, int);
void PushScaling__5CFontff(CFont *, float, float);
void PopScaling__5CFont(CFont *);
void __9CRichTextPcP5CFont(CRichText *, char *, CFont *);
char *PchzFromStringTable(void *, int);
float CRichText_DyWrap(CRichText *, float);
float DxMaxLine__9CRichText(CRichText *);
void CTextBox_SetPos(CTextBox *, float, float);
void CTextBox_SetSize(CTextBox *, float, float);
void CTextBox_SetTextColor(CTextBox *, RGBA *);
void CTextBox_SetHorizontalJust(CTextBox *, int);
void CTextBox_SetVerticalJust(CTextBox *, int);
void FillScreenRect__FiiiiffffP4GIFS(RGBA, GIFS *, float, float, float, float);
void Draw__9CRichTextP8CTextBoxT1P4GIFS(CRichText *, CTextBox *, CTextBox *, GIFS *);
extern CFont *B_002DE760;
extern char B_003E1C20[];
}

// Retail never keeps the text box's address in a register while it is set up: every setter call rebuilds
// `addiu $a0, $sp, 0x1A0`, the text colour 0xFFC0C0C0 is loaded into $s0 before PushScaling and stored to a
// stack temporary only after SetSize. That is an inlined constructor: its `this` and its own frame (the
// colour at offset 0) are substituted by sp-relative addresses, and its colour parameter goes through a
// register that the scheduler hoists across the calls. A plain sequence of calls on a local keeps the
// address in a callee-saved register instead (score 33).
struct CTextBox {
    float x;
    float y;
    float dx;
    float dy;
    RGBA rgba;
    int jh;
    int jv;
    CTextBox(float xNew, float yNew, float dxNew, float dyNew, unsigned int rgbaText)
    {
        CTextBox_SetPos(this, xNew, yNew);
        CTextBox_SetSize(this, dxNew, dyNew);
        RGBA rgbaColor(rgbaText);
        CTextBox_SetTextColor(this, &rgbaColor);
        CTextBox_SetHorizontalJust(this, 0);
        CTextBox_SetVerticalJust(this, 0);
    }
};

extern "C" {
// The subtitle box: `ptb` is a separate pointer because retail computes $s0 = sp+0x1A0 only after the
// constructor and uses it for the justification store and Draw, while FillScreenRect reads the box from
// the stack directly. The background colour is a scoped local (its slot 0x1C0 is the constructor's freed
// one) copied for the by-value argument (lwl/lwr to 0x1D0). __4GIFS returns `this` (its disassembly):
// declaring it void moves the first load from $v1 to $v0.
void DrawMpegFrame(CMpeg *self)
{
    GIFS gifs;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, 0x200, (QW *)(self->ibDma + 0x41BC00));
    AddDmaCnt__4DMAS(&gifs);
    AddPrimPack__4GIFSiiUl(&gifs, 6, 1, 0xE);
    PackAD__4GIFSll(&gifs, 6, ((0xAA80L << 18) | 0xC600) << 2);
    PackAD__4GIFSll(&gifs, 0x14, 0x61);
    PackAD__4GIFSll(&gifs, 8, 5);
    PackAD__4GIFSll(&gifs, 0x42, 0x44);
    PackAD__4GIFSll(&gifs, 0x47, 0x31001);
    AddPrimPack__4GIFSiiUl(&gifs, 0x116, 4, 0x4343);
    PackUV__4GIFSii(&gifs, 8, 8);
    PackXYZF__4GIFSiiii(&gifs, 0x7000, 0x7900, 0, 0);
    PackUV__4GIFSii(&gifs, (self->uFrame << 4) | 8, (self->vFrame << 4) | 8);
    PackXYZF__4GIFSiiii(&gifs, 0x9000, 0x8700, 0, 0);
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    PackAD__4GIFSll(&gifs, 0x61, 0);
    AddPrimEnd__4GIFS(&gifs);
    AddDmaEnd__4DMAS(&gifs);
    Detach__4DMASPiPP2QW(&gifs, 0, 0);
    if (self->psubtitle != 0) {
        AllocStatic__4DMASiP2QW(&gifs, 0x200, (QW *)(self->ibDma + 0x41DC00));
        AddDmaCnt__4DMAS(&gifs);
        PushScaling__5CFontff(B_002DE760, 0.8f, 0.8f);
        CRichText richText;
        __9CRichTextPcP5CFont(&richText, PchzFromStringTable(B_003E1C20, self->psubtitle->istring), B_002DE760);
        float dy = CRichText_DyWrap(&richText, 320.0f);
        float dx = DxMaxLine__9CRichText(&richText);
        CTextBox textBox(320.0f - dx * 0.5f, 476.80002f - dy, dx, dy, 0xFFC0C0C0);
        CTextBox *ptb = &textBox;
        ptb->jh = 1;
        {
            RGBA rgbaBack(0x80000000);
            FillScreenRect__FiiiiffffP4GIFS(rgbaBack, &gifs, textBox.x, textBox.y, textBox.x + textBox.dx, textBox.y + textBox.dy);
        }
        Draw__9CRichTextP8CTextBoxT1P4GIFS(&richText, ptb, 0, &gifs);
        PopScaling__5CFont(B_002DE760);
        AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
        PackAD__4GIFSll(&gifs, 0x61, 0);
        AddPrimEnd__4GIFS(&gifs);
        AddDmaEnd__4DMAS(&gifs);
        Detach__4DMASPiPP2QW(&gifs, 0, 0);
    }
}
}
