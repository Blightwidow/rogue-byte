#include "sly2.h"
#include "vu0inline.h"
#include "ps2inline.h"
struct VT { char pad0[0x108]; short delta108; short u108; QW (*fn10C)(char *, char *); char pad1[0x118 - 0x110]; short delta118; short u118; void (*fn11C)(char *, QW, char *); };
struct OBJ1C { char pad[0x1C]; float value; };
struct HOLDER { char pad[0x90]; OBJ1C *obj; };
struct PLAYER { char pad0[0xC]; VT *vt; char pad1[0x58 - 0x10]; HOLDER *holder58; char pad2[0x208 - 0x5C]; int f208; };
struct XFPTR;
struct XFOWNER { char pad[0x19A4]; XFPTR *xf; };
struct XFPTR { char pad[0x60]; int dummy; };
#include "goal.h"
struct GOAL_17AC90 : GOAL {
    char pad_30[0x20];
    int state;
    float since;
    char pad_58[0x4];
    char *owner;
    char pad_60[0x4];
    OBJ1C *anchor;
};
static inline QW VelocityOf(PLAYER *player)
{
    VT *vt = player->vt;
    return vt->fn10C((char *)player + vt->delta108, (char *)player);
}
union LQ { QW q; float g[4]; };
struct LEAP { QW matrix[4]; LQ pos; LQ vel; LQ target; LQ result; LQ scale; };
extern "C" {
void GoalAnimLeap_SetState(GOAL_17AC90 *, int);
void GoalAnim_Update();
QW PosLoWorld(void *);
void PredictXfTransform(int, int, float, void *, void *);
void func_0017ABC8(GOAL_17AC90 *, int);
extern float D_FLT_002BE6C8;
extern float D_FLT_002BE6CC;
extern float g_2dded0;
void GoalAnimLeap_Update(GOAL_17AC90 *self) {
    QW vel;
    GoalAnim_Update();
    {
        PLAYER *player = (PLAYER *)self->pstep;
        vel = VelocityOf(player);
    }
    int old;
    do {
        old = self->state;
        switch (old) {
        case 0:
        case 1: {
            PLAYER *player = ((PLAYER *)self->pstep);
            if (old != 1 || player->f208 == 0) {
                OBJ1C *obj = player->holder58->obj;
                if (obj != self->anchor || obj->value < g_2dded0) {
                    GoalAnimLeap_SetState(self, 2);
                } else {
                    if (LaneZInGeneralRegister(vel) < 0.0f && self->state == 0)
                        GoalAnimLeap_SetState(self, 1);
                    else
                        func_0017ABC8(self, self->state);
                }
            } else {
                GoalAnimLeap_SetState(self, 3);
            }
            break;
        }
        case 2:
            if (((PLAYER *)self->pstep)->f208 != 0) GoalAnimLeap_SetState(self, 3);
            break;
        case 4:
        case 5: {
            LEAP leap;
            float *clock = &g_2dded0;
            leap.pos.q = PosLoWorld(((PLAYER *)self->pstep));
            {
                PLAYER *player = (PLAYER *)self->pstep;
                leap.vel.q = VelocityOf(player);
            }
            PredictXfTransform(((XFOWNER *)self->owner)->xf->dummy, 0, clock[1], &leap, 0);
            leap.target.q = leap.matrix[3];
            leap.target.g[2] += D_FLT_002BE6C8;
            QW target = leap.target.q;
            QW toTarget = VectorSub(target, PosLoWorld(((PLAYER *)self->pstep)));
            leap.scale.q = VectorFromWord(*(u32 *)&clock[1]);
            leap.result.q = ScaleByReciprocalX(toTarget, leap.scale.q);
            if (self->state == 4) {
                if (leap.pos.g[2] < leap.target.g[2] || D_FLT_002BE6CC < clock[0] - self->since) {
                    GoalAnimLeap_SetState(self, 5);
                    break;
                }
                leap.result.g[2] = leap.vel.g[2];
            }
            {
                PLAYER *player = (PLAYER *)self->pstep;
                player->vt->fn11C((char *)player + player->vt->delta118, leap.result.q, (char *)player);
            }
            break;
        }
        case 6:
            if (((PLAYER *)self->pstep)->f208 != 0) GoalAnimLeap_SetState(self, -1);
            break;
        }
    } while (self->state != old);
}
}
