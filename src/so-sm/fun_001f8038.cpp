#include "sly2.h"
struct BASIC;
struct ALO { char pad[0xA4]; int count; BASIC **items; };
struct SCROLLER;
extern "C" int FIsBasicDerivedFrom(BASIC *, int);
extern "C" void SetSaiDuDv(SCROLLER *, float, float);

void func_001F8038(ALO *alo, float du, float dv)
{
    for (int i = 0; i < alo->count; i++) {
        BASIC *item = alo->items[i];
        if (FIsBasicDerivedFrom(item, 0x8F))
            SetSaiDuDv((SCROLLER *)item, du, dv);
    }
}
