#include "sly2.h"
#include "bis.h"
#include "alloc.h"
#include "lo.h"
#include "ps2inline.h"

/* a 3-row matrix held as quadwords: copied with lq/sq */
struct MATRIX3Q { QW row[3]; };
/* CRef as in include/cref.h, but its default constructor sets the tag to TAGK_Nil: retail's array loops store -1 */
union TAG { int m_n; float m_g; void *m_pv; };
struct CRef {
    int m_tagk;
    TAG m_tag;
    CRef() { m_tagk = -1; }
    CRef(const CRef &ref);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &ref);
    void Decref();
};
struct CLQ3 { float g0, g1, g2; };
struct LM2 { float gMin, gMax; };
struct RGBA { u8 r, g, b, a; };
struct ARYS16 { int c; void *pv; };

typedef BASIC *(BASIC::*PMFGET)(int fCreate);
typedef void (BASIC::*PMFINT)(int n);
typedef void (BASIC::*PMFFLOAT)(float g);
typedef void (BASIC::*PMFVECTOR)(QW vec);
typedef void (BASIC::*PMFPV)(void *pv);
typedef CRef (*PFNARGS)(BASIC *pbasic, int cref, CRef *aref);


/* an option record, 0x28 bytes (LoadOptionsFromBrx indexes them from 0x2AC880) */
struct EOPID {
    /* 0x00 */ u32 otyp;
    /* 0x04 */ u32 grfeopid;
    /* 0x08 */ PFNARGS pfnArgsSet;
    /* 0x0C */ u32 unknown_0xC;
    /* 0x10 */ union { PMFINT pmfSet; PFNARGS pfnArgs; int ibSet; };
    /* 0x18 */ union { PMFINT pmfSetAlt; int ib; int cArg; };
    /* 0x20 */ PMFGET pmfGet;
};

struct OPTSET { int oid; int ib; };
struct OPTCALL { int oid; PMFINT pmf; };
struct PDCB { void (*pfn)(BASIC *, void *); void *pv; };

class CStackFrame {
public:
    int unknown_0x0;
    CStackFrame();
    ~CStackFrame();
};

extern "C" {
CRef LoadRefFromBrx(int otyp, CBinaryInputStream *pbis);
CRef RefSetArgListFromPvs(int cpv, int *aotyp, void **apv);
MATRIX3Q LoadRotateMatrix(QW vec);
void FilterColorRgba8_1ed278(void *prgba);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *preq);
void *PvAllocStackClearImpl__Fi(ALLOCREQ *preq);
void CBinaryInputStream_Read_thunk(CBinaryInputStream *pbis, int cb, void *pv);
void *func_00210120(void *pslotheap);
PDCB *func_001A5D58(BASIC *pbasic);
void DcbSetOptionPlo(BASIC *pbasic, void *pv);
void DcbCallOptionPlo(BASIC *pbasic, void *pv);
extern char B_003DD490[];
}

/* sets the request's alignment through the pointer the allocator is then given (as in LoadTaskFromBrx) */
static inline ALLOCREQ *Aligned(ALLOCREQ *preq)
{
    preq->cbAlign = 0x10;
    return preq;
}

void LoadOptionFromBrx(BASIC *pbasic, EOPID *peopid, unsigned int grfopt, CBinaryInputStream *pbis)
{
    if (grfopt & 0x401) {
        CRef aref[32];
        int cref = peopid->cArg;
        for (int iref = 0; iref < cref; iref++) {
            int otyp = pbis->U16Read();
            if (otyp & 0x8000) {
                CRef arefList[16];
                int aotyp[16];
                void *apv[16];
                int otypList = otyp & ~0x8000;
                int cpv = pbis->U8Read();
                for (int ipv = 0; ipv < cpv; ipv++) {
                    arefList[ipv] = LoadRefFromBrx(otypList, pbis);
                    apv[ipv] = &arefList[ipv].m_tag;
                    aotyp[ipv] = otypList;
                }
                aref[iref] = RefSetArgListFromPvs(cpv, aotyp, apv);
            } else {
                aref[iref] = LoadRefFromBrx(otyp, pbis);
            }
        }
        if (grfopt & 0x400) {
            peopid->pfnArgsSet(pbasic, cref, aref);
        } else {
            peopid->pfnArgs(pbasic, cref, aref);
        }
    } else if (grfopt & 0x90) {
        void *pv;
        if (grfopt & 0x2000) {
            PMFGET pmfGet = peopid->pmfGet;
            pv = (char *)(pbasic->*pmfGet)(1) + peopid->ib;
        } else {
            pv = (char *)pbasic + peopid->ib;
        }
        switch (peopid->otyp) {
        case 0:
            *(u8 *)pv = pbis->U8Read();
            break;
        case 5:
        case 6:
            *(int *)pv = pbis->S32Read();
            break;
        case 1:
            *(float *)pv = pbis->F32Read();
            break;
        case 10:
            ((float *)pv)[0] = pbis->F32Read();
            ((float *)pv)[1] = pbis->F32Read();
            break;
        case 2:
        case 9:
        case 11:
            ((float *)pv)[0] = pbis->F32Read();
            ((float *)pv)[1] = pbis->F32Read();
            ((float *)pv)[2] = pbis->F32Read();
            break;
        case 3:
        case 12:
            ((float *)pv)[0] = pbis->F32Read();
            ((float *)pv)[1] = pbis->F32Read();
            ((float *)pv)[2] = pbis->F32Read();
            ((float *)pv)[3] = pbis->F32Read();
            break;
        case 13: {
            RGBA rgba;
            *(u32 *)&rgba = pbis->U32Read();
            FilterColorRgba8_1ed278(&rgba);
            *(u32 *)pv = *(u32 *)&rgba;
            break;
        }
        case 4: {
            VECTOR vec;
            vec.x = pbis->F32Read();
            vec.y = pbis->F32Read();
            vec.z = pbis->F32Read();
            *(MATRIX3Q *)pv = LoadRotateMatrix(*(QW *)&vec);
            break;
        }
        case 22: {
            ARYS16 *pary = (ARYS16 *)pv;
            ALLOCREQ req;
            int c = pbis->U16Read();
            pary->c = c;
            req.cb = c * 2;
            req.cbAlign = 0x10;
            pary->pv = PvAllocSwClearImpl__Fi(&req);
            CBinaryInputStream_Read_thunk(pbis, pary->c * 2, pary->pv);
            break;
        }
        case 7:
        case 14:
        case 15:
        case 16:
        case 17:
        case 19:
        case 20:
        case 21:
        case 23:
            *(int *)pv = pbis->S16Read();
            break;
        default:
            switch ((int)(peopid->otyp & ~0x8000) >> 12) {
            case 1:
                *(u32 *)pv = pbis->U32Read();
                break;
            case 2:
                if (grfopt & 0x80) {
                    int oid = pbis->S32Read();
                    OPTSET *poptset = (OPTSET *)func_00210120(B_003DD490);
                    poptset->oid = oid;
                    poptset->ib = (char *)pv - (char *)pbasic;
                    PDCB *pdcb = func_001A5D58(pbasic);
                    pdcb->pv = poptset;
                    pdcb->pfn = DcbSetOptionPlo;
                } else {
                    OPTSET optset;
                    optset.oid = pbis->S32Read();
                    optset.ib = peopid->ibSet;
                    DcbSetOptionPlo(pbasic, &optset);
                }
                break;
            }
            break;
        }
    } else {
        BASIC *pbasicSet;
        if (grfopt & 0x2000) {
            PMFGET pmfGet = peopid->pmfGet;
            pbasicSet = (pbasic->*pmfGet)(1);
        } else {
            pbasicSet = pbasic;
        }
        PMFINT pmf;
        if (grfopt & 0x100) {
            pmf = peopid->pmfSetAlt;
        } else {
            pmf = peopid->pmfSet;
        }
        switch (peopid->otyp) {
        case 0:
            (pbasicSet->*pmf)(pbis->U8Read());
            break;
        case 5:
        case 6:
            (pbasicSet->*pmf)(pbis->S32Read());
            break;
        case 1:
            (pbasicSet->*(PMFFLOAT)pmf)(pbis->F32Read());
            break;
        case 10: {
            LM2 lm;
            lm.gMin = pbis->F32Read();
            lm.gMax = pbis->F32Read();
            (pbasicSet->*(PMFPV)pmf)(&lm);
            break;
        }
        case 9: {
            float g0 = pbis->F32Read();
            float g1 = pbis->F32Read();
            float g2 = pbis->F32Read();
            CLQ3 clq;
            clq.g0 = g0;
            clq.g1 = g1;
            clq.g2 = g2;
            (pbasicSet->*(PMFPV)pmf)(&clq);
            break;
        }
        case 11: {
            float x = pbis->F32Read();
            float y = pbis->F32Read();
            float z = pbis->F32Read();
            VECTOR vec;
            vec.x = x;
            vec.y = y;
            vec.z = z;
            (pbasicSet->*(PMFPV)pmf)(&vec);
            break;
        }
        case 2: {
            float x = pbis->F32Read();
            float y = pbis->F32Read();
            float z = pbis->F32Read();
            VECTOR vec;
            QW qw = JoinLowDoublewords(z, InterleaveLowWords(y, x));
            *(QW *)&vec = qw;
            (pbasicSet->*(PMFVECTOR)pmf)(qw);
            break;
        }
        case 12: {
            float x = pbis->F32Read();
            float y = pbis->F32Read();
            float z = pbis->F32Read();
            float w = pbis->F32Read();
            VECTOR vec;
            vec.x = x;
            vec.y = y;
            vec.z = z;
            vec.w = w;
            (pbasicSet->*(PMFPV)pmf)(&vec);
            break;
        }
        case 3: {
            float x = pbis->F32Read();
            float y = pbis->F32Read();
            float z = pbis->F32Read();
            float w = pbis->F32Read();
            VECTOR vec;
            vec.x = x;
            vec.y = y;
            vec.z = z;
            vec.w = w;
            (pbasicSet->*(PMFVECTOR)pmf)(*(QW *)&vec);
            break;
        }
        case 13: {
            RGBA rgbaRead;
            *(u32 *)&rgbaRead = pbis->U32Read();
            FilterColorRgba8_1ed278(&rgbaRead);
            RGBA rgba;
            rgba = rgbaRead;
            (pbasicSet->*(PMFPV)pmf)(&rgba);
            break;
        }
        case 4: {
            VECTOR vec;
            vec.x = pbis->F32Read();
            vec.y = pbis->F32Read();
            vec.z = pbis->F32Read();
            MATRIX3Q mat;
            mat = LoadRotateMatrix(*(QW *)&vec);
            (pbasicSet->*(PMFPV)pmf)(&mat);
            break;
        }
        case 22: {
            CStackFrame frame;
            ARYS16 ary;
            ALLOCREQ req;
            int c = pbis->U16Read();
            ary.c = c;
            req.cb = c * 2;
            ary.pv = PvAllocStackClearImpl__Fi(Aligned(&req));
            CBinaryInputStream_Read_thunk(pbis, ary.c * 2, ary.pv);
            (pbasicSet->*(PMFPV)pmf)(&ary);
            break;
        }
        case 7:
        case 14:
        case 15:
        case 16:
        case 17:
        case 19:
        case 20:
        case 21:
        case 23:
            (pbasicSet->*pmf)(pbis->S16Read());
            break;
        default:
            switch ((int)(peopid->otyp & ~0x8000) >> 12) {
            case 1:
                (pbasicSet->*pmf)(pbis->U32Read());
                break;
            case 2:
                if (grfopt & 0x100) {
                    int oid = pbis->S32Read();
                    OPTCALL *poptcall = (OPTCALL *)func_00210120(B_003DD490);
                    poptcall->oid = oid;
                    poptcall->pmf = peopid->pmfSetAlt;
                    PDCB *pdcb = func_001A5D58(pbasic);
                    pdcb->pv = poptcall;
                    pdcb->pfn = DcbCallOptionPlo;
                } else {
                    OPTCALL optcall;
                    optcall.oid = pbis->S32Read();
                    optcall.pmf = peopid->pmfSet;
                    DcbCallOptionPlo(pbasic, &optcall);
                }
                break;
            }
            break;
        }
    }
}
