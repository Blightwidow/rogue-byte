#include "sly2.h"
struct CRef { int tagk; int n; int pad[2]; };
struct Slot { int gadget; int state; float t; };
struct JVT { char pad[0x338]; short delta; short idx; void *(*fn)(void *); char pad2[0x348 - 0x340]; short delta2; short idx2; void (*fn2)(void *); };
struct JtObj { char pad[0xC]; JVT *vt; };
extern "C" {
void SetJtGadgetSlotState(void *, Slot *, int);
void CRef_Destruct(CRef *);
void func_001D8B20(CRef *, CRef *, void *, const char *, char *, int);
int sprintf(char *, const char *, ...);
extern float g_2dded0[];
extern const char RO_002A4D50[];
extern const char RO_002A4D58[];
}
void EquipJtGadget(char *jt, unsigned slot, int gadget)
{
    if (slot < 3) {
        Slot *equip = (Slot *)(jt + 0x1180 + slot * 0xC);
        SetJtGadgetSlotState(jt, equip, -1);
        equip->state = 0;
        equip->t = g_2dded0[0];
        equip->gadget = gadget;
        Slot *scan = (Slot *)(jt + 0x1180);
        Slot *other = (Slot *)(jt + 0x1180);
        for (int index = 0; index < 3; index++, other++) {
            if (index != slot && other->gadget == gadget) {
                SetJtGadgetSlotState(jt, other, -1);
                other->gadget = -1;
            }
            char name[16];
            sprintf(name, RO_002A4D50, index);
            CRef result;
            CRef value;
            value.tagk = 0x15;
            value.n = scan->gadget;
            scan++;
            JtObj *obj = (JtObj *)jt;
            func_001D8B20(&result, &value, obj->vt->fn((char *)obj + obj->vt->delta), RO_002A4D58, name, 0);
            CRef_Destruct(&result);
            CRef_Destruct(&value);
        }
        JtObj *obj2 = (JtObj *)jt;
        obj2->vt->fn2((char *)obj2 + obj2->vt->delta2);
    }
}
