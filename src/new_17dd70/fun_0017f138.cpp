#include "sly2.h"
extern "C" void PostSoLoad(void *);
struct VSLOT { short delta; short index; void (*pfn)(void *); };
struct VTAB { VSLOT slot[100]; };
struct OBJ { char pad[0xC]; VTAB *pvtab; };
void func_0017F138(OBJ *pobj)
{
    PostSoLoad(pobj);
    VSLOT *pslot = &pobj->pvtab->slot[0x298 / 8];
    pslot->pfn((char *)pobj + pslot->delta);
}
