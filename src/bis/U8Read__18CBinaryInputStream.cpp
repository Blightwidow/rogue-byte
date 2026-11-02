struct Stream117BD0 {
    int unk0x0;
    unsigned char *cursor;
    int remaining;
};
extern "C" void CBinaryInputStream_Read_thunk(Stream117BD0 *, int, void *);
extern "C" int U8Read__18CBinaryInputStream(Stream117BD0 *stream)
{
    int count = stream->remaining;
    if (count >= 1) {
        unsigned char *pointer = stream->cursor;
        int value = pointer[0];
        stream->cursor = pointer + 1;
        stream->remaining = count - 1;
        return value;
    }
    unsigned char value;
    CBinaryInputStream_Read_thunk(stream, 1, &value);
    return value;
}
