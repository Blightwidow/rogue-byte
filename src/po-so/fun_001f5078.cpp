struct VT_1F5078 { char pad[0x178]; short delta; short unused; void (*fn)(void *, int); };
struct Obj_1F5078 { char pad0[0xC]; VT_1F5078 *vt; char pad1[0x58 - 0x10]; int a58; int a5c; char pad2[0xE8 - 0x60]; int e8; int ec; };
extern "C" {
void WakeXf(void *, int);
void func_001F5078(Obj_1F5078 *self) {
    if (self->ec != 0) {
        self->vt->fn((char *)self + self->vt->delta, 4);
        if (self->e8 != 0) {
            WakeXf(self, self->a58);
            WakeXf(self, self->a5c);
        }
    }
}
}
