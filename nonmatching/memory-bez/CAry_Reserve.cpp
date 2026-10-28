struct VT { char pad[0x10]; short delta; short index; void *(*fn)(void *, void *, int, int); };
struct ALLOC { VT *vt; };
struct CAry { void *data; int count; int max; int elemSize; ALLOC *alloc0; ALLOC *alloc; };

void CAry_Reserve(CAry *ary, int needed)
{
    int max = ary->max;
    if (max < needed) {
        int newMax;
        if (needed < 0x200) {
            newMax = 8;
            if (max) newMax = max;
            if (newMax < needed) {
                do newMax <<= 1; while (newMax < needed);
            }
        } else {
            newMax = (needed + 0x3FF) & ~0x3FF;
        }
        ALLOC *alloc = ary->alloc;
        VT *vt = alloc->vt;
        void *result = vt->fn((char *)alloc + vt->delta, ary->data, newMax * ary->elemSize, 4);
        ary->data = result;
        ary->max = newMax;
    }
}
