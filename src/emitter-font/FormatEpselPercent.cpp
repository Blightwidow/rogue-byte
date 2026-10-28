struct CRef { int tagk; int n; };
struct GAME { char pad[0x4774]; };
struct HERO { char pad[0x110]; int idx; };
struct GLOBALS { char pad0[0x3B7C]; int slots[1]; };
extern "C" char B_003D4A60[];
extern "C" char B_003DD490[];
extern "C" const int D_002BE2F8[];
extern "C" const char RO_002A5160[];
extern "C" CRef *RefGetGameSaveValue(CRef *, int, void *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int FGadgetAcquired(int, void *);
extern "C" int sprintf(char *, const char *, ...);

void FormatEpselPercent(char *out)
{
    char *base = B_003DD490;
    HERO *hero = *(HERO **)(base + 0x4774);
    if (hero) {
        int key = ((GLOBALS *)base)->slots[hero->idx];
        if (key) {
            CRef ref;
            RefGetGameSaveValue(&ref, key, B_003D4A60);
            int count = ref.n;
            CRef_Destruct(&ref);
            int percent = count * 95 / 100;
            HERO *again = *(HERO **)(base + 0x4774);
            int acquired = FGadgetAcquired(D_002BE2F8[again->idx], again);
            sprintf(out, RO_002A5160, acquired ? percent + 5 : percent);
        }
    }
}
