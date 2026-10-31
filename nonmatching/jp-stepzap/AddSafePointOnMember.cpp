// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LOB { char pad[0x28]; unsigned long grfo; };
struct SP { LOB *plo; void *pmember; int pad8; float tStamp; float x; int pad14[3]; } __attribute__((aligned(16)));
struct SPL { void *pjt; int count; int pad[2]; SP items[1]; };
struct MVT { char pad[0x30]; short delta; short index; LOB *(*fn)(void *); };
struct MEM { char pad[0x20]; MVT *vt; };
extern float g_2dded0[];
void *memmove(void *, const void *, unsigned int);

static inline SP *Slot(SPL *list, int found)
{
    if (found < list->count)
        return &list->items[0];
    unsigned count = list->count;
    if (count < 0x20)
        list->count = count + 1;
    memmove(&list->items[1], &list->items[0], list->count * 32 - 32);
    return &list->items[0];
}

void AddSafePointOnMember(float parameter, SPL *list, MEM *pmember)
{
    int found = 1;
    SP *first;
    for (; found < list->count; found++) {
        first = &list->items[found];
        if ((void *)pmember == first->pmember && __builtin_fabsf(parameter - first->x) < 50.0f) {
            if (found != 1) {
                SP saved = *first;
                memmove(&list->items[2], &list->items[1], (found - 1) * 32);
                list->items[1] = saved;
            }
            break;
        }
    }
    SP *slot = Slot(list, found);
    first = slot;
    memset(slot, 0, 0x20);
    list->items[0].plo = pmember->vt->fn((char *)pmember + pmember->vt->delta);
    asm volatile("");
    first->pmember = pmember;
    first->x = parameter;
    first->tStamp = g_2dded0[0];
    list->items[0].plo->grfo |= 1UL << 59;
}
