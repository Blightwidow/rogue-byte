#include "sly2.h"
struct VT48 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct VT40 { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct RIGOBJ { char pad[0x16C]; void *psma; };
struct GUARD {
    char pad0[0x3F4]; char *light0; char *light1; int state; float tState; char pad1[0x90]; RIGOBJ *prig;
};
extern "C" float g_2dded0;
extern "C" int D_002C3738[];
extern "C" void SetSmaGoalIfReachable(void *, int);

#define CALL48(light) ((*(VT48 **)((light) + 0xC))->fn((light) + (*(VT48 **)((light) + 0xC))->delta))
#define CALL40(light) ((*(VT40 **)((light) + 0xC))->fn((light) + (*(VT40 **)((light) + 0xC))->delta))

void func_001F17F8(GUARD *pguard, int state)
{
    if (state == pguard->state)
        return;
    pguard->state = state;
    pguard->tState = g_2dded0;
    switch (state) {
    case -1:
    case 0:
        if (pguard->light0)
            CALL48(pguard->light0);
        if (pguard->light1)
            CALL48(pguard->light1);
        break;
    case 1:
    case 2:
        if (pguard->light0)
            CALL40(pguard->light0);
        if (pguard->light1)
            CALL40(pguard->light1);
        break;
    }
    void *psma = pguard->prig->psma;
    if (psma)
        SetSmaGoalIfReachable(psma, D_002C3738[pguard->state + 1]);
}
