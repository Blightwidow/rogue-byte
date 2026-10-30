struct VT_1E5468 { char pad[0x190]; short delta; short unused; void (*fn)(void *); };
struct Obj_1E5468 { char pad[0xC]; VT_1E5468 *vt; };
struct Holder_1E5468 { char pad[0x64]; Obj_1E5468 *child; };
extern "C" void func_001E5468(Holder_1E5468 *self) {
    Obj_1E5468 *child = self->child;
    if (child != 0) {
        child->vt->fn((char *)child + child->vt->delta);
        self->child = 0;
    }
}
