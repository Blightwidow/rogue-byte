#include "sly2.h"
struct TN { char pad0[0xE0]; void *focus; char pade4[0x24]; void *cbsp; char pad10c[0x18]; int fAir; char pad128[0x14]; int tnsOverride; };
struct PO { char pad[0x2DC]; int field2DC; };
extern char B_003DD490[];
extern int B_002DE240;
extern "C" PO *PpoSwFocus(void *);
extern "C" QW PosLoWorld(void *);
extern "C" QW ConvertAloPos(void *, void *, QW);
extern "C" void *PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *, int, QW);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void SetTnTns__FP2TN3TNS(TN *, int);

void UpdateTnCallback(TN *t)
{
    PO *focus = PpoSwFocus(B_003DD490);
    if (focus == 0)
        return;
    if (focus != t->focus) {
        SetTnTns__FP2TN3TNS(t, 0);
        t->focus = focus;
    }
    int wanted = t->tnsOverride;
    int none = -1;
    asm("" : "+r" (none));
    if (wanted == none) {
        QW world = PosLoWorld(focus);
        QW local = ConvertAloPos(0, t, world);
        wanted = PcgtPointInCbspQuick__FP4CBSPP6VECTOR(t->cbsp, 0x7FFFFFFF, local) != 0;
    }
    if (t->fAir != 0 || !FIsBasicDerivedFrom(focus, 0x34) || focus->field2DC == -1 || B_002DE240 != 0 || t->tnsOverride != -1)
        SetTnTns__FP2TN3TNS(t, wanted);
}
