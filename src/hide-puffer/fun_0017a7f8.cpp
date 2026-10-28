// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct ALO { char pad[0x208]; int fAwake; };
struct GOAL { char pad[0x10]; ALO *palo; char pad2[0x1C]; int state; int pad3; float tEffect; };
struct SW { char pad[0x4020]; int pfxdef; };
extern "C" void func_001EEF98(void);
extern "C" void func_0017A8C8(GOAL *, int);
extern "C" QW PosLoWorld(ALO *);
extern "C" int *PhitfxSpawn(int, QW, ALO *);
extern "C" SW B_003DD490;
extern "C" float D_FLT_002BE6C0, g_2dded0;
void func_0017A7F8(GOAL *pgoal)
{
    func_001EEF98();
    int state;
    for (;;) {
        state = pgoal->state;
        if (state < 4) {
            if (state >= 2) {
                if (pgoal->palo->fAwake != 0)
                    func_0017A8C8(pgoal, -1);
            }
        }
        if (state == pgoal->state)
            break;
    }
    if (state == 1 || state == 4) {
        if (D_FLT_002BE6C0 < g_2dded0 - pgoal->tEffect) {
            pgoal->tEffect = g_2dded0;
            int *pfx = PhitfxSpawn(B_003DD490.pfxdef, PosLoWorld(pgoal->palo), pgoal->palo);
            pfx[0x54 / 4] = 3;
        }
    }
}
