struct VT { char pad[8]; short delta; short idx; int (*fn)(void *, int, int); };
struct A { VT *vt; int tag; };
void func_00116A58(A *a, int unused, int cb, int tagFallback)
{
    VT *vt = a->vt;
    int tag = a->tag;
    if (tag == -1)
        tag = tagFallback;
    vt->fn((char *)a + vt->delta, cb, tag);
}
