unsigned NLog2(unsigned value)
{
    unsigned log = 0;
    unsigned bit = 1;
    while (bit < value && log < 0x1F) {
        log++;
        bit <<= 1;
    }
    return log;
}
