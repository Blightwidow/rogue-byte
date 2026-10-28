// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SW;
struct CRef { int tagk; QW *pv; CRef &operator=(const CRef &); };
struct CFrame;
extern SW B_003DD490;
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void bevy_camera_follow_push_out(SW *, QW, QW, int, int, int *, int *);
void ExtractUniqueSosFromGeoms(int, int, int *, int *);
void RefFromAplo(CRef *, int, int);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpFindObjectsInBoundingBox(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    char frame[0x10];
    CRef refList;
    int cgeom;
    int ageom;
    int cplo;
    int aplo;
    refResult.tagk = -1;
    CStackFrame_Construct(frame);
    bevy_camera_follow_push_out(&B_003DD490, *aref[0].pv, *aref[1].pv, 0, 0, &cgeom, &ageom);
    ExtractUniqueSosFromGeoms(cgeom, ageom, &cplo, &aplo);
    RefFromAplo(&refList, cplo, aplo);
    refResult = refList;
    CRef_Destruct(&refList);
    CRef_CopyConstruct(pret, &refResult);
    CStackFrame_Destructor(frame, 2);
    CRef_Destruct(&refResult);
    return pret;
}
