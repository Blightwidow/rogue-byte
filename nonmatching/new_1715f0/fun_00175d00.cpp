#include "sly2.h"
struct VT { char pad[0x268]; short delta; short unused; int (*fn)(char *, char *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct HIT { char pad[4]; char *obj; };
struct PLAYER { char pad0[0xF00]; int f00; char pad1[0xFE8 - 0xF04]; int flags; };
struct TARGET { char pad0[0xC]; VT *vt; };
struct GUARD { char pad0[0x10]; char *player; char pad1[0x30 - 0x14]; TARGET *target; int mode; float since; int blocked; };
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void CalculateVectorPanTilt__FP6VECTORPfT1(QW, void *, float *);
void DecomposeSphere(QW, float *, float *, float *);
int FCheckLm__FP2LMf(void *, float);
int FIsBasicDerivedFrom(void *, int);
QW *PmatLoWorld(char *);
QW PosLoWorld(void *);
void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, void *);
float RadNormalize__Ff(float);
float RadYawSo(char *);
void bevy_camera_follow_push_out(void *, QW, QW, void *, int, int *, int *);
extern char B_003DD490[];
void FFilterOxaBasic();
extern float g_2dded0;
int func_00175D00(GUARD *self) {
    char sp[0xC0] __attribute__((aligned(16)));
#define sp70 (*(float *)(sp + 0x70))
#define sp74 (*(float *)(sp + 0x74))
#define sp78 (*(float *)(sp + 0x78))
#define sp7C (*(float *)(sp + 0x7C))
#define sp80 (*(int *)(sp + 0x80))
#define sp90 (*(QW *)(sp + 0x90))
#define spA0 (*(QW *)(sp + 0xA0))
#define spB0 (*(QW *)(sp + 0xB0))
    PLAYER *player = (PLAYER *)self->player;
    if ((player->flags & 8) == 0) return 0;
    if (player->f00 != 0) return 0;
    if (self->blocked != 0) return 0;
    TARGET *target = self->target;
    if (target == 0) return 0;
    if (((*(unsigned long *)((char *)target + 0x28) >> 60) & 1) == 0) return 0;
    if (FIsBasicDerivedFrom(target, 0x32) != 0) {
        VT *vt = self->target->vt;
        if (vt->fn((char *)self->target + vt->delta, (char *)self->target) == 2) return 0;
    }
    int near = 0;
    if (FIsBasicDerivedFrom(self->target, 0x34) != 0) {
        char *other = (char *)self->target;
        if (*(int *)(other + 0x4CC) != -1) {
            int level = *(int *)(other + 0x4C8);
            if (level < 5) near = level >= 3;
        }
        int anim = *(int *)(other + 0x2DC);
        if (anim != -1) near = (anim ^ 0x11) == 0 ? 1 : near;
        near = ~*(int *)(other + 0xF54) != 0 ? 1 : near;
        if (FIsBasicDerivedFrom(other, 0x35) != 0) {
            int state = *(int *)(other + 0x18C8);
            if (state == 3 || (state >= 3 && state < 0x17 && state >= 0x15)) near = 1;
        }
    }
    sp90 = PosLoWorld(self->player);
    QW targetPos = PosLoWorld(self->target);
    spA0 = targetPos;
    int chain;
    asm volatile("qmtc2.ni %1, vf1" : "=r" (chain) : "r" (targetPos));
    asm volatile("lqc2 vf2, 0x90(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
    asm volatile("vsub.xyzw vf1, vf1, vf2" : "=r" (chain) : "r" (chain));
    asm volatile("sqc2 vf1, 0xb0(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
    float yaw = RadYawSo(self->player);
    DecomposeSphere(spB0, &sp70, &sp74, &sp78);
    if (FCheckLm__FP2LMf(self->player + 0xF48, sp78) == 0) return 0;
    float panDelta = RadNormalize__Ff(sp70 - yaw);
    if (FCheckLm__FP2LMf(self->player + 0xF50, panDelta) == 0) return 0;
    CalculateVectorPanTilt__FP6VECTORPfT1(*PmatLoWorld(self->player), 0, &sp7C);
    float tiltDelta = RadNormalize__Ff(sp74 - sp7C);
    if (FCheckLm__FP2LMf(self->player + 0xF58, tiltDelta) == 0) return 0;
    if (near == 0) {
        int mode = self->mode;
        if (mode == 0) {
            if (g_2dded0 - self->since < 3.0f) return 0;
        } else if (mode != 2) {
            return 0;
        }
    }
    CStackFrame_Construct(sp);
    bevy_camera_follow_push_out(B_003DD490, sp90, spA0, (void *)FFilterOxaBasic, 0, 0, 0);
    HIT *hit = (HIT *)PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spA0, sp80, 0, 0);
    int result;
    if (hit != 0 && **(TARGET ***)(hit->obj + 0x14) != self->target) {
        CStackFrame_Destructor(sp, 2);
        result = 0;
    } else {
        CStackFrame_Destructor(sp, 2);
        result = 1;
    }
    return result;
}
}
