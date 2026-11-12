// SPDX-License-Identifier: GPL-3.0-or-later
struct DmaEnvironment {
    unsigned char stallSource;
    unsigned char stallDrain;
    unsigned char releaseCycle;
    unsigned char memoryDrainMode;
    unsigned short field04;
    unsigned short field06;
    unsigned short field08;
    unsigned short field0A;
    unsigned int field0C;
    unsigned int field10;
};

extern "C" {
extern unsigned char RO_002AB3A8[];
extern unsigned char RO_002AB3B8[];
extern unsigned char RO_002AB3C8[];
extern DmaEnvironment B_00450280;

int sceDmaPutEnv(DmaEnvironment* environment) {
    unsigned int control = *(volatile unsigned int*)0x1000E000;
    unsigned int ringBufferStart = *(volatile unsigned int*)0x1000E020;
    unsigned int ringBufferSize = *(volatile unsigned int*)0x1000E030;
    unsigned int holdAddress = *(volatile unsigned int*)0x1000E050;
    unsigned int holdCount = *(volatile unsigned int*)0x1000E040;

    if (environment->stallSource >= 10) {
        return -1;
    }
    if (environment->stallDrain >= 10) {
        return -2;
    }
    if (environment->releaseCycle >= 10) {
        return -3;
    }
    if (environment->memoryDrainMode >= 7) {
        return -4;
    }
    control = (control & ~0x30) | (RO_002AB3A8[environment->stallSource] << 4);
    control = (control & ~0xC0) | (RO_002AB3B8[environment->stallDrain] << 6);
    control = (control & ~0xC) | (RO_002AB3C8[environment->releaseCycle] << 2);
    if (environment->memoryDrainMode != 0) {
        control |= 2;
        control = (control & ~0x300) | ((environment->memoryDrainMode - 1) << 8);
    } else {
        control &= ~2;
    }
    ringBufferStart = (environment->field04 << 16) | environment->field06;
    ringBufferSize = (environment->field0A << 16) | environment->field08;
    holdCount = environment->field10;
    holdAddress = environment->field0C;
    *(volatile unsigned int*)0x1000E000 = control;
    *(volatile unsigned int*)0x1000E020 = ringBufferStart;
    *(volatile unsigned int*)0x1000E030 = ringBufferSize;
    *(volatile unsigned int*)0x1000E050 = holdAddress;
    *(volatile unsigned int*)0x1000E040 = holdCount;
    B_00450280 = *environment;
    return 0;
}
}
