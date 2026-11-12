void func_0023A920(void *a0, void *a1)
{
    extern void *B_0044E708;
    extern int D_002C5A50;
    extern int D_002C5A54;

    struct Entry { void (*fn)(void *, int); int arg; };

    int count = D_002C5A54;
    Entry *p = a0 ? (Entry *)B_0044E708 : (Entry *)&D_002C5A50;

    while (count > 0) {
        if (p->fn != 0) {
            p->fn(a1, p->arg);
        }
        count--;
        p = (Entry *)((char *)p + 0x10);
    }
}
