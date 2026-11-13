// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DMAS { char pad[0xC]; unsigned *pb; };
struct COLOR4 { char c[4]; };
struct MT {
    char pad0[0x6C];
    float f6C, f70, f74, f78;
    float rxScale, ryScale, dyLine, gScale; /* names as in CMovieText_DrawAffine */
    int i8C, i90, i94;
};
struct ARGS { float x, y, z, w; COLOR4 color; int i14; int i18; };
/* the affine block handed to CMovieText_BuildGsMatrix, cleared on construction: retail computes its
   address afresh for memset and for the call, which an inline constructor gives */
struct ZEROAFF { float f[8]; ZEROAFF() { memset(this, 0, sizeof(*this)); } };
struct PKT { int a; float b; unsigned c; int d; };
struct GPARAM { int a; int b; float f8; int c; QW q10; QW q20; };
extern "C" {
void CMovieText_SetBaseColor(MT *, COLOR4 *);
void CMovieText_BuildGsMatrix(MT *, float *, float *);
void CMovieText_DrawGlyphs(MT *, float *, GPARAM *);
void CopyAqw__FPvT0i(void *, void *, int);
PKT *OnGameLoad__FP4GAME();
extern char B_002DF010[];
extern char B_00442210[];
extern QW g_2a2e10;
extern QW g_2a2e20;
extern DMAS g_2dea28;

static inline void DmaSkip(DMAS *d) { d->pb += 4; }
static inline void AddFlush(DMAS *d) { *d->pb = 0x11000000; d->pb += 1; }
static inline void AddDirect(DMAS *d, void *src, int count)
{
    while (((unsigned)d->pb & 0xF) != 0xC) {
        *d->pb = 0;
        d->pb += 1;
    }
    *d->pb = 0x50000000 | count;
    d->pb += 1;
    CopyAqw__FPvT0i(d->pb, src, count);
    d->pb += count * 4;
}
static inline void PadEnd(DMAS *d)
{
    while ((unsigned)d->pb & 0xF) {
        *d->pb = 0;
        d->pb += 1;
    }
}

void CMovieText_Draw(MT *pmt, ARGS *pargs, int arg2)
{
    if (pargs != 0) {
        pmt->f6C = pargs->x;
        pmt->f70 = pargs->y;
        pmt->f74 = pargs->z;
        pmt->f78 = pargs->w;
        pmt->i90 = pargs->i14;
        pmt->i8C = pargs->i18;
        pmt->i94 = arg2;
        COLOR4 color = pargs->color;
        CMovieText_SetBaseColor(pmt, &color);
        ZEROAFF aff;
        aff.f[3] = pmt->ryScale * pmt->gScale;
        aff.f[4] = pmt->f6C;
        aff.f[0] = pmt->rxScale * pmt->gScale;
        aff.f[5] = pmt->f70 + pmt->dyLine * pmt->ryScale;
        float matrix[16];
        CMovieText_BuildGsMatrix(pmt, matrix, aff.f);
        GPARAM param;
        param.q10 = g_2a2e10;
        param.q20 = g_2a2e20;
        param.f8 = 16.0f;
        CMovieText_DrawGlyphs(pmt, matrix, &param);
        unsigned *tag = g_2dea28.pb;
        *(long *)tag = 0x10000000;
        DmaSkip(&g_2dea28);
        AddFlush(&g_2dea28);
        AddDirect(&g_2dea28, B_00442210, 3);
        AddDirect(&g_2dea28, B_002DF010, 0x25);
        AddFlush(&g_2dea28);
        PadEnd(&g_2dea28);
        *tag = *tag | (((int)g_2dea28.pb - (int)tag) >> 4) - 1;
        *(long *)g_2dea28.pb = 0x60000000;
        g_2dea28.pb += 4;
        PKT *p = OnGameLoad__FP4GAME();
        p->a = 0x15;
        p->b = (float)(pmt->i94 << 18);
        p->c = (unsigned)tag & 0x0FFFFFFF;
        p->d = 0;
    }
}
}
