#include "sly2.h"
extern "C" {
extern char B_002DDF40[];
extern QW g_2a2dd0;
void ActivateCplcy(void *, int);
void SetCmNearClip(void *, float);
void SetCmFov(void *, float);
int func_0012DC18(int, int, int, int, int, QW);
}
struct Close { int head; char pad[12]; int xf; int act; float tJiggle; };
extern "C" void bevy_camera_looks_activate(Close *close, int focusObj, int xf)
{
    ActivateCplcy(close, focusObj);
    close->xf = xf;
    SetCmNearClip(B_002DDF40, 25.0f);
    SetCmFov(B_002DDF40, 1.15f);
    close->act = func_0012DC18(*(int *)close, xf, 1, 8, 3, g_2a2dd0);
    close->tJiggle = -1.0f;
}
