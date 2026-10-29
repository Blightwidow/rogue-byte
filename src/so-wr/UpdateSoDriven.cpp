typedef void (*UpdateSoDrivenCall_229798)(void *, void *);

void UpdateSoDriven(char *arg0) {
    char *node = *(char **)(arg0 + 0x138);
    while (node != 0) {
        char *owner = *(char **)node;
        char *vtable = *(char **)(owner + 0xC);
        UpdateSoDrivenCall_229798 call = *(UpdateSoDrivenCall_229798 *)(vtable + 0x23C);
        call(owner + *(short *)(vtable + 0x238), node);
        node = *(char **)(node + 0x8);
    }
}
