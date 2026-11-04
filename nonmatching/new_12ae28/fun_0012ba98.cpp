#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct KEY2 { float pos[3]; float t; float vec[4]; };
struct ACRB2 { int pad0; int ckey; KEY2 *akey; };
extern "C" {
int ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, VECTOR *);
unsigned short U16Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
}
extern "C" void func_0012BA98(ACRB2 *pacrb, Bis *pbis)
{
    int ckey = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ req;
    req.cb = ckey * 0x20;
    req.cbAlign = 0x10;
    pacrb->ckey = ckey;
    pacrb->akey = (KEY2 *)PvAllocSwClearImpl__Fi(&req);
    for (int ikey = 0; ikey < pacrb->ckey; ikey++) {
        KEY2 *pkey = pacrb->akey + ikey;
        int frame = U16Read__18CBinaryInputStream(pbis);
        pkey->t = frame * (1.0f / 60.0f);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->pos);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (VECTOR *)pkey->vec);
    }
}
