struct Stream117D00 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117D00 *, int, void *);
extern "C" int S8Read__18CBinaryInputStream(Stream117D00 *stream)
{
    int count = stream->remaining;
    if (count >= 1) {
        unsigned char *pointer = stream->cursor;
        int value = (signed char)pointer[0];
        stream->cursor = pointer + 1;
        stream->remaining = count - 1;
        return value;
    }
    signed char value;
    CBinaryInputStream_Read_thunk(stream, 1, &value);
    return value;
}
