#include "sly2.h"
struct VECTOR;
struct ALO; struct RIP;
struct SO { char *p0; char *basic; };
struct FLYING { char pad[0xF0]; ALO *alo; };
extern "C" int FIsBasicDerivedFrom(void *basic, int cid);
extern "C" void RemoveRip(RIP *rip);
extern "C" void CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK(RIP *, ALO *, SO *, QW, QW);
extern int D_002C1F70[];

int FBounceFlying__FP6FLYINGP2SOP6VECTORT2(FLYING *flying, SO *so, QW pos, QW normal)
{
    for (unsigned index = 0; index < 1; index++) {
        if (FIsBasicDerivedFrom(so->basic, D_002C1F70[index]))
            return 0;
    }
    if (!FIsBasicDerivedFrom(so->basic, 0x59))
        CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK((RIP *)flying, flying->alo, (SO *)so->p0, pos, normal);
    RemoveRip((RIP *)flying);
    return 1;
}
