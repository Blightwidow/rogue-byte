/* SPDX-License-Identifier: GPL-3.0-or-later */
struct VT_116918 { char pad[8]; short delta; short unused; void *(*fn)(void *, int, int); };
struct SLOTHEAP { VT_116918 *vt; };
extern "C" void memset(void *, int, int);
extern "C" void *PvAllocSlotheapClearImpl__FP8SLOTHEAP(SLOTHEAP *heap, int size, int extra) {
    VT_116918 *vt = heap->vt;
    short delta = vt->delta;
    void *result = vt->fn((char *)heap + delta, size, extra);
    memset(result, 0, size);
    return result;
}
