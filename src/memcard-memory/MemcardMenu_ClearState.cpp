struct O;
struct VT_1ACBB8 {
    char pad0[0x58]; short delta58; short pad5A; void (*fn5C)(void *);
    char pad60[0x190 - 0x60]; short delta190; short pad192; void (*fn194)(void *);
};
struct O {
    char pad0[0xC]; VT_1ACBB8 *vt; char pad10[0x14]; O *child; char pad28[0x18]; int state;
};
extern "C" {
void MemcardMenu_ClearState(O *self) {
    self->state = -1;
    if (self->child) {
        self->vt->fn5C((char *)self + self->vt->delta58);
        O *child = self->child;
        child->vt->fn194((char *)child + child->vt->delta190);
    }
}
}
