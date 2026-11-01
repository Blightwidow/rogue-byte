typedef int QW __attribute__((mode(TI)));
extern "C" {
struct Gadget224380;
struct Touch224380 { char pad0[4]; Gadget224380 *gadget; };
struct Side224380 { Touch224380 *touch; int pad4; int field8; int otherId; char pad10[0x30]; };
struct Node224380 {
    Side224380 sides[2];
    QW vector;
    char pad90[0xC];
    int state;
    char padA0[0xC];
    Node224380 *next;
};
struct Group224380 { Node224380 *first; Group224380 *next; };
struct Owner224380 { char pad0[0x60]; int id; Group224380 *groups; };
struct Gadget224380 {
    char pad0[0xEC]; Owner224380 *owner;
    char padF0[0x60]; int fLocked; float tStamp; int mode; char pad15C[0x34]; QW slideVector; int stuckTo;
};
int FGadgetObjAcceptsStick(Gadget224380 *, int);
int FGadgetObjCanStick(Gadget224380 *);
void func_001F4F10();
extern float D_002C3C60[];
extern float D_002C42E0;
extern float g_2dded0;
void HandleGadgetObjXps(Gadget224380 *gadget)
{
    QW scratch __attribute__((aligned(16)));
    func_001F4F10();
    if (gadget->fLocked == 0 && g_2dded0 - gadget->tStamp < D_002C42E0) return;
    Owner224380 *owner = gadget->owner;
    int ownerId = owner->id;
    for (Group224380 *group = owner->groups; group != 0; group = group->next) {
        for (Node224380 *node = group->first; node != 0; node = node->next) {
            int flag = node->sides[0].field8 != ownerId;
            if (node->sides[flag].touch->gadget != gadget) continue;
            int other = node->sides[1 - flag].otherId;
            if (node->state != 8 && FGadgetObjCanStick(gadget) != 0 && FGadgetObjAcceptsStick(gadget, other) != 0) {
                gadget->stuckTo = other;
                gadget->mode = 2;
                asm volatile("qmtc2.ni %0, vf2" : : "r"(*(int *)&D_002C3C60[flag]));
                asm volatile("sqc2 vf2, (%0)" : : "r"(&scratch));
                asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(node));
                asm volatile("vmulx.xyzw vf2, vf1, vf2x");
                asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(gadget));
            } else if (gadget->fLocked == 0 && gadget->mode == -1) {
                gadget->mode = 4;
            }
        }
    }
}
}
