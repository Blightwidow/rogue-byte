struct Stream117D00 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117D00 *, int, void *);
extern "C" signed char S8Read__18CBinaryInputStream(Stream117D00 *stream)
{
    signed char value[16] __attribute__((aligned(16)));
    if (stream->remaining > 0) {
        stream->remaining--;
        return *(signed char *)stream->cursor++;
    }
    CBinaryInputStream_Read_thunk(stream, 1, value);
    return value[0];
}
