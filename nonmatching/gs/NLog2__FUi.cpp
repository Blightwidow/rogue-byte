unsigned NLog2(unsigned value)
{
    unsigned bit = 1;
    register unsigned log asm("$3") = 0;
    if (bit < value) {
        bit <<= 1;
        do {
            log++;
            if (bit < value) {
                bit <<= 1;
                if (log < 0x1F)
                    continue;
            }
            break;
        } while (1);
    }
    return log;
}
