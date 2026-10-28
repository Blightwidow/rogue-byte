// 0x1F7588 FAbsorbSoWkr
int FAbsorbSoWkr(void* arg1, void* arg2)
{
    return *(int*)((unsigned char*)arg2 + 0x44) != 0;
}