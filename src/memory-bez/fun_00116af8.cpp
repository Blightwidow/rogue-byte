struct VT { char pad[8]; short delta; short idx; int (*fn)(void *, int, int, int); }; struct A { VT *vt; };
void func_00116AF8(A *a, int unused, int cb, int tag){ VT *vt = a->vt; int d = vt->delta; vt->fn((char *)a + d, cb, tag, d); }
