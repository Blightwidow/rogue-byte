typedef struct
{
    char pad0x18[0x18];
    int (*fn)();
    int *g;
} T1;

typedef struct
{
    int x;
    int y;
} T2;

int func_0024B6E8(T2 *a0)
{
    int r = 1;
    if (a0)
    {
        T1 *p = (T1 *)(*(int **)(a0 + 4));
        if (p)
        {
            if (p->fn)
            {
                int g = (int)((char *)p->g - (char *)p);
                T2 *q = (T2 *)((char *)p + g * 3);
                p->fn();
                r = q->y;
            }
        }
    }
    return r;
}
