// 0x229D60 FFilterWaterPart_229d60
int func_00229D60(void* a0, void* a1)
{
    unsigned long v0 = *(unsigned long*)((unsigned char*)a1 + 0x10);
    v0 = v0 ^ 1;
    v0 = v0 & 1;
    v0 = v0 >> 18;
    return (int)v0;
}
