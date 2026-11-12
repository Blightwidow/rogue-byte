// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
struct MpegDecoder {
    u8 pad0[0x12C];
    int lastCodeZero;
    u8 pad130[0x828 - 0x130];
    int commandPending;
    unsigned commandState;
    u8 pad830[0x848 - 0x830];
    int topBits;
    int bitsAvailable;
};
void func_00252358(MpegDecoder *decoder);
long func_00251FC8(MpegDecoder *decoder);
int func_00252148(MpegDecoder *decoder, int bitCount);

static inline void SendVlcCommand(MpegDecoder *decoder) {
    decoder->commandPending = 0;
    decoder->commandState = 0x30000000;
}

static inline short ReadVlcResult(MpegDecoder *decoder) {
    long result;
    u32 bitPosition;
    long top;
    result = func_00251FC8(decoder);
    bitPosition = *(volatile u32 *)0x10002020;
    top = *(volatile long *)0x10002030;
    decoder->topBits = (int)top;
    if (top < 0) {
        decoder->bitsAvailable = (32 - (bitPosition & 0x1F)) & 0x1F;
    } else {
        decoder->bitsAvailable = 32;
    }
    decoder->lastCodeZero = (int)result == 0;
    return (short)(u16)result;
}

static inline short GetMotionCode(MpegDecoder *decoder) {
    func_00252358(decoder);
    *(volatile u32 *)0x10002000 = 0x38000000;
    SendVlcCommand(decoder);
    return ReadVlcResult(decoder);
}

static inline short GetDualPrime(MpegDecoder *decoder) {
    func_00252358(decoder);
    *(volatile u32 *)0x10002000 = 0x3C000000;
    SendVlcCommand(decoder);
    return ReadVlcResult(decoder);
}

static inline void DecodeMotionVector(int *prediction, int rangeSize, int motionCode, int residual, int fullPel) {
    int limit = 16 << rangeSize;
    int vector = fullPel ? (*prediction >> 1) : *prediction;
    if (motionCode > 0) {
        vector += ((motionCode - 1) << rangeSize) + residual + 1;
        if (vector >= limit) {
            vector -= limit + limit;
        }
    } else if (motionCode < 0) {
        vector -= ((-motionCode - 1) << rangeSize) + residual + 1;
        if (vector < -limit) {
            vector += limit + limit;
        }
    }
    *prediction = fullPel ? (vector << 1) : vector;
}

void func_002511C8(MpegDecoder *decoder, int *prediction, int *dualPrime, int horizontalRange, int verticalRange,
                   int dualPrimeFlag, int scaleVertical, int fullPel) {
    int motionCode;
    int residual;

    motionCode = GetMotionCode(decoder);
    residual = (horizontalRange != 0 && motionCode != 0) ? func_00252148(decoder, horizontalRange) : 0;
    DecodeMotionVector(&prediction[0], horizontalRange, motionCode, residual, fullPel);
    if (dualPrimeFlag) {
        dualPrime[0] = GetDualPrime(decoder);
    }

    motionCode = GetMotionCode(decoder);
    residual = (verticalRange != 0 && motionCode != 0) ? func_00252148(decoder, verticalRange) : 0;
    if (scaleVertical) {
        prediction[1] >>= 1;
    }
    DecodeMotionVector(&prediction[1], verticalRange, motionCode, residual, fullPel);
    if (scaleVertical) {
        prediction[1] <<= 1;
    }
    if (dualPrimeFlag) {
        dualPrime[1] = GetDualPrime(decoder);
    }
}
}
