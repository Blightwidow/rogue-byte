#include "sly2.h"
struct ASEG { char pad[0x14]; void *p14; };
struct MURRAY {
    char pad[0x10DC];
    void *ploTarget;
    char pad2[0x17FC - 0x10E0];
    void *pasegA;
    int pad1800;
    void *pasegA2;
    void *pasegB;
    char pad3[0x190C - 0x180C];
    ASEG *pasegaFade;
};
extern "C" void SetMurrayState(MURRAY *, int);
extern "C" void SetMurrayAttackState(MURRAY *, int);
extern "C" QW PosLoWorld(void *);
extern "C" QW bevy_camera_follow_track_heading_weight(void *, void *, QW);

static inline int AttackStateToStart(MURRAY *pmurray, int first)
{
    ASEG *pfade = pmurray->pasegaFade;
    if (pfade != 0) {
        void *pa = pfade->p14;
        if (pa == pmurray->pasegA || pa == pmurray->pasegA2)
            return first + 1;
        return first;
    }
    void *ploTarget = pmurray->ploTarget;
    if (ploTarget == 0)
        return first + 1;
    QW posTarget = PosLoWorld(ploTarget);
    QW posSelf = PosLoWorld(pmurray);
    asm("lqc2 vf1, %0" : : "m" (posTarget));
    asm("qmtc2.ni %0, vf2" : : "r" (posSelf));
    asm("vsub.xyzw vf1, vf1, vf2");
    QW dir;
    asm("qmfc2.ni %0, vf1" : "=r" (dir));
    QW local = bevy_camera_follow_track_heading_weight(0, pmurray, dir);
    int yBits;
    asm("prot3w %0, %1" : "=r" (yBits) : "r" (local));
    float y = *(float *)&yBits;
    if (0.0f < y)
        return first;
    return first + 1;
}

void StartMurrayAttackB(MURRAY *pmurray)
{
    if (pmurray->pasegA2 == 0 || pmurray->pasegB == 0)
        return;
    SetMurrayState(pmurray, 0xB);
    SetMurrayAttackState(pmurray, AttackStateToStart(pmurray, 2));
}
