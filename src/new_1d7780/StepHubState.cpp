#include "sly2.h"
struct SM { char pad[0x50]; int csms; };
struct HUB { char pad[0x184]; SM *sm; int sma; char pad1[0x220 - 0x18C]; int coid; int aoid[1]; };
extern "C" {
int GetSmaCur(int);
int IsmsFindSmRequired__FP2SM3OID(SM *, int);
int OidFromSmIsms(SM *, int);
void SetSmaGoal__FP3SMA3OID(int, int);
void func_001F1448(int, HUB *, int, int, int *);
void StepHubState(HUB *hub, int step)
{
    if (hub->sma == 0)
        return;
    int current = GetSmaCur(hub->sma);
    int index = IsmsFindSmRequired__FP2SM3OID(hub->sm, current);
    int start = index;
    for (;;) {
        index += step;
        if (index < 0)
            index = hub->sm->csms - 1;
        else if (index >= hub->sm->csms)
            index = 0;
        int oid = OidFromSmIsms(hub->sm, index);
        for (int slot = 0; slot < hub->coid; slot++) {
            if (hub->aoid[slot] == oid) {
                SetSmaGoal__FP3SMA3OID(hub->sma, oid);
                return;
            }
        }
        if (step == 0) {
            step = 1;
        } else if (index == start) {
            func_001F1448(0, hub, -1, 0, &hub->sma);
            return;
        }
    }
}
}
