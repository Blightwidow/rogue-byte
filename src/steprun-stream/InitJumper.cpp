#include "sly2.h"
extern char D_002DAA10[];
struct A { int f0; int f4; int f8; void* vt; int f10; };
A* InitJumper(A* a)
{
    a->vt=D_002DAA10; a->f10=-1; a->f0=0; a->f4=0;
    return a;
}
