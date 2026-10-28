#include "sly2.h"
struct XA { char pad[0x60]; void *owner; };
struct SOX { char pad[0xEC]; XA *xa; };
struct GEOM { char pad[4]; SOX *so; };
struct RIP;
extern "C" {
int FIsBasicDerivedFrom(void *, int);
void RemoveRip(RIP *);
int FBounceRip__FP3RIPP2SOP6VECTORT2(RIP *, GEOM *, QW, QW);
}
extern "C" int FBounceShrapnel(RIP *rip, GEOM *geom, QW pos, QW normal)
{
    void *owner = geom->so->xa->owner;
    if (FIsBasicDerivedFrom(owner, 0x32))
        return 0;
    if (FIsBasicDerivedFrom(owner, 0x59)) {
        RemoveRip(rip);
        return 1;
    }
    return FBounceRip__FP3RIPP2SOP6VECTORT2(rip, geom, pos, normal);
}
