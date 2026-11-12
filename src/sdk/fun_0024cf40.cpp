// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
struct BitReader {
    u64 bits;
    u64 position;
    s32 unknown10;
    u8 *cursor;
    s32 count;
    u8 *start;
    u8 *end;
};
struct PackHeader {
    u32 scrExtension;
    u32 scrLow;
    u32 scrHigh;
    s32 hasSystemHeader;
};
int func_0024CD70(BitReader *reader, PackHeader *header);

static inline void SkipBits(BitReader *reader, int count) {
    reader->bits <<= count;
    reader->count -= count;
    while (reader->count < 57) {
        reader->bits |= (u64)*reader->cursor++ << (56 - reader->count);
        if (reader->cursor >= reader->end) {
            reader->cursor = reader->start;
        }
        reader->count += 8;
    }
    reader->position += count;
}

static inline u32 GetBits(BitReader *reader, int count) {
    u32 value = reader->bits >> (64 - count);
    SkipBits(reader, count);
    return value;
}

int func_0024CF40(BitReader *reader, PackHeader *header) {
    SkipBits(reader, 34);
    u32 high = GetBits(reader, 3);
    SkipBits(reader, 1);
    u32 middle = GetBits(reader, 15);
    SkipBits(reader, 1);
    u32 low = GetBits(reader, 15);
    SkipBits(reader, 1);
    header->scrExtension = GetBits(reader, 9);
    SkipBits(reader, 30);
    u32 stuffing = GetBits(reader, 3);
    header->scrLow = (high << 30) | (middle << 15) | low;
    header->scrHigh = high >> 2;
    for (u32 index = 0; index < stuffing; index++) {
        SkipBits(reader, 8);
    }
    if ((s32)(reader->bits >> 32) == 0x1BB) {
        header->hasSystemHeader = 1;
        func_0024CD70(reader, header);
    } else {
        header->hasSystemHeader = 0;
    }
    return 1;
}
}
