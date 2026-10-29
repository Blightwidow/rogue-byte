// 0x1A6C90 GetAloFreezeMode
int GetAloFreezeMode(void *arg0)
{
    int  v0;
    v0 = v0 << 8;
    v0 = v0 >> 28;
    v0 = *(long *)((char *)arg0 + 0x28);
    return v0;
}