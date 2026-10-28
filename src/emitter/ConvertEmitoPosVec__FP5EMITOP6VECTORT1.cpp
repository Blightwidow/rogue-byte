#include "sly2.h"
struct M4 { QW row[4]; };
struct VT { char pad[0x100]; short delta; short index; void *(*fn)(void *, M4 *); };
struct PAL { char pad[0xC]; VT *vptr; };
struct XFN { char pad[0x40]; M4 world; QW pos; };
struct SUB { int a, b, kind; };
struct EMITO { char pad[8]; PAL **pref; char pad2[4]; SUB sub; };
struct EMITO;
extern "C" {
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
QW ConvertMatPos(M4 *, void *, QW);
QW ConvertAloVec(M4 *, void *, QW);
QW VelocityXfAtPos(XFN *, void *, QW);
}
void ConvertEmitoPosVec__FP5EMITOP6VECTORT1(EMITO *pemit, VECTOR *ppos, VECTOR *pvec)
{
    PAL *palo = *pemit->pref;
    SUB *psub = &pemit->sub;
    if (palo == 0) return;
    M4 local;
    XFN *pxf = (XFN *)palo->vptr->fn((char *)palo + palo->vptr->delta, &local);
    M4 world = __ml__FRC7MATRIX4T0(*(M4 *)((char *)pxf + 0x40), local);
    *(QW *)ppos = ConvertMatPos(&world, 0, *(QW *)ppos);
    if (psub->kind != 3) {
        *(QW *)pvec = ConvertAloVec(&world, 0, *(QW *)pvec);
        if (psub->kind != 2) {
            QW posRel = (psub->kind == 1) ? *(QW *)ppos : *(QW *)((char *)pxf + 0x70);
            QW vel = VelocityXfAtPos(pxf, 0, posRel);
            asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m" (*pvec) : "m" (*pvec), "r" (vel));
        }
    }
}
