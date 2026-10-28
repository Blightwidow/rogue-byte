extern "C" void CloneAct(void *);
struct Obj { char pad[8]; char *owner; char pad2[0x10]; int unk1C; };
void func_00186610(Obj *self)
{
    CloneAct(self);
    self->unk1C = *(int *)(self->owner + 0xA8);
}
