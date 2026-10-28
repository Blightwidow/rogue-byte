#include "sly2.h"
struct CLQ { float a, b, c; };
struct ASEG { char pad[0x74]; float tMax; float speed; char pad1[0x80 - 0x7C]; CLQ poly; char pad2[0x90 - 0x8C]; float svtMin; float svtMax; };
struct ASEGA { char pad[0x14]; ASEG *paseg; char pad1[4]; float tLocal; char pad2[0x40 - 0x20]; float svt; };
struct SMT { ASEG *paseg; int ismsFrom; int ismsTo; int grfsmt; };
struct SMA { char pad[0x24]; void *psm; char pad1[0x30 - 0x28]; ASEGA *pasega; int ismsCur; char pad2[0x40 - 0x38]; SMT *psmtCur; char pad3[4]; int grfsmtMask; };
extern "C" {
extern char B_002DE578;
int FSmaRetracted(SMA *);
int IsmsFindSmRequired__FP2SM3OID(void *, int);
float GetSuck(void *);
SMT *PsmtChooseSmTowards(void *, int, int, int, int);
float DtSmaReachState(SMA *psma, int oid)
{
    float dt = 0.0f;
    if (FSmaRetracted(psma)) return dt;
    int target = IsmsFindSmRequired__FP2SM3OID(psma->psm, oid);
    int isms;
    ASEGA *pasega = psma->pasega;
    if (pasega == 0) {
        isms = psma->ismsCur;
    } else {
        SMT *psmtCur = psma->psmtCur;
        SMT *psmtFrom = psmtCur;
        if ((psmtCur->grfsmt & 2) == 0) {
            float svt = pasega->svt;
            float numerator;
            if (svt < dt) {
                numerator = -pasega->tLocal;
            } else {
                if (dt < svt) numerator = pasega->paseg->tMax - pasega->tLocal;
                else return dt;
            }
            dt = numerator / svt;
        }
        isms = psmtFrom->ismsFrom;
        if (isms == psma->ismsCur) isms = psmtFrom->ismsTo;
    }
    while (isms != target) {
        SMT *psmt = PsmtChooseSmTowards(psma->psm, psma->grfsmtMask, isms, target, 1);
        if (psmt == 0) break;
        if (psmt->paseg != 0) {
            float suck = GetSuck(&B_002DE578);
            ASEG *paseg = psmt->paseg;
            float svtMin = paseg->svtMin;
            CLQ *poly = &paseg->poly;
            float scale = paseg->poly.a + suck * (poly->b + suck * poly->c);
            float svtMax = paseg->svtMax;
            if (scale < svtMin) scale = svtMin;
            else if (svtMax < scale) scale = svtMax;
            dt += psmt->paseg->tMax / (psmt->paseg->speed * scale);
        }
        int from = psmt->ismsFrom;
        if (from == isms) from = psmt->ismsTo;
        isms = from;
    }
    return dt;
}
}
