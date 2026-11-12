// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#define FIELD(base, type, offset) (*(type *)((char *)(base) + (offset)))

struct LO;
struct VTLO {
    char pad[0x10];
    short offThis10;
    char pad12[2];
    void (*pfn14)(void *, LO *);
};

extern "C" {
int CGc_FFindScreen(void *);
int ConsumeJoyButton(void *, int);
int FAsegaGone(void *);
int FFloatsNear__Ffff(float, float, float);
int FIsBasicDerivedFrom(void *, int);
int FJoyButtonPressed(void *, int);
int FLoHasOid(int, int);
int FSggHasAlarm(void *, int);
int FSmaRetracted(int);
int FStreamPlaying(void *, int);
int FVjoyButtonPressed(void *, int);
float GLimitLm__FP2LMf(void *, float);
void GetSeqnodeObjectPosRad(void *, void *, void *, void *);
int GetSmaCur(int);
int GoalFollowCrv_FAtEnd(int);
int GoalGotoPos_FArrived(int);
void GoalStack_Clear(void *);
void JT_EndPose(void *);
int JT_FPosing(int);
float MarkClockTickRealOnly__FP5CLOCK(void *);
void *PloFindSeqnodeObject(void *, int);
QW PosLoWorld(void *);
int PseqnodeFind(void *, int, void *);
void ReleaseSeqnodeSma(void *);
void StopSeqnodeCameraMove(void *, int);
float TStream(void *);
void bevy_player_p14_19e110(void *, void *);
int func_001423A0(void *);
int func_001424C0(void *);
int func_001424D0(void *);
int func_00142530(void *);
void func_001448F0(void *, QW);
int func_00150F58(void *);
int func_00151018(void *);
int func_001510D8(void *);
int func_00171DA8(int, int);
void func_001E0070(void *, int);
void func_001E5468(void *);
int func_00205458(void *, int);
int func_002121C8(int);
extern char B_002DE460[];
extern char B_002DFC00[];
extern char B_003DA530[];
extern char B_003DD040[];
extern char *B_003E133C;
extern int B_004435F8;
extern float RO_002BD850;
extern float RO_002C3620;
extern float RO_002C3624;
extern float RO_002C3628;
extern float RO_002C362C;
extern float g_2dded0;
extern float g_2ddf0c;
}

static inline float TSeqnode(char *pseqnode) {
    int grf = FIELD(FIELD(pseqnode, char *, 0x14), int, 0x40);
    if ((grf & 1) == 0) {
        grf = *(int *)grf;
    }
    float t;
    if (grf & 0x100) {
        t = g_2ddf0c;
    } else {
        t = g_2dded0;
    }
    return t - FIELD(pseqnode, float, 0x34);
}

static inline float DistToObject(char *plo, char *pvPos) {
    QW offset = VectorSub(PosLoWorld(plo), *(QW *)pvPos);
    return LaneX(SqrtX(SumXyInX(VectorMultiplyXy(offset, offset))));
}


extern "C" int FSeqnodeRecordDone(char *pseqnode, char *prec) {
    QW pos;
    QW posObj;
    int fDone;
    switch (FIELD(prec, int, 0)) {
    case 0x3: {
        fDone = 1;
        for (int i = 0; i < FIELD(prec, int, 0x10); i++) {
            if (PseqnodeFind(FIELD(pseqnode, char *, 0x14), ((int *)(prec + 0x14))[i], pseqnode) != 0) {
                fDone = 0;
                break;
            }
        }
        break;
    }
    case 0x4:
        fDone = FSggHasAlarm(FIELD(pseqnode, char *, 0x14), FIELD(prec, int, 0x10));
        if (fDone != 0 && FIELD(prec, int, 0x14) != 0) {
            func_001E0070(FIELD(pseqnode, char *, 0x14), FIELD(prec, int, 0x10));
        }
        return fDone;
    case 0xA:
        if (FIELD(pseqnode, int, 0x54) != 0) {
            fDone = 0;
            if (JT_FPosing(FIELD(pseqnode, int, 0x54)) == 0) {
                FIELD(pseqnode, int, 0x54) = 0;
                fDone = 1;
            }
            break;
        }
        if (FIELD(pseqnode, char *, 0x4C) != 0 && FAsegaGone(FIELD(pseqnode, char *, 0x4C)) != 0) {
            LO *pasega = FIELD(pseqnode, LO *, 0x4C);
            VTLO *pvt = FIELD(pasega, VTLO *, 0xC);
            short off = pvt->offThis10;
            void (*pfn)(void *, LO *) = pvt->pfn14;
            pfn((char *)pasega + off, pasega);
            FIELD(pseqnode, char *, 0x4C) = 0;
        }
        fDone = FIELD(pseqnode, char *, 0x4C) == 0;
        break;
    case 0xB:
        fDone = FIELD(pseqnode, char *, 0x50) == 0;
        if (FIELD(pseqnode, char *, 0x50) != 0) {
            if (FIELD(FIELD(pseqnode, char *, 0x50), int, 0x74) == 0) {
                FIELD(pseqnode, char *, 0x50) = 0;
            }
            fDone = FIELD(pseqnode, char *, 0x50) == 0;
        }
        break;
    case 0xD:
        if (FIELD(pseqnode, int, 0x58) != 0 &&
            (FSmaRetracted(FIELD(pseqnode, int, 0x58)) != 0 || FIELD(pseqnode, int, 0x5C) != 0)) {
            ReleaseSeqnodeSma(pseqnode);
        }
        fDone = FIELD(pseqnode, int, 0x58) == 0;
        break;
    case 0xE:
        if (FIELD(pseqnode, int, 0x64) != 0 && func_002121C8(FIELD(pseqnode, int, 0x64)) != 0) {
            func_001E5468(pseqnode);
        }
        fDone = FIELD(pseqnode, int, 0x64) == 0;
        break;
    case 0x1A: {
        if (FIELD(pseqnode, char *, 0x44) == 0) {
            fDone = 1;
            break;
        }
        bevy_player_p14_19e110(FIELD(pseqnode, char *, 0x44) + 0xF50, &pos);
        fDone = __builtin_fabsf(FIELD(FIELD(pseqnode, char *, 0x44), float, 0xF60) -
                                GLimitLm__FP2LMf(&pos, FIELD(pseqnode, float, 0x7C))) < FIELD(prec, float, 0x14);
        break;
    }
    case 0x1B: {
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x24) == 0) {
            break;
        }
        if (FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x34) == 0) {
            break;
        }
        char *plo = FIELD(pseqnode, char *, 0x24);
        fDone = 0;
        if ((unsigned)(FIELD(plo, int, 0x2DC) - 0xB) < 3) {
            break;
        }
        fDone = 1;
        if (FIELD(plo, int, 0x4CC) == -1) {
            break;
        }
        if (FIELD(plo, int, 0x4C8) == 0 || FIELD(plo, int, 0x4C8) == 0xD) {
            VTLO *pvt = FIELD(plo, VTLO *, 0xC);
            fDone = 1;
            ((void (*)(void *, int, char *))FIELD(pvt, void *, 0x2C4))(plo + FIELD(pvt, short, 0x2C0), 0, plo);
        }
        return fDone;
    }
    case 0x1C: {
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x24) == 0) {
            break;
        }
        if (FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x35) == 0) {
            fDone = 1;
            break;
        }
        char *plo = FIELD(pseqnode, char *, 0x24);
        switch (FIELD(prec, int, 0x14)) {
        case 4:
            fDone = FIELD(plo, int, 0x18C8) != 2;
            break;
        case 2:
            fDone = FIELD(plo, int, 0x18D8) == -1;
            break;
        case 8:
            fDone = FIELD(plo, int, 0x18C8) != 9;
            break;
        default:
            fDone = 1;
            break;
        }
        break;
    }
    case 0x1D:
    case 0x21:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x44) != 0) {
            fDone = func_001423A0(FIELD(pseqnode, char *, 0x44));
        }
        break;
    case 0x1E:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x44) != 0) {
            fDone = func_001424C0(FIELD(pseqnode, char *, 0x44));
        }
        break;
    case 0x1F:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x44) != 0) {
            fDone = func_001424D0(FIELD(pseqnode, char *, 0x44));
        }
        break;
    case 0x22:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x44) != 0) {
            fDone = func_00142530(FIELD(pseqnode, char *, 0x44));
        }
        break;
    case 0x23:
    {
        float dt = TSeqnode(pseqnode);
        fDone = FIELD(prec, float, 0x10) < dt;
        break;
    }
    case 0x24: {
        char *pjt = FIELD(pseqnode, char *, 0x44);
        fDone = 1;
        if (pjt == 0) {
            break;
        }
        void *plo = PloFindSeqnodeObject(pseqnode, FIELD(prec, int, 0x10));
        if (plo != 0) {

            GetSeqnodeObjectPosRad(pseqnode, plo, &posObj, 0);
            fDone = DistToObject(pjt, (char *)&posObj) < FIELD(prec, float, 0x18);
            func_001448F0(pjt + 0xFD0, *(QW *)&posObj);
        } else {
            fDone = 1;
        }
        if (fDone != 0 && FIELD(prec, int, 0x20) != -1) {
            JT_EndPose(pjt);
        }
        return fDone;
    }
    case 0x27: {
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x24) == 0) {
            break;
        }
        if (FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x34) == 0) {
            fDone = 1;
            break;
        }
        char *plo = FIELD(pseqnode, char *, 0x24);
        fDone = 0;
        int pgoal = func_00205458(plo, 0xA8);
        if (pgoal == 0 || GoalFollowCrv_FAtEnd(pgoal) != 0) {
            fDone = 1;
        }
        if (fDone != 0) {
            GoalStack_Clear(plo + 0x26C);
            if (FIELD(prec, int, 0x24) != -1) {
                JT_EndPose(plo);
            }
        }
        return fDone;
    }
    case 0x28: {
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x24) == 0) {
            break;
        }
        if (FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x34) == 0) {
            fDone = 1;
            break;
        }
        char *plo = FIELD(pseqnode, char *, 0x24);
        fDone = 0;
        int pgoal = func_00205458(plo, 0xC1);
        if (pgoal == 0 || GoalGotoPos_FArrived(pgoal) != 0) {
            fDone = 1;
        }
        if (fDone != 0) {
            GoalStack_Clear(plo + 0x26C);
            if (FIELD(prec, int, 0x24) != -1) {
                JT_EndPose(plo);
            }
        }
        return fDone;
    }
    case 0x29: {
        char *pjt = FIELD(pseqnode, char *, 0x44);
        if (pjt == 0 || FIELD(pjt, int, 0x4CC) == -1) {
            fDone = 1;
            break;
        }
        fDone = 1;
        if (FIELD(pjt, int, 0x4C8) != 8) {
            break;
        }
        void *plo = PloFindSeqnodeObject(pseqnode, FIELD(prec, int, 0x10));
        if (plo == 0) {
            fDone = 1;
            break;
        }
        GetSeqnodeObjectPosRad(pseqnode, plo, &pos, 0);
        fDone = DistToObject(pjt, (char *)&pos) < FIELD(prec, float, 0x18);
        break;
    }
    case 0x2A:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x44) != 0) {
            fDone = FIELD(FIELD(pseqnode, char *, 0x44), int, 0x2DC) == -1;
        }
        break;
    case 0x2B:
        fDone = FIELD(pseqnode, char *, 0x24) == 0 || FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x34) == 0 ||
                FIELD(FIELD(pseqnode, char *, 0x24), int, 0x2DC) == -1;
        break;
    case 0x2C:
    case 0x2D: {
        char *pmusic = FIELD(pseqnode, char *, 0x60);
        if (pmusic != 0) {
            if (FIELD(prec, int, 0) == 0x2C) {
                if (((int)(FIELD(pmusic, unsigned long, 0x28) >> 0x3C) & 1) && FIELD(pmusic, float, 0x12C) == 1.0f) {
                    FIELD(pseqnode, char *, 0x60) = 0;
                }
            } else if (((int)(FIELD(pmusic, unsigned long, 0x28) >> 0x3C) & 1) == 0) {
                FIELD(pseqnode, char *, 0x60) = 0;
            }
        }
        fDone = FIELD(pseqnode, char *, 0x60) == 0;
        break;
    }
    case 0x32:
    {
        float dt = TSeqnode(pseqnode);
        fDone = RO_002BD850 < dt;
        break;
    }
    case 0x33:
    {
        float dt = TSeqnode(pseqnode);
        fDone = FIELD(prec, float, 0x10) < dt;
        break;
    }
    case 0x39:
        fDone = FIELD(pseqnode, float, 0x80) <= g_2dded0;
        if (fDone) {
            if (FIELD(prec, int, 0x40) == 0) {
                FIELD(pseqnode, int, 0x9C) = 0;
            } else {
                StopSeqnodeCameraMove(pseqnode, FIELD(prec, int, 0x44));
            }
        }
        break;
    case 0x3B:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0xA0) != 0) {
            fDone = FIELD(FIELD(pseqnode, char *, 0xA0), int, 0xF28) == 1;
        }
        break;
    case 0x3C:
        fDone = 1;
        if (FIELD(pseqnode, char *, 0xA0) != 0) {
            fDone = FIELD(FIELD(pseqnode, char *, 0xA0), int, 0xF28) == -1;
        }
        break;
    case 0x3D:
        fDone = func_00150F58(B_002DE460);
        break;
    case 0x3E:
        fDone = func_00151018(B_002DE460);
        break;
    case 0x40:
        fDone = func_001510D8(B_002DE460);
        break;
    case 0x42:
        if (FIELD(prec, int, 0x14) == -1) {
            fDone = FJoyButtonPressed(B_002DFC00, FIELD(prec, int, 0x10));
        } else {
            char *pvjoy;
            for (pvjoy = B_003E133C; pvjoy != 0; pvjoy = FIELD(pvjoy, char *, 0x84)) {
                fDone = 0;
                if (FLoHasOid(FIELD(pvjoy, int, 0x7C), FIELD(prec, int, 0x14)) != 0) {
                    break;
                }
            }
            fDone = 0;
            if (pvjoy == 0 || FVjoyButtonPressed(pvjoy, FIELD(prec, int, 0x10)) != 0) {
                fDone = 1;
            }
            if (fDone == 0) {
                break;
            }
            ConsumeJoyButton(B_002DFC00, FIELD(prec, int, 0x10));
        }
        if (fDone != 0) {
            B_004435F8 = 0;
        }
        break;
    case 0x43:
        fDone = FIELD(pseqnode, char *, 0x24) == 0 || FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x34) == 0 ||
                ((int (*)(void *, char *))FIELD(FIELD(FIELD(pseqnode, char *, 0x24), VTLO *, 0xC), void *, 0x2CC))(
                    FIELD(pseqnode, char *, 0x24) + FIELD(FIELD(FIELD(pseqnode, char *, 0x24), VTLO *, 0xC), short, 0x2C8),
                    FIELD(pseqnode, char *, 0x24)) == FIELD(prec, int, 0x10);
        break;
    case 0x44:
        fDone = CGc_FFindScreen(B_003DA530) == 0;
        break;
    case 0x45:
        fDone = FStreamPlaying(B_003DD040, FIELD(prec, int, 0x10)) == 0;
        break;
    case 0x52: {
        int istream = -1;
        if (FIELD(pseqnode, char *, 0x68) != 0) {
            istream = FIELD(FIELD(pseqnode, char *, 0x68), int, 0x10);
        }
        fDone = FStreamPlaying(B_003DD040, istream) == 0 ||
                (!(FIELD(prec, float, 0x10) < 0.0f) && TStream(B_003DD040) - FIELD(prec, float, 0x10) >= 0.0f);
        break;
    }
    case 0x4A:
        fDone = FIELD(prec, float, 0x10) <= MarkClockTickRealOnly__FP5CLOCK(B_003DD040);
        break;
    case 0x4E:
        fDone = FIELD(prec, float, 0x10) <= MarkClockTickRealOnly__FP5CLOCK(B_003DD040);
        break;
    case 0x4F:
        fDone = FIsBasicDerivedFrom(FIELD(pseqnode, char *, 0x24), 0x36) &&
                (FIELD(FIELD(pseqnode, char *, 0x24), int, 0x13D0) != 6 ||
                 (FIELD(prec, int, 0x1C) != -1 &&
                  GetSmaCur(FIELD(FIELD(pseqnode, char *, 0x24), int, 0x1034)) == FIELD(prec, int, 0x1C)));
        break;
    case 0x50:
        fDone = FIELD(pseqnode, char *, 0x44) == 0 || FIELD(FIELD(pseqnode, char *, 0x44), int, 0x13D0) == 6;
        break;
    case 0x51:
        fDone = FIELD(pseqnode, char *, 0x44) == 0 || FIELD(FIELD(pseqnode, char *, 0x44), int, 0x13D0) != 6;
        break;
    case 0x53:
    {
        float dt = TSeqnode(pseqnode);
        fDone = FIELD(prec, float, 0x14) < dt;
        break;
    }
    case 0x55:
        if (FIELD(pseqnode, int, 0xDC) != 0 && func_00171DA8(FIELD(pseqnode, int, 0xD8), FIELD(pseqnode, int, 0xDC)) == 0) {
            FIELD(pseqnode, int, 0xD8) = 0;
            FIELD(pseqnode, int, 0xDC) = 0;
        }
        fDone = FIELD(pseqnode, int, 0xDC) == 0;
        break;
    case 0x58: {
        fDone = 1;
        if (FIELD(pseqnode, char *, 0x44) == 0) {
            break;
        }
        char *plo = (char *)PloFindSeqnodeObject(pseqnode, FIELD(prec, int, 0x10));
        fDone = 1;
        if (RO_002C3620 < TSeqnode(pseqnode)) {
            break;
        }
        fDone = 0;
        if (FIELD(plo, int, 0x1914) < 7) {
            fDone = FIELD(plo, int, 0x1914) >= 4;
        }
        break;
    }
    case 0x59: {
        char *pjt = FIELD(pseqnode, char *, 0x44);
        fDone = 1;
        if (pjt == 0) {
            break;
        }
        fDone = 1;
        if (RO_002C3624 < TSeqnode(pseqnode)) {
            break;
        }
        QW posA = FIELD(pjt, QW, 0x1A20);
        QW posB = FIELD(pjt, QW, 0x19F0);
        float eps = RO_002C3628;
        fDone = FFloatsNear__Ffff(LaneX(posA), LaneX(posB), eps) && FFloatsNear__Ffff(LaneYInGeneralRegister(posA), LaneYInGeneralRegister(posB), eps) &&
                FFloatsNear__Ffff(LaneZInGeneralRegister(posA), LaneZInGeneralRegister(posB), eps);
        break;
    }
    case 0x5A: {
        char *pjt = FIELD(pseqnode, char *, 0x44);
        fDone = 1;
        if (pjt == 0) {
            break;
        }
        fDone = 1;
        if (RO_002C362C < TSeqnode(pseqnode)) {
            break;
        }
        fDone = 0;
        if ((unsigned)(FIELD(pjt, int, 0x1914) + 1) >= 2) {
            break;
        }
        if (FIELD(pjt, int, 0x1914) == 0) {
            VTLO *pvt = FIELD(pjt, VTLO *, 0xC);
            ((void (*)(void *, int, char *))FIELD(pvt, void *, 0x2C4))(pjt + FIELD(pvt, short, 0x2C0), 0, pjt);
        }
        fDone = FIELD(FIELD(prec, char *, 0x18), int, 0x2DC) == -1;
        break;
    }
    default:
        fDone = 1;
        break;
    }
    return fDone;
}
