#include "types.h"

struct DMATAG {
    s64 low;
    s64 high;
};

struct DMAS {
    char pad[0xC];
    struct DMATAG *pdmatagNext;
};

s32 EndDmaCnt__4DMAS();                         /* extern */

void AddDmaEnd__4DMAS(struct DMAS *pdmas) {
    struct DMATAG *pdmatag;

    EndDmaCnt__4DMAS();
    pdmatag = pdmas->pdmatagNext;
    pdmas->pdmatagNext = pdmatag + 1;
    pdmatag->low = 0x70000000;
    pdmatag->high = 0;
}
