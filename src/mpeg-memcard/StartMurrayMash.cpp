#include "sly2.h"
struct SMA;
#include "murray.h"
extern "C" void SetMurrayState(MURRAY *, int);
extern "C" void SnapSmaToGoal(SMA *, int);
void SetSmaGoal(SMA *, int);
extern "C" void SetSmaGoal__FP3SMA3OID(SMA *, int);


void StartMurrayMash(MURRAY *murray, SMA *partner, int oid, int level, int snap)
{
    murray->psmaPartner = partner;
    murray->iMashLevel = level;
    SetMurrayState(murray, 6);
    if (oid != -1) {
        if (murray->psmaPartner) {
            if (snap) SnapSmaToGoal(murray->psmaPartner, oid);
            else SetSmaGoal__FP3SMA3OID(murray->psmaPartner, oid);
        }
        if (snap) SnapSmaToGoal((SMA *)murray->field_0x1034, oid);
        else SetSmaGoal__FP3SMA3OID((SMA *)murray->field_0x1034, oid);
    }
}
