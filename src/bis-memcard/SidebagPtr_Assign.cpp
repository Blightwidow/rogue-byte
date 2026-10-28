struct CRef { int a; int b; };
struct VARB { int count; int pad4; int pad8; CRef ref; VARB *next; };
struct SIDEBAG { int count; int pad4; VARB *pvarb; };
struct SLOTHEAP;
extern "C" {
void VarbPtr_Destructor(VARB **, int);
void CRef_Destruct(void *);
void UnlinkVarbNode(VARB *);
void UnlinkSidebagNode(SIDEBAG *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520D0;
extern SLOTHEAP B_00452148;
}
extern "C" void SidebagPtr_Assign(SIDEBAG **ppsidebag, SIDEBAG *psidebag)
{
    if (psidebag != 0)
        psidebag->count++;
    SIDEBAG *psidebagOld = *ppsidebag;
    if (psidebagOld != 0) {
        if (--psidebagOld->count == 0) {
            VARB *pvarb = psidebagOld->pvarb;
            if (pvarb != 0) {
                if (--pvarb->count == 0) {
                    VarbPtr_Destructor(&pvarb->next, 2);
                    CRef_Destruct(&pvarb->ref);
                    UnlinkVarbNode(pvarb);
                    FreeSlotheapPv(&B_004520D0, pvarb);
                }
            }
            UnlinkSidebagNode(psidebagOld);
            FreeSlotheapPv(&B_00452148, psidebagOld);
        }
    }
    *ppsidebag = psidebag;
}
