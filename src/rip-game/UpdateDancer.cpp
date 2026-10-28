#include "sly2.h"
extern "C" {
extern char *B_002DE570;
void UpdateStep(char *, float);
int FAsegaGone(int);
void SetXfKind(char *, int, int);
void PlayDancerAnim(char *, int, int);
void PlayDancerMove(char *, int, int, int);
void JudgeRhythmPress(char *, char *);
QW func_00204E38(char *, int, float);
}
void UpdateDancer(char *dancer, float dt)
{
    QW junk;
    asm("" : "=m" (junk));
    UpdateStep(dancer, dt);
    int handle = *(int *)(dancer + 0x408);
    if (handle == 0 || FAsegaGone(handle)) {
        SetXfKind(dancer, *(int *)(dancer + 0x58), 1);
        SetXfKind(dancer, *(int *)(dancer + 0x5C), 1);
        *(int *)(dancer + 0x40C) = 0;
        PlayDancerAnim(dancer, *(int *)(dancer + 0x2C0), 8);
    }
    int state = 0;
    if (B_002DE570)
        state = *(int *)(B_002DE570 + 0x50);
    switch (state) {
    case 0:
        if (*(int *)(dancer + 0x40C) == 0)
            PlayDancerMove(dancer, -1, -1, 0);
        break;
    case 2:
        JudgeRhythmPress(B_002DE570, dancer);
        break;
    }
    char *anim = *(char **)(dancer + 0x408);
    if (anim) {
        QW vel = func_00204E38(dancer, (int)anim, *(float *)(anim + 0x1C));
        float scale = -1.0f;
        asm("qmtc2.ni %0, vf3" : : "r" (vel));
        asm("qmtc2.ni %2, vf1\n\tvmulx.xyzw vf2, vf3, vf1x\n\tsqc2 vf1, %0\n\tsqc2 vf2, %1" : "=m" (junk), "=m" (*(QW *)(dancer + 0x190)) : "r" (scale), "r" (vel));
    }
}
