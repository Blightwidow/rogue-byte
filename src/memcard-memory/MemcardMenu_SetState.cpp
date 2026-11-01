struct O;
struct VT_1ACB58 {
    char pad0[0x50]; short delta50; short pad52; void (*fn54)(void *);
    char pad58[0x188 - 0x58]; short delta188; short pad18A; void (*fn18C)(void *, int);
};
struct O {
    char pad0[0xC]; VT_1ACB58 *vt; char pad10[0x14]; O *child; char pad28[0x18]; int state;
};
extern "C" {
void MemcardMenu_SetState(O *self, int state) {
    self->state = state;
    if (self->child) {
        self->vt->fn54((char *)self + self->vt->delta50);
        O *child = self->child;
        child->vt->fn18C((char *)child + child->vt->delta188, -1);
    }
}
}
