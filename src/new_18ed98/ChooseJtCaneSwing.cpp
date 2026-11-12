// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct LM { float lo; float hi; };
extern "C" {
QW PosLoWorld(char *);
int FCheckLm__FP2LMf(LM *, float);
char *GoalStack_PgoalFind(char *, int);
void SetJtState(char *, int, int);
int FCheckJtCaneSide(char *);
float atan2f(float, float);
float RadNormalize__Ff(float);
extern float D_002BF4AC;
extern LM D_002BF4B0;
}
extern "C" int ChooseJtCaneSwing(char *pjt)
{
    char *pbody = *(char **)(pjt + 0x10DC);
    if (pbody != 0) {
        QW position = PosLoWorld(pbody);
        QW difference = VectorSub(position, PosLoWorld(pjt));
        int near = 0;
        if (LaneX(SqrtX(SquaredLengthXy(difference))) < D_002BF4AC)
            near = FCheckLm__FP2LMf(&D_002BF4B0, LaneZInGeneralRegister(difference)) != 0;
        if (near) {
            char *pgoal = GoalStack_PgoalFind(*(char **)(pjt + 0x10DC) + 0x26C, 0xB1);
            if (pgoal != 0 && *(char **)(pgoal + 0x5C) == pjt) {
                int state = *(int *)(pgoal + 0x50);
                if (state < 2) {
                    if (state >= 0) {
                        SetJtState(pjt, 0x10, -1);
                        return -1;
                    }
                }
            }
        }
    }
    int swing;
    if (*(int *)(pjt + 0x18D0) == 5) {
        char *pvtable = *(char **)(pjt + 0xC);
        float *pforward = ((float *(*)(char *))*(void **)(pvtable + 0xFC))(pjt + *(short *)(pvtable + 0xF8));
        pvtable = *(char **)(pjt + 0xC);
        float forwardX = *((float *(*)(char *))*(void **)(pvtable + 0xFC))(pjt + *(short *)(pvtable + 0xF8));
        float diff = RadNormalize__Ff(*(float *)(*(char **)(pjt + 0x150) + 0x18) - atan2f(pforward[1], forwardX));
        float magnitude = diff < 0.0f ? -diff : diff;
        if (magnitude < 0.7853982f)
            swing = 0xE;
        else if (2.3561945f < magnitude)
            swing = 0x10;
        else if (0.0f < diff)
            swing = 0x12;
        else
            swing = 0x14;
    } else {
        swing = *(int *)(pjt + 0x18C8) == 0 ? 0xC : 0xE;
    }
    switch (*(int *)(pjt + 0x18D8)) {
    case 12: case 14: case 16: case 18: case 20:
        swing += 1;
        break;
    case 13: case 15: case 17: case 19: case 21:
        break;
    default:
        if (FCheckJtCaneSide(pjt) != 0)
            swing += 1;
        break;
    }
    return swing;
}
