// SPDX-License-Identifier: GPL-3.0-or-later
void *memset(void *, int, unsigned int);
struct ALLOCREQ { int cb; int cbAlign; };
struct CRV { char pad0[0x60]; float mat[16]; char pad1[0x40]; int crvk; int fClosed; char pad2[4]; float *mpicvu; void *mpicvs; void *mpipos; };
extern "C" CRV *PloNew(int, void *, int, int);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);

extern "C" CRV *PcrvNew(int oid, int ccv)
{
    CRV *pcrv = PloNew(10, 0, oid, -1);
    float *pmat = pcrv->mat;
    pcrv->crvk = 0;
    pcrv->fClosed = 0;
    memset(pmat, 0, 0x40);
    pmat[15] = 1.0f;
    pmat[10] = 1.0f;
    pmat[5] = 1.0f;
    pcrv->mat[0] = 1.0f;
    ALLOCREQ request;
    request.cb = ccv << 2;
    request.cbAlign = 0x10;
    pcrv->mpicvu = (float *)PvAllocSwImpl__Fi(&request);
    for (int icv = 0; icv < ccv; icv++)
        pcrv->mpicvu[icv] = (float)icv;
    request.cb = ccv << 2;
    request.cbAlign = 0x10;
    pcrv->mpicvs = PvAllocSwImpl__Fi(&request);
    request.cb = ccv << 4;
    request.cbAlign = 0x10;
    pcrv->mpipos = PvAllocSwImpl__Fi(&request);
    return pcrv;
}
