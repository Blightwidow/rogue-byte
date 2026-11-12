// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

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
    void *found[16];
    void *best = 0;
    QW posSelf = PosLoWorld(vehicle);
    int count = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x6C, 0, 0x10, found);
    float bestScore = RO_FLT_002A7810;
    for (int index = 0; index < count; index++) {
        void *object = found[index];
        QW posObject = PosLoWorld(object);
        float distance = LaneX(SqrtX(SquaredLengthXy(VectorSub(posObject, posSelf))));
        if (object == vehicle->ploChase)
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
