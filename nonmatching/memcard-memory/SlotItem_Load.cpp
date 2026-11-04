struct CRef { int tagk; float g; int pad[2]; };
struct ITEM { char pad0[8]; int slot; char pad0C[0x1C - 0xC]; int flags; };
struct SLOT { char data[0x5464]; };
extern SLOT B_002E6604[];
extern int B_003E0FAC;
extern "C" void RefGetGameSaveValue(CRef *, int, void *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void ResetSaveKeepingOptions(void *, int);
extern "C" void StartGameFromSave(void *);

void SlotItem_Load(ITEM *item)
{
    char *slot = (char *)&B_002E6604[item->slot];
    char *saves = (char *)B_002E6604 + 0x7FDC;
    CRef ref;
    RefGetGameSaveValue(&ref, B_003E0FAC, slot);
    float value = ref.g;
    CRef_Destruct(&ref);
    *(char **)(saves + 0x7D50) = slot;
    if (value == 0.0f) {
        ResetSaveKeepingOptions(slot, 1);
        StartGameFromSave(*(char **)(saves + 0x7D50));
    } else {
        StartGameFromSave(slot);
        if (item != 0)
            item->flags |= 2;
    }
}
