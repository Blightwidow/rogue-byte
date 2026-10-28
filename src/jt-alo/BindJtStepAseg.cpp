// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct JT { char pad[0x520]; void *f520; char pad2[0x1720-0x524]; void *tbl[1]; int pad3[0x40]; };
extern "C" void *PasegAttachBase(void *, int *);
extern "C" void *bevy_player_p7_damage_1a23f8(void *, int *);
extern "C" void *func_0019C870(void *, int *);
extern "C" void func_00203D00(JT *, void *, int);
void BindJtStepAseg(JT *self) {
    int local = 0;
    void *result;
    int state = *(int *)((char *)self + 0x18C8);
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
        result = self->f520;
        break;
    default:
        result = self->tbl[*(int *)((char *)self + 0x18C8)];
        break;
    }
    if (!result) result = self->tbl[0];
    func_00203D00(self, result, local);
}
