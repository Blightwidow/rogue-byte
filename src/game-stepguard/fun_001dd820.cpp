struct Obj_1DD820;
struct VT_1DD820 {
    char pad0[0x50]; short delta50; short pad52; void (*fn54)(void *);
    char pad58[0x188 - 0x58]; short delta188; short pad18A; void (*fn18C)(void *, int);
};
struct Obj_1DD820 {
    char pad0[0xC]; VT_1DD820 *vt; char pad10[0x24 - 0x10]; Obj_1DD820 *child;
};
extern "C" {
void RumbleUnknown1__Fv();
void func_001DD820(Obj_1DD820 *arg0) {
    if (arg0->child) {
        arg0->vt->fn54((char *)arg0 + arg0->vt->delta50);
        Obj_1DD820 *child = arg0->child;
        child->vt->fn18C((char *)child + child->vt->delta188, -1);
        RumbleUnknown1__Fv();
    }
}
}
