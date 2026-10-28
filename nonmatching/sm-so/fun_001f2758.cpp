// 0x1F2758 FUN_001f2758
int FUN_001f2758(void *pso)
{
    unsigned long v = *(unsigned long *)((char *)pso + 0xd0);
    return (int)((v & 3) == 0);
}
