#include "sly2.h"
struct LOOT { char pad[0x15C]; void *pguard; };
struct GUARD { char pad[0x194]; LOOT *ploot; };
struct SW { char pad[0x4638]; void *ppool; };
extern "C" SW B_003DD490;
int IdlootCrfodb(GUARD *);
LOOT *PloLeaseCloneObject(void *, int);
void SelectLootDef(LOOT *, int);
void SetLootState(LOOT *, int);
void Crfodb_SpawnLoot(GUARD *pguard)
{
    SW *psw;
    if (pguard->ploot == 0) {
        psw = &B_003DD490;
        if (psw->ppool != 0) {
            int idLoot = IdlootCrfodb(pguard);
            if (idLoot != -1) {
                LOOT *ploot = PloLeaseCloneObject(psw->ppool, 0);
                pguard->ploot = ploot;
                if (ploot != 0) {
                    SelectLootDef(ploot, idLoot);
                    pguard->ploot->pguard = pguard;
                    SetLootState(pguard->ploot, 1);
                }
            }
        }
    }
}