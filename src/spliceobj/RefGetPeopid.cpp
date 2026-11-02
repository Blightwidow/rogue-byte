#include "sly2.h"
struct REF { int tagk; void *pv; int pad[2]; };
struct ROW { QW q; };
struct MAT3 { union { QW aq[3]; int an[12]; }; };
struct BASIC { virtual void V0(); };
struct HMETHOD;
struct METHOD { int cref; int pad4; BASIC *pbasic; int f0C; int f10; };
typedef int (BASIC::*PMFI)();
typedef float (BASIC::*PMFF)();
typedef QW (BASIC::*PMFV)();
typedef MAT3 *(BASIC::*PMFM)();
typedef void (BASIC::*PMFP)(void *);
typedef REF (BASIC::*PMFR)();
typedef BASIC *(BASIC::*PMFB)(int);
struct EOPID {
    int kind;
    int grf;
    union {
        int ib;
        PMFI pmfi;
        PMFF pmff;
        PMFV pmfv;
        PMFM pmfm;
        PMFP pmfp;
        PMFR pmfr;
    };
    int f10;
    int pad14;
    int f18;
    int pad1C;
    PMFB pmfTarget;
};
extern char B_00452170[];
extern "C" {
METHOD *PmethodNew(void);
void func_00259CF8(HMETHOD *, METHOD *);
void func_00256120(METHOD *);
void FreeSlotheapPv(void *, void *);
void CRef_SetMethod(REF *, METHOD *);
void CRef_SetBool(REF *, int);
void CRef_SetF32(REF *, float);
void CRef_SetS32(REF *, int);
void CRef_SetBasic(REF *, void *);
void CRef_SetVector(REF *, QW);
void CRef_SetVectorPtr(REF *, void *);
void CRef_SetClqPtr(REF *, void *);
void CRef_SetLmPtr(REF *, void *);
void CRef_SetSmpPtr(REF *, void *);
void CRef_Destruct(REF *);
void CRef_CopyConstruct(REF *, REF *);
void SetTag__4CRef4TAGK(REF *, int);
void __as__4CRefRC4CRef(REF *, REF *);
}

struct HMETHOD {
    METHOD *p;
    ~HMETHOD()
    {
        METHOD *pmethod = p;
        if (pmethod != 0 && --pmethod->cref == 0) {
            func_00256120(pmethod);
            FreeSlotheapPv(B_00452170, pmethod);
        }
    }
};
static inline void CopyMat(MAT3 *pdst, MAT3 *psrc)
{
    pdst->aq[0] = psrc->aq[0];
    pdst->aq[1] = psrc->aq[1];
    pdst->aq[2] = psrc->aq[2];
    pdst->an[11] = 0;
    pdst->an[7] = 0;
    pdst->an[3] = 0;
}

extern "C" REF *RefGetPeopid(REF *result, BASIC *pbasic, EOPID *peopid)
{
    REF ref;
    ref.tagk = -1;
    int grf = peopid->grf;
    if (grf & 1) {
        METHOD *pmethodNew = PmethodNew();
        HMETHOD h;
        func_00259CF8(&h, pmethodNew);
        h.p->pbasic = pbasic;
        h.p->f0C = peopid->f10;
        h.p->f10 = peopid->f18;
        CRef_SetMethod(&ref, h.p);
    } else if (grf & 2) {
        if (grf & 0x2000)
            pbasic = (pbasic->*(peopid->pmfTarget))(1);
        char *pv = (char *)pbasic + peopid->ib;
        switch (peopid->kind) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 14:
        case 15:
        case 16:
        case 17:
        case 19:
        case 20:
        case 23:
            CRef_SetS32(&ref, *(int *)pv);
            break;
        case 1:
            CRef_SetF32(&ref, *(float *)pv);
            break;
        case 0:
            CRef_SetBool(&ref, *(int *)pv != 0);
            break;
        case 2:
            CRef_SetVectorPtr(&ref, pv);
            break;
        case 4:
            CRef_Destruct(&ref);
            SetTag__4CRef4TAGK(&ref, 0x1B);
            CopyMat((MAT3 *)ref.pv, (MAT3 *)pv);
            break;
        case 9:
            CRef_SetClqPtr(&ref, pv);
            break;
        case 10:
            CRef_SetLmPtr(&ref, pv);
            break;
        case 11:
            CRef_SetSmpPtr(&ref, pv);
            break;
        case 13:
            break;
        case 3:
        case 12:
        case 18:
        case 21:
        case 22:
        default:
            if (peopid->kind & 0x1000)
                CRef_SetS32(&ref, *(int *)pv);
            else if (peopid->kind & 0x2000)
                CRef_SetBasic(&ref, *(void **)pv);
            break;
        }
    } else {
        if (grf & 0x2000)
            pbasic = (pbasic->*(peopid->pmfTarget))(1);
        switch (peopid->kind) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 19:
        case 20:
        case 23:
            CRef_SetS32(&ref, (pbasic->*(peopid->pmfi))());
            break;
        case 1:
            CRef_SetF32(&ref, (pbasic->*(peopid->pmff))());
            break;
        case 0:
            CRef_SetBool(&ref, (pbasic->*(peopid->pmfi))() != 0);
            break;
        case 2:
            CRef_SetVector(&ref, (pbasic->*(peopid->pmfv))());
            break;
        case 4:
            CRef_Destruct(&ref);
            SetTag__4CRef4TAGK(&ref, 0x1B);
            {
                MAT3 *pmat = (MAT3 *)ref.pv;
                CopyMat(pmat, (pbasic->*(peopid->pmfm))());
            }
            break;
        case 9:
            CRef_Destruct(&ref);
            SetTag__4CRef4TAGK(&ref, 0x1C);
            (pbasic->*(peopid->pmfp))(ref.pv);
            break;
        case 10:
            CRef_Destruct(&ref);
            SetTag__4CRef4TAGK(&ref, 0x1C);
            (pbasic->*(peopid->pmfp))(ref.pv);
            break;
        case 11:
            CRef_Destruct(&ref);
            SetTag__4CRef4TAGK(&ref, 0x1E);
            (pbasic->*(peopid->pmfp))(ref.pv);
            break;
        case 3:
        case 12:
        case 18:
        case 21:
        case 22:
        default:
            if (peopid->kind & 0x8000) {
                REF tmp = (pbasic->*(peopid->pmfr))();
                __as__4CRefRC4CRef(&ref, &tmp);
                CRef_Destruct(&tmp);
            } else if (peopid->kind & 0x1000) {
                CRef_SetS32(&ref, (pbasic->*(peopid->pmfi))());
            } else if (peopid->kind & 0x2000) {
                CRef_SetBasic(&ref, (void *)(pbasic->*(peopid->pmfi))());
            }
            break;
        }
    }
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
