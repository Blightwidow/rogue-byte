#include "sly2.h"
struct Target_1C1F28 { void *path; void *alo; char pad8[8]; QW fixed; };
extern "C" float SMaxCrv(void *);
extern "C" void GetPathPosFromS(void *, QW *, int, float);
extern "C" QW PosLoWorld(void *);
extern "C" QW func_001C1F28(Target_1C1F28 *target)
{
    QW pos;
    if (target->path) {
        GetPathPosFromS(target->path, &pos, 0, SMaxCrv(target->path) * 0.5f);
    } else if (target->alo) {
        pos = PosLoWorld(target->alo);
    } else {
        pos = target->fixed;
    }
    return pos;
}
