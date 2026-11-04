#include "sly2.h"
struct SHVT { char pad[0x40]; short deltaShow; int (*fnShow)(void *); short deltaHide; int (*fnHide)(void *); };
struct SHOBJ { char pad[0xC]; SHVT *vt; };
extern "C" {
SHOBJ *PloFindSwObject_thunk(void *, int);
int FIsBasicDerivedFrom(SHOBJ *, int);
void FadeAloIn(SHOBJ *, float);
void FadeAloOut(SHOBJ *);
}

extern "C" SHOBJ *ShowHideLo(void *plo, int show, float t)
{
    SHOBJ *pobj = PloFindSwObject_thunk(plo, 4);
    if (pobj != 0) {
        if (t != 0.0f && FIsBasicDerivedFrom(pobj, 0x30)) {
            if (show) {
                FadeAloIn(pobj, t);
            } else {
                FadeAloOut(pobj);
            }
        } else {
            SHVT *pvt = pobj->vt;
            if (show) {
                pvt->fnShow((char *)pobj + pvt->deltaShow);
            } else {
                pvt->fnHide((char *)pobj + pvt->deltaHide);
            }
        }
    }
    return pobj;
}
