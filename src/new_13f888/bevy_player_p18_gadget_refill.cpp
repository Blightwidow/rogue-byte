// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x338]; short delta; short index; void *(*fn)(void *); };
struct PLAYER {
    char pad[0xC]; VT *vt;
    char pad2[0xDFC - 0x10]; int hpMax; int *hpCur;
    char pad3[0x12FC - 0xE04]; int *mpCur; int mpMax; char pad4[4]; int flag;
};
extern "C" int *PvFindSaveVarPath(void *, const char *, int);
extern "C" void SetJtHealth(PLAYER *, int);
extern "C" void SetJtPower(PLAYER *, int);
extern "C" void bevy_player_p18_gadget_refill(PLAYER *player, int force)
{
    VT *vt = player->vt;
    int *hp = PvFindSaveVarPath(vt->fn((char *)player + vt->delta), "hpCur", 0);
    VT *vt2 = player->vt;
    player->hpCur = hp;
    player->mpCur = PvFindSaveVarPath(vt2->fn((char *)player + vt2->delta), "mpCur", 0);
    if (*player->hpCur == 0 || force != 0) {
        SetJtHealth(player, player->hpMax);
        SetJtPower(player, player->mpMax);
        player->flag = 0;
    }
}
