#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct SPIRE { char pad[0xE0]; int cvert; char *avert; int ctri; int *atri; int *aneighbor; };
extern "C" {
void LoadXfmBaseFromBrx(SPIRE *, Bis *);
int S16Read__18CBinaryInputStream(Bis *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, void *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, Bis *);
}
extern "C" void LoadSpireFromBrx(SPIRE *pspire, Bis *pbis)
{
    LoadXfmBaseFromBrx(pspire, pbis);
    int cvert = S16Read__18CBinaryInputStream(pbis);
    ALLOCREQ req;
    req.cb = cvert << 4;
    req.cbAlign = 0x10;
    pspire->cvert = cvert;
    pspire->avert = (char *)PvAllocSwImpl__Fi(&req);
    for (int ivert = 0; ivert < pspire->cvert; ++ivert)
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, pspire->avert + ivert * 16);
    int ctri = S16Read__18CBinaryInputStream(pbis);
    req.cb = ctri * 0xC;
    req.cbAlign = 0x10;
    pspire->ctri = ctri;
    pspire->atri = (int *)PvAllocSwImpl__Fi(&req);
    for (int itri = 0; itri < pspire->ctri; ++itri) {
        int *aiVert = pspire->atri + itri * 3;
        aiVert[0] = S16Read__18CBinaryInputStream(pbis);
        aiVert[1] = S16Read__18CBinaryInputStream(pbis);
        aiVert[2] = S16Read__18CBinaryInputStream(pbis);
    }
    req.cb = pspire->ctri * 0xC;
    req.cbAlign = 0x10;
    pspire->aneighbor = (int *)PvAllocSwImpl__Fi(&req);
    for (int itri = 0; itri < pspire->ctri; ++itri) {
        pspire->aneighbor[itri * 3] = S16Read__18CBinaryInputStream(pbis);
        pspire->aneighbor[itri * 3 + 1] = S16Read__18CBinaryInputStream(pbis);
        pspire->aneighbor[itri * 3 + 2] = S16Read__18CBinaryInputStream(pbis);
    }
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(pspire, pbis);
}
