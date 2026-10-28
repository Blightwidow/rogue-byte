struct Arena { void *vt; int cb; char *base; int used; };
extern "C" void *PvAllocGlobalImpl__Fi(Arena *a, int cb)
{
    int used = a->used;
    int next = used + ((cb + 0xF) & ~0xF);
    if (a->cb < next)
        return 0;
    a->used = next;
    return a->base + used;
}
