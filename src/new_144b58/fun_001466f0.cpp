struct VT_1466F0 { char pad[0x2F8]; short delta; short unused; void (*fn)(void *, int, int, int, int); };
struct Inner_1466F0 { char pad[0xC]; VT_1466F0 *vt; char pad2[0x10E0 - 0x10]; unsigned flags; };
struct Obj_1466F0 { char pad[0x10]; Inner_1466F0 *inner; char pad2[0x38 - 0x14]; int value; };
extern "C" {
void func_001EEF70(void *);
void func_00146E18(void *, int);
void func_001466F0(Obj_1466F0 *self) {
    func_001EEF70(self);
    func_00146E18(self, 0);
    Inner_1466F0 *inner = self->inner;
    inner->vt->fn((char *)inner + inner->vt->delta, 4, self->value, 4, self->value);
    self->inner->flags |= 1;
}
}
