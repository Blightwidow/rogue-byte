int GetSoNoSafePoint(void* arg0)
{
    long v = *(long *)((char *)arg0 + 0x148);
    return (int)((v << 3) >> 32) & 1;
}
