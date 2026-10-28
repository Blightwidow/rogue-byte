struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk; int n; int p2; int p3;
    CRef() {}
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
extern "C" char B_003D4A60[];
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PpathCrfodbLoot(void *);
CRef RefSetGameSaveValue(void *, CRef &, void *);
void SetLootState(void *, int);
void Crfodb_SpawnLoot(void *, int);
}
struct GUARD { char pad[0x194]; void *lootCarried; };

void Crfodb_SetLootId(GUARD *guard, int idLoot)
{
    if (guard->lootCarried != 0)
        SetLootState(guard->lootCarried, 0);
    char frame[16];
    CStackFrame_Construct(frame);
    void *path = PpathCrfodbLoot(guard);
    {
        CRef refValue;
        refValue.tagk = 0x15;
        refValue.n = idLoot;
        RefSetGameSaveValue(path, refValue, B_003D4A60);
    }
    if (idLoot != -1)
        Crfodb_SpawnLoot(guard, 0);
    CStackFrame_Destructor(frame, 2);
}
