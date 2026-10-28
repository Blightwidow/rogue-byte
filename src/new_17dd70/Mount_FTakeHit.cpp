// SPDX-License-Identifier: GPL-3.0-or-later
struct MOUNT { char pad[0x184]; int hp; char pad2[0x38]; int state; };
extern "C" int FSwHandsOff(void *);
extern "C" void Mount_SetState(MOUNT *, int);
extern "C" void Mount_UpdateHealthBlot(MOUNT *);
extern "C" void bevy_camera_follow_activity(void *, int, int);
extern "C" int func_0017F1D0(MOUNT *, int *);
extern "C" char B_002DEB30, B_003DD490;
extern "C" int g_2e1e00;
extern "C" int Mount_FTakeHit(MOUNT *pmount, int *pmsg)
{
    int state = pmount->state;
    if (state < 5) {
        if (state >= 2)
            return 0;
    }
    if (FSwHandsOff(&B_003DD490) != 0)
        return 0;
    if ((g_2e1e00 & 1) != 0)
        return 0;
    if (func_0017F1D0(pmount, pmsg) == 0)
        return 0;
    Mount_UpdateHealthBlot(pmount);
    if (pmount->hp > 0) {
        bevy_camera_follow_activity(&B_002DEB30, 0xF, *pmsg);
        Mount_SetState(pmount, 2);
    } else {
        Mount_SetState(pmount, 4);
    }
    return 1;
}
