// 0x256C38 PairHandle_Init
void PairHandle_Init(int* a0, int* a1)
{
    if (a1 != 0)
    {
        int v0 = *a1;
        v0 = v0 + 1;
        *a1 = v0;
    }
    *a0 = (int)a1;
}
