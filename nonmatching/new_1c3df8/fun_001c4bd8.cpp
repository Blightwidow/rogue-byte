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
int func_001C4BD8(SW *psw, int cmax, void **out)
{
    if (cmax <= 0)
        return 0;
    int count = 1;
    SO *focus = PpoSwFocusBase(psw);
    if (focus != 0) {
        out[0] = (char *)focus + 0x15C;
        if (FIsBasicDerivedFrom(focus, 0x34) && count < cmax) {
            unsigned index = 0;
            void **slot = out + 1;
            SO ***pp = D_002C0D28;
            do {
                SO *other = **pp;
                if (other != 0 && other != focus && GoalStack_PgoalFind((char *)other + 0x26C, 0xC2) != 0) {
                    unsigned long bit = other->grfo >> 60 & 1;
                    if (bit) {
                        count++;
                        *slot++ = (char *)other + 0x15C;
                    }
                }
                index++;
                pp++;
            } while (index < 3 && count < cmax);
        }
    } else {
        out[0] = D_002C0D18;
    }
    return count;
}
