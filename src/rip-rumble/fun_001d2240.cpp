#include "sly2.h"
struct GUN { char p[0x80]; int mode; };
struct VEH { char p[0x4F8]; int cgun; GUN *apgun[1]; };
extern "C" int FVehicleGunHasAmmo(GUN *);
GUN *func_001D2240(VEH *v)
{
    for (int i = 0; i < v->cgun; i++) {
        GUN *g = v->apgun[i];
        if (FVehicleGunHasAmmo(g) && g->mode != 4)
            return g;
    }
    return 0;
}
