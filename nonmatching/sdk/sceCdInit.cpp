typedef unsigned int u32;
extern "C" {
struct SifClient { char pad0[0x24]; int serverReady; };
int func_00241F28(int arg);
void sceSifInitRpc(int mode);
int sceSifBindRpc(SifClient *client, u32 serverId, int mode);
int sceSifCallRpc(SifClient *client, int rpcNumber, int mode, void *sendBuffer, int sendSize, void *receiveBuffer, int receiveSize, void *endFunction, void *endArgument);
int func_00236960(const char *format, ...);
void func_0023B170(void *address, int size);
void func_00241B18();
void func_00241A30();
void func_00241C10();
extern int D_002C6764;
extern int D_002C6788;
extern int D_002C678C;
extern int D_002C677C;
extern int D_002C6794;
extern int D_002C6790;
extern int D_002C6778;
extern int D_002C679C;
extern int D_002C6798;
extern int D_002C6750;
extern int D_002C6768;
extern int D_002C676C;
extern int D_002C6760;
extern int D_002C6784;
extern int D_002C7940[4];
extern int B_00450540;
extern SifClient B_004504E8;
int sceCdInit(int mode) {
    int status;
    int result;
    int delay;
    int first;
    int second;
    int third;
    if (func_00241F28(1) != 0) {
        return 0;
    }
    sceSifInitRpc(0);
    D_002C6764 = 1;
    D_002C6788 = -1;
    D_002C678C = -1;
    D_002C677C = -1;
    D_002C6794 = -1;
    D_002C6790 = -1;
    D_002C6778 = 0;
    D_002C679C = D_002C679C + 1;
    D_002C6798 = -1;
    for (;;) {
        result = sceSifBindRpc(&B_004504E8, 0x80000592, 0);
        if (result < 0) {
            if (D_002C6750 > 0) {
                func_00236960("Libcdvd bind err %d CD_Init %d\n", result, D_002C679C);
            }
            for (delay = 0x100000; delay != -1; delay--) {
            }
            continue;
        }
        if (B_004504E8.serverReady == 0) {
            for (delay = 0x100000; delay != -1; delay--) {
            }
            continue;
        }
        break;
    }
    B_00450540 = mode;
    D_002C6798 = 0;
    func_0023B170(&B_00450540, 4);
    if (sceSifCallRpc(&B_004504E8, 0, 0, &B_00450540, 4, D_002C7940, 0x10, 0, 0) < 0) {
        D_002C6764 = 0;
        return 0;
    }
    first = *(int *)((u32)&D_002C7940[3] | 0x20000000);
    second = *(int *)((u32)&D_002C7940[1] | 0x20000000);
    third = *(int *)((u32)&D_002C7940[2] | 0x20000000);
    status = 1;
    if (first != 0xFF) {
        if (first == 0xFE) {
            D_002C6750 = status;
        } else if (second / 256 < 2) {
            status = 2;
        } else if (third / 256 < 2) {
            status = 2;
        }
    }
    D_002C6764 = 0;
    if (mode >= 0 && mode >= 2 && mode == 5) {
        if (D_002C6750 > 0) {
            func_00236960("Libcdvd Exit\n");
        }
        func_00241B18();
        D_002C6768 = -1;
        D_002C676C = -1;
        D_002C6760 = -1;
        D_002C6784 = 0;
    } else {
        func_00241A30();
        func_00241C10();
        D_002C6784 = 1;
    }
    return status;
}
}
