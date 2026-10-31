typedef int s32; typedef short s16;
struct Obj_1ACB58;
struct VT_1ACB58 {
    char pad0[0x50]; s16 delta50; s16 pad52; void (*fn54)(void *);
    char pad58[0x188 - 0x58]; s16 delta188; s16 pad18A; void (*fn18C)(void *, s32, Obj_1ACB58 *);
};
struct Obj_1ACB58 {
    char pad0[0xC]; VT_1ACB58 *vt; char pad10[0x24 - 0x10]; Obj_1ACB58 *child; char pad28[0x40 - 0x28]; s32 state;
};
static inline void Notify(Obj_1ACB58 *obj) {
    obj->vt->fn18C((char *)obj + obj->vt->delta188, -1, obj);
}
extern "C" {
void MemcardMenu_SetState(Obj_1ACB58 *arg0, s32 arg1) {
    arg0->state = arg1;
    if (arg0->child) {
        arg0->vt->fn54((char *)arg0 + arg0->vt->delta50);
        Notify(arg0->child);
    }
}
}
