struct MURRAY { char pad0[0x268]; void *defaultBase; char pad1[0x13D0 - 0x26C]; int state; char pad2[0x13F0 - 0x13D4]; int carried; char pad3[0x1458 - 0x13F4]; int index; char pad4[0x1A58 - 0x145C]; void *tableB[2]; char pad5[0x1AB0 - 0x1A60]; void *tableA[3]; void *jumpBase; };
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
        if (self->carried != 0)
            paseg = *(void **)((char *)self + 0x1ABC);
        else
            paseg = func_0019C870((char *)self + 0x2C0, &secondary);
        break;
    case 5:
        paseg = self->tableA[self->index];
        break;
    default:
        paseg = self->tableB[self->state];
        break;
    }
    if (paseg == 0)
        paseg = self->defaultBase;
    func_00203D00(self, paseg, secondary);
}
