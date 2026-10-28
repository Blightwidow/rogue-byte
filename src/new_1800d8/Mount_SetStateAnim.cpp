#include "sly2.h"
struct MOUNT { char pad[0x1C8]; struct { int a; int pad0[2]; int b; } slot[5]; };
void Mount_SetStateAnim(MOUNT *pmount, unsigned index, int first, int second)
{
    if (index < 5)
    {
        pmount->slot[index].a = first;
        pmount->slot[index].b = second;
    }
}
