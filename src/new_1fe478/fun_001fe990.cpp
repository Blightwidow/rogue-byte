struct BANK { char pad[0x1D0]; int count; int table[1]; };
extern "C" int func_001FE990(BANK *pbank, int value)
{
    int count = pbank->count;
    for (int index = 0; index < count; index++) {
        if (pbank->table[index] == value) return index;
    }
    return -1;
}
