#include "types.h"
#include "vu0inline.h"
#include "ps2inline.h"

struct Link { char pad[0x28]; unsigned long flags; };
struct Target { char pad[0x100]; Link *link; float sFade; };
struct Recon { char pad[0x30]; int count; Target *targets[1]; };
extern "C" QW PosLoWorld(void *);
extern "C" void FadeAloIn(Link *, float);
extern "C" void FadeAloOut(Link *, float);
extern QW B_002DDF40[];

void UpdateReconLinkFades(Recon *recon)
{
    for (int index = 0; index < recon->count; index++) {
        Target *target = recon->targets[index];
        if (target->link != 0) {
            QW pos = PosLoWorld(target);
            QW offset = B_002DDF40[9];
            float distance = LaneX(SqrtX(SquaredLengthXy(VectorSub(pos, offset))));
            if (target->sFade < distance && ((target->link->flags >> 60) & 1) == 0)
                FadeAloIn(target->link, 0.25f);
            else if (distance <= target->sFade && ((target->link->flags >> 60) & 1) == 1)
                FadeAloOut(target->link, 0.25f);
        }
    }
}
