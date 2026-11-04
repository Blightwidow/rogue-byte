#include "sly2.h"
struct GIFS;
struct VSLOT { short delta; short index; void (*fn)(void *, int); };
struct GIFS {
    char pad0[0xC];
    unsigned long *cursor;
    char pad1[0x18 - 0x10];
    VSLOT *vtable;
};
extern "C" void GIFS_AddPrimTag(GIFS *pgifs, int prim, unsigned long base, int creg, unsigned long regs, unsigned int flag)
{
    VSLOT *slot = &pgifs->vtable[1];
    slot->fn((char *)pgifs + slot->delta, 0);
    unsigned long *tag = pgifs->cursor;
    pgifs->cursor = tag + 2;
    tag[0] = ((unsigned long)flag << 15) | base | (((unsigned long)prim << 0x2F) | 0x400000000000UL) | ((unsigned long)creg << 0x3C);
    tag[1] = regs;
}
