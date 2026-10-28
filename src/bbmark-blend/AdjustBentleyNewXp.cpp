#include "sly2.h"
struct GEOM { char pad[0x10]; unsigned long flags; };
struct XP { GEOM *pgeom; char pad[0x3C]; };
struct BENTLEY { char pad[0x13D0]; int state; };
void AdjustJtZapNewXp(void *, XP *);
void func_0019E9C8(void *, XP *);
void AdjustStepNewXp(BENTLEY *, XP *, int);
void AdjustBentleyNewXp(BENTLEY *pbentley, XP *pxp, int ixpd)
{
    if ((((XP *)((char *)pxp + (ixpd << 6)))->pgeom->flags & (1UL << 48)) == 0) {
        switch (pbentley->state) {
        case 4:
            AdjustJtZapNewXp((char *)pbentley + 0xDF0, pxp);
            break;
        case 0xD:
            func_0019E9C8((char *)pbentley + 0xF50, pxp);
            break;
        default:
            AdjustStepNewXp(pbentley, pxp, ixpd);
        }
    }
}
