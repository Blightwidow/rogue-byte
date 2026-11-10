#include "types.h"

struct RHYTHMCROWD {
    s32 a;
    s32 b;
    char pad[4];
    s32 c;
    char pad2[0xC];
};

struct RHYTHM {
    char pad[0x2A8];
    u32 ccrowd;
    struct RHYTHMCROWD acrowd[0x80];
};

void AddRhythmCrowd(struct RHYTHM *prhythm, s32 arg1, s32 arg2) {
    u32 temp_a0;
    struct RHYTHMCROWD *pcrowd;

    temp_a0 = prhythm->ccrowd;
    if (temp_a0 < 0x80U) {
        prhythm->ccrowd = (u32) (temp_a0 + 1);
        pcrowd = &prhythm->acrowd[temp_a0];
        pcrowd->a = arg1;
        pcrowd->b = arg2;
        pcrowd->c = -1;
    }
}
