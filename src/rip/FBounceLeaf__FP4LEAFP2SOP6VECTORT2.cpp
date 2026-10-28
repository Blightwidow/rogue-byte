#include "sly2.h"
struct ALO; struct RIP; struct XF;
struct SO { char *p0; char *basic; };
struct M34 { float m[3][4]; } __attribute__((aligned(16)));
struct STUCK { char pad[0x40]; M34 mat; };
struct LEAF { char pad[0x1C]; ALO *alo; };
extern "C" int FIsBasicDerivedFrom(void *basic, int cid);
extern "C" void RemoveRip(RIP *rip);
extern "C" STUCK *CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK(RIP *, ALO *, SO *, QW, QW);
extern "C" M34 ConvertLoMat(int, char *, M34 *);

int FBounceLeaf__FP4LEAFP2SOP6VECTORT2(LEAF *leaf, SO *so, QW pos, QW normal)
{
    if (FIsBasicDerivedFrom(so->basic, 0x33))
        return 0;
    STUCK *stuck = CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK((RIP *)leaf, leaf->alo, (SO *)so->p0, pos, normal);
    if (stuck != 0)
        stuck->mat = ConvertLoMat(0, so->basic, &stuck->mat);
    RemoveRip((RIP *)leaf);
    return 1;
}
