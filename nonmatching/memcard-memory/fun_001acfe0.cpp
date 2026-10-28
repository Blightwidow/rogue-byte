#include "sly2.h"
struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk; int n; int p2; int p3;
    CRef() {}
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
struct MENU { char pad[0x40]; int state; char pad2[8]; int mode; };
extern "C" {
extern char B_003DA530[];
extern char B_003D9ED0[];
extern char B_002E65E0[];
extern char B_003D4A60[];
extern void *B_003E0FE4;
int CGc_FFindScreen(void *);
int func_001B0160(void *);
int func_001B0108(void *);
void MemcardMenu_ClearState(MENU *);
void func_001ACC38(MENU *, int);
void PauseMenu_Close(void *);
void PauseMenu_Pop(void *);
void StartNewGame(void *);
void MemcardMenu_SetState(MENU *, int);
void func_001ABD40(void *);
CRef RefSetGameSaveValue(void *, CRef &, void *);
}
void func_001ACFE0(MENU *pmenu)
{
    switch (pmenu->state) {
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x18:
        if (CGc_FFindScreen(B_003DA530) != 0) {
            if (func_001B0160(B_003D9ED0) != 0) {
                MemcardMenu_ClearState(pmenu);
                func_001ACC38(pmenu, 2);
                PauseMenu_Close(B_003D9ED0);
                StartNewGame(B_003DA530);
                return;
            }
        }
    case 0x14:
    case 0x17:
    case 0x1D:
    case 0x23:
    case 0x24:
    case 0x2E:
        MemcardMenu_ClearState(pmenu);
        func_001ACC38(pmenu, 2);
        if (func_001B0108(B_003D9ED0) != 0)
            PauseMenu_Pop(B_003D9ED0);
        break;
    case 0x1B:
    case 0x1C:
    case 0x20:
        MemcardMenu_ClearState(pmenu);
        break;
    case 0x22: {
        void *ppath = B_003E0FE4;
        {
            CRef refValue;
            refValue.tagk = 0x17;
            refValue.n = 1;
            CRef refTemp(refValue);
            RefSetGameSaveValue(ppath, refTemp, B_003D4A60);
        }
        int mode = pmenu->mode;
        if (mode < 4) {
            if (mode > 0) {
                MemcardMenu_SetState(pmenu, 0x1A);
                func_001ABD40(B_002E65E0);
            }
        }
        break;
    }
    default:
        break;
    }
}
