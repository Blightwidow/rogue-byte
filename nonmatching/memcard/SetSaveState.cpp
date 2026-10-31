#include "sly2.h"
struct MEMCARD;
struct CRef { int tagk; float g; };
struct SLOT { char pad[0x5464]; };
struct SAVE {
    char pad0[8]; int state; int want; float tStamp;
    char pad1[0x10]; SLOT aslot[3];
    char pad2[0xFD50 - 0x24 - 3 * 0x5464];
    SLOT *pslotCur; SLOT *pslotNewest; int pad3; char mc[1];
};
struct UL { long v; } __attribute__((packed));
struct MENU { char pad[0x44]; int phase; };
extern "C" {
struct SW { char pad[0x3B1C]; void *pdat; };
extern SW B_003DD490;
extern MENU B_002E6550;
extern char B_002E65A0[];
extern float g_2dded0[];
extern const UL g_2a6ba0;
extern const UL g_2a6ba8;
void func_001ACC38(MENU *, int);
int BusyMenu_FShowing(void *);
void BusyMenu_Hide(void *);
void MemcardMenu_SetState(MENU *, int);
void CreateMemcardThread__FP7MEMCARDii(MEMCARD *, long);
CRef *RefGetGameSaveValue(CRef *, void *, void *);
void CRef_Destruct(CRef *);
void ResetSaveKeepingOptions(void *, int);
}
int CompareSaves__FP4SAVET0(void *, void *);

void SetSaveState(SAVE *psave, int nState)
{
    if (nState == psave->state) return;
    if (psave->state == 6) {
        psave->pslotNewest = 0;
        if (psave->pslotCur != 0 && B_002E6550.phase == 1) {
            func_001ACC38(&B_002E6550, 3);
            if (BusyMenu_FShowing(B_002E65A0) != 0) {
                MemcardMenu_SetState(&B_002E6550, 0x23);
                BusyMenu_Hide(B_002E65A0);
            } else {
                MemcardMenu_SetState(&B_002E6550, 0x24);
            }
        }
    }
    if (nState == 3) goto case3;
    if (nState < 4) goto lt4;
    if (nState == 6) goto case6;
    psave->state = nState;
    goto stamp;
lt4:
    if (psave->state < 2) {
        if (psave->state >= 0) {
            CreateMemcardThread__FP7MEMCARDii((MEMCARD *)psave->mc, g_2a6ba0.v);
            psave->state = psave->state;
            goto stamp;
        }
    }
    goto store;
case3:
    CreateMemcardThread__FP7MEMCARDii((MEMCARD *)psave->mc, g_2a6ba8.v);
    psave->state = 3;
    goto stamp;
case6:
    psave->pslotNewest = &psave->aslot[0];
    for (int islot = 0; islot < 3; islot++) {
        SLOT *pslot = &psave->aslot[islot];
        CRef ref;
        RefGetGameSaveValue(&ref, B_003DD490.pdat, pslot);
        float dt = ref.g;
        CRef_Destruct(&ref);
        if (dt != 0.0f) {
            if (CompareSaves__FP4SAVET0((char *)psave->pslotNewest + 0x5408, (char *)pslot + 0x5408) < 0)
                psave->pslotNewest = pslot;
        } else {
            ResetSaveKeepingOptions(pslot, 0);
        }
    }
store:
    psave->state = nState;
stamp:
    psave->tStamp = g_2dded0[15];
}
