#include "sly2.h"
struct CRef { int tag; int n; int a; int b; };
struct MENU { char pad[0x4C]; int mode; };
struct AUTOSAVE { char pad[0xFD50]; void *pslotCur; void *pad2; void *pslotOther; };
extern AUTOSAVE B_002E65E0;
extern MENU B_002E6550;
extern void *B_003E0FE4;
extern char B_003D4A60[];
extern "C" void RefGetGameSaveValue(CRef *, void *, void *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void MemcardMenu_SetState(MENU *, int);
extern "C" void func_001ABD40(void *);
void func_001AD3E0()
{
    CRef ref;
    B_002E65E0.pslotCur = B_002E65E0.pslotOther;
    B_002E6550.mode = 2;
    RefGetGameSaveValue(&ref, B_003E0FE4, B_003D4A60);
    int n = ref.n;
    CRef_Destruct(&ref);
    if (n == 0) {
        MemcardMenu_SetState(&B_002E6550, 0x22);
    } else {
        MemcardMenu_SetState(&B_002E6550, 0x1A);
        func_001ABD40(&B_002E65E0);
    }
}
