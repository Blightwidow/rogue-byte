struct Stream117E38 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117E38 *, int, void *, int);
extern "C" float F32Read__18CBinaryInputStream(Stream117E38 *stream)
{
    float value[16 / sizeof(float)] __attribute__((aligned(16)));
    float result;
    int remaining = stream->remaining;
    if (remaining < 4) {
        CBinaryInputStream_Read_thunk(stream, 4, value, remaining);
        result = value[0];
    } else {
        unsigned char *cursor = stream->cursor;
        int bits = cursor[0] + (cursor[1] << 8) + (cursor[2] << 16) + (cursor[3] << 24);
        stream->cursor = cursor + 4;
        stream->remaining = remaining - 4;
        result = *(float *)&bits;
    }
    return result;
}
