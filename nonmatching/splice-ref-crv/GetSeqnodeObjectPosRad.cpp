#include "sly2.h"
#include "lo.h"
#include "vu0inline.h"

struct SEQNODE {
    u8 unknown_0x0[0x24];
    /* 0x24 */ LO *plo;
    u8 unknown_0x28[0x1C];
    /* 0x44 */ LO *ploFallback;
};
struct LOTARGET : LO {
    u8 unknown_0x50[0x158];
    /* 0x1A8 */ f32 rad;
    u8 unknown_0x1AC[0x94];
    /* 0x240 */ QW offset;
};

extern "C" QW PosLoWorld(void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" f32 atan2f(f32, f32);
extern "C" void FindCrvClosestPointAll(void *, QW, int, VECTOR *, VECTOR *, int, int);

void GetSeqnodeObjectPosRad(SEQNODE *pseqnode, LO *plo, QW *ppos, f32 *pradYaw)
{
    LO *ploSelf = pseqnode->plo;
    if (ploSelf == 0)
        ploSelf = pseqnode->ploFallback;
    union { QW qw; VECTOR vec; } pos;
    VECTOR tangent;
    f32 rad;
    if (plo != 0) {
        if (FIsBasicDerivedFrom(plo, 0xA) != 0) {
            FindCrvClosestPointAll(plo, PosLoWorld(ploSelf), 0, &pos.vec, &tangent, 0, 0);
            rad = atan2f(tangent.y, tangent.x);
        } else {
            pos.qw = PosLoWorld(plo);
            rad = atan2f(plo->PmatWorld()->mat[0][1], plo->PmatWorld()->mat[0][0]);
        }
    } else {
        pos.qw = PosLoWorld(ploSelf);
        if (FIsBasicDerivedFrom(ploSelf, 0x33) != 0) {
            LOTARGET *ploTarget = static_cast<LOTARGET *>(ploSelf);
            pos.qw = VectorAdd(pos.qw, ploTarget->offset);
            rad = ploTarget->rad;
        } else {
            rad = atan2f(ploSelf->PmatWorld()->mat[0][1], ploSelf->PmatWorld()->mat[0][0]);
        }
    }
    if (ppos != 0)
        *ppos = pos.qw;
    if (pradYaw != 0)
        *pradYaw = rad;
}
