// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct EDGE { unsigned short ipos0; unsigned short ipos1; unsigned short pad4; unsigned short isurf; struct EDGE *next; };
struct SURF { QW plane; EDGE *edges; int pad14; unsigned flags; char pad1C[4]; };
struct BSPN { int pad0; int pad4; SURF *psurf; };
struct GEOM { char pad0[0x6C]; int cbsp; char pad70[4]; BSPN *absp; char pad78[0x94 - 0x78]; QW *apos; SURF *asurf; };
struct SBI { QW pos; QW plane; int kind; unsigned ptr; char pad28[8]; };
struct LSG { QW a; QW b; QW c; QW d; QW e; float u0; float u1; char pad48[4]; unsigned psurf0; unsigned psurf1; char pad54[0xC]; };
struct PENDING { int ipos; unsigned plane0; unsigned plane1; unsigned plane2; QW pos; QW plane; };
struct ALLOCREQ { int cb; int align; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(void *);
int PruneBsp__FP3BSPP6VECTORfPP3BSP(BSPN *, int, QW, int *, BSPN **, float);
int ClsgClipEdgeToBsp(BSPN *, BSPN *, QW, QW, int, void *);
void InitPlaneFromNormalPos(void *, QW, QW);
int PcgtPointInCbsp(BSPN *, int, QW);
void bevy_physics_sphere_1a9108(BSPN *, int, void *, QW, float, int);
}
struct FRAME { PENDING pending[0x100]; char construct[0x10]; ALLOCREQ req; char padReq[8]; LSG lsg[16]; QW spill; QW nrm; QW center; };
extern "C" int CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(QW center, float radius, GEOM *geom, int cbspLimit, int cbspPruned, BSPN *abspPruned, int csbiMax, SBI *asbi)
{
    int csbi = 0;
    int cpending = 0;
    int csbiAfterFaces = 0;
    FRAME frame;
    CStackFrame_Construct(frame.construct);
    if (csbiMax > 0) {
        if (abspPruned == 0) {
            int cscratch = geom->cbsp;
            if (cscratch > 0x1555)
                cscratch = 0x1555;
            frame.req.cb = cscratch * 12;
            frame.req.align = 0x10;
            abspPruned = (BSPN *)PvAllocStackImpl__Fi(&frame.req);
            BSPN *pnext = abspPruned;
            int prune = PruneBsp__FP3BSPP6VECTORfPP3BSP(geom->absp, cbspLimit, center, &cscratch, &pnext, radius);
            if (prune == 0)
                goto inside;
            if (prune == 1)
                goto done;
            cbspPruned = pnext - abspPruned;
        }
        {
            BSPN *plast = abspPruned + (cbspPruned - 1);
            for (int ibsp = cbspPruned - 1; ibsp >= 0; ibsp--)
                abspPruned[ibsp].psurf->flags |= 0x10;
            for (int ibsp = cbspPruned - 1; ibsp >= 0; ibsp--) {
                SURF *psurf = abspPruned[ibsp].psurf;
                unsigned flags = psurf->flags;
                if ((flags & 0x10) == 0 || (flags & 0x40) != 0)
                    continue;
                psurf->flags = flags | 0x40;
                float negRadius = -radius;
                QW near;
                int junk;
                QW far;
                asm("mfc1 %1, %5\n\tqmtc2.ni %1, vf2\n\tlqc2 vf1, %3\n\tqmtc2.ni %4, vf4\n\tvadda.xyzw ACC, vf0, vf4\n\tvmaddx.xyzw vf2, vf1, vf2x\n\tsqc2 vf2, %2\n\tqmfc2.ni %0, vf2" : "=r" (near), "=&r" (junk), "=m" (frame.spill) : "m" (psurf->plane), "r" (center), "f" (radius));
                far = near;
                int clsg = ClsgClipEdgeToBsp(plast, plast, near, far, 16, frame.lsg);
                int ilsg = 0;
                int found = 0;
                for (; ilsg < clsg; ilsg++) {
                    unsigned hit = 1.0f < frame.lsg[ilsg].u0 + frame.lsg[ilsg].u1 ? frame.lsg[ilsg].psurf0 : frame.lsg[ilsg].psurf1;
                    if (hit == (unsigned)psurf) {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    continue;
                if (csbi < csbiMax) {
                    SBI *psbi = &asbi[csbi];
                    csbi++;
                    psbi->pos = far;
                    psbi->plane = psurf->plane;
                    psbi->kind = 6;
                    psbi->ptr = (unsigned)psurf;
                    if (csbi >= csbiMax)
                        goto clear;
                }
                psurf->flags |= 0x80;
            }
        }
    }
    goto done;
clear:
    for (int ibsp = cbspPruned - 1; ibsp >= 0; ibsp--)
        abspPruned[ibsp].psurf->flags &= ~0xF0u;
inside:
done:
    CStackFrame_Destructor(frame.construct, 2);
    return csbi;
}
