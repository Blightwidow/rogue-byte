struct LO;
struct SUBSCRIBER { LO *plo; int csub; SUBSCRIBER *pnext; };
struct LO { char pad[8]; SUBSCRIBER *psubFirst; };
struct SLOTHEAP;
extern SLOTHEAP B_003E1144;
extern "C" void FreeSlotheapPv(SLOTHEAP *, void *);
extern "C" void UnsubscribeLoObject(LO *plo, LO *ploTarget)
{
    SUBSCRIBER **ppsub = &plo->psubFirst;
    SUBSCRIBER *psub;
    while (psub = *ppsub) {
        if (psub->plo == ploTarget) {
            if (--psub->csub <= 0) {
                *ppsub = psub->pnext;
                FreeSlotheapPv(&B_003E1144, psub);
            }
            break;
        }
        ppsub = &psub->pnext;
    }
}