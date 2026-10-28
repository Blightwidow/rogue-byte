#include "sly2.h"
struct TN { char pad[0x128]; int state; };
struct PO { char pad[0x16C]; TN *ptn; };
struct SW;
extern SW B_003DD490;
void SetTnTnsOverride(TN *, int);
void func_001A58D0(TN *, int, int);
PO *PpoSwFocus(SW *);
void func_001C4130(PO *po, TN *ptn)
{
    TN *old = po->ptn;
    if (ptn == old) return;
    if (old != 0)
        SetTnTnsOverride(old, 0);
    po->ptn = ptn;
    if (ptn != 0) {
        ptn->state = -1;
        func_001A58D0(po->ptn, 0, 0);
        if (PpoSwFocus(&B_003DD490) == po)
            SetTnTnsOverride(po->ptn, 1);
    }
}
