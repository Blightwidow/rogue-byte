struct Lo { char pad0[0x80]; float f80; int f84; int f88; int f8C; char pad90[0x10]; float fA0; float fA4; };
void InitLo(Lo *);
extern "C" void func_00173158(Lo *self) {
    InitLo(self);
    self->f88 = 1;
    self->f80 = 5500.0f;
    self->f8C = 1;
    self->f84 = 1;
    self->fA0 = 30.0f;
    self->fA4 = 50.0f;
}
