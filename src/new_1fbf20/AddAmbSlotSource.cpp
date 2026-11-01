#include "sly2.h"
struct B8 { char b[8]; };
struct SRC { int palo; B8 range; float vol; };
struct AMB { char pad[0xA0]; int count[6]; SRC src[6][8]; };
extern "C" void SetAmbGrf(AMB *, int, int);
void AddAmbSlotSource(AMB *amb, unsigned slot, int palo, const B8 *range, float vol)
{
    if (slot < 6) {
        if (amb->count[slot] < 8) {
            SetAmbGrf(amb, 0x200, 0x200);
            SRC *src = &amb->src[slot][amb->count[slot]++];
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
