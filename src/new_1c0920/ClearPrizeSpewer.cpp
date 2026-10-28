void ClearPrizeSpewer(void* pso)
{
    *(int*)((char*)pso + 0x158) = 0;
    *(int*)((char*)pso + 0x154) = 0;
    *(int*)((char*)pso + 0x150) = 0;
}
