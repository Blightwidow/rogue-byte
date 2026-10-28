#include "sly2.h"
struct GUN { int pad0; int pad4; char pad8[4]; char *vt; char pad10[4]; int f14; int f18; char pad1C[0x2C - 0x1C]; int f2C; char pad30[8]; int f38; };
struct VEHICLE { char pad[0x4F8]; unsigned count; GUN *guns[8]; };
extern "C" void *__builtin_new(unsigned int);
extern "C" void InitVehicleGun(GUN *, VEHICLE *);
extern "C" char D_002C94A0;

void AddVehicleGun(VEHICLE *vehicle, int a, int b, int c, int d)
{
    if (vehicle->count < 8) {
        GUN *gun = (GUN *)__builtin_new(0xB0);
        gun->pad0 = 0;
        gun->vt = &D_002C94A0;
        gun->pad4 = 0;
        InitVehicleGun(gun, vehicle);
        unsigned count = vehicle->count;
        gun->f14 = a;
        gun->f18 = b;
        gun->f2C = c;
        gun->f38 = d;
        vehicle->guns[count] = gun;
        vehicle->count = count + 1;
    }
}
