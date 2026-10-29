unsigned long func_001F8500(void *arg0)
{
    unsigned long flags = *(unsigned long *)((char *)arg0 + 0x148);
    return (flags >> 33) & 1;
}
