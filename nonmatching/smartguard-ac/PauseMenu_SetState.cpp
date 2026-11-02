#include "sly2.h"
struct BVT { char pad[0x188]; short delta; short index; void (*fn)(char *, int); };
struct Blot { char pad[0xC]; BVT *vt; };
struct Item { int id; char pad[0x1C]; };
struct Entry { int count; Item *items; Blot *blot; char pad[0x14 - 0xC]; int cur; int *table; char pad2[4]; };
struct MVT { char pad[0x50]; short delta0; short index0; void (*fn0)(char *); short delta1; short index1; void (*fn1)(char *); };
struct Menu { char pad0[0xC]; MVT *vt; char pad1[0x24 - 0x10]; int count; char pad2[0x1E8 - 0x28]; unsigned state; };
extern char B_002DEB80[];
static inline int RegLow(char *base) { return *(int *)(base + 0x18); }
static inline long RegWide(char *base) { return *(long *)(base + 0x18); }
extern float B_FLT_002F6468, B_FLT_002F646C, B_FLT_003DD18C, B_FLT_003DD190;
extern "C" {
void func_00213B00(Blot *, int);
void SeekBlotLabel(Blot *, int, float);
}
extern "C" void PauseMenu_SetState(Menu *menu, unsigned state)
{
    unsigned old = menu->state;
    if (old == state)
        return;
    int count = menu->count;
    Entry *entry = 0;
    if (count > 0)
        entry = (Entry *)((char *)menu + (count * 0x1C + 0xC));
    switch (old) {
    case 5:
        if (entry) {
            int next = entry->cur + 1;
            entry->cur = next;
            if (next >= entry->count)
                entry->cur = 0;
        }
        break;
    case 6:
        if (entry) {
            int prev = entry->cur - 1;
            entry->cur = prev;
            if (prev < 0)
                entry->cur = entry->count - 1;
        }
        break;
    case 0:
        menu->vt->fn0((char *)menu + menu->vt->delta0);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    default:
        break;
    }
    menu->state = state;
    if (state < 12) {
        switch (state) {
        case 1:
            if (entry && entry->blot) {
                entry->blot->vt->fn((char *)entry->blot + entry->blot->vt->delta, entry->table[0]);
                func_00213B00(entry->blot, entry->table[3]);
            }
            break;
        case 3:
            if (entry && entry->blot)
                func_00213B00(entry->blot, entry->table[5]);
            break;
        case 4:
            if (entry && entry->blot)
                func_00213B00(entry->blot, entry->table[3]);
            break;
        case 2:
        case 8:
            if (entry && entry->blot) {
                entry->blot->vt->fn((char *)entry->blot + entry->blot->vt->delta, entry->table[2]);
                func_00213B00(entry->blot, entry->table[5]);
            }
            break;
        case 5:
            if (entry && entry->blot)
                func_00213B00(entry->blot, entry->table[6]);
            break;
        case 6:
            if (entry && entry->blot)
                func_00213B00(entry->blot, entry->table[7]);
            break;
        case 11:
            if (entry && entry->blot)
                func_00213B00(entry->blot, 0x331);
            break;
        case 9:
            if (entry && entry->blot)
                func_00213B00(entry->blot, 0x332);
            break;
        case 10:
            if (entry && entry->blot) {
                switch (*(int *)((char *)entry->items + (entry->cur << 5))) {
                case 0x67:
                    func_00213B00(entry->blot, 0x333);
                    func_00213B00(entry->blot, 0x315);
                    SeekBlotLabel(entry->blot, 0x315, B_FLT_003DD190);
                    break;
                case 0x68:
                    func_00213B00(entry->blot, 0x334);
                    func_00213B00(entry->blot, 0x315);
                    SeekBlotLabel(entry->blot, 0x315, B_FLT_003DD18C);
                    break;
                case 0x3F:
                    func_00213B00(entry->blot, 0x335);
                    B_FLT_002F6468 = (float)(unsigned)(RegLow(B_002DEB80) & 0xFFF);
                    int shifted = (int)((RegWide(B_002DEB80) << 20) >> 32);
                    B_FLT_002F646C = (float)(unsigned)(shifted & 0x7FF);
                    break;
                }
            }
            break;
        case 7:
            if (entry && entry->blot) {
                entry->blot->vt->fn((char *)entry->blot + entry->blot->vt->delta, entry->table[1]);
                func_00213B00(entry->blot, entry->table[4]);
            }
            break;
        case 0:
            menu->vt->fn1((char *)menu + menu->vt->delta1);
            break;
        }
    }
}
