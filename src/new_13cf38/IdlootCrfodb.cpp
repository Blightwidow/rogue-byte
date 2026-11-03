struct CRef { int tagk; int n; int p2; int p3; };
extern "C" {
extern int B_003D4A60[];
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PpathCrfodbLoot(void *);
void CRef_Destruct(CRef *);
void RefGetGameSaveValue(CRef *, void *, int *);
}
struct GUARD { char pad[0x184]; int idLootDefault; };

static inline int GetSaveInt_13D248(void *path)
{
    CRef ref;
    RefGetGameSaveValue(&ref, path, B_003D4A60);
    int n = ref.n;
    CRef_Destruct(&ref);
    return n;
}

int IdlootCrfodb(GUARD *guard)
{
    char frame[16];
    CStackFrame_Construct(frame);
    int id = GetSaveInt_13D248(PpathCrfodbLoot(guard));
    if (id == 0) {
        id = guard->idLootDefault;
    } else if (id >= 0) {
        if (id < 10) {
            if (id >= 7) id = -1;
        }
    }
    switch (id) {
    case 0x2BF: id = 0x2BC; break;
    case 0x2C0: id = 0x2BD; break;
    case 0x2C1: id = 0x2BE; break;
    }
    CStackFrame_Destructor(frame, 2);
    return id;
}
