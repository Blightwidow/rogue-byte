/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct CM;
struct SO;
struct CPLCY;
struct CPP { int v; };
struct ALO {
    char pad0[0xC];
    VT *vt;
    char pad10[0x124];
    int next;
    int unk138;
    int state;
    char pad140[0x18];
    float tWarp;
    char pad15C[4];
    float delay;
    int msg;
    int tasks;
};
extern "C" {
extern char B_003DD490[];
extern char B_002DEB30[];
extern char B_002DDF40[];
extern float g_2dded0;
void Warp_SetState(ALO *, int);
void *func_002280D0(char *);
void ApplyTaskStateRequests(char *, int, int *, ALO *);
void Warp_Start(ALO *);
void Warp_Start_self(ALO *);
}
void RevokeCmPolicy(CM *, int, CPP, CPLCY *, SO *, void *);
void Warp_Start(ALO *warp)
{
    CPP mone;
    mone.v = -1;
    if (warp->state != 3) return;
    if (warp->next != 0) {
        Warp_SetState(warp, 0);
        void *next = func_002280D0(B_003DD490);
        if (next) Warp_Start_self((ALO *)next);
    } else {
        ApplyTaskStateRequests(B_002DEB30, warp->msg, &warp->tasks, warp);
        RevokeCmPolicy((CM *)B_002DDF40, 2, mone, (CPLCY *)(B_002DDF40 + 0x450), 0, 0);
        RevokeCmPolicy((CM *)B_002DDF40, 2, mone, (CPLCY *)(B_002DDF40 + 0x520), 0, 0);
        Warp_SetState(warp, 4);
        warp->tWarp = g_2dded0 + warp->delay;
        warp->vt->fn((char *)warp + warp->vt->delta, 5, 0, 0, 0, 0);
    }
}
