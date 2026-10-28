#include "sly2.h"
struct VT { char pad[0x98]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct ENTRY { unsigned flags; OBJ *obj; };
struct SW { char pad[0x3D5C]; int a; int count; int b; char pad2[0x3F14 - 0x3D68]; int centry; char pad3[4]; int loopIndex; ENTRY *entries; };
extern "C" void func_001A3EE8(SW *);
extern "C" void func_001CD9E0(SW *);
extern "C" void GadgetMenu_DrawSlotLabels(void *);
extern "C" void func_001574A0(void *);
extern char B_003B3980[];
extern char *B_003D4A50;
extern char B_003DA0F0[];
extern char B_002DEA00[];
extern char g_2dea28[];

void func_001CDA80(SW *sw)
{
    int index;
    func_001A3EE8(sw);
    sw->count = sw->count + 1;
    B_003D4A50 = B_003B3980;
    if (sw->a != sw->b) {
        sw->b = sw->a;
        func_001CD9E0(sw);
    }
    index = 0;
    sw->loopIndex = (int)&index;
    for (index = 0; index < sw->centry; index++) {
        ENTRY *entry = &sw->entries[index];
        if ((entry->flags & 0x88) == 8) {
            OBJ *object = entry->obj;
            VT *vt = object->vt;
            vt->fn((char *)object + vt->delta);
        }
    }
    sw->loopIndex = 0;
    GadgetMenu_DrawSlotLabels(B_003DA0F0);
    func_001574A0(B_002DEA00);
    func_001574A0(g_2dea28);
}
