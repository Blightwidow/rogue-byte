#include "sly2.h"
struct XF_1FAC30 { char pad[0x98]; short kind; char pad9a[0xA0 - 0x9A]; void *parent; char pada4[0xF0 - 0xA4]; QW accel; };
struct SO_1FAC30 { char pad[0x58]; XF_1FAC30 *pxf; };
extern "C" int FXfKindDynamic(int kind);
extern "C" QW ConvertXfVec(int, void *, QW);

extern "C" void AddSoAcceleration(SO_1FAC30 *pso, QW dv)
{
    if (FXfKindDynamic(pso->pxf->kind)) {
        XF_1FAC30 *pxf = pso->pxf;
        QW accel = pxf->accel;
        QW world = ConvertXfVec(0, pxf->parent, dv);
        asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf3\n\tvadd.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m"(pxf->accel) : "m"(accel), "r"(world));
    }
}
