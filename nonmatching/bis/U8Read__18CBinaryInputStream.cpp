struct Stream117BD0 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117BD0 *, int, void *);
extern "C" unsigned char U8Read__18CBinaryInputStream(Stream117BD0 *stream)
{
    unsigned char value[16] __attribute__((aligned(16)));
    if (stream->remaining > 0) {
        stream->remaining--;
        return *stream->cursor++;
    }
    CBinaryInputStream_Read_thunk(stream, 1, value);
    return value[0];
}
