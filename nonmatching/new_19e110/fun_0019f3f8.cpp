// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct XFH;
struct MV18 { char pad[0x18]; short delta; short index; void (*fn)(void *, void *, QW *, int, float); };
struct MEMB { char pad[0x20]; MV18 *vt; };
struct LVT { char pad[0x100]; short delta; short index; XFH *(*fn)(void *, int); };
struct LOV { char pad[0xC]; LVT *vt; };
struct TARGET { LOV *plo; MEMB *pmember; XFH **ppxfFixed; int pad; float px; float py; float pz; float pw; } __attribute__((aligned(16)));
struct JTH { char pad[0x240]; QW grab; };
extern "C" QW ConvertXfPos(XFH *, XFH *, QW);
extern "C" void PredictXfTransform(XFH *, XFH *, float, QW *, void *);

extern "C" QW func_0019F3F8(float dt, JTH *pjt, TARGET *ptarget)
{
    struct { QW aim; QW mat[4]; QW local; } l;
    XFH *pxf;
    if (ptarget->pmember) {
        MEMB *pm = ptarget->pmember;
        pm->vt->fn((char *)pm + pm->vt->delta, pjt, &l.aim, 0, ptarget->px);
        LOV *plo = ptarget->plo;
        pxf = plo->vt->fn((char *)plo + plo->vt->delta, 0);
        l.local = ConvertXfPos(0, pxf, l.aim);
    } else {
        pxf = 0;
        if (ptarget->ppxfFixed)
            pxf = *ptarget->ppxfFixed;
        l.local = *(QW *)&ptarget->px;
    }
    register QW r2 asm("vf2");
    if (pxf && 0.0f < dt) {
        PredictXfTransform(pxf, 0, dt, l.mat, 0);
        asm("lqc2 vf4, %1\n\tlqc2 vf3, %2\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tlqc2 vf5, %5\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w" : "=j" (r2) : "m" (l.mat[0]), "m" (l.mat[1]), "m" (l.mat[2]), "m" (l.mat[3]), "m" (l.local));
    } else {
        QW v = ConvertXfPos(pxf, 0, l.local);
        asm("qmtc2.ni %1, vf2" : "=j" (r2) : "r" (v));
    }
    if (ptarget->pmember == 0)
        asm("lqc2 vf1, %1\n\tvsub.xyzw vf2, vf2, vf1" : "+j" (r2) : "m" (pjt->grab));
    QW result;
    asm("qmfc2.ni %0, vf2" : "=r" (result) : "j" (r2));
    return result;
}
