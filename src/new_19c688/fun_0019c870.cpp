struct Owner { char p0[0x520]; int f520; };
struct Obj { Owner *owner; char p4[0x18]; int f1C; char p20[0xA0]; int fC0; int fC4; };
extern "C" int func_0019C870(Obj *self, int *out) {
    int result; int kind = self->f1C;
    switch (kind) { case 0xB: case 0xC: case 0xD: result = self->owner->f520; break; case 0x11: result = self->fC4; break; default: result = self->fC0; }
    *out = 0;
    return result;
}
