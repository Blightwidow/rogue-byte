#include "sly2.h"
struct VT_1EC968 { char pad[0x40]; short delta; short unused; void (*fn)(void *); };
struct SAA { char pad0[0xC]; VT_1EC968 *vt; char pad1[0x30 - 0x10]; int flag; char pad2[0x40 - 0x34]; SAA *next; };
extern "C" {
extern SAA *B_003E159C;
int FUpdatableSaa__FP3SAA(SAA *);
void UpdateSaas(void)
{
    char frame[0x10] __attribute__((aligned(16))); // retail frame shows a dead 0x10 area
    SAA *saa = B_003E159C;
    while (saa && saa->flag == 0) {
        if (FUpdatableSaa__FP3SAA(saa) != 0) saa->vt->fn((char *)saa + saa->vt->delta);
        saa = saa->next;
    }
}
}
