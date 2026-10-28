struct EYES;
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" EYES *PsaaFromOid(int);
extern "C" void SetAloEyesClosed(void *, float);
extern "C" void SetEyesClosed__FP4EYESf(EYES *, float);
void SetEyesClosedByOid(void *sw, int oidAlo, int oidEyes, void *ctx, float u)
{
    void *alo = 0;
    EYES *eyes = 0;
    if (oidAlo != -1) {
        void *lo = PloFindSwObject_thunk(sw, 4, oidAlo, ctx);
        if (lo && FIsBasicDerivedFrom(lo, 0x30)) alo = lo;
    }
    if (oidEyes != -1) {
        eyes = PsaaFromOid(oidEyes);
        if (eyes && !FIsBasicDerivedFrom(eyes, 0x8E)) eyes = 0;
    }
    if (alo) SetAloEyesClosed(alo, u);
    if (eyes) SetEyesClosed__FP4EYESf(eyes, u);
}
