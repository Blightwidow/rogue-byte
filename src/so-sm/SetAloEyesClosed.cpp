#include "sly2.h"
struct EYES;
struct ALO { char pad0[0x24]; ALO *next; char pad28[0x3C]; ALO *child; char pad68[8]; ALO *end; char pad74[0x30]; int count; EYES **items; };
extern "C" int FIsBasicDerivedFrom(void *, int);
void SetEyesClosed__FP4EYESf(EYES *, float);
extern "C" void SetAloEyesClosed(ALO *, float);

extern "C" void SetAloEyesClosed(ALO *alo, float closed)
{
    for (int index = 0; index < alo->count; index++) {
        EYES *eyes = alo->items[index];
        if (FIsBasicDerivedFrom(eyes, 0x8E)) {
            SetEyesClosed__FP4EYESf(eyes, closed);
        }
    }
    for (ALO *child = alo->child; child != alo->end; child = child->next) {
        if (FIsBasicDerivedFrom(child, 0x30)) {
            SetAloEyesClosed(child, closed);
        }
    }
}
