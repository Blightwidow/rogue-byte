#include "sly2.h"
extern "C" float g_2dded0;
extern "C" void func_0017F4C0(void *, void *);

void Chaser_SetState(void *pchaser, int state)
{
    int *pint = (int *)pchaser;
    int stateOld = pint[0x1C0 / 4];
    if (stateOld == state)
        return;
    if (stateOld == -1)
        pint[0x184 / 4] = pint[0x180 / 4];
    pint[0x1C0 / 4] = state;
    ((float *)pchaser)[0x1C4 / 4] = g_2dded0;
    if (state != 3) {
        if (state < 4) {
            if (state >= 0) {
                int *pvec = pint + 0x210 / 4;
                pvec[2] = 0;
                pvec[1] = 0;
                pint[0x210 / 4] = 0;
            }
        } else if (state == 4) {
            int *pvec = pint + 0x210 / 4;
            pvec[2] = 0;
            pvec[1] = 0;
            pint[0x210 / 4] = 0;
        }
    }
    void *pentry = (state == -1) ? 0 : (char *)pchaser + 0x220 + state * 0x10;
    func_0017F4C0(pchaser, pentry);
}
