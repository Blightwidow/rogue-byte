// 0x1D4CE0
void func_001D4CE0(int a0, int a1, int a2, float a3)
{
    int v0 = 12;
    int v1 = a1 * v0;
    v1 = v1 + 0x574;
    int v2 = a0 + v1;
    *(int*)(v2 + 4) = a2;
    *(float*)(v2 + 8) = a3;
}