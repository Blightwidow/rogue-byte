// 0x1A6E70 GetLoNoPassInherit
int func_001A6E70(void *arg0)
{
    unsigned int v0 = *(unsigned int *)((unsigned char *)arg0 + 0x28);
    v0 = v0 >> 26;
    return v0 & 1;
}
