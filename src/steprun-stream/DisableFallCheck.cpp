#include "sly2.h"
struct A { int f0; int f4; int f8; int fC; };
void SetFallCheckState(A*, int);
void DisableFallCheck(A* a)
{
    a->fC = 0;
    SetFallCheckState(a, 0);
}
