// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; union { int n; float *pg; float g; }; CRef &operator=(const CRef &); };
struct CFrame;
struct SW;
extern SW B_003DD490;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
int CploFindSwObjectsByClass(SW *, int, int, int, int, int *);
void RefFromAplo(CRef *, int, int *);
}
extern "C" CRef *RefOpFindClassObjects(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    refResult.tagk = -1;
    int grffso = (aref[1].n != 0) ? 0x401 : 0x405;
    int aplo[0x180];
    int cplo = CploFindSwObjectsByClass(&B_003DD490, grffso, aref[0].n, aref[1].n, 0x180, aplo);
    CRef refList;
    RefFromAplo(&refList, cplo, aplo);
    refResult = refList;
    CRef_Destruct(&refList);
    CRef_CopyConstruct(pret, &refResult);
    CRef_Destruct(&refResult);
    return pret;
}
