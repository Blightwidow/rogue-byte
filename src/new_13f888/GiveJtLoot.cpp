struct JT { char pad0[0x11A8]; void *plootHeld; };
struct LO { char pad0[0x160]; JT *pjt; };
extern "C" int LootId(void *);
extern "C" void DropJtLoot(JT *);
extern "C" LO *PloLeaseCloneObject(void *, int);
extern "C" void SelectLootDef(LO *, int);
extern "C" void SetLootState(LO *, int);
extern "C" void *B_003E1AC8;
void GiveJtLoot(JT *pjt, int id)
{
    void *held = pjt->plootHeld;
    if (held == 0 || LootId(held) != id) {
        DropJtLoot(pjt);
        if (id != -1) {
            if (B_003E1AC8 != 0) {
                LO *ploot = PloLeaseCloneObject(B_003E1AC8, 1);
                SelectLootDef(ploot, id);
                ploot->pjt = pjt;
                SetLootState(ploot, 6);
                SetLootState(ploot, 4);
            }
        }
    }
}
