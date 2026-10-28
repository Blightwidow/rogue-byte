#include "sly2.h"
struct XPC { QW pos; QW normal; float dist; int other; int pad2; int pad3; };
struct BOMB { char pad0[0xE4]; void *geom; char pad1[0x1F4 - 0xE8]; int fCustom; int cXp; XPC *axp; };
struct OXA { char pad[0x60]; int root; };
struct SOX { char pad[0xEC]; OXA *oxa; };
struct OTH { int pad; SOX *so; };
extern "C" char B_003DD490[];
extern "C" void func_001F5990(void *);
extern "C" void PxpAdd(float, void *, void *, void *, QW, QW, int, void *, void *, void *);

void AddBombCustomXps(BOMB *bomb, OTH *other, int a2, void *a3, void *a4, void *ppxpFirst)
{
    func_001F5990(bomb);
    if (bomb->fCustom == 0) return;
    XPC *xp = bomb->axp;
    for (; xp < bomb->axp + bomb->cXp; xp++) {
        if (xp->other == other->so->oxa->root) {
            PxpAdd(xp->dist, B_003DD490, bomb->geom, other, xp->pos, xp->normal, 9, 0, 0, ppxpFirst);
            return;
        }
    }
}
