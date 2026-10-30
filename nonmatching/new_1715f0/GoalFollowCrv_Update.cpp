#include "sly2.h"
struct VT { char pad[0x78]; short delta; short unused; void (*setState)(void *, int); };
struct PLO { char pad[0xDC]; char *crvdata; };
struct PLAYER { char pad[0xE8]; PLO *plo; };
struct CRV { char pad0[0x28]; unsigned long flags; char pad1[0x1D8 - 0x30]; int busy; };
struct GOAL {
    char pad0[0xC]; VT *vt; PLAYER *player; char pad1[0x30 - 0x14]; int owner; float ownerS; int mode38; char pad2[0x40 - 0x3C]; int fixed;
    char pad3[0x4C - 0x44]; unsigned state; char pad4[0x54 - 0x50]; CRV *crv; unsigned result; float hint; float diff;
    char pad5[0x68 - 0x64]; float nearDist; float farDist; char pad6[0x80 - 0x70]; QW goalPos;
};
extern "C" {
void FindCrvClosestPointAll(CRV *, QW, void *, int, int, int, float *);
void GoalFollowCrv_Steer(GOAL *);
QW PosLoWorld(void *);
float SDiffCrv(CRV *, float, float);
unsigned func_001BD718(QW, int, void *, int, float, int, void *, void *);
void func_001EEF98();
extern char B_003DD020[];
void GoalFollowCrv_Update(GOAL *self) {
    char sp[0x20] __attribute__((aligned(16)));
#define pos (*(QW *)(sp + 0x10))
#define closest ((float *)sp)
    func_001EEF98();
    GoalFollowCrv_Steer(self);
    pos = PosLoWorld(self->player);
    unsigned old;
    do {
        old = self->state;
        switch (old) {
        case 0:
        case 2:
        case 3: {
            if (self->fixed == 0) {
                PLO *plo = self->player->plo;
                char *crvdata = 0;
                if (plo != 0) crvdata = plo->crvdata;
                int id = 0;
                if (crvdata != 0) id = ((int *)crvdata)[4];
                unsigned result = func_001BD718(pos, id, plo->crvdata + 0x20, self->owner, self->ownerS, self->mode38 == 0, &self->crv, &self->diff);
                self->result = result;
                switch (result) {
                case 0:
                    break;
                case 3:
                case 4:
                    self->vt->setState((char *)self + self->vt->delta, 3);
                    break;
                case 1:
                case 2:
                    FindCrvClosestPointAll(self->crv, pos, B_003DD020, 0, 0, 0, closest);
                    if (__builtin_fabsf(SDiffCrv(self->crv, closest[0], self->diff)) > 80.0f) {
                        self->hint = closest[0];
                        self->vt->setState((char *)self + self->vt->delta, 1);
                        break;
                    }
                    self->result = 0;
                    break;
                }
            }
            if (self->result == 0) {
                float limit;
                if (self->state == 0)
                    limit = self->nearDist;
                else
                    limit = self->farDist;
                QW dummy;
                int chain;
                asm volatile("lqc2 vf1, 0x80(%1)" : "=r" (chain) : "r" (self));
                asm volatile("lqc2 vf2, 0x10(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
                asm volatile("vsub.xyzw vf1, vf2, vf1" : "=r" (chain) : "r" (chain));
                asm volatile("vmul.xy vf1, vf1, vf1" : "=r" (chain) : "r" (chain));
                asm volatile("vaddy.x vf1, vf1, vf1y" : "=r" (chain) : "r" (chain));
                asm volatile("vsqrt Q, vf1x" : "=r" (chain) : "r" (chain));
                asm volatile("vwaitq" : "=r" (chain) : "r" (chain));
                asm volatile("vaddq.x vf1, vf0, Q" : "=r" (chain) : "r" (chain));
                float dist;
                asm volatile("qmfc2.ni %0, vf1" : "=r" (dist) : "r" (chain));
                int farther = 0;
                if (limit < dist) farther = 1;
                int next = farther != 0 ? 0 : 2;
                self->vt->setState((char *)self + self->vt->delta, next);
            }
            break;
        }
        case 1:
        case 4: {
            CRV *crv = self->crv;
            if (((crv->flags >> 60) & 1) != 0 && crv->busy == 0) {
                if (__builtin_fabsf(SDiffCrv(crv, self->hint, self->diff)) < 80.0f) {
                    self->vt->setState((char *)self + self->vt->delta, 0);
                } else {
                    float limit;
                    if (self->state != 1)
                        limit = self->farDist;
                    else
                        limit = self->nearDist;
                    int chain;
                    asm volatile("lqc2 vf1, 0x80(%1)" : "=r" (chain) : "r" (self));
                    asm volatile("lqc2 vf2, 0x10(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
                    asm volatile("vsub.xyzw vf1, vf2, vf1" : "=r" (chain) : "r" (chain));
                    asm volatile("vmul.xy vf1, vf1, vf1" : "=r" (chain) : "r" (chain));
                    asm volatile("vaddy.x vf1, vf1, vf1y" : "=r" (chain) : "r" (chain));
                    asm volatile("vsqrt Q, vf1x" : "=r" (chain) : "r" (chain));
                    asm volatile("vwaitq" : "=r" (chain) : "r" (chain));
                    asm volatile("vaddq.x vf1, vf0, Q" : "=r" (chain) : "r" (chain));
                    float dist;
                    asm volatile("qmfc2.ni %0, vf1" : "=r" (dist) : "r" (chain));
                    int farther = 0;
                    if (limit < dist) farther = 1;
                    if (farther != 0)
                        self->vt->setState((char *)self + self->vt->delta, 1);
                    else
                        self->vt->setState((char *)self + self->vt->delta, 4);
                }
            } else {
                self->vt->setState((char *)self + self->vt->delta, 0);
            }
            break;
        }
        }
    } while (self->state != old);
}
}
