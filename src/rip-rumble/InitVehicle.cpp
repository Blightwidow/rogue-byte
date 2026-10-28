#include "sly2.h"
struct V3 { float x, y; int z; };
struct VEH { char p0[0x180]; int state; char p1[0x51C-0x184]; float f51c; V3 acc; char p2[0x530-0x52C]; int f530; float f534; float f538; float f53c; char p3[0x55C-0x540]; int f55c; char p4[0x578-0x560]; int f578; char p5[0x584-0x57C]; int f584; char p6[0x590-0x588]; int f590; char p7[0x59C-0x594]; int f59c; };
extern "C" void InitPo(VEH *);
void InitVehicle(VEH *v)
{
    InitPo(v);
    V3 *a = &v->acc;
    v->f51c = 500.0f; v->state = -1; a->x = 1500.0f; a->y = -1000.0f; a->z = 0; v->f59c = -1; v->f534 = 1500.0f; v->f538 = 2500.0f; v->f53c = 1.0f; v->f55c = 100; v->f590 = 30; v->f584 = 30; v->f578 = 30; v->f530 = 0;
}
