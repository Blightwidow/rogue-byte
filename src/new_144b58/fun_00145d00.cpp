struct VT_145D00 { char pad[0x2F8]; short delta; short unused; void (*fn)(void *, int, int, int, int); };
struct Inner_145D00 { char pad[0xC]; VT_145D00 *vt; char pad2[0x10E0 - 0x10]; unsigned flags; };
struct Obj_145D00 { char pad[0x10]; Inner_145D00 *inner; char pad2[0x38 - 0x14]; int value; };
extern "C" {
void func_001EEF70(void *);
void func_00146158(void *, int);
void func_00145D00(Obj_145D00 *self) {
    func_001EEF70(self);
    func_00146158(self, 0);
    Inner_145D00 *inner = self->inner;
    inner->vt->fn((char *)inner + inner->vt->delta, 4, self->value, 4, self->value);
    self->inner->flags |= 1;
}
}
