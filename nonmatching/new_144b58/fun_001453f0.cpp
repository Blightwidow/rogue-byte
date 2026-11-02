// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
// Draft: assembler wall (lqc2 in a bnel delay slot plus ps2eeas hazard nops); the chunk also ends one word early
// (its jr delay slot addiu $sp sits at 0x1457A0).
struct LM;
struct ASEGA;
struct LO_1453F0 { char pad0[0xE8]; struct X_1453F0 *px; char pad1[0x2DC - 0xEC]; int n2DC; char pad2[0x1030 - 0x2E0]; ASEGA *pasega; };
struct Y_1453F0 { char pad[0x10]; void *p10; };
struct X_1453F0 { char pad[0xDC]; Y_1453F0 *py; };
struct PARTNER_1453F0 { char pad[0x40]; int n40; };
struct GOAL_1453F0 {
    char pad0[0x10];
    LO_1453F0 *ploSelf;
    char pad1[0x18 - 0x14];
    PARTNER_1453F0 *ppartner;
    char pad2[0x30 - 0x1C];
    LO_1453F0 *ploLeader;
    char pad3[0x50 - 0x34];
    QW posHome;
    int state;
    char pad4[0x6C - 0x64];
    float dMin;
    float dMax;
    float gSpeedNear;
    float gSpeedFar;
    char pad5[0x90 - 0x7C];
    LO_1453F0 *ploTarget;
};
extern "C" {
void func_001EEF98(GOAL_1453F0 *);
QW PosLoWorld(LO_1453F0 *);
LO_1453F0 *GoalPartnerFollow_PloFindEnemy(GOAL_1453F0 *);
int func_001EF0A8(GOAL_1453F0 *);
int func_001459C0(GOAL_1453F0 *);
void func_00145B18(GOAL_1453F0 *, int);
int CidGetBasic(LO_1453F0 *);
int GoalPartnerAttackSly_FIdle(PARTNER_1453F0 *);
int GoalPartnerAttackMurray_FIdle(PARTNER_1453F0 *);
int GoalPartnerAttackBentley_FIdle(PARTNER_1453F0 *);
void func_001457A8(GOAL_1453F0 *);
void SetAsegaSpeed(ASEGA *, float);
}
int FCheckLm(LM *, float);
extern "C" LM D_002BD330;
extern "C" LM D_002BD338;
extern "C" float g_2bd340;
static inline float GClamp(float g, float lo, float hi)
{
    if (g < lo)
        g = lo;
    else if (hi < g)
        g = hi;
    return g;
}
static inline float Lane0(QW q)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); // lane x
    return f;
}
static inline float Dist2(VECTOR *pa, QW b)
{
    QW d;
    asm("qmtc2.ni %2, vf3\n\tlqc2 vf2, %1\n\tvsub.xyzw vf1, vf2, vf3\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\t"
        "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(d) : "m"(*pa), "r"(b));
    return Lane0(d);
}
static inline float Dist2M(VECTOR *pa, VECTOR *pb)
{
    QW d;
    asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\t"
        "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(d) : "m"(*pa), "m"(*pb));
    return Lane0(d);
}
// distances from pos to *pa (first result) and to *pb (second result)
static inline void Dist3Pair(QW pos, VECTOR *pa, VECTOR *pb, float *pdA, float *pdB)
{
    QW dA;
    QW dB;
    asm("qmtc2.ni %2, vf1\n\tlqc2 vf3, %3\n\tvsub.xyzw vf2, vf1, vf3\n\tlqc2 vf3, %4\n\tvsub.xyzw vf1, vf1, vf3\n\t"
        "vmul.xyz vf2, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\t"
        "vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z\n\t"
        "vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\t"
        "qmfc2.ni %0, vf2\n\tqmfc2.ni %1, vf1" : "=r"(dA), "=r"(dB) : "r"(pos), "m"(*pa), "m"(*pb));
    *pdA = Lane0(dA);
    *pdB = Lane0(dB);
}
static inline float Dist3(QW a, VECTOR *pb)
{
    QW d;
    asm("qmtc2.ni %2, vf1\n\tlqc2 vf3, %1\n\tvsub.xyzw vf2, vf1, vf3\n\tvmul.xyz vf2, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\t"
        "vadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tqmfc2.ni %0, vf2" : "=r"(d) : "m"(*pb), "r"(a));
    return Lane0(d);
}
extern "C" void func_001453F0(GOAL_1453F0 *pgoal)
{
    func_001EEF98(pgoal);
    LO_1453F0 *ploSelf = pgoal->ploSelf;
    LO_1453F0 *ploLeader = pgoal->ploLeader;
    VECTOR posSelf;
    VECTOR posLeader;
    *(QW *)&posSelf = PosLoWorld(ploSelf);
    *(QW *)&posLeader = PosLoWorld(ploLeader);
    float dLeader = Dist2(&posSelf, *(QW *)&posLeader);
    LO_1453F0 *ploEnemy = GoalPartnerFollow_PloFindEnemy(pgoal);
    float dEnemy;
    if (ploEnemy) {
        QW posEnemy = PosLoWorld(ploEnemy);
        float d0;
        float d1;
        Dist3Pair(posEnemy, &posSelf, &posLeader, &d0, &d1);
        dEnemy = d0 < d1 ? d0 : d1;
    } else
        dEnemy = 3.402823466e+38f;
    for (;;) {
        if (func_001EF0A8(pgoal))
            break;
        int state = pgoal->state;
        switch (state) {
        case 0:
            if (func_001459C0(pgoal)) {
                func_00145B18(pgoal, 1);
            } else if (FCheckLm(&D_002BD330, dEnemy)) {
                pgoal->ploTarget = ploEnemy;
                func_00145B18(pgoal, 2);
            }
            break;
        case 1:
            if (pgoal->ploSelf->n2DC == -1)
                func_00145B18(pgoal, 0);
            break;
        case 2:
            if (func_001459C0(pgoal)) {
                func_00145B18(pgoal, 1);
            } else if (!FCheckLm(&D_002BD338, dEnemy)) {
                func_00145B18(pgoal, 0);
            } else {
                switch (CidGetBasic(pgoal->ploSelf)) {
                case 0x36:
                    if (GoalPartnerAttackMurray_FIdle(pgoal->ppartner))
                        func_00145B18(pgoal, 0);
                    break;
                case 0x37:
                    if (GoalPartnerAttackBentley_FIdle(pgoal->ppartner))
                        func_00145B18(pgoal, 0);
                    break;
                case 0x35:
                    if (GoalPartnerAttackSly_FIdle(pgoal->ppartner))
                        func_00145B18(pgoal, 0);
                    break;
                }
            }
            break;
        }
        if (pgoal->state == state)
            break;
    }
    if (pgoal->state != 0)
        return;
    X_1453F0 *px = pgoal->ploSelf->px;
    Y_1453F0 *py = px ? px->py : 0;
    void *pv = py ? py->p10 : 0;
    if (!pv)
        pgoal->ppartner->n40 = 1;
    int fFar = g_2bd340 < Dist2M((VECTOR *)&pgoal->posHome, &posLeader) ? 1 : 0;
    if (fFar)
        func_001457A8(pgoal);
    if (ploSelf->pasega) {
        float t = GClamp((dLeader - pgoal->dMin) / (pgoal->dMax - pgoal->dMin), 0.0f, 1.0f);
        SetAsegaSpeed(ploSelf->pasega, (1.0f - t) * pgoal->gSpeedNear + t * pgoal->gSpeedFar);
    }
}
