struct CRef { int tagk; union { int n; float g; void *pv; }; };
struct CFrame;
struct CLQ;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_RefCoerceF32(CRef *, CRef *);
}
void FitClq__FffffP3CLQ(float, float, float, float, CLQ *);
struct Slot { CRef ref; int pad[2]; };
extern "C" CRef *RefOpClqFit(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    struct Frame { Slot clq; Slot g[4]; } f;
    SetTag__4CRef4TAGK(&f.clq.ref, 0x1C);
    CRef_RefCoerceF32(&f.g[0].ref, &aref[0]);
    float g0 = f.g[0].ref.g;
    CRef_RefCoerceF32(&f.g[1].ref, &aref[1]);
    float g1 = f.g[1].ref.g;
    CRef_RefCoerceF32(&f.g[2].ref, &aref[2]);
    float g2 = f.g[2].ref.g;
    CRef_RefCoerceF32(&f.g[3].ref, &aref[3]);
    FitClq__FffffP3CLQ(g0, g1, g2, f.g[3].ref.g, (CLQ *)f.clq.ref.pv);
    CRef_Destruct(&f.g[3].ref);
    CRef_Destruct(&f.g[2].ref);
    CRef_Destruct(&f.g[1].ref);
    CRef_Destruct(&f.g[0].ref);
    CRef_CopyConstruct(pret, &f.clq.ref);
    CRef_Destruct(&f.clq.ref);
    return pret;
}
