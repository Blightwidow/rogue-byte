extern "C" int func_001F78A0(unsigned mask)
{
    int index = 0;
    unsigned bit = 1;
    while (index < 26 && (mask & bit) == 0) {
        index++;
        bit <<= 1;
    }
    return index;
}
