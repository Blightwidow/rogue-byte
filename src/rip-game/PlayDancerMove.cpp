#include "sly2.h"
extern "C" int FVjoyButtonPressed(int, int);
extern "C" int PaloFindDancerAnim(void *, int);
extern "C" void SetXfKind(void *, int, int);
extern "C" void PlayDancerAnim(void *, int, int);
struct STEP { int oid; int anim; int apl; };
struct DM { int btn; STEP step[3]; };
struct DANCER { char pad[0x58]; int xf1; int xf2; char pad2[0x150 - 0x60]; int vjoy; char pad3[0x2C4 - 0x154]; int count; DM moves[8]; };
extern "C" void PlayDancerMove(DANCER *dancer, int btn, int oid, int istep)
{
    for (int i = 0; i < dancer->count; i++) {
        DM *move = &dancer->moves[i];
        if (btn == -1 && FVjoyButtonPressed(dancer->vjoy, move->btn)) {
        } else if (move->btn != btn) {
            continue;
        }
        if (oid != -1) {
            int found = PaloFindDancerAnim(dancer, oid);
            if (found) move->step[0].anim = found;
        }
        SetXfKind(dancer, dancer->xf1, 2);
        SetXfKind(dancer, dancer->xf2, 2);
        PlayDancerAnim(dancer, move->step[istep].anim, move->step[istep].apl);
        return;
    }
}
