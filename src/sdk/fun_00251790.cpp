// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
struct MpegFrameBuffer {
    u8 pad0[0x4];
    void *coefficients;
    u8 pad8[0x13C - 0x8];
    int noCoefficients;
};
struct MpegDecoder {
    u8 pad0[0x12C];
    int fault;
    u8 pad130[0x160 - 0x130];
    int pictureCodingType;
    int fullPelForward;
    int forwardCode;
    int fullPelBackward;
    int backwardCode;
    int motionCode[2][2];
    int pictureStructure;
    u8 pad188[0x18C - 0x188];
    int framePredFrameDct;
    int concealmentVectors;
    u8 pad194[0x1C0 - 0x194];
    int resetDcPredictor;
    int quantizerScaleCode;
    u8 pad1C8[0x5A0 - 0x1C8];
    MpegFrameBuffer buffers[2];
    u8 pad820[0x820 - 0x820];
    int bufferIndex;
    u8 pad824[0x828 - 0x824];
    int commandPending;
    unsigned commandState;
    u8 pad830[0x848 - 0x830];
    int topBits;
    int bitsAvailable;
    u8 pad850[0x858 - 0x850];
    int mpeg2;
};
extern const char RO_STR_002AC620[];
void func_00252358(MpegDecoder *decoder);
long func_00251FC8(MpegDecoder *decoder);
int func_00252148(MpegDecoder *decoder, int bitCount);
void func_00252390(MpegDecoder *decoder, int bitCount);
void func_0024FA38(MpegDecoder *decoder, const char *message);
void func_00253478(void *buffer, int size);
void func_002511C8(MpegDecoder *decoder, int *prediction, int *dualPrime, int horizontalRange, int verticalRange,
                   int dualPrimeFlag, int scaleVertical, int fullPel);
void func_002515F0(MpegDecoder *decoder, int prediction[2][2][2], int *dualPrime, int fieldSelect[2][2], int direction,
                   int vectorCount, int vectorFormat, int horizontalRange, int verticalRange, int dualPrimeFlag,
                   int scaleVertical);

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
    decoder->fault = (int)result == 0;
    return (short)(u16)result;
}

static inline short GetMacroblockType(MpegDecoder *decoder) {
    func_00252358(decoder);
    *(volatile u32 *)0x10002000 = 0x34000000;
    SendVlcCommand(decoder);
    return ReadVlcResult(decoder);
}

static inline void IssueCommand(MpegDecoder *decoder, u32 command) {
    unsigned state;
    *(volatile u32 *)0x10002000 = command;
    state = command & 0xF0000000;
    decoder->commandState = state;
    if (state == 0x20000000 || state == 0x30000000 || state == 0x40000000) {
        decoder->commandPending = 0;
    } else {
        decoder->commandPending = 1;
    }
}

static inline void IssueBlockDecode(MpegDecoder *decoder, u32 flags) {
    u32 command = 0x20000000 | (decoder->quantizerScaleCode << 16);
    IssueCommand(decoder, flags | command);
}

int func_00251790(MpegDecoder *decoder, int *macroblockType, int *motionType, int *dctType, int prediction[2][2][2],
                  int fieldSelect[2][2], int *dualPrime) {
    int vectorCount;
    int vectorFormat;
    int dualPrimeFlag;
    int scaleVertical;

    *(volatile u32 *)0x10002010 = (*(volatile u32 *)0x10002010 & 0xF8FFFFFF) | (decoder->pictureCodingType << 24);
    *macroblockType = GetMacroblockType(decoder);
    if (*macroblockType == 0) {
        func_0024FA38(decoder, RO_STR_002AC620);
        decoder->fault = 1;
        return 0;
    }

    if (*macroblockType & 0xC) {
        if (decoder->pictureStructure == 3 && decoder->framePredFrameDct) {
            *motionType = 2;
        } else {
            *motionType = func_00252148(decoder, 2);
        }
    } else if ((*macroblockType & 1) && decoder->concealmentVectors) {
        *motionType = decoder->pictureStructure == 3 ? 2 : 1;
    }

    if (decoder->pictureStructure == 3) {
        vectorCount = *motionType == 1 ? 2 : 1;
        vectorFormat = *motionType == 2;
    } else {
        vectorCount = *motionType == 2 ? 2 : 1;
        vectorFormat = 0;
    }
    dualPrimeFlag = *motionType == 3;
    scaleVertical = vectorFormat == 0 && decoder->pictureStructure == 3;

    *dctType = (decoder->pictureStructure == 3 && !decoder->framePredFrameDct && (*macroblockType & 3))
                   ? func_00252148(decoder, 1)
                   : 0;

    if (*macroblockType & 0x10) {
        decoder->quantizerScaleCode = func_00252148(decoder, 5);
    }

    if ((*macroblockType & 8) || ((*macroblockType & 1) && decoder->concealmentVectors)) {
        if (decoder->mpeg2) {
            func_002515F0(decoder, prediction, dualPrime, fieldSelect, 0, vectorCount, vectorFormat,
                          decoder->motionCode[0][0] - 1, decoder->motionCode[0][1] - 1, dualPrimeFlag, scaleVertical);
        } else {
            func_002511C8(decoder, prediction[0][0], dualPrime, decoder->forwardCode - 1, decoder->forwardCode - 1, 0, 0,
                          decoder->fullPelForward);
        }
    }
    if (decoder->fault) {
        return 0;
    }

    if (*macroblockType & 4) {
        if (decoder->mpeg2) {
            func_002515F0(decoder, prediction, dualPrime, fieldSelect, 1, vectorCount, vectorFormat,
                          decoder->motionCode[1][0] - 1, decoder->motionCode[1][1] - 1, 0, scaleVertical);
        } else {
            func_002511C8(decoder, prediction[0][1], dualPrime, decoder->backwardCode - 1, decoder->backwardCode - 1, 0,
                          0, decoder->fullPelBackward);
        }
    }
    if (decoder->fault) {
        return 0;
    }

    if ((*macroblockType & 1) && decoder->concealmentVectors) {
        func_00252390(decoder, 1);
    }

    if (*macroblockType & 3) {
        func_00253478(decoder->buffers[decoder->bufferIndex].coefficients, 0x300);
        func_00252358(decoder);
        IssueBlockDecode(decoder, ((*macroblockType & 1) << 27) | ((*dctType << 25) | (decoder->resetDcPredictor << 26)));
    } else {
        decoder->buffers[decoder->bufferIndex].noCoefficients = 1;
    }

    decoder->resetDcPredictor = 0;
    if (decoder->fault) {
        return 0;
    }

    if ((*macroblockType & 1) == 0) {
        decoder->resetDcPredictor = 1;
    }
    if ((*macroblockType & 1) && !decoder->concealmentVectors) {
        prediction[0][0][0] = prediction[0][0][1] = prediction[1][0][0] = prediction[1][0][1] = 0;
        prediction[0][1][0] = prediction[0][1][1] = prediction[1][1][0] = prediction[1][1][1] = 0;
    }

    if (decoder->pictureCodingType == 2 && !(*macroblockType & 9)) {
        prediction[0][0][0] = prediction[0][0][1] = prediction[1][0][0] = prediction[1][0][1] = 0;
        if (decoder->pictureStructure == 3) {
            *motionType = 2;
        } else {
            *motionType = 1;
            fieldSelect[0][0] = decoder->pictureStructure == 2;
        }
    }
    return 1;
}
}
