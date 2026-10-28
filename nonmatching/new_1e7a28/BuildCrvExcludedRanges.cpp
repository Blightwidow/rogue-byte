/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CRV { char pad[0xE4]; int closed; };
struct PATHZONE;
struct CRVRANGES { CRV *pcrv; int cRange; void *pvRange; int cRange2; char ab[0x80]; int cpathzone; void *pvPathzone; int stamp; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" float g_2c367c;
extern "C" float SMinCrv(CRV *);
extern "C" float SMaxCrv(CRV *);
extern "C" void GetPathPosFromS(CRV *, void *, int, float);
extern "C" PATHZONE *PpathzoneFindPos(QW, int);
extern "C" int FPosInPathzone(PATHZONE *, QW, int);
void *PvAllocSwCopyImpl(int, void *);
void CopyAb(void *, void *, unsigned);
void BuildCrvExcludedRanges(CRVRANGES *pranges, CRV *pcrv)
{
    struct { float aRange[0x80]; PATHZONE *appathzone[0x40]; QW pos0; union { QW pos; ALLOCREQ request; } u; } l;
#define aRange l.aRange
#define appathzone l.appathzone
#define pos l.u.pos
#define request l.u.request
    float *pRange = 0;
    int cpathzone = 0;
    int cRange = 0;
    pranges->pcrv = pcrv;
    float sMin = SMinCrv(pcrv);
    float sSample = sMin;
    PATHZONE **papz = appathzone;
    float sPrevSample = sSample;
    float sMax = SMaxCrv(pranges->pcrv);
    GetPathPosFromS(pranges->pcrv, &l.pos0, 0, sMin);
    PATHZONE *ppathzonePrev = PpathzoneFindPos(l.pos0, 0);
    if (sMin < sMax) {
        do {
            GetPathPosFromS(pranges->pcrv, &pos, 0, sSample);
            PATHZONE *ppathzone = PpathzoneFindPos(pos, 0);
            if (ppathzone != 0) {
                int ipathzone;
                for (ipathzone = 0; ipathzone < cpathzone; ipathzone++)
                    if (appathzone[ipathzone] == ppathzone)
                        break;
                if (ipathzone >= cpathzone && cpathzone < 0x40)
                    papz[cpathzone++] = ppathzone;
            }
            int fOutside = 0;
            if (ppathzone == 0 || ppathzonePrev != ppathzone || FPosInPathzone(ppathzonePrev, pos, 0) == 0)
                fOutside = 1;
            if (fOutside) {
                if (pRange == 0 && cRange < 0x40) {
                    pRange = &aRange[cRange * 2];
                    cRange++;
                    pRange[0] = sPrevSample;
                }
            } else if (pRange != 0) {
                pRange[1] = sSample;
                pRange = 0;
            }
            sPrevSample = sSample;
            sSample += g_2c367c;
            ppathzonePrev = ppathzone;
        } while (sSample < sMax);
    }
    if (pRange != 0)
        pRange[1] = sMax;
    if (cRange > 1 && pranges->pcrv->closed != 0 && aRange[0] == sMin && aRange[(cRange - 1) * 2 + 1] == sMax) {
        aRange[0] = aRange[(cRange - 1) * 2] - sMax;
        aRange[(cRange - 1) * 2 + 1] = aRange[1] + sMax;
    }
    int cb = cRange << 3;
    request.cb = cb;
    pranges->cRange = cRange;
    request.cbAlign = 0x10;
    pranges->pvRange = PvAllocSwCopyImpl((int)&request, aRange);
    pranges->cRange2 = cRange;
    CopyAb(pranges->ab, aRange, cb);
    pranges->cpathzone = cpathzone;
    request.cb = cpathzone << 2;
    request.cbAlign = 0x10;
    pranges->pvPathzone = PvAllocSwCopyImpl((int)&request, appathzone);
    pranges->stamp = -1;
}
