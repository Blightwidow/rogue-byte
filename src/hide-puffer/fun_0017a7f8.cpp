// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct ALO { char pad[0x208]; int fAwake; };
#include "goal.h"
struct GOAL_17A7F8 : GOAL {
    int state;
    char pad_34[0x4];
    float tEffect;
};
#include "sw.h"
extern "C" void func_001EEF98(void);
extern "C" void func_0017A8C8(GOAL_17A7F8 *, int);
extern "C" QW PosLoWorld(ALO *);
extern "C" int *PhitfxSpawn(BASIC *, QW, ALO *);
extern "C" SW B_003DD490;
extern "C" float D_FLT_002BE6C0, g_2dded0;
void func_0017A7F8(GOAL_17A7F8 *pgoal)
{
    func_001EEF98();
    int state;
    for (;;) {
        state = pgoal->state;
        if (state < 4) {
            if (state >= 2) {
                if (((ALO *)pgoal->pstep)->fAwake != 0)
                    func_0017A8C8(pgoal, -1);
            }
        }
        if (state == pgoal->state)
            break;
    }
    if (state == 1 || state == 4) {
        if (D_FLT_002BE6C0 < g_2dded0 - pgoal->tEffect) {
            pgoal->tEffect = g_2dded0;
            int *pfx = PhitfxSpawn(B_003DD490.phitfxdef, PosLoWorld(((ALO *)pgoal->pstep)), ((ALO *)pgoal->pstep));
            pfx[0x54 / 4] = 3;
        }
    }
}
