#include "sly2.h"
struct HIT {
    int ploSource;        // 0x00
    int a4, a8;
    int grftak;           // 0x0C
    int cDamage;          // 0x10
    char pad14[0x1C];
    QW vecImpulse;        // 0x30
    int a40;
    unsigned grfhit;      // 0x44
    char pad48[0x18];
};
struct CMD { int kind; char pad4[0xC]; HIT hit; };
struct VT { char pad[0x2B0]; short delta; short idx; int (*fn)(void *, void *); };
struct OBJ { char pad[0xC]; VT *vt; };
extern "C" {
int Goal_FHandleMessage(void *, int, void *);
void func_001B9DB8(void *, QW);
void func_001B9D28(void *, QW);
void PhitfxSpawn(void *, QW, void *);
void SetGuardMode(void *, int);
void GoalBrain_SetCommand(void *, void *);
void func_001F7A68(void *, int);
int GrficFromAlo(void *, int);
void SetAlertState(void *, int);
void GoalFlinch_SetState(void *, int);
void ApplyAsegToHandle(float, float, void *, void *, int, void *);
int GrfsgsFromSgs(int);
int func_0020A378(void *, int, int);
int func_0020A298(void *, int, int);
int FIsBasicDerivedFrom(int, int);
int func_001F78A0(int);
void *PguardanimBestMatch(void *, int);
QW bevy_camera_follow_track_heading_weight(int, void *, QW);
QW PosLoWorld(void *);
QW *PmatLoWorld(int);

}
extern void *g_2f7900;
extern void *B_003E14BC;
extern void *B_003E14B0;
extern char B_003DD490[];
extern float g_2dded0;
extern float D_002BE620;
struct FR { CMD cmd; QW s70, s80, s90, sA0, sB0; };
int GoalBrain_FHandleMessage(char *pgoal, int nMsg, HIT *phit)
{
    FR fr;
    if (nMsg == 0xC) {
    HIT *phitWork = phit;
    OBJ *pguardObj = *(OBJ **)(pgoal + 0x10);
    if (pguardObj->vt->fn((char *)pguardObj + pguardObj->vt->delta, phit)) {
        if (g_2f7900) {
            if (phit->ploSource == (int)g_2f7900) {
                if (phit->grftak == 0x40000) {
                    if (*(int *)(phit->ploSource + 0x143C)) {
                        func_001B9DB8(g_2f7900, PosLoWorld(*(void **)(pgoal + 0x10)));
                    }
                }
            }
        }
        if (phit->grftak == 0x40000) {
            void *fx = B_003E14BC;
            PhitfxSpawn(fx, PosLoWorld(*(void **)(pgoal + 0x10)), *(void **)(pgoal + 0x10));
        }
        memset(&fr.cmd, 0, 0x70);
        fr.cmd.kind = 0xB;
        fr.cmd.hit = *phit;
        fr.cmd.hit.grfhit = 0x40;
        GoalBrain_SetCommand(pgoal, &fr.cmd);
        return 1;
    }
    char *pguard = *(char **)(pgoal + 0x10);
    int mode = *(int *)(pguard + 0xFBC);
    switch (mode) {
    case 0xD:
    case 8:
        phit->cDamage = phit->cDamage << 2;
        break;
    case 0xE:
        SetGuardMode(pguard, -1);
        break;
    }
    if (*(int *)(*(char **)(pgoal + 0x10) + 0x29C))
        phit->cDamage = 0;
    char *pguard2 = *(char **)(pgoal + 0x10);
    int kindNow = *(int *)(pgoal + 0x30);
    if (*(int *)(pguard2 + 0x4A4) && kindNow != 0xB && kindNow != 5 && (phit->grftak == 0x4000 || phit->grftak == 0x2000)) {
        func_001F7A68(pguard2, 0);
        memset(&fr.cmd, 0, 0x70);
        fr.cmd.kind = 0x13;
        GoalBrain_SetCommand(pgoal, &fr.cmd);
        return 1;
    }
    switch (kindNow) {
    case 0xA:
        if (!(phit->grftak & *(int *)(pguard2 + 0x354)))
            return 1;
        break;
    case 0xB: {
        int knock = *(int *)(pguard2 + 0x358);
        if (!(phit->grftak & knock))
            return 1;
        if (*(int *)(*(char **)(pgoal + 0x18) + 0x5C) & knock)
            return 1;
        break;
    }
    case 9:
        if (!(GrficFromAlo(pguard2, phit->grftak) & 0x40)) {
            int hitA = *(int *)(*(char **)(pgoal + 0x10) + 0x350);
            if (!(phit->grftak & hitA))
                return 1;
            if (*(int *)(*(char **)(pgoal + 0x18) + 0x5C) & hitA)
                return 1;
        }
        break;
    }
    pguard = *(char **)(pgoal + 0x10);
    if (*(int *)(pguard + 0x38C) == phit->ploSource)
        SetAlertState(*(void **)(pguard + 0x3CC), 5);
    unsigned grfhit = phit->grfhit;
    if (phit->grftak == 0x80000 && (grfhit & 8)) {
        if (*(int *)(pgoal + 0x30) == 8) {
            char *child = *(char **)(pgoal + 0x18);
            GoalFlinch_SetState(child, 0);
            float tMin = g_2dded0 + D_002BE620;
            float tEnd = *(float *)(child + 0x58);
            *(float *)(child + 0x58) = tMin > tEnd ? tMin : tEnd;
        } else {
            char *g = *(char **)(pgoal + 0x10);
            *(int *)(g + 0xE88) = *(int *)(g + 0xE88) + phit->cDamage;
            g = *(char **)(pgoal + 0x10);
            if (*(int *)(g + 0xE88) > 0) {
                ApplyAsegToHandle(0.0f, 1.0f, *(void **)(g + 0xE8C), g, 1, g + 0xE90);
            } else {
                *(int *)(g + 0xE88) = *(int *)(g + 0xE84);
                memset(&fr.cmd, 0, 0x70);
                fr.cmd.kind = 8;
                GoalBrain_SetCommand(pgoal, &fr.cmd);
            }
        }
    } else {
        if (phit->grftak == 0x200000 && (grfhit & 8) && func_0020A378(*(void **)(pgoal + 0x10), phit->ploSource, GrfsgsFromSgs(6))) {
            char *g = *(char **)(pgoal + 0x10);
            int health = *(int *)(g + 0x33C) + phit->cDamage;
            *(int *)(g + 0x33C) = health > 4 ? health : 5;
            char *sw = B_003DD490;
            PhitfxSpawn(*(void **)(sw + 0x4028), PosLoWorld(*(void **)(pgoal + 0x10)), *(void **)(pgoal + 0x10));
            memset(&fr.cmd, 0, 0x70);
            fr.cmd.kind = 7;
            fr.cmd.hit.ploSource = phit->ploSource;
            GoalBrain_SetCommand(pgoal, &fr.cmd);
        } else if (phit->grftak == 0x1000000 && (grfhit & 8)) {
            memset(&fr.cmd, 0, 0x70);
            fr.cmd.kind = func_0020A298(*(void **)(pgoal + 0x10), phit->ploSource, GrfsgsFromSgs(0x17)) ? 0xA : 9;
            fr.cmd.hit = *phit;
            *(int *)(pgoal + 0x30) = -1;
            GoalBrain_SetCommand(pgoal, &fr.cmd);
            SetGuardMode(*(void **)(pgoal + 0x10), 8);
        } else if (phit->grftak == 0x2000000 && (grfhit & 8)) {
            memset(&fr.cmd, 0, 0x70);
            fr.cmd.kind = func_0020A298(*(void **)(pgoal + 0x10), phit->ploSource, GrfsgsFromSgs(0x17)) ? 0xA : 9;
            fr.cmd.hit = *phit;
            *(int *)(pgoal + 0x30) = -1;
            GoalBrain_SetCommand(pgoal, &fr.cmd);
            SetGuardMode(*(void **)(pgoal + 0x10), 0x22);
        } else if (grfhit & 0xF0) {
            unsigned flags = grfhit;
            memset(&fr.cmd, 0, 0x70);
            void *fx;
            if (phit->grftak == 0x40000)
                fx = B_003E14BC;
            else
                fx = B_003E14B0;
            PhitfxSpawn(fx, PosLoWorld(*(void **)(pgoal + 0x10)), *(void **)(pgoal + 0x10));
            int kindRunning = *(int *)(pgoal + 0x30);
            if (kindRunning < 0xB && kindRunning >= 8) {
                if (FIsBasicDerivedFrom(phit->ploSource, 0x65) && (grfhit & 0xB0))
                    flags |= 0x40;
            }
            if (func_0020A298(*(void **)(pgoal + 0x10), phit->ploSource, GrfsgsFromSgs(0x17)))
                flags |= 0x80;
            if (flags & 0x40)
                flags &= ~0xB0u;
            if (flags & 0xA0)
                flags &= ~0x10u;
            if (flags & 0x80) {
                flags &= ~0x20u;
                char *g = *(char **)(pgoal + 0x10) + func_001F78A0(phit->grftak) * 16;
                int animA = *(int *)(g + 0x8D0);
                if (animA == -1) {
                    g = *(char **)(pgoal + 0x10) + func_001F78A0(phit->grftak) * 16;
                    if (*(int *)(g + 0xA70) != animA) {
                        flags &= ~0x80u;
                        flags |= 0x20;
                    }
                }
                g = *(char **)(pgoal + 0x10) + func_001F78A0(phit->grftak) * 16;
                if (*(int *)(g + 0x8D0) == -1) {
                    if (!PguardanimBestMatch(*(void **)(pgoal + 0x10), GrfsgsFromSgs(6))) {
                        flags &= ~0x80u;
                        flags |= 0x20;
                    }
                }
            }
            if (flags & 0x10) {
                char *g = *(char **)(pgoal + 0x10);
                if (*(int *)(g + 0x340) < 1) {
                    flags |= 0x20;
                } else {
                    *(int *)(g + 0x344) = *(int *)(g + 0x344) + phit->cDamage;
                    g = *(char **)(pgoal + 0x10);
                    if (*(int *)(g + 0x344) < 1) {
                        flags |= 0x20;
                    } else {
                        ApplyAsegToHandle(0.0f, 1.0f, *(void **)(g + 0x348), g, 1, g + 0x34C);
                        *(float *)(*(char **)(pgoal + 0x10) + 0x360) = g_2dded0;
                    }
                }
            }
            if (flags & 0xA0) {
                char *g = *(char **)(pgoal + 0x10);
                *(int *)(g + 0x344) = *(int *)(g + 0x340);
                g = *(char **)(pgoal + 0x10);
                int armor = *(int *)(g + 0x340);
                int loss;
                if (armor > 0)
                    loss = -armor;
                else
                    loss = phit->cDamage;
                int health = *(int *)(g + 0x33C) + loss;
                if (health < 0)
                    health = 0;
                *(int *)(g + 0x33C) = health;
                if (*(int *)(*(char **)(pgoal + 0x10) + 0x33C) > 0) {
                    fr.cmd.kind = (flags & 0x80) ? 0xA : 9;
                    fr.cmd.hit = *phit;
                    phitWork = &fr.cmd.hit;
                } else {
                    flags |= 0x40;
                }
            }
            if (flags & 0x40) {
                fr.cmd.kind = 0xB;
                fr.cmd.hit = *phitWork;
                phitWork = &fr.cmd.hit;
            }
            if (flags & 0xE0) {
                if (FIsBasicDerivedFrom(phitWork->ploSource, 0x34)) {
                    fr.s80 = PosLoWorld(*(void **)(pgoal + 0x10));
                    fr.s90 = PosLoWorld((void *)phitWork->ploSource);
                    float off = -150.0f;
                    QW offQ;
                    asm("mfc1 %0, %1" : "=r" (offQ) : "f" (off));
                    fr.sA0 = offQ;
                    fr.s70 = offQ;
                    QW *pmat = PmatLoWorld(phitWork->ploSource);
                    register QW m1 asm("vf1") = pmat[0];
                    register QW m2 asm("vf2") = fr.s90;
                    register QW m3 asm("vf3") = fr.sA0;
                    asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf1, vf1, vf3x" : "=j" (m1) : "j" (m1), "j" (m2), "j" (m3));
                    register QW g2 asm("vf2") = fr.s80;
                    register QW away asm("vf3");
                    asm("vsub.xyzw vf3, vf2, vf1" : "=j" (away) : "j" (g2), "j" (m1));
                    fr.sB0 = away;
                    if (FIsBasicDerivedFrom(phitWork->ploSource, 0x36)) {
                        register QW away2 asm("vf3") = fr.sB0;
                        int hitter = phitWork->ploSource;
                        if (*(int *)(hitter + 0x13D0) == 0xC) {
                            QW awayQ;
                            asm("qmfc2.ni %0, vf3" : "=r" (awayQ) : "j" (away2));
                            fr.s70 = bevy_camera_follow_track_heading_weight(0, (void *)hitter, awayQ);
                            ((float *)&fr.s70)[0] = ((float *)&fr.s70)[0] * 0.25f;
                            QW back = bevy_camera_follow_track_heading_weight(hitter, 0, fr.s70);
                            asm("qmtc2.ni %1, vf3" : "=j" (away2) : "r" (back));
                        }
                        register QW l1 asm("vf1");
                        register QW l2 asm("vf2");
                        asm("vmul.xyz vf2, vf3, vf3\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z" : "=j" (l1), "=j" (l2) : "j" (away2));
                        asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=j" (l2) : "j" (l2));
                        float five = 500.0f;
                        QW fiveQ;
                        asm("mfc1 %0, %1" : "=r" (fiveQ) : "f" (five));
                        asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q" : "=j" (l2) : "j" (l2), "j" (away2));
                        asm("qmtc2.ni %1, vf1" : "=j" (l1) : "r" (fiveQ));
                        fr.s70 = l1;
                        asm("vmulx.xyzw vf1, vf2, vf1x" : "=j" (l1) : "j" (l2), "j" (l1));
                        phitWork->vecImpulse = l1;
                    }
                } else {
                    if (*(int *)(*(char **)(pgoal + 0x10) + 0xFBC) == -1) {
                        if (FIsBasicDerivedFrom(phitWork->ploSource, 0x38)) {
                            if (*(int *)(phitWork->ploSource + 0xFBC) == 0x22)
                                SetGuardMode(*(void **)(pgoal + 0x10), 0x22);
                        }
                    }
                }
                *(int *)(pgoal + 0x30) = -1;
                GoalBrain_SetCommand(pgoal, &fr.cmd);
            }
        }
    }
    if (g_2f7900) {
        if (phitWork->grftak == 0x20000)
            func_001B9D28(g_2f7900, PosLoWorld(*(void **)(pgoal + 0x10)));
    }
    return 1;
    }
    return Goal_FHandleMessage(pgoal, nMsg, phit);
}
