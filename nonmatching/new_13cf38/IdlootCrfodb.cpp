struct CRef { int tagk; int n; };
extern "C" char B_003D4A60[];
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PpathCrfodbLoot(void *);
CRef *RefGetGameSaveValue(CRef *, void *, void *);
void CRef_Destruct(CRef *);
}
struct GUARD { char pad[0x184]; int idLootDefault; };

int IdlootCrfodb(GUARD *guard)
{
    char frame[16];
    CStackFrame_Construct(frame);
    CRef ref;
    RefGetGameSaveValue(&ref, PpathCrfodbLoot(guard), B_003D4A60);
    CRef_Destruct(&ref);
    int id = ref.n;
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
