#include "sly2.h"
struct PMF { char b[8]; };
struct UL { unsigned long v; } __attribute__((packed));
struct XP { char pad0[8]; void *plo; char pad[0x34]; };
struct SO { char pad[0x184]; int state; };
extern "C" char B_003DD490[];
extern "C" const UL RO_002A4B58;
void func_001F4FB0(SO *, XP *, int);
int FIsBasicDerivedFrom(void *, int);
void QueueSwCallbackOnce(void *, SO *, unsigned long, int);
void AdjustLootNewXp(SO *ploot, XP *pxp, int iside)
{
    func_001F4FB0(ploot, pxp, iside);
    if (ploot->state == 5) {
        if (!FIsBasicDerivedFrom(((XP *)((char *)pxp + ((1 - iside) << 6)))->plo, 0x34))
            QueueSwCallbackOnce(B_003DD490, ploot, RO_002A4B58.v, 0);
    }
}
