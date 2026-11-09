#include "sly2.h"
#include "xf.h"
struct G_1F40A0 { char pad[0x3D58]; int counter; };
extern G_1F40A0 B_003DD490;
struct PHYS { char pad[0xDC]; int link; };
#include "so.h"
extern "C" {
void InvertMatrix4Affine(MATRIX4 *, MATRIX4 *);
void __ml__FRC7MATRIX4T0(MATRIX4 *, const MATRIX4 *, const MATRIX4 *);
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
    struct LOCALS { MATRIX4 target, rootInLinear, parent, a, b, c, d, e; } l;
    MATRIX4 *pworld = &pso->pxfRoot->matWorld;
    __as__6VECTORG9VU_VECTOR(&l.target.row[3], pos);
    l.target.row[0] = pworld->row[0];
    l.target.row[1] = pworld->row[1];
    l.target.row[2] = pworld->row[2];
    ((float *)&l.target)[7] = 0;
    ((float *)&l.target)[11] = 0;
    ((float *)&l.target)[3] = 0;
    ((float *)&l.target)[15] = 1.0f;
    MATRIX4 *pa = &l.a;
    InvertMatrix4Affine(&l.b, &pso->pxfLinear->matWorld);
    __ml__FRC7MATRIX4T0(pa, &l.b, &pso->pxfRoot->matWorld);
    l.rootInLinear = l.a;
    XF *pparent = pso->pxfLinear->pxfParent;
    if (pparent != 0) {
        l.parent = pparent->matWorld;
    } else {
        float *pp = (float *)&l.parent;
        memset(pp, 0, 0x40);
        pp[15] = 1.0f;
        pp[10] = 1.0f;
        pp[5] = 1.0f;
        ((float *)&l.parent)[0] = 1.0f;
    }
    MATRIX4 *pc = &l.c;
    InvertMatrix4Affine(&l.d, &l.parent);
    __ml__FRC7MATRIX4T0(pc, &l.d, &l.target);
    InvertMatrix4Affine(&l.e, &l.rootInLinear);
    __ml__FRC7MATRIX4T0(&l.b, pc, &l.e);
    l.a = l.b;
    XF *pxf = pso->pxfLinear;
    __as__6VECTORG9VU_VECTOR(&pxf->mat.row[3], l.b.row[3]);
    ((float *)&pxf->mat)[15] = 1.0f;
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
