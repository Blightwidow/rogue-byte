// 0x1C7A40 GetCoinLootDefId
int func_001C7A40(void *a0)
{
    int v0 = -1;
    int **pp = (int **)((char *)a0 + 0x244);
    if (*pp != 0) {
        v0 = **pp;
    }
    return v0;
}
