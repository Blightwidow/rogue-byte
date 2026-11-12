// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct SifClient_2425F0 {
    char field_0x0[0x24];
    int field_0x24;
};
extern SifClient_2425F0 B_00450510;
extern int B_00450550;
extern char D_002C81C0[];
extern int D_002C6750;
extern volatile int D_002C6770; // volatile-ok: semaphore id shared with the CD library's other threads
extern int D_002C6780;
extern int D_002C6790;
int sceSifBindRpc(SifClient_2425F0 *client, unsigned int rpcNumber, unsigned int mode);
int sceSifCallRpc(SifClient_2425F0 *client, int rpcNumber, int mode, void *sendBuffer, int sendSize,
                  void *receiveBuffer, int receiveSize, void *endFunction, void *endParameter);
void sceSifInitRpc(int);
int PollSema(int);
void SignalSema(int);
void func_00236960(const char *, ...);
void func_00241A30(void);
int func_00239450(void);
void func_002394A0(void);
void func_0023B170(void *, int);
int sceCdDiskReady(int);

int func_002425F0(int mode)
{
    int retries;
    int spinCount;
    int interruptsWereEnabled;
    int result;

    if (D_002C6750 > 0) {
        func_00236960("NEW DiskReady Call\n");
    }
    func_00241A30();
    if (D_002C6770 != PollSema(D_002C6770)) {
        return (mode != 8) ? 6 : -1;
    }
    sceSifInitRpc(0);
    retries = 0;
    if (D_002C6790 < 0) {
        for (;;) {
            if (sceSifBindRpc(&B_00450510, 0x8000059C, 0) < 0) {
                if (D_002C6750 > 0) {
                    func_00236960("Libcdvd bind err CdDiskReady\n");
                }
                spinCount = 0x100000;
                do {
                    spinCount--;
                } while (spinCount != -1);
            } else {
                if (B_00450510.field_0x24 != 0) {
                    D_002C6790 = 0;
                    break;
                }
                if (retries >= 0x11) {
                    SignalSema(D_002C6770);
                    return sceCdDiskReady(mode);
                }
                spinCount = 0x100000;
                do {
                    spinCount--;
                } while (spinCount != -1);
                retries++;
            }
        }
    }
    interruptsWereEnabled = func_00239450();
    D_002C6780 = 0;
    if (interruptsWereEnabled != 0) {
        func_002394A0();
    }
    B_00450550 = mode;
    func_0023B170(&B_00450550, 4);
    if (sceSifCallRpc(&B_00450510, 0, 0, &B_00450550, 4, D_002C81C0, 4, 0, 0) < 0) {
        SignalSema(D_002C6770);
        return (mode != 8) ? 6 : -1;
    }
    if (D_002C6750 > 0) {
        func_00236960("DiskReady ended\n");
    }
    result = *(int *)((int)D_002C81C0 | 0x20000000);
    SignalSema(D_002C6770);
    return result;
}
}
