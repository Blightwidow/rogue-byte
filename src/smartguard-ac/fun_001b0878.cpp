#include "sly2.h"
struct CRef { int a; union { float g; int n; }; int c; int d; };
struct ITEM { char pad[0x1C]; unsigned grf; };
struct SAVE { char pad[0xFD50]; int fHasMemcard; };
struct MCM { char pad[0x4C]; int fPending; };
extern char B_002DEB30[];
extern SAVE B_002E65E0;
extern MCM B_002E6550;
extern int B_003E0FE4;
extern int B_003D4A60;
extern "C" {
void bevy_camera_follow_activity(void *, int, int);
void RestartBootQueue();
void RefGetGameSaveValue(CRef *, int, int *);
void CRef_Destruct(CRef *);
void MemcardMenu_SetState(void *, int);
void func_001ABD40(void *);
}
extern "C" void func_001B0878(ITEM *pitem)
{
    bevy_camera_follow_activity(B_002DEB30, 0x2D, 0);
    bevy_camera_follow_activity(B_002DEB30, 0x2E, 0);
    if (B_002E65E0.fHasMemcard != 0) {
        B_002E6550.fPending = 1;
        CRef ref;
        RefGetGameSaveValue(&ref, B_003E0FE4, &B_003D4A60);
        int n = ref.n;
        CRef_Destruct(&ref);
        if (n == 0) {
            MemcardMenu_SetState(&B_002E6550, 0x22);
        } else {
            MemcardMenu_SetState(&B_002E6550, 0x1A);
            func_001ABD40(&B_002E65E0);
        }
    } else {
        RestartBootQueue();
    }
    if (pitem)
        pitem->grf |= 2;
}
