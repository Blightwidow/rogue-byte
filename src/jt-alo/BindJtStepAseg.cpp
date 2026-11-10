// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "sly.h"
extern "C" void *PasegAttachBase(void *, int *);
extern "C" void *bevy_player_p7_damage_1a23f8(void *, int *);
extern "C" void *func_0019C870(void *, int *);
extern "C" void func_00203D00(SLY *, void *, int);
void BindJtStepAseg(SLY *self) {
    int local = 0;
    void *result;
    int state = self->jts;
    switch (state) {
    case 7:
        result = PasegAttachBase((char *)self + 0x4C0, &local);
        break;
    case 4:
        result = bevy_player_p7_damage_1a23f8((char *)self + 0xDF0, &local);
        break;
    case 2:
        result = func_0019C870((char *)self + 0x2C0, &local);
        break;
    case 21:
    case 22:
        result = self->field_0x520;
        break;
    default:
        result = self->apasegJts[self->jts];
        break;
    }
    if (!result) result = self->apasegJts[0];
    func_00203D00(self, result, local);
}
