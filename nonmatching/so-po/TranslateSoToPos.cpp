#include "sly2.h"
struct M4 { QW row[4]; };
struct VT { char pad[0x90]; short delta; short index; void (*fn)(void *); };
struct XF { char pad0[0x30]; QW rowLocal3; char pad1[0x40 - 0x40]; };
struct XFN { M4 local; M4 world; char pad[0xA4 - 0x80]; int generation; };
struct PHYS { char pad[0xDC]; int link; };
struct SO { char pad0[0xC]; VT *vt; char pad1[0x58 - 0x10]; XFN *plinear; int pad2; XFN *proot; char pad3[0xE8 - 0x64]; PHYS *pphys; };
extern "C" {
extern char B_003DD490[];
void InvertMatrix4Affine(M4 *, M4 *);
void __ml__FRC7MATRIX4T0(M4 *, const M4 *, const M4 *);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
void DiscardSoXps(SO *);
void WakeXf(SO *, XFN *);
void func_001F3900(SO *);
QW PosLoWorld(SO *);
void *PpathzoneFindPos(QW, int);
void func_001F37C8(SO *, void *);
}
extern "C" void TranslateSoToPos(SO *pso, QW pos)
{
    if (pso->plinear == 0)
        return;
    struct LOCALS { M4 target, rootInLinear, parent, a, b, c, d, e; } l;
    M4 *pworld = &pso->proot->world;
    __as__6VECTORG9VU_VECTOR(&l.target.row[3], pos);
    l.target.row[0] = pworld->row[0];
    l.target.row[1] = pworld->row[1];
    l.target.row[2] = pworld->row[2];
    ((float *)&l.target)[7] = 0;
    ((float *)&l.target)[11] = 0;
    ((float *)&l.target)[3] = 0;
    ((float *)&l.target)[15] = 1.0f;
    InvertMatrix4Affine(&l.b, &pso->plinear->world);
    __ml__FRC7MATRIX4T0(&l.a, &l.b, &pso->proot->world);
    l.rootInLinear = l.a;
    XFN *pparent = *(XFN **)((char *)pso->plinear + 0xA0);
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
    InvertMatrix4Affine(&l.d, &l.parent);
    __ml__FRC7MATRIX4T0(&l.c, &l.d, &l.target);
    InvertMatrix4Affine(&l.e, &l.rootInLinear);
    __ml__FRC7MATRIX4T0(&l.b, &l.c, &l.e);
    l.a = l.b;
    M4 &local = l.a;
    XFN *pxf = pso->plinear;
    __as__6VECTORG9VU_VECTOR(&pxf->local.row[3], l.b.row[3]);
    ((float *)&pxf->local)[15] = 1.0f;
    (*(int *)(B_003DD490 + 0x3D58))++;
    pso->vt->fn((char *)pso + pso->vt->delta);
    pso->plinear->generation = *(int *)(B_003DD490 + 0x3D58);
    DiscardSoXps(pso);
    WakeXf(pso, pso->plinear);
    func_001F3900(pso);
    void *pregion = 0;
    if (pso->pphys != 0)
        pregion = (void *)pso->pphys->link;
    if (pregion != 0)
        func_001F37C8(pso, PpathzoneFindPos(PosLoWorld(pso), 1));
}
