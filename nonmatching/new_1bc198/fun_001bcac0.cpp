#include "sly2.h"
#include "vu0inline.h"
struct M4 { QW row[4]; };
struct Obstacle;
struct VT { char pad[0xF8]; short delta; short index; M4 *(*fn)(void *); };
struct Obstacle { char pad0[0xC]; VT *vtable; char pad1[0xF4 - 0x10]; QW *apos; };
extern "C" {
int IcvFindCrvS(Obstacle *, float, int, int);
int Obstacle_IposWrap(Obstacle *, int);
void GetPathPosFromS(Obstacle *, float, QW *, int);
int FClipEdgeToPathzone(void *, QW, QW, int);
}
struct Locals {
    M4 mat;
    QW posPrev;
    QW posEnd;
    int icvFrom;
    int result;
    QW pos;
    QW *pposPrev;
};
int func_001BCAC0(float sFrom, float sTo, Obstacle *obstacle, void *pathzone, int forward)
{
    Locals l;
    l.icvFrom = IcvFindCrvS(obstacle, sFrom, 0, 0);
    int icvTo = IcvFindCrvS(obstacle, sTo, 0, 0);
    int attempt = 0;
    l.pposPrev = &l.posPrev;
    do {
        int grf;
        switch (attempt) {
        case 0: l.result = 0; grf = 0; break;
        case 1: l.result = 1; grf = 1; break;
        }
        int icvStart, icvEnd;
        if (forward) {
            icvStart = Obstacle_IposWrap(obstacle, l.icvFrom + 1);
            icvEnd = Obstacle_IposWrap(obstacle, icvTo + 1);
        } else {
            icvStart = l.icvFrom;
            icvEnd = icvTo;
        }
        VT *vt = obstacle->vtable;
        l.mat = *vt->fn((char *)obstacle + vt->delta);
        GetPathPosFromS(obstacle, sFrom, l.pposPrev, 0);
        QW cur = l.posPrev;
        int icvCur = icvStart;
        while (icvCur != icvEnd) {
            l.pos = TransformPoint(obstacle->apos[icvCur], l.mat.row[0], l.mat.row[1], l.mat.row[2], l.mat.row[3]);
            if (FClipEdgeToPathzone(pathzone, cur, l.pos, grf))
                goto next;
            if (forward)
                icvCur = Obstacle_IposWrap(obstacle, icvCur + 1);
            else
                icvCur = Obstacle_IposWrap(obstacle, icvCur - 1);
            cur = l.pos;
        }
        GetPathPosFromS(obstacle, sTo, &l.posEnd, 0);
        if (!FClipEdgeToPathzone(pathzone, cur, l.posEnd, grf))
            return l.result;
    next:
        attempt++;
    } while (attempt < 2);
    return 2;
}
