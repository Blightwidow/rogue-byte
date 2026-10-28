#include "sly2.h"
struct TNFN { char pad[0x70]; float x, y, z; };
struct TN { char pad[0x118]; TNFN *pstepCur; };
extern "C" void func_00221960(TN *ptn, float g)
{
    ptn->pstepCur->x = ptn->pstepCur->y = g;
    ptn->pstepCur->z = 1.0f;
}
