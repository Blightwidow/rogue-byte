extern "C" int func_001EA688(const unsigned char *pmaterial)
{
    switch (pmaterial[4]) {
    case 1: return 2;
    case 7: return (pmaterial[5] & 0x20) ? 2 : 3;
    }
    return 1;
}
