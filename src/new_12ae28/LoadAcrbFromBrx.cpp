#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct KEYB { float pos[3]; float t; float vecIn[4]; float vecOut[4]; };
struct ACRB { int pad0; int ckey; KEYB *akey; };
extern "C" {
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, VECTOR *);
unsigned short U16Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
}
extern "C" void LoadAcrbFromBrx(ACRB *pacrb, Bis *pbis)
{
    int ckey = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ req;
    req.cb = ckey * 0x30;
    req.cbAlign = 0x10;
    pacrb->ckey = ckey;
    pacrb->akey = (KEYB *)PvAllocSwClearImpl__Fi(&req);
    for (int ikey = 0; ikey < pacrb->ckey; ikey++) {
        KEYB *pkey = pacrb->akey + ikey;
        int frame = U16Read__18CBinaryInputStream(pbis);
        pkey->t = frame * (1.0f / 60.0f);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->pos);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->vecIn);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->vecOut);
    }
}
