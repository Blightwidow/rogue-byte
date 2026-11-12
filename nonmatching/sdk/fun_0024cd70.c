/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef struct BitReader {
    unsigned long window;
    long consumed;
    int pad10;
    unsigned char *cursor;
    int bitCount;
    unsigned char *start;
    unsigned char *end;
} BitReader;

static inline void Consume(BitReader *reader, int count)
{
    reader->window = reader->window << count;
    reader->bitCount -= count;
    while (reader->bitCount <= 0x38) {
        reader->window |= (long)*reader->cursor++ << (0x38 - reader->bitCount);
        if (reader->cursor >= reader->end)
            reader->cursor = reader->start;
        reader->bitCount += 8;
    }
    reader->consumed += count;
}

int func_0024CD70(BitReader *reader)
{
    unsigned int top;
    Consume(reader, 0x38);
    Consume(reader, 0x28);
    top = reader->window >> 0x3F;
    if (top == 1) {
        do {
            Consume(reader, 0x18);
            top = reader->window >> 0x3F;
        } while (top == 1);
    }
    return 1;
}
