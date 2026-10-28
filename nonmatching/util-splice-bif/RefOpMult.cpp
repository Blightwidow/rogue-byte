#include "sly2.h"
struct CRef { int tagk; union { int n; float g; void *pv; }; CRef &operator=(const CRef &); };
struct Node { int pad0; int pad4; CRef ref; Node *next; };
struct ArgBlock { CRef first; int hasExtra; Node *head; };
extern "C" void CRef_SetF32(CRef *, float);
extern "C" void CRef_SetS32(CRef *, int);
extern "C" void CRef_RefClone(CRef *, CRef *, int, int);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_SetVector(CRef *, QW);
extern "C" void CRef_SetMatrixPtr(CRef *, void *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *MulMatrix4(MATRIX4 *, const MATRIX4 *, const MATRIX4 *);

#define acc l.a_
#define temp l.t_
#define saved l.s_
#define scaled l.sc_
#define m l.m_
CRef *RefOpMult(CRef *pref, int unused, ArgBlock *aref)
{
    struct L { CRef a_; int p0, p1; CRef t_; int p2, p3; QW s_; float sc_[16]; MATRIX4 m_; QW extra[2]; } l;
    int fInt = 0;
    float *pacc = 0;
    acc.tagk = -1;
    switch (aref->first.tagk) {
    case 0x15:
        fInt = 1;
        CRef_SetF32(&acc, (float)aref->first.n);
        break;
    case 0x16:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D: {
        CRef_RefClone(&temp, &aref->first, 0, 0);
        acc = temp;
        CRef_Destruct(&temp);
        break;
    }
    }
    Node *node = aref->hasExtra ? aref->head : 0;
    CRef *op;
    for (; node; node = node->next) {
        op = &node->ref;
        switch (acc.tagk) {
        case 0x16:
            switch (op->tagk) {
            case 0x15:
                acc.g = acc.g * (float)op->n;
                break;
            case 0x16:
                fInt = 0;
                acc.g = acc.g * op->g;
                break;
            case 0x1A: {
                int bits, t1, t2;
                QW vecOut;
                float scale = acc.g;
                asm("mfc1 %0, %1" : "=r"(bits) : "f"(scale));
                asm("qmtc2.ni %1, vf2" : "=r"(t1) : "r"(bits));
                asm("sqc2 vf2, %1" : "=r"(t2), "=m"(saved) : "r"(t1));
                asm("lqc2 vf1, 0(%1)\n\tvmulx.xyzw vf3, vf1, vf2x" : "=r"(t1) : "r"(op->pv), "r"(t2));
                asm("qmfc2.ni %0, vf3" : "=r"(vecOut) : "r"(t1));
                CRef_SetVector(&acc, vecOut);
                break;
            }
            case 0x1B: {
                float *src = (float *)op->pv;
                for (int i = 0; i < 16; i++)
                    scaled[i] = acc.g * src[i];
                CRef_SetMatrixPtr(&acc, scaled);
                break;
            }
            case 0x1C: {
                float scale = acc.g;
                CRef_Destruct(&acc);
                SetTag__4CRef4TAGK(&acc, 0x1C);
                float *src = (float *)op->pv;
                float *dst = (float *)acc.pv;
                dst[0] = src[0] * scale; dst[1] = src[1] * scale; dst[2] = src[2] * scale; dst[3] = src[3] * scale;
                break;
            }
            case 0x1D: {
                float scale = acc.g;
                CRef_Destruct(&acc);
                SetTag__4CRef4TAGK(&acc, 0x1D);
                float *src = (float *)op->pv;
                float *dst = (float *)acc.pv;
                dst[0] = src[0] * scale; dst[1] = src[1] * scale;
                break;
            }
            }
            break;
        case 0x1A:
        case 0x1C: {
            float s;
            if (op->tagk == 0x16) s = op->g;
            else if (op->tagk == 0x15) s = (float)op->n;
            else break;
            float *dst = (float *)acc.pv;
            dst[0] *= s; dst[1] *= s; dst[2] *= s; dst[3] *= s;
            break;
        }
        case 0x1B: {
            float s;
            float *dst = pacc = (float *)acc.pv;
            if (op->tagk == 0x16 || op->tagk == 0x15) {
                s = op->tagk == 0x16 ? op->g : (float)op->n;
                for (int i = 0; i < 16; i++) scaled[i] = s * dst[i];
                for (int i = 0; i < 16; i++) dst[i] = scaled[i];
            } else if (op->tagk == 0x1A) {
                MulMatrix4(&m, (MATRIX4 *)dst, (MATRIX4 *)op->pv);
                *(MATRIX4 *)dst = m;
            }
            break;
        }
        case 0x1D: {
            float s;
            if (op->tagk == 0x16) s = op->g;
            else if (op->tagk == 0x15) s = (float)op->n;
            else break;
            float *dst = (float *)acc.pv;
            dst[0] *= s; dst[1] *= s;
            break;
        }
        }
    }
    if (fInt && acc.tagk == 0x16)
        CRef_SetS32(&acc, (int)acc.g);
    CRef_CopyConstruct(pref, &acc);
    CRef_Destruct(&acc);
    return pref;
}
