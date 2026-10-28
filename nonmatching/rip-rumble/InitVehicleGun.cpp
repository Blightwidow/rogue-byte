#include "sly2.h"
struct B8 { char b[8]; };
struct VEHICLE;
struct GUN { char pad0[0x10]; VEHICLE *vehicle; char pad14[0x40 - 0x14]; B8 f40; B8 f48; VECTOR f50; B8 f60; float f68; char pad6C[0x88 - 0x6C]; float f88; float f8C; int f90; float f94; float f98; float f9C; };
extern "C" const B8 D_002C2218;
extern "C" const B8 D_002C2220;
extern "C" const VECTOR D_002C2230;
extern "C" const B8 D_002C2240;

void InitVehicleGun(GUN *gun, VEHICLE *vehicle)
{
    gun->vehicle = vehicle;
    gun->f40 = D_002C2218;
    gun->f48 = D_002C2220;
    gun->f50 = D_002C2230;
    gun->f60 = D_002C2240;
    gun->f68 = -1750.0f;
    gun->f88 = 200.0f;
    gun->f98 = 1.0f;
    gun->f8C = 400.0f;
    gun->f94 = 500.0f;
    gun->f9C = 1.5f;
    gun->f90 = 0;
}
