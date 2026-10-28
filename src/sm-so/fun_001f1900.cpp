#include "sly2.h"
struct RIGOBJ { char pad[0x158]; int unk158; };
struct GUARDACT { int oid; int unk4; int unk8; int unkC; };
struct GUARDOBJ { char pad[0x404]; int oid; };
struct GUARD {
    char pad0[0x2C0]; unsigned long grfsgs; char pad1[0x484 - 0x2C8]; int cguardact; char pad2[0xC]; RIGOBJ *prig;
};
static inline GUARDACT *Aguardact(GUARD *pguard) { return (GUARDACT *)((char *)pguard + 0x404); }
extern "C" unsigned long GrfsgsFromSgs(int);
extern "C" void *PpoSwFocusBase(void *);
extern "C" void func_001F17F8(GUARD *, int);
extern "C" char B_003DD490;
extern "C" void *g_2e1e40;

static inline int FocusIsGlobal()
{
    void *focus = PpoSwFocusBase(&B_003DD490);
    register void *want asm("$4") = g_2e1e40;
    return focus == want;
}
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
            if (cguardact != 0 && ((GUARDOBJ *)((char *)pguard + ((cguardact - 1) << 4)))->oid != 0x2B3 &&
                PpoSwFocusBase(&B_003DD490) != 0 && FocusIsGlobal())
                state = 2;
            else
                state = 1;
        }
    }
    func_001F17F8(pguard, state);
}
