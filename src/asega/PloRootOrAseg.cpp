// 0x131270 PloRootOrAseg
extern "C" void *PloRootOrAseg(void *arg0)
{
    unsigned int v0 = *(unsigned int *)((unsigned int)arg0 + 0x18);
    if (v0 != 0)
        return (void *)v0;
    return *(void **)((unsigned int)arg0 + 0x14);
}