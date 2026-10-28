#include "sly2.h"
struct SM; struct ALO; struct SMA;
extern "C" {
void *PloFindSwObject_thunk(void *, int, int, void *);
SMA *PsmaFindSm__FP2SMP3ALO(SM *, ALO *);
void RetractSma(SMA *);
int func_001FD0C0(void *, unsigned);
extern char B_003DD040[];
extern char B_003DD490[];
}
extern "C" void ReleaseAloSmKinds(ALO *palo, unsigned grf)
{
    int *pcount = (int *)((char *)palo + 0x2A0);
    unsigned kind = 0;
    do {
        int m = 1 << kind;
        if (kind >= 6U)
            m = 0;
        if (grf & m) {
            int count = *pcount;
            if (count != 0) {
                count = count - 1;
                *pcount = count;
                if (count <= 0) {
                    void *psw = B_003DD490;
                    int oid = func_001FD0C0(B_003DD040, kind);
                    SM *psm = (SM *)PloFindSwObject_thunk(psw, 4, oid, palo);
                    if (psm != 0) {
                        SMA *psma = PsmaFindSm__FP2SMP3ALO(psm, palo);
                        if (psma != 0)
                            RetractSma(psma);
                    }
                }
            }
        }
        kind++;
        pcount++;
    } while ((int)kind < 6);
}
