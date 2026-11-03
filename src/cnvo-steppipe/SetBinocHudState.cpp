#include "sly2.h"
struct VTable {
    char pad[0x188];
    short deltaMute;
    short pad1;
    void (*mute)(void *, int);
    short deltaApply;
    short pad2;
    void (*apply)(void *);
};
struct Widget {
    char pad[0xC];
    VTable *vt;
    char pad2[0x58 - 0x10];
    int active;
};
struct Camera { char pad[0x1A8]; float angle; };
struct Actor { Camera *camera; char pad[0x20 - 4]; int mode; char pad2[0x3C - 0x24]; float seekValue; };
struct Owner { Actor *actor; };
struct BinocHud {
    Actor *actor;
    int state;
    Widget *left;
    char pad[4];
    Widget *right;
    int recon;
};
extern "C" {
void SeekBlotLabel(Widget *, int, float);
void SetBlotBlots(Widget *, int);
float SetTimerTimers__FP5TIMER6TIMERS(Widget *, int);
void bevy_camera_follow_activity(void *, int, int);
void bevy_ui_binoc_recon_202768(int, int);
void func_0019D948();
int func_00213B00(Widget *, int);
void func_00227788(void *);
extern char B_002DEB30[];
extern char B_004435F0[];
}
extern "C" void SetBinocHudState(BinocHud *phud, int state)
{
    int old = phud->state;
    if (old == state)
        return;
    if (old == -1)
        func_0019D948();
    int previous = phud->state;
    phud->state = state;
    switch (state) {
    case 0:
        if (phud->actor->mode == 1)
            bevy_camera_follow_activity(B_002DEB30, 0xC, 0);
        else
            bevy_camera_follow_activity(B_002DEB30, 7, 0);
        if (phud->left != 0) {
            Widget *pleft = phud->left;
            pleft->vt->mute((char *)pleft + pleft->vt->deltaMute, -1);
            func_00213B00(phud->left, 0x352);
            func_00213B00(phud->left, 0x351);
            SeekBlotLabel(phud->left, 0x352, (phud->actor->camera->angle + 3.1415927f) * 0.15915494f);
            SeekBlotLabel(phud->left, 0x351, phud->actor->seekValue);
        }
        if (phud->actor->mode == 1) {
            func_00227788(B_004435F0);
            if (phud->right != 0) {
                Widget *pright = phud->right;
                pright->vt->mute((char *)pright + pright->vt->deltaMute, -1);
            }
        }
        if (phud->recon != 0)
            bevy_ui_binoc_recon_202768(phud->recon, 0);
        break;
    case 2:
        if (phud->actor->mode == 1)
            bevy_camera_follow_activity(B_002DEB30, 0xD, 0);
        else
            bevy_camera_follow_activity(B_002DEB30, 8, 0);
        if (phud->left != 0) {
            Widget *pleft = phud->left;
            pleft->vt->apply((char *)pleft + pleft->vt->deltaApply);
        }
        if (phud->right != 0) {
            Widget *pright = phud->right;
            pright->vt->apply((char *)pright + pright->vt->deltaApply);
        }
        if (phud->recon != 0)
            bevy_ui_binoc_recon_202768(phud->recon, 10);
        break;
    case -1:
        if (previous != 2) {
            if (phud->actor->mode == 1)
                bevy_camera_follow_activity(B_002DEB30, 0xD, 0);
            else
                bevy_camera_follow_activity(B_002DEB30, 8, 0);
        }
        if (phud->left != 0 && phud->left->active != 0) {
            SetBlotBlots(phud->left, 1);
            SetTimerTimers__FP5TIMER6TIMERS(phud->left, 1);
        }
        if (phud->right != 0 && phud->right->active != 0) {
            SetBlotBlots(phud->right, 1);
            SetTimerTimers__FP5TIMER6TIMERS(phud->right, 1);
        }
        if (phud->recon != 0)
            bevy_ui_binoc_recon_202768(phud->recon, -1);
        break;
    }
}
