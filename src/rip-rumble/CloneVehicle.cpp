#include "sly2.h"
struct VEHICLE; struct PO;
struct GUN { int pad0; int pad4; char pad8[4]; char *vt; };
struct VEHICLE { char pad[0x4F8]; int count; GUN *guns[8]; };
extern "C" void *__builtin_new(unsigned int);
extern "C" void ClonePo(VEHICLE *, VEHICLE *);
extern "C" void InitVehicleGun(GUN *, VEHICLE *);
extern "C" void CopyVehicleGun(GUN *, GUN *);
extern "C" char D_002C94A0;

void CloneVehicle(VEHICLE *vehicle, VEHICLE *base)
{
    ClonePo(vehicle, base);
    for (int index = 0; index < vehicle->count; index++) {
        GUN *old = vehicle->guns[index];
        GUN *gun = (GUN *)__builtin_new(0xB0);
        gun->pad0 = 0;
        gun->pad4 = 0;
        gun->vt = &D_002C94A0;
        InitVehicleGun(gun, vehicle);
        CopyVehicleGun(gun, old);
        vehicle->guns[index] = gun;
    }
}
