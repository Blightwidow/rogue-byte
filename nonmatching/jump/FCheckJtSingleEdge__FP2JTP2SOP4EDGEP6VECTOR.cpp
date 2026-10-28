// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct JT;
struct EDGE { unsigned short v0; unsigned short v1; unsigned short f0; unsigned short f1; };
struct SUBG { int pad0; char *verts; int pad8; char *faces; };
struct SO { char pad[0x90]; SUBG sub; };
struct FACE { float nx; float ny; float nz; float pad; float pad2[4]; };
extern QW g_2a2da0;
static inline void asm_nop(float &value) { asm volatile("nop" : "+f" (value)); }
struct LOC { float ex, ey, ez, ew; float sx, sy, sz, sw; QW tmp; } __attribute__((aligned(16)));

extern "C" int FCheckJtSingleEdge__FP2JTP2SOP4EDGEP6VECTOR(JT *pjt, SO *pso, EDGE *pedge, QW *pnormal)
{
    LOC l;
    SUBG *psub = &pso->sub;
    FACE *pfaceA = (FACE *)(psub->faces + (pedge->f0 << 5));
    FACE *pfaceB = (FACE *)(psub->faces + (pedge->f1 << 5));
    FACE *pwall;
    int result = 0;
    float ey, ex, length, zero, dot;
    QW fallback;
    char *verts;
    QW qresult;
    if (0.7f < pfaceA->nz) {
        float low = 0.55f;
        float bz = pfaceB->nz;
        asm volatile("nop" : "+f" (low));
        if (bz < low) {
            pwall = pfaceB;
            goto found;
        }
    }
    {
        float low = 0.55f;
        float az = pfaceA->nz;
        asm volatile("nop" : "+f" (low));
        if (az < low) {
            float high2 = 0.7f;
            float bz = pfaceB->nz;
            asm volatile("nop" : "+f" (high2));
            if (high2 < bz) {
                pwall = pfaceA;
                goto found;
            }
        }
        return result;
    }
found:
    verts = psub->verts;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW v3 asm("vf3");
    asm volatile("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf1, vf2" : "=j" (v1) : "m" (*(QW *)(verts + (pedge->v1 << 4))), "m" (*(QW *)(verts + (pedge->v0 << 4))));
    l.sz = 0.0f;
    asm("sqc2 vf1, %0" : "=m" (l.ex) : "j" (v1));
    ey = l.ey;
    ex = l.ex;
    fallback = g_2a2da0;
    l.sy = ex;
    l.sx = -ey;
    asm("lqc2 vf3, %1" : "=j" (v3) : "m" (l.sx));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\t.word 0x4A0103BD\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (v1), "=j" (v2) : "j" (v3));
    register int bits asm("$2");
    asm("qmfc2.ni %0, vf1" : "=r" (bits) : "j" (v1));
    asm("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (bits));
    if (length < 0.0001f) {
        asm("qmtc2.ni %1, vf3" : "=j" (v3) : "r" (fallback));
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf3, vf3, Q" : "+j" (v3) : "j" (v1));
    }
    asm("sqc2 vf3, %0" : "=m" (l.sx) : "j" (v3));
    zero = 0.0f;
    asm("lqc2 vf1, %2\n\tvmul.xyz vf1, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1), "=j" (v2) : "m" (*(QW *)pwall), "j" (v3));
    asm("qmfc2.ni %0, vf1" : "=r" (bits) : "j" (v1));
    asm("mtc1 %1, %0\n\tnop" : "=f" (dot) : "r" (bits));
    if (dot < zero) {
        float minusOne = -1.0f;
        asm volatile("nop" : "+f" (minusOne));
        register int scaleBits asm("$2");
        asm("mfc1 %0, %1" : "=r" (scaleBits) : "f" (minusOne));
        asm("qmtc2.ni %2, vf1\n\tvmulx.xyzw vf2, vf3, vf1x" : "=j" (v1), "=j" (v2) : "r" (scaleBits), "j" (v3));
        asm("sqc2 vf1, %0" : "=m" (l.tmp) : "j" (v1));
        asm("sqc2 vf2, %0" : "=m" (l.sx) : "j" (v2));
    }
    *pnormal = *(QW *)&l.sx;
    result = 1;
    return result;
}
