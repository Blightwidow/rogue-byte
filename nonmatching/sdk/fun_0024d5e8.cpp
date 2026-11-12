// SPDX-License-Identifier: GPL-3.0-or-later
/* libmpeg: reads one MPEG-2 program-stream PES packet header from the demuxer's bit reader */
extern "C" {
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned char u8;

/* the demuxer's bit reader over a ring buffer */
struct BitReader {
    /* 0x00 */ u64 buffer;       /* the next bits, left-aligned */
    /* 0x08 */ u64 position;     /* bits consumed since the start */
    /* 0x10 */ u8 *base;         /* the stream data, indexed by position / 8 */
    /* 0x14 */ u8 *next;         /* the next byte to load */
    /* 0x18 */ int bitCount;     /* valid bits in buffer */
    /* 0x1C */ u8 *ringStart;
    /* 0x20 */ u8 *ringEnd;
    /* 0x24 */ int ringSize;
};

/* what the header says about the packet */
struct PacketHeader {
    /* 0x00 */ u64 streamId;     /* the stream id in the high word, a private stream's sub-id in the low word */
    /* 0x08 */ int length;
    /* 0x0C */ int scrambling;
    /* 0x10 */ long pts;
    /* 0x18 */ long dts;
    /* 0x20 */ int payloadPosition;
    /* 0x24 */ int payloadLength;
    /* 0x28 */ int headerPosition;
};

void func_0024FA38(void *context, const char *message);

static inline void FlushBits(BitReader *reader, int count)
{
    reader->buffer <<= count;
    reader->bitCount -= count;
    while (reader->bitCount < 57) {
        reader->buffer |= (u64)*reader->next++ << (56 - reader->bitCount);
        if (reader->next >= reader->ringEnd)
            reader->next = reader->ringStart;
        reader->bitCount += 8;
    }
    reader->position += count;
}

static inline u32 GetBits(BitReader *reader, int count)
{
    u32 value = reader->buffer >> (64 - count);
    FlushBits(reader, count);
    return value;
}

static inline void SkipBytes(BitReader *reader, int count)
{
    u64 position = count * 8 + reader->position;
    reader->buffer = 0;
    reader->bitCount = 0;
    reader->next = reader->base + (int)(position >> 3);
    reader->position = position;
    if (reader->next >= reader->ringEnd)
        reader->next -= reader->ringSize;
    FlushBits(reader, 0);
}

static inline long ReadTimestamp(BitReader *reader)
{
    u32 high, middle, low;
    FlushBits(reader, 4);
    high = GetBits(reader, 3);
    FlushBits(reader, 1);
    middle = GetBits(reader, 15);
    FlushBits(reader, 1);
    low = GetBits(reader, 15);
    FlushBits(reader, 1);
    return ((u64)(high >> 2) << 32) | (u32)((high << 30) | (middle << 15) | low);
}

int func_0024D5E8(void *context, BitReader *reader, PacketHeader *header)
{
    u8 optionalBits[16] = { 0, 16, 8, 24, 8, 24, 16, 32, 24, 40, 32, 48, 32, 48, 40, 56 };
    u32 timestampFlags, escrFlag, optionalFlags, extensionFlag, headerLength;
    int headerStart, remaining, payloadLength;

    header->headerPosition = reader->position;
    FlushBits(reader, 24);
    header->streamId = (u64)GetBits(reader, 8) << 32;
    header->length = GetBits(reader, 16);
    header->dts = -1;
    header->pts = -1;

    if (header->streamId != 0xBC00000000UL && header->streamId != 0xBE00000000UL && header->streamId != 0xBF00000000UL
        && header->streamId != 0xF000000000UL && header->streamId != 0xF100000000UL && header->streamId != 0xFF00000000UL
        && header->streamId != 0xF200000000UL && header->streamId != 0xF800000000UL) {
        FlushBits(reader, 2);
        header->scrambling = GetBits(reader, 2);
        FlushBits(reader, 4);
        timestampFlags = GetBits(reader, 2);
        escrFlag = GetBits(reader, 1);
        optionalFlags = GetBits(reader, 4);
        extensionFlag = GetBits(reader, 1);
        headerLength = GetBits(reader, 8);
        headerStart = reader->position;

        if (timestampFlags & 2)
            header->pts = ReadTimestamp(reader);
        if (timestampFlags == 3)
            header->dts = ReadTimestamp(reader);
        if (escrFlag == 1)
            FlushBits(reader, 48);
        if (optionalFlags != 0)
            FlushBits(reader, optionalBits[optionalFlags]);
        if (extensionFlag == 1) {
            u32 privateFlag = GetBits(reader, 1);
            u32 packHeaderFlag = GetBits(reader, 1);
            u32 sequenceFlag = GetBits(reader, 1);
            u32 bufferFlag = GetBits(reader, 1);
            u32 extensionFlag2;
            FlushBits(reader, 3);
            extensionFlag2 = GetBits(reader, 1);
            if (privateFlag == 1) {
                FlushBits(reader, 48);
                FlushBits(reader, 48);
                FlushBits(reader, 32);
            }
            if (packHeaderFlag == 1) {
                func_0024FA38(context, "pack_header_field_flag needs to be '0' in PS\n");
                return 0;
            }
            if (sequenceFlag == 1)
                FlushBits(reader, 16);
            if (bufferFlag == 1)
                FlushBits(reader, 16);
            if (extensionFlag2 == 1) {
                u32 count, index;
                FlushBits(reader, 1);
                count = GetBits(reader, 7);
                for (index = 0; index < count; index++)
                    FlushBits(reader, 8);
            }
        }

        remaining = headerLength - (int)((reader->position - headerStart) >> 3);
        if (remaining != 0)
            SkipBytes(reader, remaining);

        payloadLength = header->length - headerLength - 3;
        header->payloadLength = payloadLength;
        header->payloadPosition = reader->position;
        if (header->streamId == 0xBD00000000UL) {
            header->streamId |= GetBits(reader, 32);
            payloadLength -= 4;
        }
        if (payloadLength != 0)
            SkipBytes(reader, payloadLength);
        return 1;
    }
    if (header->streamId == 0xBC00000000UL || header->streamId == 0xBF00000000UL || header->streamId == 0xF000000000UL
        || header->streamId == 0xF100000000UL || header->streamId == 0xFF00000000UL || header->streamId == 0xF200000000UL
        || header->streamId == 0xF800000000UL) {
        int length = header->length;
        if (header->streamId == 0xBF00000000UL) {
            header->streamId |= GetBits(reader, 32);
            length -= 4;
        }
        if (length != 0)
            SkipBytes(reader, length);
    } else if (header->streamId == 0xBE00000000UL) {
        if (header->length != 0)
            SkipBytes(reader, header->length);
    }
    return 1;
}
}
