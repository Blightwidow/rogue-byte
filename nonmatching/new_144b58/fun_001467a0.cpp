#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
#include "goal.h"
union VU_DIR { QW q; VECTOR v; };
struct LO_TARGET { char pad[0x330]; int fBlocked; };
struct STEP_1467A0 { char pad_0[0x2DC]; int mode2DC; float t2E0; };
struct GOAL_1467A0 : GOAL {
    int state;
    float tState;
    LO_TARGET *ptarget;
};
extern "C" {
void func_001EEF98(void *);
int FIsLoInWorld(void *);
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
float GRandInRange(float, float);
void func_00146E18(GOAL_1467A0 *, int);
}
extern QW g_2a2da0;
extern float D_FLT_002BD360;
extern float D_FLT_002BD368;
extern float D_FLT_002BD36C;
extern float D_FLT_002BD370;
extern float g_2dded0;
extern "C" void func_001467A0(GOAL_1467A0 *pgoal)
{
    func_001EEF98(pgoal);
    if (pgoal->state == -1)
        return;
    if (*(int *)((char *)pgoal->pstep + 0xDF4) != -1 || !FIsLoInWorld(pgoal->ptarget) || pgoal->ptarget->fBlocked != 0) {
        func_00146E18(pgoal, -1);
        return;
    }
    QW target = PosLoWorld(pgoal->ptarget);
    QW self = PosLoWorld(pgoal->pstep);
    QW *pdefault = &g_2a2da0;
    VU_DIR dir;
    dir.q = VectorSub(target, self);
    dir.v.z = 0.0f;
    QW flat = dir.q;
    QW lengthq = SqrtX(SquaredLength(flat));
    if (LaneX(lengthq) < 0.0001f)
        dir.q = *pdefault;
    else
        dir.q = ScaleByReciprocalX(flat, lengthq);
    float distance = LaneX(lengthq);
    int state;
    do {
        state = pgoal->state;
        switch ((unsigned int)state) {
        case 0:
            if (distance < D_FLT_002BD360) {
                QW *pmat = PmatLoWorld(pgoal->pstep);
                if (0.8f < LaneX(DotProduct(pmat[0], dir.q))) {
                    if (GRandInRange(0.0f, 1.0f) < 0.3f)
                        func_00146E18(pgoal, 3);
                    else
                        func_00146E18(pgoal, 2);
                }
            } else if (D_FLT_002BD36C < distance) {
                func_00146E18(pgoal, 1);
            }
            break;
        case 1:
            if (distance < D_FLT_002BD368)
                func_00146E18(pgoal, 0);
            break;
        case 2:
            if (*(int *)((char *)pgoal->pstep + 0x18D8) == -1 && g_2dded0 - pgoal->tState > 0.1f)
                func_00146E18(pgoal, -1);
            break;
        case 3:
            if (g_2dded0 - pgoal->tState > 0.1f) {
                STEP_1467A0 *pstep = (STEP_1467A0 *)pgoal->pstep;
                if (pstep->mode2DC != -1) {
                    if (pstep->mode2DC == 1) {
                        if (D_FLT_002BD370 < g_2dded0 - pstep->t2E0)
                            func_00146E18(pgoal, 4);
                    }
                } else {
                    func_00146E18(pgoal, -1);
                }
            }
            break;
        case 4:
            if (g_2dded0 - pgoal->tState > 0.1f && *(int *)((char *)pgoal->pstep + 0x18C8) != 0xD)
                func_00146E18(pgoal, -1);
            break;
        }
    } while (pgoal->state != state);
}
