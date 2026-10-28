#include "sly2.h"
struct VT { char pad[0x1F0]; short delta; short index; int (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct OWNER { char pad[0x60]; OBJ *so; };
struct OWNERHOLDER { char pad[0xEC]; OWNER *owner; };
struct GEOM { int a; OWNERHOLDER *owner; };
struct WHEEL { char pad[8]; char *xps; char pad2[0x60 - 0xC]; };
struct VEHICLE { char pad[0x190]; int cwheel; int pad194; int pad198; int pad19c; char wheels[1]; };
extern "C" void func_001F5990(VEHICLE *, GEOM *, int, void *, void *);
extern "C" void func_001D3450(VEHICLE *, void *, GEOM *, int, void *, void *, void *);

void AddVehicleCustomXps(VEHICLE *vehicle, GEOM *geom, int count, void *list, void *bsp)
{
    func_001F5990(vehicle, geom, count, list, bsp);
    OBJ *other = geom->owner->owner->so;
    VT *vt = other->vt;
    if (vt->fn((char *)other + vt->delta) != 0) {
        for (int index = 0; index < vehicle->cwheel; index++) {
            char *wheel = vehicle->wheels + index * 0x60;
            func_001D3450(vehicle, wheel, geom, count, list, bsp, wheel + 8);
        }
    }
}
