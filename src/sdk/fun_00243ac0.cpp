extern "C" {
extern char B_00450580[];
extern int B_004507C0[];
int func_00243458(int, int, int);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int func_00243AC0(int port, int slot, int mode) {
    B_004507C0[0] = 10;
    B_004507C0[3] = mode;
    B_004507C0[1] = port;
    B_004507C0[2] = slot;
    if (sceSifCallRpc(B_00450580, 1, 0, B_004507C0, 0x80, B_004507C0, 0x80, 0, 0) < 0) return 0;
    if (B_004507C0[4] == 1) func_00243458(port, slot, 2);
    return B_004507C0[4];
}
}
