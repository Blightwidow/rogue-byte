#include "sly2.h"
struct UL { unsigned long v; } __attribute__((packed));
struct XP { char pad0[8]; void *plo0; char pad1[0x38]; void *plo1; char pad2[0x80 - 0x48 - 4 - 0x34 + 0x34 - 0x34]; };
struct XPR { char pad0[8]; void *plo; char pad1[0x34]; };
struct MQ { XPR side[2]; QW normal; char pad[4]; float friction; float bounce; };
struct SO { char pad[1]; };
extern "C" char B_003DD490[];
extern "C" const UL RO_002A7840;
void func_001F4FB0(SO *, MQ *, int);
int FIsBasicDerivedFrom(void *, int);
void QueueSwCallbackOnce(void *, SO *, unsigned long, int);

inline float ZOf(QW vector)
{
    int zbits;
    asm("pextuw %0, $0, %1" : "=r" (zbits) : "r" (vector));
    float z;
    asm("mtc1 %1, %0\n\tnop" : "=f" (z) : "r" (zbits));
    return z;
}

void AdjustVehicleNewXp(SO *vehicle, MQ *contact, int side)
{
    func_001F4FB0(vehicle, contact, side);
    void *other = contact->side[1 - side].plo;
    QW normal;
    QW scalarSlot;
    if (side == 0) {
        normal = contact->normal;
    } else {
        float minusOne = -1.0f;
        QW scalar;
        asm("lqc2 vf2, %0" : : "m" (contact->normal));
        asm("mfc1 %0, %1" : "=r" (scalar) : "f" (minusOne));
        asm("qmtc2.ni %0, vf1" : : "r" (scalar));
        asm("sqc2 vf1, %0" : "=m" (scalarSlot));
        asm("vmulx.xyzw vf3, vf2, vf1x\n\tqmfc2.ni %0, vf3" : "=r" (normal));
    }
    if (FIsBasicDerivedFrom(other, 0x4D) != 0 || ZOf(normal) < 0.7f) {
        contact->friction = 0.0f;
        contact->bounce = 0.1f;
    } else {
        contact->friction = 0.5f;
        contact->bounce = 0.1f;
    }
    if (FIsBasicDerivedFrom(other, 0x6C))
        QueueSwCallbackOnce(B_003DD490, vehicle, RO_002A7840.v, (int)other);
}
