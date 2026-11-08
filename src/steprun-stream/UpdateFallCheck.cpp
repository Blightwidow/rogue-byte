#include "sly2.h"

// One vtable slot (8 bytes): the this-adjustment and the function.
struct FALLCHECK_VTABLE_ENTRY {
    short thisDelta;
    short pad2;
    int (*pfn)(void *, int);
};

struct FALLCHECK_VTABLE {
    char pad0[0x260];
    FALLCHECK_VTABLE_ENTRY entry260;
};

struct FALLCHECK_OWNER {
    char pad0[0xC];
    FALLCHECK_VTABLE *pvtable;
};

struct FALLCHECK {
    FALLCHECK_OWNER *powner;
    int state;
    float timeStateChange;
    int fEnabled;
};

extern "C" {
int FGuardOffGround(FALLCHECK *pfallcheck);
void SetFallCheckState(FALLCHECK *pfallcheck, int state);
extern float g_2dded0;
extern float RO_002C3DF0; // 0.1f, the delay before a fall counts
}

// Retail: the state is re-read at the loop's foot (`bnel` with the load in its delay slot), so the
// body is a do/while that repeats while a state handler changed the state; the state dispatch is
// gcc's decision tree for a three-case switch (`beq 1`, `slti 2`, `beqz`, `beq 2`). The owner call
// is a virtual call through the 8-byte slot at 0x260 (16-bit this-adjustment, then the function).
// Written as `elapsed > delay` (not `delay < elapsed`): that order gives the time global the first
// hoisted %hi register ($s4) and the constant $s3, as retail has. The 0.1f at 0x2C3DF0 is read as a
// plain extern: declared `const`, gcc moves its load and the function no longer matches.
extern "C" void UpdateFallCheck(FALLCHECK *pfallcheck)
{
    if (pfallcheck->fEnabled == 0) {
        return;
    }
    int fOffGround = FGuardOffGround(pfallcheck);
    int state;
    do {
        state = pfallcheck->state;
        switch (state) {
        case 0:
            if (fOffGround != 0) {
                SetFallCheckState(pfallcheck, 1);
            }
            break;
        case 1:
            if (fOffGround == 0) {
                SetFallCheckState(pfallcheck, 0);
            } else if (g_2dded0 - pfallcheck->timeStateChange > RO_002C3DF0) {
                FALLCHECK_OWNER *powner = pfallcheck->powner;
                FALLCHECK_VTABLE_ENTRY *pentry = &powner->pvtable->entry260;
                if (pentry->pfn((char *)powner + pentry->thisDelta, 0x4000) == 0) {
                    SetFallCheckState(pfallcheck, 2);
                }
            }
            break;
        case 2:
            if (fOffGround == 0) {
                SetFallCheckState(pfallcheck, 0);
            }
            break;
        }
    } while (pfallcheck->state != state);
}
