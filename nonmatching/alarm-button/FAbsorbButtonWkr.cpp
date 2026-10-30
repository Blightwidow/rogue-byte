#include "sly2.h"
struct Wkr { int pobj; char p0[0x44 - 4]; unsigned grfic; };
struct Button { char p0[0x1E0]; int buttons; float tButtons; float dtRepush; char p1[0x2A8 - 0x1EC]; int btnt; };
extern "C" {
int FAbsorbSoWkr(Button *, Wkr *);
int FCheckButtonObject(Button *);
void SetButtonButtons(Button *, int);
extern float g_2dded0;
}
int FAbsorbButtonWkr(Button *pbutton, Wkr *pwkr)
{
    int fAbsorbed = FAbsorbSoWkr(pbutton, pwkr);
    if (fAbsorbed != 0 && (pwkr->grfic & 4) == 0) {
        if (FCheckButtonObject(pbutton) != 0) {
            int buttons;
            switch (pbutton->btnt) {
            case 1:
                if (pbutton->buttons == 0)
                    goto press;
                break;
            case 2:
                buttons = pbutton->buttons;
                if (buttons == 0) {
                    if (pbutton->dtRepush <= g_2dded0 - pbutton->tButtons)
                    {
press:
                        SetButtonButtons(pbutton, 1);
                    }
                } else if (buttons == 1)
                    SetButtonButtons(pbutton, 0);
                break;
            }
        }
    }
    return fAbsorbed;
}
