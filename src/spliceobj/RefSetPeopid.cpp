#include "sly2.h"
#include "cref.h"
#include "lo.h"
enum OTYP { OTYP_Nil = -1 };
typedef void (BASIC::*PMFSETN)(int);
typedef void (BASIC::*PMFSETG)(float);
typedef void (BASIC::*PMFSETV)(QW);
typedef void (BASIC::*PMFSETPV)(void *);
typedef BASIC *(BASIC::*PMFTARGET)(int);
struct EOPID {
    OTYP otyp;
    int grf;
    int pad8[2];
    union {
        int ib;
        PMFSETN pmfsetn;
        PMFSETG pmfsetg;
        PMFSETV pmfsetv;
        PMFSETPV pmfsetpv;
    };
    int pad18[2];
    PMFTARGET pmfTarget;
};
CRef RefSetPvsFromSplice(int cref, CRef *aref, OTYP *aotyp, void **apv);
extern "C" CRef CRef_RefCoerceS32(CRef *pref);
extern "C" CRef CRef_RefCoerceF32(CRef *pref);
extern "C" CRef RefSetPeopid(BASIC *pbasic, EOPID *peopid, CRef *pref)
{
    CRef ref;
    ref.m_tagk = TAGK_Nil;
    ref.Decref();
    ref.SetTag(TAGK_Void);
    int grf = peopid->grf;
    if (grf & 0x10) {
        if (grf & 0x2000)
            pbasic = (pbasic->*(peopid->pmfTarget))(1);
        void *pv = (char *)pbasic + peopid->ib;
        ref = RefSetPvsFromSplice(1, pref, &peopid->otyp, &pv);
    } else {
        if (grf & 0x2000)
            pbasic = (pbasic->*(peopid->pmfTarget))(1);
        switch (peopid->otyp) {
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
        {
            int n;
            if (pref->m_tagk == TAGK_S32) {
                n = pref->m_tag.m_n;
            } else {
                CRef refN;
                refN.m_tagk = TAGK_Nil;
                refN = CRef_RefCoerceS32(pref);
                n = refN.m_tag.m_n;
            }
            (pbasic->*(peopid->pmfsetn))(n);
        }
            break;
        case 1:
        {
            float g;
            if (pref->m_tagk == TAGK_F32) {
                g = pref->m_tag.m_g;
            } else {
                CRef refG;
                refG.m_tagk = TAGK_Nil;
                refG = CRef_RefCoerceF32(pref);
                g = refG.m_tag.m_g;
            }
            (pbasic->*(peopid->pmfsetg))(g);
        }
            break;
        case 0:
            (pbasic->*(peopid->pmfsetn))(pref->m_tag.m_bool);
            break;
        case 2:
            (pbasic->*(peopid->pmfsetv))(*(QW *)pref->m_tag.m_pvector);
            break;
        case 4:
            (pbasic->*(peopid->pmfsetpv))(pref->m_tag.m_pmatrix);
            break;
        case 9:
            (pbasic->*(peopid->pmfsetpv))(pref->m_tag.m_pclq);
            break;
        case 10:
            (pbasic->*(peopid->pmfsetpv))(pref->m_tag.m_plm);
            break;
        case 11:
            (pbasic->*(peopid->pmfsetpv))(pref->m_tag.m_psmp);
            break;
        default:
            if (peopid->otyp & 0x1000)
                (pbasic->*(peopid->pmfsetn))(pref->m_tag.m_n);
            else if (peopid->otyp & 0x2000)
                (pbasic->*(peopid->pmfsetpv))(pref->m_tag.m_pbasic);
            break;
        }
    }
    return ref;
}
