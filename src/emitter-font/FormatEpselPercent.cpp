#include "cref.h"
struct GAME { char pad[0x4774]; };
struct HERO { char pad[0x110]; int idx; };
struct GLOBALS { char pad0[0x3B7C]; int slots[1]; };
extern "C" char B_003D4A60[];
extern "C" char B_003DD490[];
extern "C" const int D_002BE2F8[];
extern "C" const char RO_002A5160[];
extern "C" CRef RefGetGameSaveValue(int, void *);
extern "C" int FGadgetAcquired(int, void *);
extern "C" int sprintf(char *, const char *, ...);

void FormatEpselPercent(char *out)
{
    char *base = B_003DD490;
    HERO *hero = *(HERO **)(base + 0x4774);
    if (hero) {
        int key = ((GLOBALS *)base)->slots[hero->idx];
        if (key) {
            int count = RefGetGameSaveValue(key, B_003D4A60).m_tag.m_n;
            int percent = count * 95 / 100;
            HERO *again = *(HERO **)(base + 0x4774);
            int acquired = FGadgetAcquired(D_002BE2F8[again->idx], again);
            sprintf(out, RO_002A5160, acquired ? percent + 5 : percent);
        }
    }
}
