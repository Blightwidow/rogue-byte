#include "sly2.h"
extern "C" {
int bevy_player_p4_144068(void *);
void AdjustSoXpVelocity(void *, void *, void *, void *, int);
extern int g_2e1e40;
extern int g_2dd5bc;
extern int g_2f7900;
}
void AdjustJtXpVelocity(char *jt, void *arg1, char *xp, void *arg3, int index)
{
    QW junk;
    asm("" : "=m" (junk));
    int sly = g_2e1e40;
    QW saved = *(QW *)(xp + 0x40);
    int other = *(int *)(*(char **)(xp + 0x50) + (1 - index) * 0x40 + 8);
    if (other == sly || other == g_2dd5bc || other == g_2f7900) {
        if (*(int *)(*(char **)(jt + 0x150) + 0x80) != 1 || bevy_player_p4_144068(jt)) {
            float scale = 0.01f;
            asm("lqc2 vf3, %0" : : "m" (saved));
            asm("qmtc2.ni %0, vf1\n\tvmulx.xyzw vf2, vf3, vf1x" : : "r" (scale));
            asm("sqc2 vf1, %0" : "=m" (junk));
            asm("sqc2 vf2, %0" : "=m" (*(QW *)(xp + 0x40)));
        }
    }
    AdjustSoXpVelocity(jt, arg1, xp, arg3, index);
    *(QW *)(xp + 0x40) = saved;
}
