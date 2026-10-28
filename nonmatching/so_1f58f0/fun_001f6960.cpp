// 0x1F6960 GetSoIntersectionFlag
int func_001F6960(void *arg0)
{
    int v = *(int *)((char *)arg0 + 0x148);
    return (int)((v >> 26) & 1);
}
