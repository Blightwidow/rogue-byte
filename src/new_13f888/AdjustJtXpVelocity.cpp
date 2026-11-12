#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct JOYSTATE { u8 unknown_0x0[0x80]; s32 mode; };
struct JTARG { u8 unknown_0x0[0x150]; JOYSTATE *pjoy; };
struct XPENTRY { u8 unknown_0x0[8]; s32 kind; u8 unknown_0xC[0x34]; };
struct XPARG {
    u8 unknown_0x0[0x40];
    VECTOR velocity;
    u8 *pbEntries;
};
union VU_SCALE { QW q; VECTOR v; };
extern s32 g_2e1e40;
extern s32 g_2dd5bc;
extern s32 g_2f7900;
extern "C" {
s32 bevy_player_p4_144068(JTARG *);
void AdjustSoXpVelocity(JTARG *, s32, XPARG *, s32, s32);
}
void AdjustJtXpVelocity(JTARG *pjt, s32 a1, XPARG *pxp, s32 a3, s32 index)
{
    VU_SCALE scale;
    QW saved = *(QW *)&pxp->velocity;
    s32 kind = ((XPENTRY *)(pxp->pbEntries + ((1 - index) << 6)))->kind;
    if (kind == g_2e1e40 || kind == g_2dd5bc || kind == g_2f7900) {
        if (pjt->pjoy->mode != 1 || bevy_player_p4_144068(pjt) != 0) {
            scale.q = VectorFromFloat(0.01f);
            *(QW *)&pxp->velocity = VectorScaleX(saved, scale.q);
        }
    }
    AdjustSoXpVelocity(pjt, a1, pxp, a3, index);
    *(QW *)&pxp->velocity = saved;
}
