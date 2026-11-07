extern "C" {
struct PadClient { char pad0[0x24]; int serverReady; };
int sceSifBindRpc(PadClient *client, int serverId, int mode);
int func_00243C40();
int func_00242E90(int arg);
int func_00236960(const char *format, ...);
extern int D_002C8308;
extern int D_002C830C;
extern PadClient B_00450580[2];
int scePadInit(int arg) {
    int delay;
    int version;
    int major;
    D_002C8308 = 1;
    for (;;) {
        sceSifBindRpc(&B_00450580[0], 0x80000100, 0);
        if (B_00450580[0].serverReady != 0) {
            break;
        }
        for (delay = 0x10000; delay != -1; delay--) {
        }
    }
    for (;;) {
        sceSifBindRpc(&B_00450580[1], 0x80000101, 0);
        if (B_00450580[1].serverReady != 0) {
            break;
        }
        for (delay = 0x10000; delay != -1; delay--) {
        }
    }
    version = func_00243C40();
    major = version >> 8;
    if (major != 4) {
        if (D_002C830C != 0) {
            func_00236960("libpad: Module version mismatch ");
            func_00236960("[libpad.a = %d.%d, padman.irx = %d.%d]\n", 4, 0, major, version & 0xFF);
        }
        return 0;
    }
    return func_00242E90(arg);
}
}
