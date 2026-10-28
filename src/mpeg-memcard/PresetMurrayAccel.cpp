// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct JT { char pad[4]; };
struct MURRAY { char pad[0x13D0]; int state; };
extern "C" void AddSoGravityAcceleration(MURRAY *);
extern "C" void PresetStepAccel(MURRAY *);
extern "C" void bevy_player_p18_gadget_glide_force(void *);
void PresetJtAccelHide(JT *);
extern "C" void PresetJtAccelZap(void *);
void PresetJtAccelPipe(JT *);
extern "C" void func_001B6CC0(MURRAY *);
void PresetMurrayAccel(MURRAY *self) {
    if (self->state == 20) {
        AddSoGravityAcceleration(self);
    } else {
        PresetStepAccel(self);
    }
    switch (self->state) {
    case 2:
        bevy_player_p18_gadget_glide_force((char *)self + 0x2C0);
        return;
    case 13:
        PresetJtAccelHide((JT *)((char *)self + 0x4C0));
        return;
    case 14:
        PresetJtAccelZap((char *)self + 0xDF0);
        return;
    case 3:
        func_001B6CC0(self);
        return;
    case 20:
        PresetJtAccelPipe((JT *)((char *)self + 0xF50));
        return;
    }
}
