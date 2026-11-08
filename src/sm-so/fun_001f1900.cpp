#include "sly2.h"
struct RIGOBJ { char pad[0x158]; int unk158; };
struct GUARDOBJ { char pad[0x404]; int oid; };
struct GUARD {
    char pad0[0x2C0]; unsigned long grfsgs; char pad1[0x484 - 0x2C8]; int cguardact; char pad2[0xC]; RIGOBJ *prig;
};
extern "C" unsigned long GrfsgsFromSgs(int);
extern "C" void *PpoSwFocusBase(void *);
extern "C" void func_001F17F8(GUARD *, int);
extern "C" char B_003DD490;
extern "C" void *g_2e1e40;

// The last guard is written as an `||` chain ending in `PpoSwFocusBase(...) != g_2e1e40` (state 1) with `else` state 2. The `&& ==
// g_2e1e40` form put $v1 and $a0 on the wrong sides of the g_2e1e40 load (score 3).
void func_001F1900(GUARD *pguard)
{
    if (!pguard->prig)
        return;
    int state;
    if (!pguard->prig->unk158) {
        state = -1;
    } else {
        unsigned long grfsgsAlert = GrfsgsFromSgs(0x1D) | GrfsgsFromSgs(0x20) | GrfsgsFromSgs(5) | GrfsgsFromSgs(6) |
                                    GrfsgsFromSgs(7) | GrfsgsFromSgs(0x17) | GrfsgsFromSgs(0x16);
        if (pguard->grfsgs & grfsgsAlert) {
            state = 0;
        } else {
            int cguardact = pguard->cguardact;
            if (cguardact == 0 || ((GUARDOBJ *)((char *)pguard + ((cguardact - 1) << 4)))->oid == 0x2B3 ||
                PpoSwFocusBase(&B_003DD490) == 0 || PpoSwFocusBase(&B_003DD490) != g_2e1e40)
                state = 1;
            else
                state = 2;
        }
    }
    func_001F17F8(pguard, state);
}
