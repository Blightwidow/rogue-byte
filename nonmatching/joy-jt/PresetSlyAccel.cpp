// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct JT { char pad[4]; };
struct SLY { char pad[0x18C8]; int state; int pad2; int state2; };
extern "C" void AddSoGravityAcceleration(SLY *);
extern "C" void PresetStepAccel(SLY *);
extern "C" void bevy_player_p18_gadget_glide_force(void *);
void PresetJtAccelHang(JT *);
void PresetJtAccelHide(JT *);
void PresetJtAccelPipe(JT *);
extern "C" void PresetJtAccelZap(void *);
extern "C" void PresetJtOrbitAccel(void *);
extern "C" void func_00204E38(SLY *, float);
extern "C" void AddSoAcceleration(SLY *, QW);
extern "C" void func_big14(SLY *, void *);
extern "C" int func_big24(SLY *, void *);
extern "C" void *func_big14b(SLY *, int);
void PresetSlyAccel(SLY *self) {
    char scratch[0xD0];
    switch (self->state) {
    case 3:
    case 8:
        AddSoGravityAcceleration(self);
        break;
    case 21:
    case 22:
        break;
    default:
        PresetStepAccel(self);
    }
    switch (self->state) {
    case 3:
        PresetJtAccelHang((JT *)self);
        break;
    case 8:
        PresetJtAccelPipe((JT *)((char *)self + 0xF50));
        break;
    case 2:
        bevy_player_p18_gadget_glide_force((char *)self + 0x2C0);
        break;
    case 4:
        PresetJtAccelZap((char *)self + 0xDF0);
        break;
    case 7:
        PresetJtAccelHide((JT *)((char *)self + 0x4C0));
        break;
    case 6:
        PresetJtOrbitAccel((char *)self + 0x1FF0);
        break;
    case 14:
        func_big14(self, scratch);
        break;
    case 24: {
        if (self->state2 == 13) {
            int held = func_big24(self, scratch);
            void *other = func_big14b(self, held);
            func_big14(self, other);
            func_big14(self, scratch);
        }
        break;
    }
    }
}
