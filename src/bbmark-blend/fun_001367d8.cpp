#include "sly2.h"
struct VT { short delta; short index; void (*fn)(void *, int); };
struct BENTLEY { char pad0[0xC]; VT *vt; char pad1[0x1F8]; void *psurface; char pad2[0x15F4]; int ride; };
void SetBentleyState(BENTLEY *, int);
void func_001367D8(BENTLEY *pbentley)
{
    int start, now;
    do {
        start = pbentley->ride;
        if (start != 0) { if (start == 1 && pbentley->psurface != 0) {
            SetBentleyState(pbentley, 0);
            VT *slot = (VT *)((char *)pbentley->vt + 0x278);
            slot->fn((char *)pbentley + slot->delta, 1);
        } }
        now = pbentley->ride;
    } while (now != start && now != -1);
}