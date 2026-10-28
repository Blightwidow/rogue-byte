typedef int QW __attribute__((mode(TI)));
struct MQ { int plo; char pad0[0x10 - 4]; QW pos; char pad1[0x4C - 0x20]; int pgeom; char pad2[0xA0 - 0x50]; float s; char pad3[0xAC - 0xA4]; MQ *next; };
struct WKR { int ploSource; int ppartSource; int ploTarget; int grftak; int nDamage; char pad[0xC]; QW pos; char pad2[0x30]; };
struct BEAM { char pad[0x140]; float sFull; float sClipped; MQ *pmqFirst; char pad2[0x150 - 0x14C]; };
struct LASER { char pad[0x198]; int cbeam; BEAM *abeam; };
extern "C" {
void GetLaserBeamPoints(LASER *, BEAM *, QW *, float *);
void PaloAbsorbWkr(WKR *);
void *memset(void *, int, unsigned);
}

void ClipLaserBeams(LASER *plaser)
{
    for (int ibeam = 0; ibeam < plaser->cbeam; ibeam++) {
        BEAM *pbeam = &plaser->abeam[ibeam];
        QW apos[2];
        float sLength;
        GetLaserBeamPoints(plaser, pbeam, apos, &sLength);
        if (pbeam->pmqFirst == 0) {
            float sFull = sLength;
            pbeam->sClipped = sFull;
            pbeam->sFull = sFull;
        } else {
            MQ *pmqNearest = 0;
            float sNearest = sLength;
            for (MQ *pmq = pbeam->pmqFirst; pmq != 0; pmq = pmq->next) {
                if (pmq->s < sNearest) {
                    sNearest = pmq->s;
                    pmqNearest = pmq;
                }
            }
            WKR wkr;
            memset(&wkr, 0, 0x60);
            wkr.ploSource = (int)plaser;
            wkr.ppartSource = pmqNearest->plo;
            wkr.ploTarget = pmqNearest->pgeom;
            wkr.grftak = 0x1000;
            wkr.nDamage = -10;
            wkr.pos = pmqNearest->pos;
            PaloAbsorbWkr(&wkr);
            pbeam->sClipped = sNearest;
        }
    }
}
