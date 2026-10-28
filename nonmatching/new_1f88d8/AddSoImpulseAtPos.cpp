#include "sly2.h"
struct XF { char pad[0xA0]; void *parent; char pad2[0x4C]; QW acc; };
struct SO { char pad[0x58]; XF *lin; XF *ang; };
extern "C" QW DvFromImpulse(SO *, QW);
extern "C" QW DwFromImpulseAtPos(SO *, QW, QW);
extern "C" QW ConvertXfVec(void *, void *, QW);
void AddSoImpulseAtPos(SO *pso, QW pos, QW impulse)
{
    QW dv = DvFromImpulse(pso, impulse);
    QW dw = DwFromImpulseAtPos(pso, pos, impulse);
    XF *xl = pso->lin;
    QW tmp = xl->acc;
    QW r = ConvertXfVec(0, xl->parent, dv);
    int cxl;
    asm("lqc2 vf2, %1" : "=r" (cxl) : "m" (tmp));
    asm("qmtc2.ni %2, vf3\n\tvadd.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %1" : "+r" (cxl), "=m" (xl->acc) : "r" (r));

    XF *xa = pso->ang;
    QW tmp2 = xa->acc;
    QW r2 = ConvertXfVec(0, xa->parent, dw);
    int cxa;
    asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf3" : "=r" (cxa) : "m" (tmp2), "r" (r2));
    asm("vadd.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %1" : "+r" (cxa), "=m" (xa->acc));

}
