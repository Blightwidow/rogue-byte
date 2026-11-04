#include "sly2.h"
struct VT { char pad[0x190]; short delta; short index; void (*fn)(void *); };
struct BLOT { char pad0[0xC]; VT *vt; char pad1[0x48]; int state; float time; };
extern "C" int func_002121C8();
extern "C" void UpdateBlotMovie(BLOT *);
extern "C" int CGc_FFindScreen(void *);
extern "C" int FJoyButtonPressed(void *, int);
extern "C" void ClearHandsOff(void *, int);
extern "C" void bevy_jobs_162df8(int);
extern "C" char B_002E6550[], B_003DA4F0[], B_002DFC00[], B_003DD490[];
extern "C" int g_2dd318;
extern "C" float g_2ddf0c;
void bevy_jobs_restart_current(BLOT *blot)
{
    if (func_002121C8() != 0)
        return;
    UpdateBlotMovie(blot);
    if (blot->state == 2 && g_2ddf0c - blot->time > 0.5f && CGc_FFindScreen(B_002E6550) == 0
        && CGc_FFindScreen(B_003DA4F0) == 0 && FJoyButtonPressed(B_002DFC00, 0xF0) != 0) {
        ClearHandsOff(B_003DD490, 0);
        if (*(int *)((char *)blot + 0x114) == 0 && *(int *)(B_003DD490 + 0x3B0C) != 0) {
            g_2dd318 = g_2dd318 + 1;
            bevy_jobs_162df8(*(int *)(B_003DD490 + 0x3B0C));
        }
        blot->vt->fn((char *)blot + blot->vt->delta);
    }
    *(int *)((char *)blot + 0x110) = 1;
}
