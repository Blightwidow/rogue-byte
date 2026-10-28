#include "sly2.h"
struct M4 { QW row[4]; };
struct RTE { char pad0[0x10]; unsigned long low : 32; unsigned long type : 4; unsigned long high : 28; unsigned child; };
struct XFR { char pad[0xA4]; int generation; };
struct VT { char pad[0xF8]; short delta; short index; M4 *(*fn)(char *); };
struct ALO { char pad0[0xC]; VT *vt; char pad1[0x2D - 0x10]; unsigned char layer; char pad2[0x38 - 0x2E]; float distance; char pad3[0x40 - 0x3C]; unsigned grf; char pad4[0x60 - 0x44]; XFR *xf; char pad5[0x90 - 0x64]; QW centre; float radius; char pad6[0x140 - 0xA4]; int generation; RTE *rte; };
struct SWX { char pad[1]; };
extern SWX B_003DD490;
extern "C" {
float GMaxAxisScale(M4 *);
RTE *AddSphereToRenderTree(float, float, SWX *, QW, int);
void AddAloToRenderTree(ALO *alo)
{
    M4 *source = alo->vt->fn((char *)alo + alo->vt->delta);
    M4 mat;
    QW posCentre;
    asm("lqc2 vf4, %1\n\tlqc2 vf5, %2\n\tsqc2 vf4, %0" : "=m" (mat.row[0]) : "m" (source->row[0]), "m" (alo->centre));
    asm("lqc2 vf3, %1\n\tsqc2 vf3, %0" : "=m" (mat.row[1]) : "m" (source->row[1]));
    asm("lqc2 vf2, %1\n\tsqc2 vf2, %0" : "=m" (mat.row[2]) : "m" (source->row[2]));
    asm("lqc2 vf1, %2\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf4, vf1, vf0w\n\tsqc2 vf4, %0\n\tsqc2 vf1, %1" : "=m" (posCentre), "=m" (mat.row[3]) : "m" (source->row[3]));
    float scale = GMaxAxisScale(&mat);
    QW pos;
    asm volatile("lqc2 vf4, %0" : : "m" (posCentre));
    asm("qmfc2.ni %0, vf4" : "=r" (pos));
    RTE *rte = AddSphereToRenderTree(scale * alo->radius, alo->distance, &B_003DD490, pos, alo->layer);
    alo->rte = rte;
    if (rte != 0) {
        rte->type = 4;
        alo->rte->child = (unsigned)alo;
        unsigned grf = alo->grf;
        if (((grf ^ 1) & 1) != 0)
            *(unsigned *)grf |= 0x80;
        else
            alo->grf = grf | 0x80;
        alo->generation = alo->xf->generation;
    }
}
}
