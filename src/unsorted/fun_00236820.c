int func_00236820(char **buffer, int *remaining, int character)
{
    if (*remaining == 0) {
        return 1;
    }
    if (character < 0x100) {
        if (*remaining == 1) {
            character = 0;
        }
        *(*buffer)++ = character;
        *remaining = *remaining - 1;
        return 1;
    }
    **buffer = 0;
    return 0;
}
