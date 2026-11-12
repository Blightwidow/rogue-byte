extern "C" {
void FlushCache(int);
void func_00234F48(int *, int *);
int printf(const char *, ...);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
int sceSifCheckStatRpc(void *);
void snd_FlushSoundCommands(void);
int snd_StreamSafeCdSync(int);
extern char B_00448440[];
extern int B_00448480;
extern int B_004484C0[2];
extern int D_002C4648;
extern int D_002C4688;
extern int D_002C46B8;
extern char RO_002AA1C8[];
int snd_BankLoadByLoc(int arg0, int arg1) {
    D_002C4648 = 0;
    const char *message;
    if (D_002C4688 != 0) {
        if (D_002C46B8 != 0)
            return 0;
        message = "snd_BankLoadByLoc: Load already in progress!\n";
        goto report;
    }
    if (snd_StreamSafeCdSync(1) == 1) {
        if (D_002C46B8 != 0)
            return 0;
        message = "snd_BankLoadByLoc: CD BUSY!\n";
    report:
        printf(message);
        return 0;
    }
    B_00448480 = 0xFFFFFFFF;
    func_00234F48(&B_00448480, &B_00448480 + 1);
    B_004484C0[0] = arg0;
    B_004484C0[1] = arg1;
    while (sceSifCheckStatRpc(B_00448440) != 0) {
        if (D_002C46B8 == 0) {
            printf(RO_002AA1C8);
        }
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    if (sceSifCallRpc(B_00448440, 3, 1, B_004484C0, 8, &B_00448480, 4, 0, 0) < 0) {
        if (D_002C46B8 == 0) {
            printf("989snd.c: RPC call has failed inside snd_BankLoadByLoc\n");
        }
        D_002C4648 = 0x106;
        return 0;
    }
    if (B_00448480 == 0xFFFFFFFF) {
        do {
            FlushCache(0);
        } while (B_00448480 == 0xFFFFFFFF);
    }
    return B_00448480;
}
}
