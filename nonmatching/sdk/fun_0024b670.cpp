// func_0024B670
typedef int (*fn3)(int, int, int, int);
int func_0024B670(void *a0, void *a1)
{
    int t1 = 0;
    if (a0)
    {
        int a2 = *(int *)((char *)a0 + 0x40);
        if (a2)
        {
            int t0 = 0xC;
            int v1 = *(int *)a1;
            v1 = v1 * t0;
            int v0 = a2 + v1;
            fn3 a3 = (fn3)*(int *)(v0 + 0xC);
            if (a3)
            {
                int v1b = *(int *)(v0 + 0x14);
                int s0 = v1b;
                int v0b = *(int *)a1;
                v1 = v0b * t0;
                v0 = v1 + a2;
                a3(a2 + v1, (int)a1, s0, *(int *)(v0 + 0x10));
                t1 = v0;
            }
        }
    }
    return t1;
}
