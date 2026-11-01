struct Obj_1DD728;
struct VT_1DD728 {
    char pad0[0x58]; short delta58; short pad5A; void (*fn5C)(void *);
    char pad60[0x190 - 0x60]; short delta190; short pad192; void (*fn194)(void *);
};
struct Obj_1DD728 {
    char pad0[0xC]; VT_1DD728 *vt; char pad10[0x24 - 0x10]; Obj_1DD728 *child;
};
extern "C" {
void func_001DD728(Obj_1DD728 *arg0) {
    if (arg0->child) {
        arg0->vt->fn5C((char *)arg0 + arg0->vt->delta58);
        Obj_1DD728 *child = arg0->child;
        child->vt->fn194((char *)child + child->vt->delta190);
    }
}
}
