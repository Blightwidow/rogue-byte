struct Stream117D50 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117D50 *, int, void *);
extern "C" int S16Read__18CBinaryInputStream(Stream117D50 *stream)
{
    short value[16 / sizeof(short)] __attribute__((aligned(16)));
    int result;
    int remaining = stream->remaining;
    if (remaining < 2) {
        CBinaryInputStream_Read_thunk(stream, 2, value);
        result = value[0];
    } else {
        unsigned char *cursor = stream->cursor;
        result = cursor[0] | (short)(cursor[1] << 8);
        stream->cursor = cursor + 2;
        stream->remaining = remaining - 2;
    }
    return result;
}
