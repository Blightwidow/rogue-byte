struct BIS_167320;
struct REQ_167320 { int size; int align; };
struct GLOB_167320 { char c0; char pad1[2]; char type; float f4; char pad8[0x14 - 8]; };
struct GLOBI_167320 {
    int n0;
    int n4;
    char pad8[4];
    unsigned type : 3;
    unsigned c : 5;
    unsigned pad8b : 2;
    unsigned fHasF : 1;
    unsigned fFlag : 1;
    char pad10[0x28 - 0x10];
};
struct VEC_167320 { float x, y, z; };
struct SUBGLOB_167320 { VEC_167320 pos; float fC; float f10; unsigned u14; };
struct INFO_167320 { float f0; int pad4; int n8; };
struct VTE_167320 { short d; short i; int (*pfn)(void *, int); };
struct VT_167320 { VTE_167320 ae[0x34]; };
struct ALO_167320 { char pad0[0xC]; VT_167320 *vt; };
struct GLOBSET_167320 {
    ALO_167320 *palo;
    char pad4[0x10 - 4];
    VEC_167320 pos;
    int pad1C;
    float f20;
    int c24;
    int *p28;
    int c2C;
    int *p30;
    int c34;
    int cglob;
    GLOB_167320 *aglob;
    GLOBI_167320 *aglobi;
    SUBGLOB_167320 *asubglob;
};
extern "C" {
void *memset(void *, int, unsigned int);
int S8Read__18CBinaryInputStream(BIS_167320 *);
unsigned U8Read__18CBinaryInputStream(BIS_167320 *);
int S16Read__18CBinaryInputStream(BIS_167320 *);
int U16Read__18CBinaryInputStream(BIS_167320 *);
int S32Read__18CBinaryInputStream(BIS_167320 *);
unsigned U32Read__18CBinaryInputStream(BIS_167320 *);
float F32Read__18CBinaryInputStream(BIS_167320 *);
void ReadVector__18CBinaryInputStreamP6VECTOR(BIS_167320 *, VEC_167320 *);
void CBinaryInputStream_Read_thunk(BIS_167320 *, int, void *);
void CBinaryInputStream_Skip(BIS_167320 *, int);
void *PvAllocSwClearImpl__Fi(REQ_167320 *);
int func_001ED7A8(int, BIS_167320 *);
int func_0013FAD0(int, short *);
void LoadGlobFromBrx(GLOBSET_167320 *, GLOB_167320 *, GLOBI_167320 *, INFO_167320 *, SUBGLOB_167320 *, int, BIS_167320 *);
void LoadGlobSkinnedFromBrx(GLOBSET_167320 *, GLOB_167320 *, GLOBI_167320 *, INFO_167320 *, SUBGLOB_167320 *, int, BIS_167320 *);
void LoadGlobStreamedFromBrx(GLOBSET_167320 *, GLOB_167320 *, GLOBI_167320 *, INFO_167320 *, SUBGLOB_167320 *, int, BIS_167320 *);
void LoadGlobIndexedFromBrx(GLOBSET_167320 *, GLOB_167320 *, GLOBI_167320 *, INFO_167320 *, SUBGLOB_167320 *, int, BIS_167320 *);
void LoadGlobsetBndTreeFromBrx(GLOBSET_167320 *, BIS_167320 *);
}

static inline void *PvAllocSwClear(int cb)
{
    REQ_167320 req;
    req.size = cb;
    req.align = 0x10;
    return PvAllocSwClearImpl__Fi(&req);
}

#define FLT_MAX_167320 3.40282347e+38f

extern "C" void LoadGlobsetFromBrx(GLOBSET_167320 *pglobset, ALO_167320 *palo, BIS_167320 *pbis)
{
    pglobset->palo = palo;
    int fNoSub = S8Read__18CBinaryInputStream(pbis);
    ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &pglobset->pos);
    pglobset->f20 = F32Read__18CBinaryInputStream(pbis);
    pglobset->c24 = U8Read__18CBinaryInputStream(pbis);
    pglobset->p28 = (int *)PvAllocSwClear(pglobset->c24 * 4);
    for (int i = 0; i < pglobset->c24; i++)
        pglobset->p28[i] = func_001ED7A8(1, pbis);
    pglobset->c2C = U8Read__18CBinaryInputStream(pbis);
    pglobset->p30 = (int *)PvAllocSwClear(pglobset->c2C * 4);
    pglobset->c34 = 0;
    for (int i = 0; i < pglobset->c2C; i++)
        pglobset->p30[i] = S32Read__18CBinaryInputStream(pbis);
    pglobset->cglob = S16Read__18CBinaryInputStream(pbis);
    pglobset->aglob = (GLOB_167320 *)PvAllocSwClear(pglobset->cglob * sizeof(GLOB_167320));
    pglobset->aglobi = (GLOBI_167320 *)PvAllocSwClear(pglobset->cglob * sizeof(GLOBI_167320));
    if (!fNoSub)
        pglobset->asubglob = (SUBGLOB_167320 *)PvAllocSwClear(pglobset->cglob * sizeof(SUBGLOB_167320));
    for (int iglob = 0; iglob < pglobset->cglob; iglob++) {
        GLOB_167320 *pglob = &pglobset->aglob[iglob];
        GLOBI_167320 *pglobi = &pglobset->aglobi[iglob];
        SUBGLOB_167320 *psubglob = pglobset->asubglob ? &pglobset->asubglob[iglob] : 0;
        INFO_167320 info;
        memset(&info, 0, sizeof(info));
        short ashort[0x80];
        int cshort = S8Read__18CBinaryInputStream(pbis);
        if (cshort != 0) {
            CBinaryInputStream_Read_thunk(pbis, cshort * 2, ashort);
            int cbSkip = S32Read__18CBinaryInputStream(pbis);
            if (!func_0013FAD0(cshort, ashort)) {
                CBinaryInputStream_Skip(pbis, cbSkip);
                iglob--;
                pglobset->cglob--;
                continue;
            }
        }
        pglob->type = S8Read__18CBinaryInputStream(pbis);
        int count = U16Read__18CBinaryInputStream(pbis);
        VTE_167320 *pvte = &palo->vt->ae[0x33];
        pglobi->n4 = pvte->pfn((char *)palo + pvte->d, S16Read__18CBinaryInputStream(pbis));
        pglob->c0 = S8Read__18CBinaryInputStream(pbis);
        float scale = F32Read__18CBinaryInputStream(pbis);
        pglob->f4 = scale == FLT_MAX_167320 ? FLT_MAX_167320 : scale * __builtin_fabsf(scale);
        info.f0 = F32Read__18CBinaryInputStream(pbis);
        pglobi->n0 = S32Read__18CBinaryInputStream(pbis);
        info.n8 = S8Read__18CBinaryInputStream(pbis);
        pglobi->fFlag = S8Read__18CBinaryInputStream(pbis);
        if (!fNoSub) {
            ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &psubglob->pos);
            psubglob->fC = F32Read__18CBinaryInputStream(pbis);
            psubglob->u14 = U32Read__18CBinaryInputStream(pbis);
            if ((psubglob->f10 = F32Read__18CBinaryInputStream(pbis)) == FLT_MAX_167320) {
                switch (pglob->type) {
                case 0:
                case 2:
                case 3:
                    psubglob->f10 = 1e10f;
                    break;
                case 1:
                    psubglob->f10 = 2000.0f;
                    break;
                }
            }
        }
        pglobi->type = pglob->type;
        pglobi->c = pglob->c0;
        if (pglob->f4 != FLT_MAX_167320)
            pglobi->fHasF = 1;
        switch (pglob->type) {
        case 0:
            LoadGlobFromBrx(pglobset, pglob, pglobi, &info, psubglob, count, pbis);
            break;
        case 1:
            LoadGlobSkinnedFromBrx(pglobset, pglob, pglobi, &info, psubglob, count, pbis);
            break;
        case 2:
            LoadGlobStreamedFromBrx(pglobset, pglob, pglobi, &info, psubglob, count, pbis);
            break;
        case 3:
            LoadGlobIndexedFromBrx(pglobset, pglob, pglobi, &info, psubglob, count, pbis);
            break;
        }
        iglob += count;
    }
    LoadGlobsetBndTreeFromBrx(pglobset, pbis);
}
