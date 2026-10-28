struct WATERBITS { unsigned long long low : 50; unsigned long long flag : 1; unsigned long long high : 13; };
int func_00229D60(void* a0, void* a1)
{
    return !((WATERBITS *)((char *)a1 + 0x10))->flag;
}
