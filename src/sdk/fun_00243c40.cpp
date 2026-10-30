extern "C" {
extern char B_00450580[];
extern int B_004507C0[];
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int func_00243C40(void) {
    B_004507C0[0] = 0x12;
    int status = sceSifCallRpc(B_00450580, 1, 0, B_004507C0, 0x80, B_004507C0, 0x80, 0, 0);
    if (status < 0) return 0;
    return B_004507C0[3];
}
}
