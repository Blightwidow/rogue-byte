struct CRef { int tagk; union { int n; float g; }; };
struct CFrame;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void CRef_SetS32(CRef *, int);
void CRef_SetF32(CRef *, float);
}
extern "C" CRef *RefOpAbs(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refAbs;
    refAbs.tagk = -1;
    if (aref[0].tagk == 0x15) {
        CRef_SetS32(&refAbs, aref[0].n < 0 ? -aref[0].n : aref[0].n);
    } else {
        float gAbs = aref[0].g;
        if (gAbs < 0.0f) {
            gAbs = -gAbs;
        }
        CRef_SetF32(&refAbs, gAbs);
    }
    CRef_CopyConstruct(pret, &refAbs);
    CRef_Destruct(&refAbs);
    return pret;
}
