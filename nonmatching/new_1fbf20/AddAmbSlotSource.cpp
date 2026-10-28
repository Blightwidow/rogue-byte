#include "sly2.h"
struct B8 { char b[8]; };
struct SRC { int palo; B8 range; float vol; };
struct AMB { char pad[0xA0]; };
extern "C" void SetAmbGrf(AMB *, int, int);

static inline int *AcSource(AMB *amb) { return (int *)((char *)amb + 0xA0); }
void AddAmbSlotSource(AMB *amb, unsigned slot, int palo, const B8 *range, float vol)
{
    if (slot < 6) {
        int *pcount = &AcSource(amb)[slot];
        if (*pcount < 8) {
            SetAmbGrf(amb, 0x200, 0x200);
            int n = *pcount;
            char *base = (char *)amb + ((slot << 7) + 0xB8);
            SRC *src = (SRC *)base + n;
            *pcount = n + 1;
            src->palo = palo;
            src->vol = vol;
            src->range = *range;
            float a = *(float *)((char *)src + 4);
            float b = *(float *)((char *)src + 8);
            if (a == b)
                *(float *)((char *)src + 8) = b + 1.0f;
        }
    }
}
