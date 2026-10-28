// 0x1F7B40 GetSoImpactKind
int func_001F7B40(void *arg0)
{
    long v = *(long *)((char *)arg0 + 0x148);
    return (int)((v << 8) >> 32) & 3;
}
