#include "sly2.h"
struct REF { int tagk; int n; };
struct VTG { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int *, REF *); };
struct VTT { char pad[0x100]; short delta; short index; void *(*fn)(void *, void *); };
struct VTA { char pad[0x268]; short delta; short index; int (*fn)(void *); };
struct OBJ { char pad[0xC]; void *vptr; };
extern "C" char B_003DD490;
extern "C" float g_2dded0[2];
extern "C" float D_FLT_002BE600;
extern "C" float g_2bbb60;
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int func_0020A818(void *, void *);
extern "C" QW PosLoWorld(void *);
extern "C" int IsetFromCloneId(int);
extern "C" int FCheckLm__FP2LMf(void *, float);
extern "C" QW ConvertAloPos(void *, void *, QW);
extern "C" float atan2f(float, float);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void func_00175820(void);
extern "C" void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern "C" void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, void *);
extern "C" void CRef_Destruct(REF *);
extern "C" void func_0020AB68(void *, void *, void *, QW);
extern "C" void SetAlertState(void *, int);
extern "C" void *PsenseFindNotice(char *pguard, char *ptarget, void *pknowledge)
{
    QW posGuard;
    QW posTarget;
    if (*(int *)(pguard + 0xF00) != 0) return 0;
    if (ptarget == 0) return 0;
    if (((*(unsigned long *)(ptarget + 0x28) >> 60) & 1) == 0) return 0;
    if (g_2dded0[0] < *(float *)(pguard + 0xF04)) return 0;
    if (FIsBasicDerivedFrom(ptarget, 0x32) != 0) {
        VTA *vt = (VTA *)((OBJ *)ptarget)->vptr;
        if (vt->fn(ptarget + vt->delta) != 0) return 0;
    }
    if (pknowledge != 0) {
        if (func_0020A818(pknowledge, pguard) == 0) return 0;
    }
    posGuard = PosLoWorld(pguard);
    posTarget = PosLoWorld(ptarget);
    int *ownerTarget = *(int **)(ptarget + 0x3C);
    QW diff;
    int token1, token2, token3;
    float sVertical, sDistance;
    asm("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tvsub.xyzw vf1, vf2, vf3" : "=r" (token1) : "m" (posTarget), "m" (posGuard));
    int idTarget = *ownerTarget;
    asm("vmul.xy vf2, vf1, vf1\n\tvaddy.x vf2, vf2, vf2y\n\tqmfc2.ni %0, vf1" : "=r" (diff) : "r" (token1));
    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=r" (token2) : "r" (diff));
    int upper;
    asm("pextuw %0, $0, %1" : "=r" (upper) : "r" (diff), "r" (token2));
    asm("qmfc2.ni %0, vf2" : "=r" (token3) : "r" (upper));
    asm("mtc1 %1, %0" : "=f" (sVertical) : "r" (upper));
    asm("mtc1 %1, %0" : "=f" (sDistance) : "r" (token3), "f" (sVertical));
    int isetTarget = IsetFromCloneId(idTarget);
    if (isetTarget == IsetFromCloneId(**(int **)(pguard + 0x3C))) {
        if (ptarget < pguard) sDistance += 75.0f;
        else sDistance += -75.0f;
    }
    int mode = *(int *)(pguard + 0xFBC);
    if (mode == 8 || mode == 0xD) {
        char *pscale = *(char **)(pguard + 0xFC4);
        if (pscale != 0) {
            float scale = *(float *)(pscale + 0x20);
            sVertical = sVertical / scale;
            sDistance = sDistance / scale;
        }
    }
    for (int index = 0; index < *(int *)(pguard + 0xEFC); index++) {
        char *psense = ((char **)(pguard + 0xEDC))[index];
        if (*(int *)(psense + 0xA8) == 0) continue;
        if (FCheckLm__FP2LMf(psense + 0x50, sDistance) == 0) continue;
        if (FCheckLm__FP2LMf(psense + 0x58, sVertical) == 0) continue;
        QW local = ConvertAloPos(0, pguard, posTarget);
        int yword;
        asm("prot3w %0, %1" : "=r" (yword) : "r" (local));
        float xf, yf;
        asm("mtc1 %1, %0" : "=f" (xf) : "r" (local));
        asm("mtc1 %1, %0" : "=f" (yf) : "r" (yword));
        float angle = atan2f(yf, xf);
        float *pd = &D_FLT_002BE600;
        float scale = D_FLT_002BE600 + sDistance * (pd[1] + sDistance * pd[2]);
        float *pg = &g_2bbb60;
        if (scale < g_2bbb60) scale = g_2bbb60;
        else if (pg[1] < scale) scale = pg[1];
        float absAngle = __builtin_fabsf(angle);
        if (*(float *)(psense + 0x68) < scale * absAngle) continue;
        int arg;
        if (*(int *)(psense + 0x70) != 0) {
            int aso;
            int cso;
            char lsg[0x60];
            QW line1 = posTarget;
            QW line0 = posGuard;
            char aframe[0x10];
            CStackFrame_Construct(aframe);
            bevy_camera_follow_push_out(&B_003DD490, line0, line1, (void *)func_00175820, psense, &cso, &aso);
            void *phit = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, line0, line1, cso, aso, lsg);
            if (phit != 0) {
                QW d3;
                asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (d3) : "m" (*(QW *)lsg), "m" (line0));
                float len;
                asm("mtc1 %1, %0" : "=f" (len) : "r" (d3));
                if (len < *(float *)(psense + 0x6C)) {
                    CStackFrame_Destructor(aframe, 2);
                    continue;
                }
            }
            CStackFrame_Destructor(aframe, 2);
        }
        {
            char mat[0x40];
            REF ref;
            ref.tagk = 0x17;
            ref.n = 1;
            arg = (int)(psense + 0x18);
            VTG *vt = *(VTG **)(pguard + 0xC);
            vt->fn(pguard + vt->delta, 0x18, 0, 1, &arg, &ref);
            if (ref.tagk != 0x17 || ref.n == 0) {
                CRef_Destruct(&ref);
                continue;
            }
            void *result = psense;
            if (*(int *)(psense + 0x78) != 0) {
                VTT *vtt = *(VTT **)(ptarget + 0xC);
                void *pose = vtt->fn(ptarget + vtt->delta, mat);
                func_0020AB68(pguard, psense, pose, *(QW *)(mat + 0x30));
                result = 0;
                if (pknowledge != 0) SetAlertState(pknowledge, 3);
            }
            CRef_Destruct(&ref);
            return result;
        }
    }
    return 0;
}
