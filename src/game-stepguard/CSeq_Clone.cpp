struct ALLOCREQ_1DFBF8 { int cb; int cbAlign; };
struct SEQ_1DFBF8 { char pad0[0x54]; void *items; int count; char pad1[0x80 - 0x5C]; int flag; };
extern "C" void CLo_Clone(SEQ_1DFBF8 *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ_1DFBF8 *, void *);
extern "C" void CSeq_Clone(SEQ_1DFBF8 *seq)
{
    CLo_Clone(seq);
    if (seq->flag != 0) {
        void *src = seq->items;
        ALLOCREQ_1DFBF8 req;
        req.cb = seq->count * 0x50;
        req.cbAlign = 0x10;
        seq->items = PvAllocSwCopyImpl__FiPv(&req, src);
    }
}
