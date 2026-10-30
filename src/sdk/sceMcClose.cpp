struct McClient_450880 { int pad0[9]; int server; int pad28[7]; };
extern "C" {
int PollSema(int);
int SignalSema(int);
void func_00243ED8(void *);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern McClient_450880 B_00450880;
extern int B_00450900[];
extern int B_00451E40[];
extern int D_002C8350;
extern int D_002C8354;
int sceMcClose(int fd) {
    if (B_00450880.server == 0) {
        return -0x64;
    }
    if (PollSema(D_002C8354) < 0) {
        return -0xC8;
    }
    B_00450900[0] = fd;
    if (sceSifCallRpc(&B_00450880, 3, 1, B_00450900, 0x30, B_00451E40, 4, (void *)func_00243ED8, 0) != 0) {
        SignalSema(D_002C8354);
        return -0x5B;
    }
    D_002C8350 = 3;
    return 0;
}
}
