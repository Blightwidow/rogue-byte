// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
void memclr(void* destination, int size);
int sceDmaPutEnv(void* environment);
extern int RO_002AB380[];
extern volatile int* D_002C6710[]; // volatile-ok: DMA channel register blocks (0x10008000-0x1000D400)

int sceDmaReset(int mode) {
    char environment[0x14];
    int previousEnable = *(volatile int*)0x1000E000 & 1;
    int channelIndex;

    for (channelIndex = 0; channelIndex < 10; channelIndex++) {
        if (RO_002AB380[channelIndex] != 0) {
            volatile int* channel = D_002C6710[channelIndex]; // volatile-ok: one DMA channel register block
            channel[0x80 / 4] = 0;
            channel[0x00 / 4] = 0;
            channel[0x30 / 4] = 0;
            channel[0x10 / 4] = 0;
            channel[0x50 / 4] = 0;
            channel[0x40 / 4] = 0;
        }
    }
    *(volatile int*)0x1000E010 = 0xFF1F;
    *(int*)0x1000E010 = *(volatile int*)0x1000E010 & 0xFF1F0000;
    memclr(environment, 0x14);
    sceDmaPutEnv(environment);
    if (mode == 1) {
        *(volatile int*)0x1000E000 |= 1;
    }
    return previousEnable;
}
}
