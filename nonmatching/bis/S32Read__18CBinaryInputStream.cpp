struct Stream117DB8 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117DB8 *, int, void *, int);
extern "C" int S32Read__18CBinaryInputStream(Stream117DB8 *stream)
{
    int value[16 / sizeof(int)] __attribute__((aligned(16)));
    int result;
    int remaining = stream->remaining;
    if (remaining < 4) {
        CBinaryInputStream_Read_thunk(stream, 4, value, remaining);
        result = value[0];
    } else {
        unsigned char *cursor = stream->cursor;
        result = cursor[0] + (cursor[1] << 8) + (cursor[2] << 16) + (cursor[3] << 24);
        stream->cursor = cursor + 4;
        stream->remaining = remaining - 4;
    }
    return result;
}
