extern "C" int strlen(const unsigned char *string)
{
    int length = 0;
    while (*string) { string++; length++; }
    return length;
}
