// SPDX-License-Identifier: GPL-3.0-or-later
extern int D_002C6750;
extern int D_002C6780;
extern volatile int D_002C676C;  // volatile-ok: the CD library semaphore id (a library semaphore id shared between threads), signalled on every exit
extern int D_002C6790;
extern int D_002C7940[];
extern int B_00450550;
extern char B_00450510[];
extern int PollSema(int);
extern int SignalSema(int);
extern void func_00236960(const char *);
extern int func_00239450(void);
extern void func_002394A0(void);
extern void func_00241A30(void);
extern int func_00241F28(int);
extern void func_0023B170(void *, int);
extern void sceSifInitRpc(int);
extern int sceSifBindRpc(void *, int, int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);

int sceCdDiskReady(int mode)
{
    int delay;
    int result;
    if (D_002C6750 > 0) {
        func_00236960("OLD DiskReady Call\n");
    }
    result = func_00239450();
    D_002C6780 = 1;
    if (result != 0) {
        func_002394A0();
    }
    func_00241A30();
    if (D_002C676C != PollSema(D_002C676C)) {
        return 6;
    }
    if (func_00241F28(1) != 0) {
        goto fail;
    }
    sceSifInitRpc(0);
    if (D_002C6790 < 0) {
        goto bind;
retry:
        delay = 0x100000;
        do {
            delay -= 1;
        } while (delay != -1);
bind:
        if (sceSifBindRpc(B_00450510, 0x8000059A, 0) < 0) {
            if (D_002C6750 > 0) {
                func_00236960("Libcdvd bind err CdDiskReady\n");
            }
            delay = 0x100000;
            do {
                delay -= 1;
            } while (delay != -1);
            goto bind;
        }
        if (*(int *)(B_00450510 + 0x24) == 0) {
            goto retry;
        }
        D_002C6790 = 0;
    }
    B_00450550 = mode;
    func_0023B170(&B_00450550, 4);
    if (sceSifCallRpc(B_00450510, 0, 0, &B_00450550, 4, D_002C7940, 4, 0, 0) < 0) {
fail:
        SignalSema(D_002C676C);
        return mode != 8 ? 6 : -1;
    }
    if (D_002C6750 > 0) {
        func_00236960("DiskReady ended\n");
    }
    result = *(int *)((unsigned int)D_002C7940 | 0x20000000);
    SignalSema(D_002C676C);
    return result;
}
