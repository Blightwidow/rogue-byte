#include "sly2.h"
struct SLOTHEAP;
struct Bis;
struct BLOT { char pad[0xC4]; SLOTHEAP *heap; };
struct B4 { char b[4]; };
struct M3 { QW r[3]; };
struct SPRITE;
struct MOVIE;
struct PLACE { unsigned short a, b, c; short d; char pad0[8]; float m[6]; char padm[8]; unsigned char e, f; char pad2[2]; int g; char pad3[8]; };
struct PAIR { int second; int first; };
struct ACTION { unsigned kind; int arg; };
struct KEY { float t; unsigned char cplace, cpair, chalf, cbyte; unsigned char *abyte; PLACE *aplace; PAIR *apair; unsigned short *ahalf; unsigned char caction; char pad[3]; ACTION *aaction; };
struct LABEL { unsigned short ckey; char pad[2]; KEY *akey; float dur; MOVIE *pmovie; SPRITE *psprite; int id; };
struct SLOT { char pad[0x70]; };
struct INST { int cslot; SLOT *aslot; short ilabel; short unk; int c; int d; int e; };
struct SPRITE { unsigned short clabel; unsigned short cinst; LABEL *alabel; INST *ainst; char pad[0x20 - 0xC]; int pending; MOVIE *pmovie; int root; int pad2[1]; };
struct MOVIE { char pad[0x80]; unsigned short csprite; char pad2[2]; SPRITE *asprite; };
extern "C" {
unsigned short U16Read__18CBinaryInputStream(Bis *);
unsigned char U8Read__18CBinaryInputStream(Bis *);
short S16Read__18CBinaryInputStream(Bis *);
unsigned U32Read__18CBinaryInputStream(Bis *);
int S32Read__18CBinaryInputStream(Bis *);
float F32Read__18CBinaryInputStream(Bis *);
void CBinaryInputStream_ReadMatrix(Bis *, M3 *);
void InitDepthSlot(SLOT *);
void *PvAllocSlotheapClearImpl__FP8SLOTHEAP(SLOTHEAP *, int, int);
}
void LoadMovieSprites(BLOT *pblot, Bis *pbis, MOVIE *pmovie)
{
    pmovie->csprite = U16Read__18CBinaryInputStream(pbis);
    pmovie->asprite = (SPRITE *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pmovie->csprite * 0x30, 0x12);
    for (int isprite = 0; isprite < pmovie->csprite; isprite++) {
        SPRITE *psprite = pmovie->asprite + isprite;
        psprite->root = isprite == 0;
        psprite->pmovie = pmovie;
        psprite->cinst = U16Read__18CBinaryInputStream(pbis);
        psprite->ainst = (INST *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, psprite->cinst * 0x18, 0x12);
        int cslot = U16Read__18CBinaryInputStream(pbis);
        for (int iinst = 0; iinst < psprite->cinst; iinst++) {
            INST *pinst = psprite->ainst + iinst;
            pinst->c = 0;
            pinst->ilabel = -1;
            pinst->unk = 0;
            pinst->d = 0;
            pinst->cslot = cslot;
            pinst->aslot = (SLOT *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, cslot * 0x70, 0x10);
            for (int islot = 0; islot < pinst->cslot; islot++)
                InitDepthSlot(pinst->aslot + islot);
        }
        psprite->clabel = U16Read__18CBinaryInputStream(pbis);
        psprite->alabel = (LABEL *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, psprite->clabel * 0x18, 0x12);
        psprite->pending = -1;
        for (int ilabel = 0; ilabel < psprite->clabel; ilabel++) {
            LABEL *plabel = psprite->alabel + ilabel;
            plabel->pmovie = pmovie;
            plabel->psprite = psprite;
            plabel->dur = F32Read__18CBinaryInputStream(pbis);
            plabel->id = S32Read__18CBinaryInputStream(pbis);
            plabel->ckey = U16Read__18CBinaryInputStream(pbis);
            plabel->akey = (KEY *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, plabel->ckey << 5, 0x12);
            for (int ikey = 0; ikey < plabel->ckey; ikey++) {
                KEY *pkey = plabel->akey + ikey;
                pkey->t = F32Read__18CBinaryInputStream(pbis);
                pkey->cplace = U8Read__18CBinaryInputStream(pbis);
                pkey->aplace = (PLACE *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pkey->cplace << 6, 0x12);
                for (int iplace = 0; iplace < pkey->cplace; iplace++) {
                    PLACE *pplace = pkey->aplace + iplace;
                    pplace->a = U16Read__18CBinaryInputStream(pbis);
                    pplace->b = U16Read__18CBinaryInputStream(pbis);
                    pplace->c = U16Read__18CBinaryInputStream(pbis);
                    pplace->d = S16Read__18CBinaryInputStream(pbis);
                    pplace->e = U8Read__18CBinaryInputStream(pbis);
                    pplace->f = U8Read__18CBinaryInputStream(pbis);
                    pplace->g = S32Read__18CBinaryInputStream(pbis);
                    M3 mat;
                    CBinaryInputStream_ReadMatrix(pbis, &mat);
                    M3 mat2 = mat;
                    float *pf = pplace->m;
                    pf[0] = ((float *)&mat2)[0];
                    pf[1] = ((float *)&mat2)[1];
                    pf[2] = ((float *)&mat2)[4];
                    pf[3] = ((float *)&mat2)[5];
                    pf[4] = ((float *)&mat2)[8];
                    pf[5] = ((float *)&mat2)[9];
                }
                pkey->cpair = U8Read__18CBinaryInputStream(pbis);
                pkey->apair = (PAIR *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pkey->cpair << 3, 0x12);
                for (int ipair = 0; ipair < pkey->cpair; ipair++) {
                    PAIR *ppair = pkey->apair + ipair;
                    B4 first, second;
                    *(unsigned *)&first = U32Read__18CBinaryInputStream(pbis);
                    *(unsigned *)&second = U32Read__18CBinaryInputStream(pbis);
                    *(B4 *)&ppair->first = first;
                    *(B4 *)&ppair->second = second;
                }
                pkey->chalf = U8Read__18CBinaryInputStream(pbis);
                pkey->ahalf = (unsigned short *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pkey->chalf << 1, 0x12);
                for (int ihalf = 0; ihalf < pkey->chalf; ihalf++)
                {
                    unsigned short *phalf = pkey->ahalf + ihalf;
                    *phalf = U16Read__18CBinaryInputStream(pbis);
                }
                pkey->cbyte = U8Read__18CBinaryInputStream(pbis);
                pkey->abyte = (unsigned char *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pkey->cbyte, 0x12);
                for (int ibyte = 0; ibyte < pkey->cbyte; ibyte++)
                    pkey->abyte[ibyte] = U8Read__18CBinaryInputStream(pbis);
                pkey->caction = U8Read__18CBinaryInputStream(pbis);
                pkey->aaction = (ACTION *)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pkey->caction << 3, 0x12);
                for (int iaction = 0; iaction < pkey->caction; iaction++) {
                    int off = iaction << 3;
                    *(unsigned *)((char *)pkey->aaction + off) = U8Read__18CBinaryInputStream(pbis);
                    int dead = *(unsigned *)((char *)pkey->aaction + off) < 2;
                    asm volatile("" : : "r" (dead));
                    *(int *)((char *)pkey->aaction + off + 4) = S32Read__18CBinaryInputStream(pbis);
                }
            }
        }
    }
}
