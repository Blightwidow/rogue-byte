// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
struct MpegBlockEntry {
    u32 address;
    int offset;
    int firstCount;
    int secondCount;
    int stride;
    u8 *firstSource;
    u8 *secondSource;
};
struct MpegFrameBuffer {
    u8 *base;
    void *coefficients;
    u8 *upper[4];
    u8 *lower[4];
    void *lumaRoutine[4];
    void *chromaRoutine[4];
    MpegBlockEntry luma[4];
    MpegBlockEntry chroma[4];
    u8 pad128[0x12C - 0x128];
    int count;
    u8 pad130[0x13C - 0x130];
    int noCoefficients;
};
struct MpegReference {
    u8 *base;
    u8 pad4[0x10 - 0x4];
    int width;
};
struct MpegDecoder {
    u8 pad0[0x5A0];
    MpegFrameBuffer buffers[2];
    u8 pad820[0x820 - 0x820];
    int bufferIndex;
    u8 pad824[0x830 - 0x824];
    u32 output;
    u8 pad834[0x87C - 0x834];
    int sameFrame;
};
extern void *D_002C8478[];
extern void *D_002C8498[];

void func_002505B0(MpegDecoder *decoder, MpegReference *reference, int fieldOffset, int destinationRow, int row,
                   int height, int column, int rowOffset, int vectorX, int vectorY, int fieldPrediction, int average) {
    u32 output = decoder->output;
    int index = decoder->buffers[decoder->bufferIndex].count;
    MpegBlockEntry *luma = &decoder->buffers[decoder->bufferIndex].luma[index];
    MpegBlockEntry *chroma = &decoder->buffers[decoder->bufferIndex].chroma[index];
    int x;
    int y;
    int lumaX;
    int lumaY;
    int blockX;
    int blockY;
    int fraction;
    int offset;
    int base;
    u8 *upper;
    u8 *lower;
    u8 *source;
    int routine;
    int chromaVectorY;
    int chromaVectorX;
    int chromaHeight;
    int chromaRow;
    int chromaOffset;
    u8 *block;
    int xHalf;
    int yHalf;

    x = (vectorX >> 1) + column;
    if (fieldPrediction) {
        y = ((vectorY >> 1) << 1) + row + (rowOffset + fieldOffset);
    } else {
        y = (vectorY >> 1) + row + (rowOffset + fieldOffset);
    }
    lumaX = x >> 4;
    lumaY = y >> 4;
    upper = reference->base + (lumaX * reference->width + lumaY) * 0x180;
    lower = reference->base + (lumaX * reference->width + lumaY + reference->width) * 0x180;
    decoder->buffers[decoder->bufferIndex].upper[index] = upper;
    decoder->buffers[decoder->bufferIndex].lower[index] = lower;
    luma->address = output + (destinationRow + row) * 32;
    luma->offset = x - (lumaX << 4);
    fraction = y - (lumaY << 4);
    xHalf = vectorX & 1;
    yHalf = vectorY & 1;
    if (yHalf) {
        if (fraction + (height << fieldPrediction) > 15) {
            luma->firstCount = (16 >> fieldPrediction) - (fraction >> fieldPrediction) - 1;
            luma->secondCount = height - luma->firstCount;
        } else {
            luma->firstCount = height;
            luma->secondCount = 0;
        }
    } else {
        if (fraction + (height << fieldPrediction) > 16) {
            luma->firstCount = (16 >> fieldPrediction) - (fraction >> fieldPrediction);
            luma->secondCount = height - luma->firstCount;
        } else {
            luma->firstCount = height;
            luma->secondCount = 0;
        }
    }
    if (decoder->sameFrame == 0) {
        source = decoder->buffers[decoder->bufferIndex].base + index * 0x600;
        luma->firstSource = source + fraction * 16;
        luma->secondSource = source + (fraction * 16 + 0x300);
    } else {
        source = upper;
        luma->firstSource = upper + fraction * 16;
        luma->secondSource = lower + fraction * 16;
    }
    luma->stride = 16 << fieldPrediction;
    routine = (average << 2) | (xHalf << 1) | yHalf;
    chromaVectorY = vectorY / 2;
    chromaVectorX = vectorX / 2;
    chromaHeight = height >> 1;
    chromaRow = row >> 1;
    x = (chromaVectorX >> 1) + (column >> 1);
    if (fieldPrediction) {
        y = ((chromaVectorY >> 1) << 1) + chromaRow + ((rowOffset >> 1) + fieldOffset);
    } else {
        y = (chromaVectorY >> 1) + chromaRow + ((rowOffset >> 1) + fieldOffset);
    }
    blockX = x >> 3;
    blockY = y >> 3;
    chromaOffset = ((destinationRow + chromaRow) << 4) + 0x200;
    fraction = y - (blockY << 3);
    xHalf = chromaVectorX & 1;
    yHalf = chromaVectorY & 1;
    chroma->offset = x - (blockX << 3);
    chroma->address = output + chromaOffset;
    if (yHalf) {
        if (fraction + (chromaHeight << fieldPrediction) > 7) {
            chroma->firstCount = (8 >> fieldPrediction) - (fraction >> fieldPrediction) - 1;
            chroma->secondCount = chromaHeight - chroma->firstCount;
        } else {
            chroma->firstCount = chromaHeight;
            chroma->secondCount = 0;
        }
    } else {
        if (fraction + (chromaHeight << fieldPrediction) > 8) {
            chroma->firstCount = (8 >> fieldPrediction) - (fraction >> fieldPrediction);
            chroma->secondCount = chromaHeight - chroma->firstCount;
        } else {
            chroma->firstCount = chromaHeight;
            chroma->secondCount = 0;
        }
    }
    offset = ((blockX - lumaX) * 2 + (blockY - lumaY)) * 0x180;
    block = source + offset;
    if (decoder->sameFrame == 0) {
        chroma->firstSource = block + (fraction * 8 + 0x100);
        chroma->secondSource = block + (fraction * 8 + 0x400);
    } else {
        base = fraction * 8 + 0x100;
        if ((u32)(offset + base) < 0x301) {
            chroma->firstSource = upper + offset + base;
        } else {
            chroma->firstSource = lower + offset + base - 0x300;
        }
        chroma->secondSource = lower + offset + (fraction * 8 + 0x100);
    }
    chroma->stride = 8 << fieldPrediction;
    decoder->buffers[decoder->bufferIndex].lumaRoutine[index] = D_002C8478[routine];
    decoder->buffers[decoder->bufferIndex].chromaRoutine[index] =
        D_002C8498[(average << 2) | (xHalf << 1) | yHalf];
    decoder->buffers[decoder->bufferIndex].count++;
}
}
