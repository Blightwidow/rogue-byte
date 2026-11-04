// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct MRSG { float g0; float g4; };
struct ASEG_1380F0 { char pad[0x74]; float gDuration; };
struct ENTRY_1380F0 { float w; ASEG_1380F0 *paseg; };
struct BLEND_1380F0 { char pad[0xC0]; int cb; int c; char *a; };
float GModPositive__Fff(float, float);
static inline ENTRY_1380F0 *Entry(BLEND_1380F0 *p, int i) { return (ENTRY_1380F0 *)(p->a + i * p->cb); }
extern "C" void CalculateBlendAmrsg__FiiPviiP4MRSGPf(BLEND_1380F0 *pblend, int ib, int cmrsg, MRSG *amrsg, float *pgSum)
{
    float sum = 0.0f;
    int i;
    if (cmrsg == 0) {
        if (pgSum != 0) {
            for (i = 0; i < pblend->c; i++) {
                ENTRY_1380F0 *pentry = Entry(pblend, i);
                if (pentry->w != 0.0f)
                    sum += pentry->paseg->gDuration * pentry->w;
            }
            *pgSum = sum;
        }
        return;
    }
    for (i = 0; i < cmrsg; i++) {
        amrsg[i].g4 = 0.0f;
        for (int j = 0; j < pblend->c; j++) {
            ENTRY_1380F0 *pentry = Entry(pblend, j);
            if (pentry->w != 0.0f)
                amrsg[i].g4 += ((MRSG *)((char *)pentry + ib))[i].g4 * pentry->w;
        }
        sum += amrsg[i].g4;
    }
    int fFirst = 1;
    float g;
    float gFirst;
    for (i = 0; i < pblend->c; i++) {
        ENTRY_1380F0 *pentry = Entry(pblend, i);
        if (pentry->w != 0.0f) {
            if (fFirst) {
                fFirst = 0;
                g = ((MRSG *)((char *)pentry + ib))->g0 / pentry->paseg->gDuration;
                gFirst = g;
            } else {
                float d = ((MRSG *)((char *)pentry + ib))->g0 / pentry->paseg->gDuration - gFirst;
                if (d <= -0.5f)
                    d += 1.0f;
                else if (d > 0.5f)
                    d -= 1.0f;
                g += d * pentry->w;
            }
        }
    }
    amrsg[0].g0 = GModPositive__Fff(g, 1.0f) * sum;
    for (i = 1; i < cmrsg; i++) {
        float f = amrsg[i - 1].g0 + amrsg[i - 1].g4;
        amrsg[i].g0 = f;
        if (sum <= f)
            amrsg[i].g0 = f - sum;
    }
    if (pgSum != 0)
        *pgSum = sum;
}
