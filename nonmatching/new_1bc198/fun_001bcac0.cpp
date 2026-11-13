// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "lo.h"
#include "vu0inline.h"

struct CRV;
struct Obstacle : LO {
    u8 unknown_0x50[0xF4 - 0x50];
    /* 0xF4 */ QW *apos;
};
extern "C" {
int IcvFindCrvS(CRV *pcrv, float s, float *pds, float *pdsSeg);
int Obstacle_IposWrap(void *p, int ipos);
void GetPathPosFromS(CRV *, float, void *, int);
int FClipEdgeToPathzone(void *ppathzone, QW posFrom, QW posTo, int grf);
}

// The obstacle's outline (apos, through its world matrix) and the path from sFrom to sTo must stay inside the
// pathzone: tried first with grf 0, then with grf 1. Returns the attempt that fits, or 2. icvFrom, the result, the
// transformed point and the address of posPrev live in reload's spill slots (0x60, 0x64, 0x70, 0x80), not in locals.
// GetPathPosFromS takes s before the position, as in the matched func_001BD560 and func_001BD718: with s last, as
// FFindCrvSInPathzone declares it, the argument moves of the first call come out in another order.
int func_001BCAC0(float sFrom, float sTo, Obstacle *obstacle, void *pathzone, int forward)
{
    MATRIX4 mat;
    QW posPrev;
    QW posEnd;
    int icvFrom = IcvFindCrvS((CRV *)obstacle, sFrom, 0, 0);
    int icvTo = IcvFindCrvS((CRV *)obstacle, sTo, 0, 0);
    int attempt = 0;
    do {
        int result;
        int grf;
        switch (attempt) {
        case 0:
            result = 0;
            grf = 0;
            break;
        case 1:
            result = 1;
            grf = 1;
            break;
        }
        int icvStart;
        int icvEnd;
        if (forward) {
            icvStart = Obstacle_IposWrap(obstacle, icvFrom + 1);
            icvEnd = Obstacle_IposWrap(obstacle, icvTo + 1);
        } else {
            icvStart = icvFrom;
            icvEnd = icvTo;
        }
        mat = *obstacle->PmatWorld();
        GetPathPosFromS((CRV *)obstacle, sFrom, &posPrev, 0);
        QW cur = posPrev;
        int icvCur = icvStart;
        while (icvCur != icvEnd) {
            QW pos = TransformPoint(obstacle->apos[icvCur], mat.row[0], mat.row[1], mat.row[2], mat.row[3]);
            if (FClipEdgeToPathzone(pathzone, cur, pos, grf))
                goto next;
            if (forward)
                icvCur = Obstacle_IposWrap(obstacle, icvCur + 1);
            else
                icvCur = Obstacle_IposWrap(obstacle, icvCur - 1);
            cur = pos;
        }
        GetPathPosFromS((CRV *)obstacle, sTo, &posEnd, 0);
        if (!FClipEdgeToPathzone(pathzone, cur, posEnd, grf))
            return result;
    next:
        attempt++;
    } while (attempt < 2);
    return 2;
}
