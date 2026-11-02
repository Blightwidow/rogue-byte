struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct ROW { unsigned char b[64]; };
struct CNT { int c; short *p; };
extern "C" {
int U32Read__18CBinaryInputStream(Bis *);
unsigned U8Read__18CBinaryInputStream(Bis *);
unsigned U16Read__18CBinaryInputStream(Bis *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void func_00118458(Bis *, void *);
extern int B_003E1C38;
extern int B_003E1C3C;
extern ROW *B_003E1C40;
extern int *B_003E1C44;
extern int *B_003E1C48;
extern CNT *B_003E1C4C;
extern ROW *B_003E1C50;
static inline void *AllocWith(ALLOCREQ *r, int cb, int align)
{
    r->cb = cb;
    r->cbAlign = align;
    return PvAllocSwImpl__Fi(r);
}
void LoadLevelTableFromBrx(void *unused, Bis *pbis)
{
    ALLOCREQ req;
    B_003E1C38 = U32Read__18CBinaryInputStream(pbis);
    B_003E1C3C = U32Read__18CBinaryInputStream(pbis);
    B_003E1C40 = (ROW *)AllocWith(&req, B_003E1C38 << 6, 0x10);
    B_003E1C44 = (int *)AllocWith(&req, B_003E1C38 * 4, 0x10);
    B_003E1C48 = (int *)AllocWith(&req, B_003E1C38 * 4, 0x10);
    B_003E1C4C = (CNT *)AllocWith(&req, B_003E1C38 * 8, 0x10);
    req.cb = 0x240; req.cbAlign = 0x10;
    B_003E1C50 = (ROW *)PvAllocSwClearImpl__Fi(&req);
    for (int i = 0; i < B_003E1C38; i++) {
        func_00118458(pbis, B_003E1C40 + i);
        B_003E1C44[i] = U8Read__18CBinaryInputStream(pbis);
        B_003E1C48[i] = U8Read__18CBinaryInputStream(pbis);
        if (U8Read__18CBinaryInputStream(pbis))
            B_003E1C50[B_003E1C44[i]] = B_003E1C40[i];
        CNT *pc = B_003E1C4C + i;
        pc->c = U8Read__18CBinaryInputStream(pbis);
        pc->p = (short *)AllocWith(&req, pc->c * 2, 0x10);
        for (int j = 0; j < pc->c; j++)
            pc->p[j] = U16Read__18CBinaryInputStream(pbis);
    }
}
}
