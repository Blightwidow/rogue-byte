#include "sly2.h"
struct REQ { int size; int align; };
struct OWNER { char pad[0xDC]; float *light; };
struct ALO { char pad[0xE8]; OWNER *owner; };
extern "C" void *PvAllocSwClearImpl__Fi(void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
float *func_001F8300(ALO *palo)
{
    if (palo->owner == 0)
        return 0;
    if (palo->owner->light == 0) {
        REQ req;
        req.size = 0x70;
        req.align = 0x10;
        float *plight = (float *)PvAllocSwClearImpl__Fi(&req);
        *(ALO **)plight = palo;
        if (FIsBasicDerivedFrom(palo, 0x34) != 0)
            plight[2] = 150.0f;
        else
            plight[2] = 75.0f;
        plight[3] = 1.0f;
        palo->owner->light = plight;
    }
    return palo->owner->light;
}
