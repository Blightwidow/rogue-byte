// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct SndCall {
    void (*function)(int, long);
    long argument;
};
extern int D_002C4640;
extern int D_002C4654;
extern int D_002C4688;
extern int D_002C465C;
extern void (*D_002C46A4)(int, long);
extern long D_002C46A8;
extern int B_00443844;
extern int D_002C4680;
extern int *D_002C4660[];
extern SndCall *D_002C4670[];
extern int *D_002C4678[];
extern unsigned int B_00448480;
extern SndCall D_002C4690;
extern int D_002C4684;
extern int D_002C4658;
extern void (*D_002C4650)(int);
int snd_GotReturns__Fv(void);
void FlushCache(int);
void snd_SendCurrentBatch__Fv(void);
void snd_StreamSafeCdSync(int);

int snd_FlushSoundCommands(void) {
    if (D_002C4640 != 0) {
        if (snd_GotReturns__Fv() != 0) {
            if (D_002C465C != 0) {
                if (D_002C46A4 != 0) {
                    D_002C46A4(B_00443844, D_002C46A8);
                }
                D_002C46A4 = 0;
                D_002C465C = 0;
            } else {
                int slot = D_002C4680 != 1;
                for (int index = 0; index < *D_002C4660[slot]; index++) {
                                        if (D_002C4670[slot][index].function != 0) {
                        D_002C4670[slot][index].function(D_002C4678[slot][index + 1], D_002C4670[slot][index].argument);
                    }
                }
            }
        }
    }
    if (D_002C4688 != 0) {
        FlushCache(0);
        if (B_00448480 != 0xFFFFFFFF) {
            if (D_002C4690.function != 0) {
                void (*function)(int, long) = D_002C4690.function;
                long argument = D_002C4690.argument;
                D_002C4690.function = 0;
                D_002C4690.argument = 0;
                function(B_00448480, argument);
            }
            B_00448480 = 0;
            D_002C4688 = 0;
        }
    }
    if (D_002C4640 == 0) {
        int *queue = D_002C4660[D_002C4680];
        if (*queue != 0 && D_002C4684 == 0) {
            snd_SendCurrentBatch__Fv();
        }
    }
    if (D_002C4654 != 0) {
        snd_StreamSafeCdSync(1);
        if (D_002C4658 != 0) {
            D_002C4654 = 0;
            void (*callback)(int) = D_002C4650;
            D_002C4658 = 0;
            if (callback != 0) {
                callback(1);
            }
        }
    }
    if (D_002C4640 != 0 || D_002C4688 != 0) {
        return 1;
    }
    return 0;
}
}
