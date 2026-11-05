#include "sly2.h"
struct MEMCARD;
struct B8 { char b[8]; };
struct SAVE { char pad0[8]; int state; int want; float tWait; float tNext; char pad1[0xFD5C - 0x18]; char mc[1]; };
extern "C" {
int FSwLoadBusy(void *);
extern char B_003DD490[];
extern int g_2deb4c;
struct MENU { char pad[0x44]; int phase; };
extern MENU B_002E6550;
extern float g_2ddf0c;
struct UL { long v; } __attribute__((packed));
extern const UL g_2a6ba0;
void CreateMemcardThread__FP7MEMCARDii(MEMCARD *, long);
void func_001AB630(SAVE *, int);
void SetSaveState(SAVE *, int);
int func_001B42C0(void *);
int func_001B01E8(void *);
void MemcardMenu_SetState(MENU *, int);
extern char B_002F66B0[];
extern char B_003D9ED0[];
}
int FMemcardThreadValid(MEMCARD *);

void UpdateSave(SAVE *psave)
{
    if (FSwLoadBusy(B_003DD490) != 0) return;
    if (g_2deb4c != 0) return;
    if (B_002E6550.phase == 3) return;
    MEMCARD *pmc = (MEMCARD *)psave->mc;
    if (FMemcardThreadValid(pmc) != 0) return;
    if (psave->state == psave->want) {
        if (psave->tNext <= g_2ddf0c)
            CreateMemcardThread__FP7MEMCARDii(pmc, g_2a6ba0.v);
        else
            func_001AB630(psave, psave->want);
    } else {
        SetSaveState(psave, psave->want);
    }
    if (FMemcardThreadValid((MEMCARD *)psave->mc) != 0) return;
    if (func_001B42C0(B_002F66B0) != 0) return;
    int phase = B_002E6550.phase;
    if (phase != 1) return;
    if (0.3f <= g_2ddf0c - psave->tWait) {
        if (func_001B01E8(B_003D9ED0) != 0) {
            if (psave->state != 6)
                MemcardMenu_SetState(&B_002E6550, 0x2E);
            return;
        }
        switch (psave->state) {
        case 1: MemcardMenu_SetState(&B_002E6550, 0x11); break;
        case 2: MemcardMenu_SetState(&B_002E6550, 0x12); break;
        case 3: MemcardMenu_SetState(&B_002E6550, 0x15); break;
        case 4: MemcardMenu_SetState(&B_002E6550, 0x18); break;
        }
    }
}
