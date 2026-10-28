#include "sly2.h"
struct SMA;
struct MURRAY { char pad[0x1034]; SMA *psmaOwn; };
struct MURRAYB { char pad[0x1530]; SMA *psmaPartner; int iMashLevel; };
extern "C" void SetMurrayState(MURRAY *, int);
extern "C" void SnapSmaToGoal(SMA *, int);
void SetSmaGoal(SMA *, int);
extern "C" void SetSmaGoal__FP3SMA3OID(SMA *, int);

struct M { char pad0[0x1034]; SMA *own; char pad1[0x1530-0x1038]; SMA *partner; int level; };

void StartMurrayMash(M *murray, SMA *partner, int oid, int level, int snap)
{
    murray->partner = partner;
    murray->level = level;
    SetMurrayState((MURRAY *)murray, 6);
    if (oid != -1) {
        if (murray->partner) {
            if (snap) SnapSmaToGoal(murray->partner, oid);
            else SetSmaGoal__FP3SMA3OID(murray->partner, oid);
        }
        if (snap) SnapSmaToGoal(murray->own, oid);
        else SetSmaGoal__FP3SMA3OID(murray->own, oid);
    }
}
