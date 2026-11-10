#include "murray.h"
extern "C" void *PasegAttachBase(void *, int *);
extern "C" void *bevy_player_p7_damage_1a23f8(void *, int *);
extern "C" void *func_0019C870(void *, int *);
extern "C" void func_00203D00(MURRAY *, void *, int);

void SetMurrayAnimBase(MURRAY *self)
{
    int secondary = 0;
    void *paseg;
    switch (self->state) {
    case 0xD:
        paseg = PasegAttachBase((char *)self + 0x4C0, &secondary);
        break;
    case 0xE:
        paseg = bevy_player_p7_damage_1a23f8((char *)self + 0xDF0, &secondary);
        break;
    case 2:
        if (self->ploCarried != 0)
            paseg = *(void **)((char *)self + 0x1ABC);
        else
            paseg = func_0019C870((char *)self + 0x2C0, &secondary);
        break;
    case 5:
        paseg = self->apasegByIndex[self->iapasegByIndex];
        break;
    default:
        paseg = self->apasegState[self->state];
        break;
    }
    if (paseg == 0)
        paseg = self->pasegDefault;
    func_00203D00(self, paseg, secondary);
}
