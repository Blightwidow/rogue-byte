extern "C" char *strchr(const unsigned char *string, int ch)
{
    const unsigned char *cursor = string;
    do {
        if (*cursor == ch) return (char *)cursor;
        asm volatile("nop");
    } while (*cursor++);
    return 0;
}
