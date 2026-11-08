// Word copy: copies size >> 2 words and returns 0 (retail loads the count shifted once; a for loop over the word count). 0x239518 held this
// function's 8-byte head as a stray `lw` and `nop`, which stay a fragment; the symbol was split at 0x239520 and again at 0x239558.
int func_00239520(int *destination, int *source, unsigned int size)
{
    unsigned int count = size >> 2;
    unsigned int index;
    for (index = 0; index < count; index++) {
        *destination++ = *source++;
    }
    return 0;
}
