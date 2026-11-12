#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct FCVT { char pad[0x78]; short delta; short unused; void (*setState)(void *, int); };
struct FCVPLO { char pad[0xDC]; char *crvdata; };
struct FCVPLAYER { char pad[0xE8]; FCVPLO *plo; };
struct FCVCRV { char pad0[0x28]; unsigned long flags; char pad1[0x1D8 - 0x30]; int busy; };
struct GOALFOLLOWCRV {
    char pad0[0xC]; FCVT *vt; FCVPLAYER *player; char pad1[0x30 - 0x14]; int owner; float ownerS; int mode38; char pad2[0x40 - 0x3C]; int fixed;
    char pad3[0x4C - 0x44]; unsigned state; char pad4[0x54 - 0x50]; FCVCRV *crv; unsigned result; float hint; float diff;
    char pad5[0x68 - 0x64]; float nearDist; float farDist; char pad6[0x80 - 0x70]; QW goalPos;
};
extern "C" {
void FindCrvClosestPointAll(FCVCRV *, QW, void *, int, int, int, float *);
void GoalFollowCrv_Steer(GOALFOLLOWCRV *);
QW PosLoWorld(void *);
float SDiffCrv(FCVCRV *, float, float);
unsigned func_001BD718(QW, int, void *, int, float, int, void *, void *);
void func_001EEF98();
extern char B_003DD020[];
void GoalFollowCrv_Update(GOALFOLLOWCRV *self) {
    float closest;
    QW pos;
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
                FCVPLO *plo = self->player->plo;
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
                    FindCrvClosestPointAll(self->crv, pos, B_003DD020, 0, 0, 0, &closest);
                    if (__builtin_fabsf(SDiffCrv(self->crv, closest, self->diff)) > 80.0f) {
                        self->hint = closest;
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
                float dist = LaneX(SqrtX(SquaredLengthXy(VectorSub(pos, self->goalPos))));
                int farther = limit < dist;
                if (farther != 0)
                    self->vt->setState((char *)self + self->vt->delta, 0);
                else
                    self->vt->setState((char *)self + self->vt->delta, 2);
            }
            break;
        }
        case 1:
        case 4: {
            FCVCRV *crv = self->crv;
            if (((int)(crv->flags >> 60) & 1) == 0 || crv->busy != 0) {
                self->vt->setState((char *)self + self->vt->delta, 0);
            } else {
                if (__builtin_fabsf(SDiffCrv(crv, self->hint, self->diff)) < 80.0f) {
                    self->vt->setState((char *)self + self->vt->delta, 0);
                } else {
                    float limit;
                    if (self->state == 1)
                        limit = self->nearDist;
                    else
                        limit = self->farDist;
                    float dist = LaneX(SqrtX(SquaredLengthXy(VectorSub(pos, self->goalPos))));
                    int farther = limit < dist;
                    if (farther != 0)
                        self->vt->setState((char *)self + self->vt->delta, 1);
                    else
                        self->vt->setState((char *)self + self->vt->delta, 4);
                }
            }
            break;
        }
        }
    } while (self->state != old);
}
}
