#include "ps2inline.h"
#include "vu0inline.h"
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
    if (ploTarget != 0) {
    QW posTarget = PosLoWorld(ploTarget);
    QW posSelf = PosLoWorld(pmurray);
    QW dir = VectorSub(posTarget, posSelf);
    QW local = bevy_camera_follow_track_heading_weight(0, pmurray, dir);
    float y = LaneYInGeneralRegister(local);
    if (0.0f < y)
        return first;
    return first + 1;
    }
    return first + 1;
}

void StartMurrayAttackB(MURRAY *pmurray)
{
    if (pmurray->pasegA2 == 0 || pmurray->pasegB == 0)
        return;
    SetMurrayState(pmurray, 0xB);
    SetMurrayAttackState(pmurray, AttackStateToStart(pmurray, 2));
}
