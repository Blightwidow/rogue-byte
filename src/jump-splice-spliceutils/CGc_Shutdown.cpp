// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct SVT { char pad[0x58]; short delta; short index; void (*fn)(char *); };
struct SCR { char pad[0xC]; SVT *vt; };
extern DLI *g_2dd2fc;
extern int g_2dd318;
extern char B_003D9E80, B_003D9ED0, B_002E1E60, B_003DA0F0, B_003DA150, B_003DA0C0, B_003DA3C0, B_002E6550, B_002E65A0, B_003DA4F0, B_003DA530;
extern "C" {
void ReleaseMeter(void *);
void func_001AE970(void *);
void func_001A3070(void *);
void GadgetMenu_Reset(void *);
void ShopMenu_Reset(void *);
void InitHudLabel(void *);
void JobMenu_Reset(void *);
void MemcardMenu_Reset(void *);
void Menu_Reset(void *);
}

static inline void PushDli(DLI *iterator, DL *list)
{
    iterator->list = list;
    iterator->current = (char *)list;
    iterator->offset = list->offset;
    iterator->next = g_2dd2fc;
    g_2dd2fc = iterator;
}

static inline char *PvStep(DLI *iterator)
{
    char *item = *(char **)iterator->current;
    iterator->current = item + iterator->offset;
    return item;
}

// Retail stores the iterator into g_2dd2fc before it loads list->first, then
// stores list, current and offset: the push sets current to the list head and
// the first step reads the first item through it (the store to g_2dd2fc may
// alias that load, so it stays after it). Same push/step pair as UpdateRipg.
void CGc_Shutdown(DL *list)
{
    DLI iterator;
    PushDli(&iterator, list);
    for (char *item = PvStep(&iterator); item != 0; item = PvStep(&iterator)) {
        SVT *vt = ((SCR *)item)->vt;
        vt->fn(item + vt->delta);
    }
    g_2dd318 = 0;
    ReleaseMeter(&B_003D9E80);
    func_001AE970(&B_003D9ED0);
    func_001A3070(&B_002E1E60);
    GadgetMenu_Reset(&B_003DA0F0);
    ShopMenu_Reset(&B_003DA150);
    InitHudLabel(&B_003DA0C0);
    JobMenu_Reset(&B_003DA3C0);
    MemcardMenu_Reset(&B_002E6550);
    Menu_Reset(&B_002E65A0);
    Menu_Reset(&B_003DA4F0);
    Menu_Reset(&B_003DA530);
    g_2dd2fc = iterator.next;
}
