struct CRef { int tagk; union { int n; float g; }; };
struct CFrame;
extern "C" {
void CRef_RefCoerceF32(CRef *, CRef *);
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_SetS32(CRef *, int);
void CRef_SetF32(CRef *, float);
int NRandInRange(int, int);
float GRandInRange(float, float);
}
extern "C" CRef *RefOpRandom(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refRandom;
    refRandom.tagk = -1;
    if (aref[0].tagk == 0x15 && aref[1].tagk == 0x15) {
        CRef_SetS32(&refRandom, NRandInRange(aref[0].n, aref[1].n));
    } else {
        CRef refTemp;
        CRef_RefCoerceF32(&refTemp, &aref[0]);
        float gMin = refTemp.g;
        CRef_Destruct(&refTemp);
        CRef_RefCoerceF32(&refTemp, &aref[1]);
        float gMax = refTemp.g;
        CRef_Destruct(&refTemp);
        CRef_SetF32(&refRandom, GRandInRange(gMin, gMax));
    }
    CRef_CopyConstruct(pret, &refRandom);
    CRef_Destruct(&refRandom);
    return pret;
}
