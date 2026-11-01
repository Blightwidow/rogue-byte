struct VT { char pad[0x30]; short delta; short index; void (*fnAdded)(void *, int *); };
struct CARY { int *pb; int c; };
struct VEC { char pad[0xC]; VT *vt; CARY ary; };
extern "C" void func_00116E30(CARY *, const void *, int);
extern "C" int *Vector_Add(VEC *pvec, const void *pvSrc)
{
    CARY *pary = &pvec->ary;
    func_00116E30(pary, pvSrc, 1);
    pvec->vt->fnAdded((char *)pvec + pvec->vt->delta, &pvec->ary.pb[pary->c - 1]);
    return &pvec->ary.pb[pary->c - 1];
}
