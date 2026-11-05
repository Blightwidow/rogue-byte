struct IVec { int x; float y; int z; };
struct Launch {
    char pad0[0x70];
    int a0, a1, a2;
    char pad7C[4];
    int f80; float f84;
    char pad88[8];
    int f90; float f94; int f98;
    char pad9C[4];
    int fA0; float fA4;
    char padA8[8];
    float fB0;
};
extern "C" {
void InitLo();
void InitLaunch(Launch *self) {
    InitLo();
    self->a0 = 0;
    int *a = &self->a0;
    int *c = &self->f90;
    a[1] = 0;
    a[2] = 0;
    self->f80 = 0;
    self->f84 = 3.4028235e38f;
    self->f90 = 0;
    ((float *)c)[1] = 1.0f;
    c[2] = 0;
    self->fB0 = 0.5f;
    self->fA4 = 3.4028235e38f;
    self->fA0 = 0;
}
}
