#include "sly2.h"
struct SWX { char pad[1]; };
struct AMMO { float bias; int a; int b; };
struct VEHICLE { char pad[0x57C]; AMMO aammo[4]; char pad1[0x5B8 - 0x5AC]; void *ploChase; };
extern SWX B_003DD490;
extern "C" {
extern const float RO_FLT_002A7810;
extern float g_2c20c0[3];
QW PosLoWorld(void *);
int CploFindSwObjectsByClass(SWX *, int, int, int, int, void **);
void *func_001D22D0(VEHICLE *vehicle)
{
    int bits;
    void *found[16];
    void *best = 0;
    QW posSelf = PosLoWorld(vehicle);
    int count = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x6C, 0, 0x10, found);
    float bestScore = RO_FLT_002A7810;
    for (int index = 0; index < count; index++) {
        void *object = found[index];
        QW posObject = PosLoWorld(object);
        QW delta;
        asm("qmtc2.ni %0, vf2" : : "r" (posObject));
        asm("lqc2 vf3, %0" : : "m" (posSelf));
        asm("vsub.xyzw vf1, vf2, vf3");
        float distance;
        register void *chase asm("$2") = vehicle->ploChase;
        asm("vmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm volatile("qmfc2.ni %0, vf1\n\tmtc1 %0, %1" : "=&r" (bits), "=f" (distance));
        if (object == chase)
            distance = g_2c20c0[0] + distance * (g_2c20c0[1] + distance * g_2c20c0[2]);
        distance += vehicle->aammo[*(int *)((char *)object + 0x158)].bias;
        if (distance < bestScore) {
            bestScore = distance;
            best = object;
        }
    }
    return best;
}
}
