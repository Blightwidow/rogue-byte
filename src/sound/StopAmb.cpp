#include "sly2.h"
struct A { char pad[0x48]; float f48; };
void SetAmbGrf(A*, int, int);
void StopAmb(A* a, float v)
{
    a->f48 = v;
    SetAmbGrf(a, 0x1FFF, 8);
}
