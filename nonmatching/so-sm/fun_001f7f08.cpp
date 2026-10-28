int GetSoNoSafePoint(void* arg0)
{
    unsigned int v0 = *(unsigned int*)((unsigned int)arg0 + 0x148);
    v0 = v0 << 3;
    return v0 & 1;
}
