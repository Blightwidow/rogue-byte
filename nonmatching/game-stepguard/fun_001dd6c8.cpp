typedef int s32; typedef short s16;
struct Obj_1DD6C8;
struct VT_1DD6C8 {
    char pad0[0x50]; s16 delta50; s16 pad52; void (*fn54)(void *);
    char pad58[0x188 - 0x58]; s16 delta188; s16 pad18A; void (*fn18C)(void *, s32, Obj_1DD6C8 *);
};
struct Obj_1DD6C8 {
    char pad0[0xC]; VT_1DD6C8 *vt; char pad10[0x24 - 0x10]; Obj_1DD6C8 *child;
};
extern "C" {
void func_001DD6C8(Obj_1DD6C8 *arg0) {
    if (arg0->child) {
        arg0->vt->fn54((char *)arg0 + arg0->vt->delta50);
        Obj_1DD6C8 *child = arg0->child;
        VT_1DD6C8 *vt = child->vt;
        void (*fn)(void *, s32, Obj_1DD6C8 *) = vt->fn18C;
        s32 delta = vt->delta188;
        fn((char *)child + delta, -1, child);
    }
}
}
