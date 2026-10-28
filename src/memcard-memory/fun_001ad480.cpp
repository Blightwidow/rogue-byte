#include "sly2.h"
struct CRef { int a; union { float g; int n; }; int c; int d; };
struct ITEM { char pad0[8]; int slot; char pad1[0x10]; int flags; };
extern int B_003E0FAC;
struct SLOT { char pad[0x5464]; };
struct CARD { SLOT slots[3]; char pad[8]; SLOT *cur; };
extern CARD B_002E6604;
extern char B_002E6550;
extern "C" void RefGetGameSaveValue(CRef *, int, SLOT *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void func_001AD3E0();
extern "C" void MemcardMenu_SetState(char *, int);

extern "C" void func_001AD480(ITEM *item)
{
    CRef ref;
    SLOT *slot = &B_002E6604.slots[item->slot];
    RefGetGameSaveValue(&ref, B_003E0FAC, slot);
    float dt = ref.g;
    CRef_Destruct(&ref);
    { char *p = (char *)&B_002E6604 + 0x7FDC; *(SLOT **)(p + 0x7D58) = slot; }
    if (dt == 0.0f)
        func_001AD3E0();
    else
        MemcardMenu_SetState(&B_002E6550, 0x1C);
    if (item != 0)
        item->flags |= 2;
}
