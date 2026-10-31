struct SM; struct ALO; struct SMA;
extern "C" {
void *PloFindSwObject_thunk(void *, int, int, void *);
SMA *PsmaFindSm__FP2SMP3ALO(SM *, ALO *);
void RetractSma(SMA *);
int func_001FD0C0(void *, unsigned);
extern char B_003DD040[];
extern char B_003DD490[];
}
static inline int GrfOfKind(int kind) { int m = 1 << kind; if ((unsigned)kind >= 6U) m = 0; return m; }
extern "C" int ReleaseAloSmKinds(ALO *palo, unsigned grf)
{
    int *pcount = (int *)((char *)palo + 0x2A0);
    for (int kind = 0; kind < 6; kind++, pcount++) {
        if (grf & GrfOfKind(kind)) {
            if (*pcount != 0) {
                int count = *pcount - 1;
                *pcount = count;
                if (count <= 0) {
                    int oid = func_001FD0C0(B_003DD040, kind);
                    SM *psm = (SM *)PloFindSwObject_thunk(B_003DD490, 4, oid, palo);
                    if (psm != 0) {
                        SMA *psma = PsmaFindSm__FP2SMP3ALO(psm, palo);
                        if (psma != 0)
                            RetractSma(psma);
                    }
                }
            }
        }
    }
    return 0;
}