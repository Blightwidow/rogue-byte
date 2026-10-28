#include "sly2.h"
struct Mat { QW row0; QW row1; QW row2; QW row3; };
extern "C" Mat *PmatLoWorld(void *);
extern "C" void InvertMatrix3(void *, Mat *);
QW bevy_camera_follow_track_heading_weight(void *from, void *to, QW vec)
{
    if (from != 0) {
        Mat *pmat = PmatLoWorld(from);
        asm("lqc2 vf3, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %0\n\tvmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf4, vf3, vf4z\n\tsqc2 vf4, %0"
            : "+m" (vec) : "m" (pmat->row2), "m" (pmat->row0), "m" (pmat->row1));
    }
    if (to != 0) {
        struct { QW row0; QW row1; QW row2; } inv;
        InvertMatrix3(&inv, PmatLoWorld(to));
        asm("lqc2 vf4, %0\n\tlqc2 vf3, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z\n\tsqc2 vf4, %0"
            : "+m" (vec) : "m" (inv.row0), "m" (inv.row1), "m" (inv.row2));
    }
    return vec;
}
