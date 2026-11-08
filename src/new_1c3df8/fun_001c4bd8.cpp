#include "sly2.h"
struct SO { char pad[0x28]; unsigned long grfo; };
struct SW;
extern "C" {
SO *PpoSwFocusBase(SW *);
int FIsBasicDerivedFrom(SO *, int);
void *GoalStack_PgoalFind(void *, int);
extern SO **D_002C0D28[3];
extern char D_002C0D18[];
}
// Retail walks the three-entry table at 0x2C0D28 with an unsigned index (sltiu 3) and a
// separate table pointer, and keeps a store pointer that starts at out + 4 only after the
// first count < cmax test: that is loop.c's strength reduction of a plain indexed store
// out[count++] inside a for loop. A hand-written slot pointer or a do/while put the
// pointer setup before the guard and swapped the index and table registers. The flag bit
// is read into a 64-bit local first (ld/dsrl32/andi); testing the expression in place
// compiles to a longer sequence.
int func_001C4BD8(SW *psw, int cmax, void **out)
{
    if (cmax <= 0)
        return 0;
    int count = 1;
    SO *focus = PpoSwFocusBase(psw);
    if (focus != 0) {
        out[0] = (char *)focus + 0x15C;
        if (FIsBasicDerivedFrom(focus, 0x34)) {
            for (unsigned index = 0; index < 3 && count < cmax; index++) {
                SO *other = *D_002C0D28[index];
                if (other != 0 && other != focus && GoalStack_PgoalFind((char *)other + 0x26C, 0xC2) != 0) {
                    unsigned long bit = other->grfo >> 60 & 1;
                    if (bit) {
                        out[count++] = (char *)other + 0x15C;
                    }
                }
            }
        }
    } else {
        out[0] = D_002C0D18;
    }
    return count;
}
