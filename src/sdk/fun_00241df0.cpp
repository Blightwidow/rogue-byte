extern "C" {
int func_00241C98(int);
int sceSifCallRpc(int *, int, int, void *, int, int *, int, int, int);
int SignalSema(int);
extern int D_002C67C0;
extern int D_002C7910;
extern int D_002C6768;
int func_00241DF0(void) {
    int *buffer;
    int result;
    if (!func_00241C98(2)) {
        return 0;
    }
    buffer = &D_002C67C0;
    result = sceSifCallRpc(&D_002C7910, 0xE, 0, 0, 0, buffer, 4, 0, 0);
    if (result < 0) {
        SignalSema(D_002C6768);
        return 0;
    }
    int value = *(int *)((unsigned int)buffer | 0x20000000);
    SignalSema(D_002C6768);
    return value;
}
}
