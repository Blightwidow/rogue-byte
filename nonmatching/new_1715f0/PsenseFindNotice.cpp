// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
#include "cref.h"
#include "po.h"
union VU_VECTOR { QW q; VECTOR v; };
struct LM { float gMin; float gMax; };
struct LSG { QW pos; char rest[0x50]; };
struct SENSE {
    char pad0[0x18];
    char field_0x18[0x50 - 0x18];
    LM lmDistance;
    LM lmVertical;
    char pad60[0x68 - 0x60];
    float gAngleMax;
    float sHitMin;
    int fCheckLine;
    char pad74[0x78 - 0x74];
    int fAlert;
    char pad7C[0xA8 - 0x7C];
    int fEnabled;
};
struct COEFFS { float c0, c1, c2; };
struct GUARD;
struct SCALE { char pad0[0x20]; float g; };
struct GUARD : LO {
    u8 unknown_0x50[0xEDC - 0x50];
    SENSE *apsense[8];
    int csense;
    int field_0xF00;
    float tNotice;
    char padF08[0xFBC - 0xF08];
    int mode;
    char padFC0[0xFC4 - 0xFC0];
    SCALE *pscale;
};
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
int FIsBasicDerivedFrom(void *, int);
int func_0020A818(void *, void *);
QW PosLoWorld(void *);
int IsetFromCloneId(int);
QW ConvertAloPos(void *, void *, QW);
float atan2f(float, float);
void func_00175820(void);
void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, LSG *);
void func_0020AB68(void *, void *, void *, QW);
void SetAlertState(void *, int);
extern char B_003DD490;
extern float g_2dded0;
extern COEFFS D_FLT_002BE600;
extern LM g_2bbb60;
}
int FCheckLm(LM *, float);
static inline float Quadratic(COEFFS *pcoeffs, float u)
{
    return pcoeffs->c0 + u * (pcoeffs->c1 + u * pcoeffs->c2);
}
static inline float GLimitLm(LM *plm, float g)
{
    float lo = plm->gMin;
    float hi = plm->gMax;
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}
extern "C" SENSE *PsenseFindNotice(GUARD *pguard, PO *ptarget, void *pknowledge)
{
    if (pguard->field_0xF00 != 0)
        return 0;
    if (ptarget == 0)
        return 0;
    if (((ptarget->grfo >> 60) & 1) == 0)
        return 0;
    if (g_2dded0 < pguard->tNotice)
        return 0;
    if (FIsBasicDerivedFrom(ptarget, 0x32)) {
        if (ptarget->NAlertLevel() != 0)
            return 0;
    }
    if (pknowledge != 0 && func_0020A818(pknowledge, pguard) == 0)
        return 0;
    QW posGuard = PosLoWorld(pguard);
    QW posTarget = PosLoWorld(ptarget);
    QW delta = VectorSub(posTarget, posGuard);
    float sVertical = LaneZInGeneralRegister(delta);
    float sDistance = LaneX(SqrtX(SquaredLengthXy(delta)));
    int isetTarget = IsetFromCloneId(*(int *)ptarget->pscope);
    if (isetTarget == IsetFromCloneId(*(int *)pguard->pscope)) {
        if ((unsigned)ptarget < (unsigned)pguard)
            sDistance += 75.0f;
        else
            sDistance += -75.0f;
    }
    if (pguard->mode == 8 || pguard->mode == 0xD) {
        if (pguard->pscale != 0) {
            float scale = pguard->pscale->g;
            sDistance = sDistance / scale;
            sVertical = sVertical / scale;
        }
    }
    for (int isense = 0; isense < pguard->csense; isense++) {
        SENSE *psense = pguard->apsense[isense];
        if (psense->fEnabled == 0)
            continue;
        if (!FCheckLm(&psense->lmDistance, sDistance))
            continue;
        if (!FCheckLm(&psense->lmVertical, sVertical))
            continue;
        QW posLocal = ConvertAloPos(0, pguard, posTarget);
        float angle = __builtin_fabsf(atan2f(LaneYInGeneralRegister(posLocal), LaneX(posLocal)));
        float scale = GLimitLm(&g_2bbb60, Quadratic(&D_FLT_002BE600, sDistance));
        if (psense->gAngleMax < scale * angle)
            continue;
        void *parg;
        char frame[0x10];
        if (psense->fCheckLine != 0) {
            VU_VECTOR posFrom;
            VU_VECTOR posTo;
            LSG lsg;
            int count, list;
            CStackFrame_Construct(frame);
            posFrom.q = posGuard;
            posTo.q = posTarget;
            bevy_camera_follow_push_out(&B_003DD490, posGuard, posTarget, (void *)func_00175820, psense, &count, &list);
            void *phit = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, posFrom.q, posTo.q, count, list, &lsg);
            if (phit != 0) {
                int fBlocked = LaneX(SqrtX(SquaredLength(VectorSub(posFrom.q, lsg.pos)))) < psense->sHitMin;
                if (fBlocked) {
                    CStackFrame_Destructor(frame, 2);
                    continue;
                }
            }
            CStackFrame_Destructor(frame, 2);
        }
        {
            CRef ref;
            QW mat[4];
            parg = psense->field_0x18;
            CRef *pref = &ref;
            pref->m_tagk = TAGK_Bool;
            pref->m_tag.m_bool = 1;
            pguard->HandleSpliceEvent(0x18, 0, 1, (int)&parg, (int)&ref);
            if (ref.m_tagk != TAGK_Bool || ref.m_tag.m_bool == 0) {
                continue;
            }
            if (psense->fAlert != 0) {
                void *ppose = ptarget->Slot32(mat);
                func_0020AB68(pguard, psense, ppose, mat[3]);
                psense = 0;
                if (pknowledge != 0)
                    SetAlertState(pknowledge, 3);
            }
            return psense;
        }
    }
    return 0;
}
