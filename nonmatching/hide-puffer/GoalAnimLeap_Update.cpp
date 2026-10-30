#include "sly2.h"
struct VT { char pad0[0x108]; short delta108; short u108; QW (*fn10C)(char *, char *); char pad1[0x118 - 0x110]; short delta118; short u118; void (*fn11C)(char *, QW, char *); };
struct OBJ1C { char pad[0x1C]; float value; };
struct HOLDER { char pad[0x90]; OBJ1C *obj; };
struct PLAYER { char pad0[0xC]; VT *vt; char pad1[0x58 - 0x10]; HOLDER *holder58; char pad2[0x208 - 0x5C]; int f208; };
struct XFOWNER { char pad[0x19A4]; int xf; };
struct XFPTR { char pad[0x60]; int dummy; };
struct GOAL { char pad0[0x10]; PLAYER *player; char pad1[0x50 - 0x14]; int state; float since; char pad2[0x5C - 0x58]; char *owner; char pad3[0x64 - 0x60]; OBJ1C *anchor; };
extern "C" {
void GoalAnimLeap_SetState(GOAL *, int);
void GoalAnim_Update();
QW PosLoWorld(void *);
void PredictXfTransform(int, int, float, void *, void *);
void func_0017ABC8(GOAL *, int);
extern float D_FLT_002BE6C8;
extern float D_FLT_002BE6CC;
extern float g_2dded0;
void GoalAnimLeap_Update(GOAL *self) {
    char sp[0xA0] __attribute__((aligned(16)));
    QW vel;
    GoalAnim_Update();
    vel = self->player->vt->fn10C((char *)self->player + self->player->vt->delta108, (char *)self->player);
    int old;
    do {
        old = self->state;
        switch (old) {
        case 0:
        case 1: {
            PLAYER *player = self->player;
            if (self->state != 1 || player->f208 == 0) {
                OBJ1C *obj = player->holder58->obj;
                if (obj != self->anchor || obj->value < g_2dded0) {
                    GoalAnimLeap_SetState(self, 2);
                } else {
                    float velz;
                    asm("pextuw %0, $zero, %1" : "=r" (velz) : "r" (vel));
                    if (velz < 0.0f && self->state == 0)
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
            if (self->player->f208 != 0) GoalAnimLeap_SetState(self, 3);
            break;
        case 4:
        case 5: {
            float *clock = &g_2dded0;
            *(QW *)(sp + 0x40) = PosLoWorld(self->player);
            *(QW *)(sp + 0x50) = self->player->vt->fn10C((char *)self->player + self->player->vt->delta108, (char *)self->player);
            PredictXfTransform(((XFOWNER *)self->owner)->xf, 0, clock[1], sp, 0);
            *(QW *)(sp + 0x60) = *(QW *)(sp + 0x30);
            *(float *)(sp + 0x68) += D_FLT_002BE6C8;
            int chain;
            asm volatile("lqc2 vf1, 0x60(%1)" : "=r" (chain) : "r" (sp));
            asm volatile("sqc2 vf1, 0x90(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
            QW world = PosLoWorld(self->player);
            asm volatile("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (world), "r" (chain));
            asm volatile("lqc2 vf1, 0x90(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
            asm volatile("vsub.xyzw vf1, vf1, vf2" : "=r" (chain) : "r" (chain));
            asm volatile("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (clock[1]), "r" (chain));
            asm volatile("vdiv Q, vf0w, vf2x" : "=r" (chain) : "r" (chain));
            asm volatile("vwaitq" : "=r" (chain) : "r" (chain));
            asm volatile("vmulq.xyzw vf1, vf1, Q" : "=r" (chain) : "r" (chain));
            asm volatile("sqc2 vf2, 0x80(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
            asm volatile("sqc2 vf1, 0x70(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
            if (self->state == 4) {
                if (*(float *)(sp + 0x48) < *(float *)(sp + 0x68) || D_FLT_002BE6CC < clock[0] - self->since) {
                    GoalAnimLeap_SetState(self, 5);
                    break;
                }
                *(float *)(sp + 0x78) = *(float *)(sp + 0x58);
            }
            PLAYER *player = self->player;
            VT *vt = player->vt;
            vt->fn11C((char *)player + vt->delta118, *(QW *)(sp + 0x70), (char *)player);
            break;
        }
        case 6:
            if (self->player->f208 != 0) GoalAnimLeap_SetState(self, -1);
            break;
        }
    } while (self->state != old);
}
}
