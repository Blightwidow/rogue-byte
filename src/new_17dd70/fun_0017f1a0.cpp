#include "sly2.h"
extern "C" void func_001F4FB0(void *, void *);
struct OBJ { char pad[0x94]; int a; int b; };
void func_0017F1A0(void *punused, OBJ *pobj)
{
    func_001F4FB0(punused, pobj);
    pobj->a = 0;
    pobj->b = 0;
}
