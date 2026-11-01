#include "sly2.h"
struct Xf_14C6D8 { char pad[0x70]; QW pos; };
struct So_14C6D8 { Xf_14C6D8 *pxf; int pad4; float sRadius; int padc; unsigned long grf; };
extern "C" int ClsgClipEdgeToBsp(void *, int, QW, QW, int, int);
extern "C" int ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(QW, float, QW, QW, int, int);
extern "C" int ClsgClipEdgeToObjectPruned(So_14C6D8 *pso, void *pbsp, QW posA, QW posB, int clsgMax, int alsg)
{
    if (pbsp != 0)
        return ClsgClipEdgeToBsp(pbsp, 0x7FFFFFFF, posA, posB, clsgMax, alsg);
    if (pso->grf & (0x8000UL << 34))
        return ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(pso->pxf->pos, pso->sRadius, posA, posB, clsgMax, alsg);
    return 0;
}
