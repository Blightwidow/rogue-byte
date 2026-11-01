struct Stream117C20 { int unk0x0; unsigned char *cursor; int remaining; };
extern "C" void CBinaryInputStream_Read_thunk(Stream117C20 *, int, void *);
extern "C" unsigned short U16Read__18CBinaryInputStream(Stream117C20 *stream)
{
    unsigned short value;
    int remaining = stream->remaining;
    if (remaining >= 2) {
        unsigned char *cursor = stream->cursor;
        unsigned short result = cursor[0] | (cursor[1] << 8);
        stream->cursor = cursor + 2;
        stream->remaining = remaining - 2;
        return result;
    }
    CBinaryInputStream_Read_thunk(stream, 2, &value);
    return value;
}
