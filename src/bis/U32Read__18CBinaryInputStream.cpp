struct Stream117C80 { int unk0x0; unsigned char *cursor; int remaining; };
extern "C" void CBinaryInputStream_Read_thunk(Stream117C80 *, int, void *);
extern "C" unsigned int U32Read__18CBinaryInputStream(Stream117C80 *stream)
{
    unsigned int value;
    int remaining = stream->remaining;
    if (remaining >= 4) {
        unsigned char *cursor = stream->cursor;
        unsigned int result = cursor[0] + (cursor[1] << 8) + (cursor[2] << 16) + (cursor[3] << 24);
        stream->cursor = cursor + 4;
        stream->remaining = remaining - 4;
        return result;
    }
    CBinaryInputStream_Read_thunk(stream, 4, &value);
    return value;
}
