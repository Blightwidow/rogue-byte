// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct REQ { int size; int align; };
struct CGV;
struct CGVL { CGV *pcgv; int unk; };
struct CGV { VECTOR pos; int ccgvl; CGVL *acgvl; int pad[2]; };
struct CGVDEF { VECTOR pos; int ccgv; int aicgv[3]; };
struct CGF { CGV *apcgv[3]; };
struct CGFDEF { int aicgv[3]; };
struct CGE { float g0; float g1; int unk; unsigned short s0; unsigned short s1; };
struct CG { int ccgv; CGV *acgv; int ccgf; CGF *acgf; int ccge; CGE *acge; };
struct PATHZONE { char pad[0xE0]; CG cg; char pad2[0x114 - 0xF8]; int ipathzone; };
struct GLOBALS { char pad[0x3D70]; int cpathzone; };
extern CGVDEF D_002C0C10[];
extern CGFDEF D_002C0C90[];
extern GLOBALS B_003DD490;
extern "C" void *PvAllocSwClearImpl__Fi(REQ *);
extern "C" void *PvAllocSwImpl__Fi(REQ *);
void HookupCg(CG *);

// Sqrt: sqrt.s with an early-clobber output (=&f). Measured on every sqrt.s user (16 sources): none gets worse, six get closer, two reach 0 (a third holds VU0 asm and stays out);
// retail's helper keeps the result out of the operand's register. The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float SqrtF(float value)
{
    float result;
    asm volatile("sqrt.s %0, %1" : "=&f"(result) : "f" (value));
    return result;
}

// Retail builds the default graph: 4 vertices from D_002C0C10 (each with its edge list), 2 faces from D_002C0C90, one edge whose
// weights are +/- sqrt(2)/2. In the edge-list loop retail computes j*8 into $a1 and loads pcgv->acgvl into $a0, then adds them:
// the element address is formed first and stored through, which is what a pointer to the CGVL element (pcgvl) gives; indexing
// acgvl[j].pcgv directly swaps $a0/$a1 (score 2).
void SetupDefaultPathzone(PATHZONE *ppathzone)
{
    REQ req;
    int i;
    int j;
    ppathzone->cg.ccgv = 4;
    req.size = 0x80;
    req.align = 0x10;
    ppathzone->cg.acgv = (CGV *)PvAllocSwClearImpl__Fi(&req);
    for (i = 0; i < ppathzone->cg.ccgv; i++) {
        CGVDEF *pdef = &D_002C0C10[i];
        CGV *pcgv = &ppathzone->cg.acgv[i];
        pcgv->pos = pdef->pos;
        int ccgv = pdef->ccgv;
        pcgv->ccgvl = ccgv;
        req.size = ccgv * 8 + 8;
        req.align = 0x10;
        pcgv->acgvl = (CGVL *)PvAllocSwImpl__Fi(&req);
        for (j = 0; j < pcgv->ccgvl; j++) {
            CGVL *pcgvl = &pcgv->acgvl[j];
            pcgvl->pcgv = &ppathzone->cg.acgv[pdef->aicgv[j]];
        }
    }
    ppathzone->cg.ccgf = 2;
    req.size = 0x18;
    req.align = 0x10;
    ppathzone->cg.acgf = (CGF *)PvAllocSwClearImpl__Fi(&req);
    int icgf;
    for (icgf = 0; icgf < ppathzone->cg.ccgf; icgf++) {
        CGV **ppcgv = ppathzone->cg.acgf[icgf].apcgv;
        int *picgv = D_002C0C90[icgf].aicgv;
        for (i = 0; i < 3; i++)
            *ppcgv++ = &ppathzone->cg.acgv[*picgv++];
    }
    ppathzone->cg.ccge = 1;
    req.size = 0x10;
    req.align = 0x10;
    CGE *pcge = (CGE *)PvAllocSwClearImpl__Fi(&req);
    ppathzone->cg.acge = pcge;
    float g = SqrtF(2.0f) * 0.5f;
    pcge->s0 = 0xC001;
    pcge->s1 = 0xC000;
    pcge->unk = 0;
    pcge->g0 = g;
    pcge->g1 = -g;
    HookupCg(&ppathzone->cg);
    ppathzone->ipathzone = ++B_003DD490.cpathzone;
}
