typedef short s16;
struct VT { char pad[0x10]; s16 d10; s16 u10; void (*f14)(void *); };
struct Obj { char pad0[0xC]; VT *vt; char pad1[0x42]; s16 s52; };
extern "C" {
void ContinueAmb(Obj *);
void SetAmbGrf(Obj *, int, int);
void func_001FCC30(int flag, long arg1) {
    Obj *self = (Obj *)(int)arg1;
    if (flag != 0) {
        self->s52 = 0;
        ContinueAmb(self);
    } else {
        SetAmbGrf(self, 0x1000, 0x1000);
    }
    self->vt->f14((char *)self + self->vt->d10);
}
}
