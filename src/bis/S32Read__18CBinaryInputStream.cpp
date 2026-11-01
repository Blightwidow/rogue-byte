struct Stream117DB8 { int unk0x0; unsigned char *cursor; int remaining; };
extern "C" void CBinaryInputStream_Read_thunk(Stream117DB8 *, int, void *);
extern "C" int S32Read__18CBinaryInputStream(Stream117DB8 *stream)
{
    int value;
    int remaining = stream->remaining;
    if (remaining >= 4) {
        unsigned char *cursor = stream->cursor;
        int result = cursor[0] + (cursor[1] << 8) + (cursor[2] << 16) + (((signed char *)cursor)[3] << 24);
        stream->cursor = cursor + 4;
        stream->remaining = remaining - 4;
        return result;
    }
    CBinaryInputStream_Read_thunk(stream, 4, &value);
    return value;
}
