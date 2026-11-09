struct CRef { int tagk; int n; };
struct HERO { char pad[0x110]; int idx; };
struct GLOBALS { char pad0[0x3B58]; int slots[1]; };
extern "C" char B_003D4A60[];
extern "C" char B_003DD490[];
extern "C" const char RO_002A5168[];
extern "C" CRef *RefGetGameSaveValue(CRef *, int, void *);
extern "C" void CRef_Destruct(CRef *);
extern "C" float fmodf(float, float);
extern "C" int sprintf(char *, const char *, ...);

void FormatEpselTime(char *out)
{
    char *base = B_003DD490;
    HERO *hero = *(HERO **)(base + 0x4774);
    if (hero) {
        int key = ((GLOBALS *)base)->slots[hero->idx];
        if (key) {
            CRef ref;
            RefGetGameSaveValue(&ref, key, B_003D4A60);
            float seconds = *(float *)&ref.n;
            CRef_Destruct(&ref);
            int whole = (int)(seconds * 0.00027777778f);
            int minutes = (int)(fmodf(seconds, 3600.0f) * 0.016666668f);
            sprintf(out, RO_002A5168, whole, minutes);
        }
    }
}
