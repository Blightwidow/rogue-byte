// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
void FlushCache(int);
void func_00231F38(void *, int);
void *memcpy(void *, const void *, unsigned int);
int printf(const char *, ...);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
int sceSifCheckStatRpc(void *);
void snd_FlushSoundCommands(void);
int snd_GotReturns__Fv(void);
void snd_SendCurrentBatch__Fv(int);
extern char B_00443800[];
extern int B_00443840[];
extern char B_00443880[];
extern char B_0044388C[];
extern int D_002C4640;
extern int *D_002C4660[];
extern int D_002C4680;
extern int D_002C4684;
extern int D_002C46B8;
extern char RO_002AA1C8[];
struct ExternalCommand {
    int field0;
    int field4;
    unsigned int length;
    char *data;
};
int func_002325E0(int command, int size, ExternalCommand *payload) {
    char *sourceBytes = (char *)payload;
    if (command != 0x68) {
        for (int index = 0; index < size; index++) {
            B_00443880[index] = sourceBytes[index];
        }
    } else {
        if (payload->length + 0xC > 0x200) {
            printf("989snd ERROR: cannot send external command larger then 500 bytes!\n");
            for (;;) {
            }
        }
        for (int index = 0; index < 0xC; index++) {
            B_00443880[index] = sourceBytes[index];
        }
        memcpy(B_0044388C, payload->data, payload->length);
    }
    while (D_002C4640 != 0) {
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    func_00231F38(B_00443840, 1);
    while (sceSifCheckStatRpc(B_00443800) != 0) {
        if (D_002C46B8 == 0) {
            printf(RO_002AA1C8);
        }
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    if (size != 0) {
        sceSifCallRpc(B_00443800, command, 1, B_00443880, size, B_00443840, 0xC, 0, 0);
    } else {
        sceSifCallRpc(B_00443800, command, 1, 0, 0, B_00443840, 0xC, 0, 0);
    }
    while (snd_GotReturns__Fv() == 0) {
    }
    int result = B_00443840[1];
    if (*D_002C4660[D_002C4680] != 0) {
        if (D_002C4684 == 0) {
            snd_SendCurrentBatch__Fv(*D_002C4660[D_002C4680]);
        }
    }
    return result;
}
}
