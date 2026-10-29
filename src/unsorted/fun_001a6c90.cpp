extern "C" int GetAloFreezeMode(void *arg0)
{
    long flags = *(long *)((char *)arg0 + 0x28);
    return (int)((flags << 8) >> 60);
}
