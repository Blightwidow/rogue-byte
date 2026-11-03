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
    QW row0 = source->row[0];
    QW centre = alo->centre;
    mat.row[0] = row0;
    QW row1 = source->row[1];
    mat.row[1] = row1;
    QW row2 = source->row[2];
    mat.row[2] = row2;
    QW row3 = source->row[3];
    QW posCentre;
    asm("vmulax.xyz ACC, %1, %2x\n\tvmadday.xyz ACC, %3, %2y\n\tvmaddaz.xyz ACC, %4, %2z\n\tvmaddw.xyz %0, %5, vf0w"
        : "=j"(posCentre) : "0"(row0), "j"(centre), "j"(row1), "j"(row2), "j"(row3));
    mat.row[3] = row3;
    float scale = GMaxAxisScale(&mat);
    QW pos = posCentre;
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
