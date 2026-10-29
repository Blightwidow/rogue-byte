int func_001A6E70(void *arg0)
{
    unsigned long flags = *(unsigned long *)((unsigned char *)arg0 + 0x28);
    return (int)(flags >> 58) & 1;
}
