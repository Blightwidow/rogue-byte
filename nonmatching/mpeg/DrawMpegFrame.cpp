struct GIFS { char b[0x30]; };
struct CFont;
struct CRichText { char b[0x170]; };
struct PackedInt { int v; } __attribute__((packed));
struct MPEG { char pad0[0x104]; int *ptext; char pad1[8]; int ibDma; char pad2[4]; int u0; int v0; };
extern "C" {
void __4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW__FPvii(GIFS *, int, int);
void AddDmaCnt__4DMAS__FPv(GIFS *);
void AddDmaEnd__4DMAS__FPv(GIFS *);
void Detach__4DMASPiPP2QW__FPvii(GIFS *, int, int);
void AddPrimPack__4GIFSiiUl__FPviii(GIFS *, int, int, long);
void AddPrimEnd__4GIFS(GIFS *);
void PackAD__4GIFSll__FPvii(GIFS *, int, long);
void PackUV__4GIFSii__FPvii(GIFS *, int, int);
void PackXYZF__4GIFSiiii__FPviii(GIFS *, int, int, int, int);
void PushScaling__5CFontff__Fiii(CFont *, float, float);
void PopScaling__5CFont__Fi(CFont *);
void __9CRichTextPcP5CFont(CRichText *, char *, CFont *);
char *PchzFromStringTable__FPii(void *, int);
float CRichText_DyWrap__FPii(CRichText *, float);
float DxMaxLine__9CRichText__FPi(CRichText *);
void CTextBox_SetPos(float *, float, float);
void CTextBox_SetSize(float *, float, float);
void CTextBox_SetTextColor(float *, int *);
void CTextBox_SetHorizontalJust(float *, int);
void CTextBox_SetVerticalJust(float *, int);
void FillScreenRect__FiiiiffffP4GIFS(PackedInt *, GIFS *, float, float, float, float);
void Draw__9CRichTextP8CTextBoxT1P4GIFS__FPiPfiPv(CRichText *, float *, int, GIFS *);
extern CFont *B_002DE760;
extern char B_003E1C20[];
}
#define MANGLE(n) n
void DrawMpegFrame__FPv(MPEG *self)
{
    struct { GIFS gifs; CRichText rt; float box[8]; int color; int pad[3]; PackedInt color2; } l;
    __4GIFS(&l.gifs);
    AllocStatic__4DMASiP2QW__FPvii(&l.gifs, 0x200, self->ibDma + 0x41BC00);
    AddDmaCnt__4DMAS__FPv(&l.gifs);
    AddPrimPack__4GIFSiiUl__FPviii(&l.gifs, 6, 1, 0xE);
    PackAD__4GIFSll__FPvii(&l.gifs, 6, (long)(((0xAA80 << 18) | 0xC600) * 4));
    PackAD__4GIFSll__FPvii(&l.gifs, 0x14, 0x61);
    PackAD__4GIFSll__FPvii(&l.gifs, 8, 5);
    PackAD__4GIFSll__FPvii(&l.gifs, 0x42, 0x44);
    PackAD__4GIFSll__FPvii(&l.gifs, 0x47, 0x31001);
    AddPrimPack__4GIFSiiUl__FPviii(&l.gifs, 0x116, 4, 0x4343);
    PackUV__4GIFSii__FPvii(&l.gifs, 8, 8);
    PackXYZF__4GIFSiiii__FPviii(&l.gifs, 0x7000, 0x7900, 0, 0);
    PackUV__4GIFSii__FPvii(&l.gifs, (self->u0 << 4) | 8, (self->v0 << 4) | 8);
    PackXYZF__4GIFSiiii__FPviii(&l.gifs, 0x9000, 0x8700, 0, 0);
    AddPrimPack__4GIFSiiUl__FPviii(&l.gifs, 0, 1, 0xE);
    PackAD__4GIFSll__FPvii(&l.gifs, 0x61, 0);
    AddPrimEnd__4GIFS(&l.gifs);
    AddDmaEnd__4DMAS__FPv(&l.gifs);
    Detach__4DMASPiPP2QW__FPvii(&l.gifs, 0, 0);
    if (self->ptext != 0) {
        AllocStatic__4DMASiP2QW__FPvii(&l.gifs, 0x200, self->ibDma + 0x41DC00);
        AddDmaCnt__4DMAS__FPv(&l.gifs);
        PushScaling__5CFontff__Fiii(B_002DE760, 0.8f, 0.8f);
        __9CRichTextPcP5CFont(&l.rt, PchzFromStringTable__FPii(B_003E1C20, self->ptext[1]), B_002DE760);
        float dy = CRichText_DyWrap__FPii(&l.rt, 320.0f);
        float dx = DxMaxLine__9CRichText__FPi(&l.rt);
        CTextBox_SetPos(l.box, 320.0f - dx * 0.5f, 476.80002f - dy);
        CTextBox_SetSize(l.box, dx, dy);
        l.color = 0xFFC0C0C0;
        CTextBox_SetTextColor(l.box, &l.color);
        CTextBox_SetHorizontalJust(l.box, 0);
        CTextBox_SetVerticalJust(l.box, 0);
        float *pbox = l.box;
        *(int *)&pbox[5] = 1;
        l.color = 0x80000000;
        l.color2 = *(PackedInt *)&l.color;
        FillScreenRect__FiiiiffffP4GIFS(&l.color2, &l.gifs, l.box[0], l.box[1], l.box[0] + l.box[2], l.box[1] + l.box[3]);
        Draw__9CRichTextP8CTextBoxT1P4GIFS__FPiPfiPv(&l.rt, pbox, 0, &l.gifs);
        PopScaling__5CFont__Fi(B_002DE760);
        AddPrimPack__4GIFSiiUl__FPviii(&l.gifs, 0, 1, 0xE);
        PackAD__4GIFSll__FPvii(&l.gifs, 0x61, 0);
        AddPrimEnd__4GIFS(&l.gifs);
        AddDmaEnd__4DMAS__FPv(&l.gifs);
        Detach__4DMASPiPP2QW__FPvii(&l.gifs, 0, 0);
    }
}
