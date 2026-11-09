#include "sly2.h"
struct M4 { QW row[4]; };
struct XF { M4 local; M4 world; char pad[0xA4 - 0x80]; int generation; };
struct G_1F40A0 { char pad[0x3D58]; int counter; };
extern G_1F40A0 B_003DD490;
struct PHYS { char pad[0xDC]; int link; };
#include "so.h"
extern "C" {
void InvertMatrix4Affine(M4 *, M4 *);
void __ml__FRC7MATRIX4T0(M4 *, const M4 *, const M4 *);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
void DiscardSoXps(SO *);
void WakeXf(SO *, XF *);
void func_001F3900(SO *);
QW PosLoWorld(SO *);
void *PpathzoneFindPos(QW, int);
void func_001F37C8(SO *, void *);
}
extern "C" void TranslateSoToPos(SO *pso, QW pos)
{
    if (pso->pxfLinear == 0)
        return;
    struct LOCALS { M4 target, rootInLinear, parent, a, b, c, d, e; } l;
    M4 *pworld = &pso->pxfRoot->world;
    __as__6VECTORG9VU_VECTOR(&l.target.row[3], pos);
    l.target.row[0] = pworld->row[0];
    l.target.row[1] = pworld->row[1];
    l.target.row[2] = pworld->row[2];
    ((float *)&l.target)[7] = 0;
    ((float *)&l.target)[11] = 0;
    ((float *)&l.target)[3] = 0;
    ((float *)&l.target)[15] = 1.0f;
    M4 *pa = &l.a;
    InvertMatrix4Affine(&l.b, &pso->pxfLinear->world);
    __ml__FRC7MATRIX4T0(pa, &l.b, &pso->pxfRoot->world);
    l.rootInLinear = l.a;
    XF *pparent = *(XF **)((char *)pso->pxfLinear + 0xA0);
    if (pparent != 0) {
        l.parent = pparent->world;
    } else {
        float *pp = (float *)&l.parent;
        memset(pp, 0, 0x40);
        pp[15] = 1.0f;
        pp[10] = 1.0f;
        pp[5] = 1.0f;
        ((float *)&l.parent)[0] = 1.0f;
    }
    M4 *pc = &l.c;
    InvertMatrix4Affine(&l.d, &l.parent);
    __ml__FRC7MATRIX4T0(pc, &l.d, &l.target);
    InvertMatrix4Affine(&l.e, &l.rootInLinear);
    __ml__FRC7MATRIX4T0(&l.b, pc, &l.e);
    l.a = l.b;
    XF *pxf = pso->pxfLinear;
    __as__6VECTORG9VU_VECTOR(&pxf->local.row[3], l.b.row[3]);
    ((float *)&pxf->local)[15] = 1.0f;
    int gen = ++B_003DD490.counter;
    pso->pxfLinear->generation = gen;
    pso->UpdateXfWorldHierarchy();
    DiscardSoXps(pso);
    WakeXf(pso, pso->pxfLinear);
    func_001F3900(pso);
    void *pregion = 0;
    if (pso->pphys != 0)
        pregion = (void *)pso->pphys->link;
    if (pregion != 0)
        func_001F37C8(pso, PpathzoneFindPos(PosLoWorld(pso), 1));
}
