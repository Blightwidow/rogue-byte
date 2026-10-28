// 0x1F2740 GetSoSphereKind
int func_001F2740(void *arg0)
{
    int  v0;
    v0 = *(long *)((unsigned char *)arg0 + 0x148);
    v0 = v0 << 8;
    v0 = v0 >> 28;
    return v0;
}
