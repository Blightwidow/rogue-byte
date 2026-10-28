struct CRef { int tagk; float g; };
extern "C" char B_002E6604[];
extern "C" char *B_003E0FAC;
struct SAVE { char pad[0x7D50]; char *pslotCur; };
struct ITEM { char pad[8]; int slot; char pad2[0x10]; unsigned flags; };
extern "C" {
CRef *RefGetGameSaveValue(CRef *, void *, void *);
void CRef_Destruct(CRef *);
void ResetSaveKeepingOptions(void *, int);
void StartGameFromSave(void *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, void *);
}

extern "C" void func_001AD250(ITEM *item)
{
    char *base = B_002E6604;
    char *pslot = base + item->slot * 0x5464;
    CRef ref;
    RefGetGameSaveValue(&ref, B_003E0FAC, pslot);
    float g = ref.g;
    CRef_Destruct(&ref);
    float zero;
    asm volatile("mtc1 $0, %0\n\tnop" : "=f" (zero) : "f" (g));
    if (g == zero) {
        SAVE *psave = (SAVE *)(base + 0x7FDC);
        psave->pslotCur = pslot;
        ResetSaveKeepingOptions(pslot, 1);
        StartGameFromSave(psave->pslotCur);
    } else {
        void *emitter = NewEmitter(0x36);
        SetEmitterUnpositioned(emitter, 0);
        if (item != 0)
            item->flags |= 2;
    }
}
