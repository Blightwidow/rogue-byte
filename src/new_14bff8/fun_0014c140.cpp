// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32;
extern "C" {
extern s8 B_003DD040[];
extern s8 B_003DD490[];
void SetSndbankMasterVolume(void *, float);
void RequestTransition(void *, void *, int, int, unsigned, int);

void func_0014C140(s32 arg0) {
    SetSndbankMasterVolume(B_003DD040, 0.0f);
    RequestTransition(B_003DD490, 0, 0x189, -1, arg0, -1);
}

}
