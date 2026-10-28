struct ALO {
    char pad[0x110];
    unsigned char interact[0x1A];
};
extern "C" void SetAloInteract(ALO *alo, unsigned mask, unsigned value)
{
    int index;
    unsigned bit;
    for (index = 0, bit = 1; index < 0x1A; index++, bit <<= 1) {
        if ((bit & mask) != 0)
            alo->interact[index] = value;
    }
}
