typedef int s32; typedef short s16;
struct Obj_1ACB58;
struct VT_1ACB58 {
    char pad0[0x58]; s16 delta58; s16 pad5A; void (*fn5C)(void *);
    char pad60[0x190 - 0x60]; s16 delta190; s16 pad18A; void (*fn194)(void *, Obj_1ACB58 *);
};
struct Obj_1ACB58 {
    char pad0[0xC]; VT_1ACB58 *vt; char pad10[0x24 - 0x10]; Obj_1ACB58 *child; char pad28[0x40 - 0x28]; s32 state;
};
static inline void Notify2(Obj_1ACB58 *obj) {
    obj->vt->fn194((char *)obj + obj->vt->delta190, obj);
}
extern "C" {
void MemcardMenu_ClearState(Obj_1ACB58 *arg0) {
    arg0->state = -1;
    if (arg0->child) {
        arg0->vt->fn5C((char *)arg0 + arg0->vt->delta58);
        Notify2(arg0->child);
    }
}
}
