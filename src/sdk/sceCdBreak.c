extern volatile int D_002C67A0;  // volatile-ok: CD library busy flag, set to 8 around the RPC here and written by the interrupt callback func_002418C8 (it calls iSignalSema)
extern volatile int D_002C676C;  // volatile-ok: the CD library semaphore id (a library semaphore id shared between threads), signalled on every exit
extern char B_002C82C0[];
extern int B_002C7940[];
extern int func_00241F98(int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
extern int SignalSema(int);
int sceCdBreak(void)
{
    int result;
    if (func_00241F98(0x1e) == 0)
        return 0;
    D_002C67A0 = 8;
    if (sceSifCallRpc(B_002C82C0, 0x16, 0, 0, 0, B_002C7940, 4, 0, 0) < 0) {
        SignalSema(D_002C676C);
        D_002C67A0 = 0;
        return 0;
    }
    D_002C67A0 = 0;
    result = *(int *)((unsigned int)B_002C7940 | 0x20000000);
    SignalSema(D_002C676C);
    return result;
}
