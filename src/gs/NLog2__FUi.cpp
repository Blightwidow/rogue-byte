unsigned NLog2(unsigned value)
{
    unsigned count = 0;
    unsigned bit = 1;
    while (bit < value && count < 0x1F) {
        bit <<= 1;
        count++;
    }
    return count;
}
