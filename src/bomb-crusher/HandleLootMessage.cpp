#include "sly2.h"
struct LOOT {
    char pad0[0x184]; int loots; int unk188; void *prip;
};
extern "C" void HandleLoMessage(LOOT *, int, void *);
extern "C" void SetLootState(LOOT *, int);
extern "C" void HandleLootMessage(LOOT *ploot, int msgid, void *pv)
{
    HandleLoMessage(ploot, msgid, pv);
    switch (msgid) {
    case 4:
        if (ploot->loots == 5)
            SetLootState(ploot, 0);
        break;
    case 8:
        if (pv == ploot->prip) {
            switch (ploot->loots) {
            case 2: SetLootState(ploot, 4); break;
            case 3: SetLootState(ploot, 1); break;
            }
        }
        break;
    }
}
