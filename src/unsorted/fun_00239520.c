int func_00239520(int *destination, int *source, unsigned int size)
{
    unsigned int count = size >> 2;
    unsigned int index;
    for (index = 0; index < count; index++) {
        *destination++ = *source++;
    }
    return 0;
}
