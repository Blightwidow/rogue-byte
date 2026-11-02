#include "sly2.h"
struct DMAS { char pad[0xC]; unsigned *pb; };
struct W40 { int w[16]; };
struct W30 { int w[12]; };
struct PKT { int a; float b; unsigned c; int d; };
struct OBJA4 { char pad[0xC8]; char *pad2; };
struct OBJ8 { char pad[0xA4]; int shift; };
struct SRC { char pad[0x18]; int count; void *src; };
struct DMC {
    int pad0; int mode; OBJ8 *obj8; char pad0c[8]; SRC *psrc; int i18; int i1C; void *p20;
};
struct IN { float f0, f4, f8, fC, f10, f14; };
struct OUT { int pad0; int i4; float f8; int iC; float rest[8]; };
struct B0 { char pad[0xC8]; struct B1 *p; };
struct B1 { char pad[0x9C]; float f9C; float fA0; };
struct OBJ8x { char pad[0xC8]; B1 *p; };
struct LOCAL {
    float f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C;
};
extern "C" {
void CopyAqw__FPvT0i(void *, void *, int);
PKT *OnGameLoad__FP4GAME();
extern DMAS g_2dea28;
}
static inline void CopyWords(int *d, int *s, int n)
{
    for (int i = 0; i < n; i += 4) {
        int w0 = s[i], w1 = s[i + 1], w2 = s[i + 2], w3 = s[i + 3];
        d[i] = w0; d[i + 1] = w1; d[i + 2] = w2; d[i + 3] = w3;
    }
}
static inline void AddDirect(DMAS *d, void *src, int count)
{
    *d->pb = count | 0x50000000;
    d->pb += 1;
    CopyAqw__FPvT0i(d->pb, src, count);
    d->pb += count * 4;
}
static inline void AddUnpack(DMAS *d, unsigned hdr, int *src, int nwords)
{
    *d->pb = hdr;
    d->pb += 1;
    CopyWords((int *)d->pb, src, nwords);
    d->pb += nwords;
}
static inline void Align3(DMAS *d)
{
    while (((unsigned)d->pb & 0xF) != 0xC) {
        *d->pb = 0;
        d->pb += 1;
    }
}
static inline void PadEnd(DMAS *d)
{
    while ((unsigned)d->pb & 0xF) {
        *d->pb = 0;
        d->pb += 1;
    }
}
extern "C" void DrawMovieBitmapCharacter(DMC *pdmc, IN *pin, OUT *pout)
{
    void *cond;
    switch (pdmc->mode) {
    case 6:
        cond = pdmc->psrc;
        break;
    case 7:
        cond = (void *)pdmc->i1C;
        break;
    default:
        return;
    }
    if (cond != 0) {
        LOCAL loc;
        memset(&loc, 0, 0x40);
        OBJ8x *po = (OBJ8x *)pdmc->obj8;
        loc.f0 = pin->f0 * 0.8f;
        loc.f4 = pin->f4 * 0.45454547f;
        loc.f10 = pin->f8 * 0.8f;
        loc.f14 = pin->fC * 0.45454547f;
        loc.f20 = pin->f10 * 0.8f + po->p->f9C + 786432.0f;
        loc.f24 = pin->f14 * 0.45454547f + po->p->fA0 + 786432.0f;
        loc.f3C = 1.0f;
        loc.f28 = 1.0f;
        pout->iC = 0x7FFF;
        pout->i4 = 0;
        unsigned *tag = g_2dea28.pb;
        *(long *)tag = 0x10000000;
        g_2dea28.pb += 4;
        *g_2dea28.pb = 0x6C04C000;
        g_2dea28.pb += 1;
        CopyWords((int *)g_2dea28.pb, (int *)&loc, 16);
        g_2dea28.pb += 0x10;
        AddUnpack(&g_2dea28, 0x6C03C004, (int *)pout, 12);
        int count;
        void *src;
        if (pdmc->mode == 6) {
            SRC *ps = pdmc->psrc;
            src = ps->src;
            count = ps->count;
            Align3(&g_2dea28);
        } else {
            count = pdmc->i1C;
            Align3(&g_2dea28);
            src = pdmc->p20;
        }
        AddDirect(&g_2dea28, src, count);
        PadEnd(&g_2dea28);
        *tag = *tag | (((int)g_2dea28.pb - (int)tag) >> 4) - 1;
        *(long *)g_2dea28.pb = 0x60000000;
        g_2dea28.pb += 4;
        PKT *p = OnGameLoad__FP4GAME();
        p->a = 0x15;
        p->c = (unsigned)tag & 0x0FFFFFFF;
        p->b = pout->f8 + (float)(pdmc->obj8->shift << 18);
        p->d = pdmc->mode == 6 ? pdmc->i1C : pdmc->i18;
    }
}
