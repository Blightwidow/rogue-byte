struct QW;

#define GS_TEST(ate, atst, aref, afail, date, datm, zte, ztst)                                                          \
    ((unsigned long)(ate) | ((unsigned long)(atst) << 1) | ((unsigned long)(aref) << 4) |                                \
     ((unsigned long)(afail) << 12) | ((unsigned long)(date) << 14) | ((unsigned long)(datm) << 15) |                    \
     ((unsigned long)(zte) << 16) | ((unsigned long)(ztst) << 17))
#define GS_ALPHA(a, b, c, d, fix)                                                                                         \
    ((unsigned long)(a) | ((unsigned long)(b) << 2) | ((unsigned long)(c) << 4) | ((unsigned long)(d) << 6) |             \
     ((unsigned long)(fix) << 32))


class DMAS {
public:
    int w[12];
    void AllocStatic(int, QW *);
    void EndDmaCnt();
    void Clear();
};

class GIFS : public DMAS {
public:
    GIFS();
    void AddPrimBulk(int, int, int, unsigned long, QW **);
    void AddPrimPack(int, int, unsigned long);
    void PackAD(long, long);
    void PackRGBA(unsigned);
    void PackSTQ(float, float, float);
    void EndPrim(int);
};

struct DMAREF_1EB960 {
    int cqw;
    QW *aqw;
};

struct RGBA_1EB960 {
    unsigned char r, g, b, a;
};

struct SHD_1EB960 {
    int pad0;
    unsigned char kind;
    unsigned char grf;
    char pad6[6];
    unsigned char rgba[4];
    RGBA_1EB960 rgbaTex;
    char pad14[4];
    int ishd;
    char pad1C[4];
    DMAREF_1EB960 *admaref;
    char pad24[8];
};

extern "C" {
extern int D_003DCFE8;
extern SHD_1EB960 *D_003DCFEC;
extern unsigned D_002DE18C;
void GIFS_AddPrimTag(GIFS *, int, int, int, int, int);
void func_001EA750(int, int, GIFS *);
}

void FillShaders(int grfshd) {

    for (int ishd = 0; ishd < D_003DCFE8; ishd++) {
        SHD_1EB960 *pshd = &D_003DCFEC[ishd];
        DMAREF_1EB960 *pdmaref = pshd->admaref;
        switch (pshd->kind) {
        case 0:
        case 4:
        case 5:
        case 6: {
            GIFS gifs;
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            gifs.AddPrimBulk(0x7C, 0, 4, 0x4F12, 0);
            gifs.AddPrimBulk(0x7D, 0, 4, 0x4F12, 0);
            gifs.AddPrimPack(0, 1, 0xE);
            func_001EA750(pshd->ishd, 0, &gifs);
            if (pshd->grf & 0x20) {
                unsigned long test = (pshd->grf & 4) ? 0x13001 : 0x11001;
                test |= (pshd->kind != 0) ? 0x20000 : 0x60000;
                gifs.PackAD(0x47, test);
                gifs.PackAD(0x42, 0);
            } else if (pshd->grf & 0x10) {
                gifs.PackAD(0x47, GS_TEST(1, (pshd->kind == 0) ? 5 : 0, 0x7E, (pshd->grf & 4) ? 3 : 1, 0, 0, 1,
                                          (pshd->kind != 0) ? 1 : 3));
                {
                    unsigned long sel = (pshd->grf & 1) ? 2 : 0;
                    gifs.PackAD(0x42, GS_ALPHA(1, sel, 0, 0, 0));
                }
            } else if (pshd->grf & 0x80) {
                gifs.PackAD(0x47, 0x77000);
                gifs.PackAD(0x42, 0x54);
            } else {
                gifs.PackAD(0x47, GS_TEST(1, (pshd->kind == 0) ? 5 : 0, 0x7E, (pshd->grf & 4) ? 3 : 1, 0, 0, 1,
                                          (pshd->kind != 0) ? 1 : 3));
                {
                unsigned long sel = (pshd->grf & 1) ? 2 : 1;
                gifs.PackAD(0x42, GS_ALPHA(0, sel, 0, 1, 0));
            }
            }
            gifs.PackAD(0x3D, D_002DE18C);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            break;
        }
        case 3: {
            GIFS gifs;
            unsigned char rgba[4];
            RGBA_1EB960 rgbaTex;
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            if (pshd->grf & 2) {
                gifs.AddPrimBulk(0x7C, 0, 4, 0x4F12, 0);
                gifs.AddPrimBulk(0x7D, 0, 4, 0x4F12, 0);
                gifs.AddPrimPack(0, 1, 0xE);
                func_001EA750(pshd->ishd, 0, &gifs);
                gifs.PackAD(0x47, 0x71001);
                {
                unsigned long sel = (pshd->grf & 1) ? 2 : 1;
                gifs.PackAD(0x42, GS_ALPHA(0, sel, 0, 1, 0));
            }
                gifs.PackAD(0x3D, D_002DE18C);
            } else {
                gifs.AddPrimBulk(0x4C, 0, 4, 0x4FFF, 0);
                gifs.AddPrimBulk(0x4D, 0, 4, 0x4FFF, 0);
                gifs.AddPrimPack(0, 1, 0xE);
                gifs.PackAD(0x47, 0x71001);
                gifs.PackAD(0x42, 0x6A);
                gifs.PackAD(1, 0x100000020L);
            }
            gifs.EndPrim(1);
            pdmaref++;
            gifs.EndDmaCnt();
            gifs.Clear();
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            pdmaref++;
            gifs.AddPrimBulk(0x4C, 0, 4, 0x4FFF, 0);
            gifs.AddPrimBulk(0x4D, 0, 4, 0x4FFF, 0);
            gifs.AddPrimPack(0, 1, 0xE);
            gifs.PackAD(0x47, 0x71001);
            gifs.PackAD(0x42, 0x6A);
            gifs.PackAD(1, 0x180002000L);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            gifs.Clear();
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            pdmaref++;
            gifs.AddPrimBulk(0x6C, 0, 4, 0x4FFF, 0);
            gifs.AddPrimBulk(0x6D, 0, 4, 0x4FFF, 0);
            gifs.AddPrimPack(0, 5, 0x12EEE);
            gifs.PackAD(0x47, 0x75001);
            {
                unsigned long sel = (pshd->grf & 1) ? 2 : 1;
                gifs.PackAD(0x42, GS_ALPHA(0, sel, 0, 1, 0));
            }
            gifs.PackAD(0x3D, D_002DE18C);
            gifs.PackSTQ(0.0f, 0.0f, 1.0f);
            rgba[0] = (pshd->rgba[0] + 1) >> 1;
            rgba[1] = (pshd->rgba[1] + 1) >> 1;
            rgba[2] = (pshd->rgba[2] + 1) >> 1;
            rgba[3] = (pshd->rgba[3] + 1) >> 1;
            gifs.PackRGBA(*(unsigned *)rgba);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            gifs.Clear();
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            gifs.AddPrimBulk(0x4D, 0, 1, 4, 0);
            rgbaTex = pshd->rgbaTex;
            gifs.AddPrimPack(0, 1, 0xE);
            {
                unsigned long sel = (pshd->grf & 1) == 0 ? 1 : 2;
                gifs.PackAD(0x42, GS_ALPHA(0, sel, 0, 1, 0));
            }
            {
                unsigned long rgb = (unsigned long)rgbaTex.r | ((unsigned long)rgbaTex.g << 8) | ((unsigned long)rgbaTex.b << 16);
                unsigned long rgbaq;
                if (pshd->grf & 2) {
                    rgbaq = rgb | ((unsigned long)rgbaTex.a << 24) | 0x100000000L;
                } else {
                    rgbaq = rgb | 0x100000000L;
                }
                gifs.PackAD(1, rgbaq);
            }
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            break;
        }
        case 2: {
            GIFS gifs;
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            GIFS_AddPrimTag(&gifs, 0x44, 0, 2, 0x41, 1);
            GIFS_AddPrimTag(&gifs, 0x45, 0, 2, 0x41, 1);
            gifs.AddPrimPack(0, 1, 0xE);
            if (pshd->grf & 8) {
                gifs.PackAD(0x47, 0x71001);
            } else {
                gifs.PackAD(0x47, 0x75001);
            }
            gifs.PackAD(0x42, 0x8000000062L);
            pdmaref++;
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            gifs.Clear();
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            GIFS_AddPrimTag(&gifs, 0x44, 0, 2, 0x41, 1);
            GIFS_AddPrimTag(&gifs, 0x45, 0, 2, 0x41, 1);
            gifs.AddPrimPack(0, 1, 0xE);
            if (pshd->grf & 8) {
                gifs.PackAD(0x47, 0x31001);
            } else {
                gifs.PackAD(0x47, 0x35001);
            }
            gifs.PackAD(0x42, 0x8000000068L);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            break;
        }
        case 1: {
            GIFS gifs;
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            gifs.AddPrimBulk(0x7C, 0, 4, 0x4F12, 0);
            gifs.AddPrimBulk(0x7D, 0, 4, 0x4F12, 0);
            gifs.AddPrimPack(0, 1, 0xE);
            func_001EA750(pshd->ishd, 1, &gifs);
            if (pshd->grf & 0x80) {
                gifs.PackAD(0x47, 0x77000);
                gifs.PackAD(0x42, 0x54);
            } else {
                gifs.PackAD(0x47, (pshd->grf & 4) ? 0x737EB : 0x717EB);
                {
                unsigned long sel = (pshd->grf & 1) ? 2 : 1;
                gifs.PackAD(0x42, GS_ALPHA(0, sel, 0, 1, 0));
            }
            }
            gifs.PackAD(0x3D, D_002DE18C);
            pdmaref++;
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            gifs.Clear();
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            gifs.AddPrimBulk(0x7C, 0, 4, 0x41F2, 0);
            gifs.AddPrimBulk(0x7D, 0, 4, 0x41F2, 0);
            gifs.AddPrimPack(0, 1, 0xE);
            func_001EA750(pshd->ishd, 0, &gifs);
            if (pshd->grf & 0x80) {
                gifs.PackAD(0x47, 0x57000);
                gifs.PackAD(0x42, 0x58);
            } else {
                gifs.PackAD(0x47, 0x51001);
                gifs.PackAD(0x42, 0x48);
            }
            gifs.PackAD(0x3D, 0);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            break;
        }
        case 7: {
            GIFS gifs;
            if (!(pshd->grf & 0x20)) {
                gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
                pdmaref++;
                gifs.AddPrimBulk(0x7C, 0, 4, 0x41F2, 0);
                gifs.AddPrimBulk(0x7D, 0, 4, 0x41F2, 0);
                gifs.AddPrimPack(0, 1, 0xE);
                func_001EA750(pshd->ishd, 2, &gifs);
                gifs.PackAD(0x47, 0x5000D);
                gifs.PackAD(0x42, 0x40);
                gifs.PackAD(0x3D, 0);
                gifs.EndPrim(1);
                gifs.EndDmaCnt();
                gifs.Clear();
            }
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            pdmaref++;
            gifs.AddPrimBulk(0x7C, 0, 4, 0x4F12, 0);
            gifs.AddPrimBulk(0x7D, 0, 4, 0x4F12, 0);
            gifs.AddPrimPack(0, 1, 0xE);
            func_001EA750(pshd->ishd, 1, &gifs);
            gifs.PackAD(0x47, 0x53001);
            {
                unsigned long sel = (pshd->grf & 1) ? 2 : 1;
                gifs.PackAD(0x42, GS_ALPHA(0, sel, 0, 1, 0));
            }
            gifs.PackAD(0x3D, D_002DE18C);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            gifs.Clear();
            gifs.AllocStatic(pdmaref->cqw, pdmaref->aqw);
            gifs.AddPrimBulk(0x7C, 0, 4, 0x41F2, 0);
            gifs.AddPrimBulk(0x7D, 0, 4, 0x41F2, 0);
            gifs.AddPrimPack(0, 1, 0xE);
            func_001EA750(pshd->ishd, 0, &gifs);
            gifs.PackAD(0x47, 0x53001);
            gifs.PackAD(0x42, 0x48);
            gifs.PackAD(0x3D, 0);
            gifs.EndPrim(1);
            gifs.EndDmaCnt();
            break;
        }
        }
    }
}
