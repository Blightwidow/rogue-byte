#include "sly2.h"
struct CBinaryInputStream { int pad; unsigned U16Read(); };
struct ALLOCREQ { int cb; int cbAlign; };
struct TEX { char pad[6]; unsigned char cbmp; unsigned char cpal; int unk8; unsigned *abmp; unsigned *apal; };
extern "C" int CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" unsigned B_003DCFF4;
extern "C" unsigned B_003DCFFC;
void LoadTexFromBrx(CBinaryInputStream *pbis, TEX *ptex)
{
    ALLOCREQ req;
    int i;
    CBinaryInputStream_Read_thunk(pbis, 8, ptex);
    int cbmp = ptex->cbmp;
    if (cbmp != 0) {
        req.cb = cbmp * 4;
        req.cbAlign = 0x10;
        ptex->abmp = (unsigned *)PvAllocSwImpl__Fi(&req);
        for (i = 0; i < ptex->cbmp; i++) {
            unsigned index = pbis->U16Read();
            ptex->abmp[i] = B_003DCFF4 + index * 0x28;
        }
    }
    int cpal = ptex->cpal;
    if (cpal != 0) {
        req.cb = cpal * 4;
        req.cbAlign = 0x10;
        ptex->apal = (unsigned *)PvAllocSwImpl__Fi(&req);
        for (i = 0; i < ptex->cpal; i++) {
            unsigned index = pbis->U16Read();
            if (index == 0xFFFF)
                ptex->apal[i] = 0;
            else
                ptex->apal[i] = B_003DCFFC + index * 0x20;
        }
    }
}
