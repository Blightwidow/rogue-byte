struct ELEM_14E000 {
    char pad0[0xE4];
    int keyE4;
    char padE8[0x110 - 0xE8];
    int key110;
    float key114;
    char pad118[8];
};
extern "C" int func_0014E000(ELEM_14E000 **first, ELEM_14E000 **second)
{
    ELEM_14E000 *a = *first;
    ELEM_14E000 *b = *second;
    int diff = b->key110 - a->key110;
    if (diff != 0)
        return diff;
    diff = b->keyE4 - a->keyE4;
    if (diff != 0)
        return diff;
    if (a->key114 < b->key114)
        return -1;
    if (b->key114 < a->key114)
        return 1;
    return a - b;
}
