struct UL { unsigned long v; } __attribute__((packed));
struct SIDE { char pad0[8]; void *pso; char pad1[0x34]; };
struct MQ { SIDE side[2]; char pad[0x2C]; MQ *pmqNext; };
struct LASERBEAM { char pad[0x148]; MQ *pmqFirst; char pad2[4]; };
struct LASER { char pad[0x198]; int cbeam; LASERBEAM *abeam; };
struct SW;
extern "C" char B_003DD490[];
extern "C" const UL RO_002A7AC0;
void func_001F5988(LASER *, void *);
void FreeSwMqList(SW *, MQ *);
void QueueSwCallbackOnce(void *, LASER *, unsigned long, int);

void NotifyLaserXpEnded(LASER *plaser, void *psoOther)
{
    MQ *pmqFree = 0;
    func_001F5988(plaser, psoOther);
    for (int ibeam = 0; ibeam < plaser->cbeam; ibeam++) {
        LASERBEAM *pbeam = &plaser->abeam[ibeam];
        MQ **ppmqLink = &pbeam->pmqFirst;
        MQ *pmq = *ppmqLink;
        if (pmq != 0) {
            do {
                int n = (pmq->side[0].pso == plaser);
                SIDE *sd = (SIDE *)((char *)pmq + (n << 6));
                if (psoOther == sd->pso) {
                    *ppmqLink = pmq->pmqNext;
                    pmq->pmqNext = pmqFree;
                    pmqFree = pmq;
                } else {
                    ppmqLink = &pmq->pmqNext;
                }
            } while ((pmq = *ppmqLink) != 0);
        }
    }
    FreeSwMqList((SW *)B_003DD490, pmqFree);
    QueueSwCallbackOnce(B_003DD490, plaser, RO_002A7AC0.v, 0);
}
