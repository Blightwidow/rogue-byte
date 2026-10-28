#include "sly2.h"
struct CRef { int tagk; union { int n; float g; float *pg; }; CRef &operator=(const CRef &); };
struct NODE { int unk0; int unk4; CRef ref; NODE *next; };
struct ARG { int tagk; int n; int has; NODE *first; };
struct M4 { QW q[4]; };
extern "C" {
void CRef_SetF32(CRef *, float);
void CRef_SetS32(CRef *, int);
void CRef_RefClone(CRef *, CRef *, int, int);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void __8VU_FLOATf(QW *, float);
void __9VU_VECTORRC6VECTOR(QW *, void *);
QW __ml__FG8VU_FLOATG9VU_VECTOR(QW, QW);
void __as__6VECTORG9VU_VECTOR(void *, QW);
}
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" CRef *RefOpDiv(CRef *pret, int carg, ARG *aref)
{
    CRef acc;
    int fInt = 0;
    QW scalarA, vectorA, scalarB, vectorB;
    acc.tagk = -1;
    switch (aref->tagk) {
    case 0x15:
        CRef_SetF32(&acc, (float)aref->n);
        fInt = 1;
        break;
    case 0x16:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D: {
        CRef tmp;
        CRef_RefClone(&tmp, (CRef *)aref, 0, 0);
        acc = tmp;
        CRef_Destruct(&tmp);
        break;
    }
    }
    NODE *node = 0;
    if (aref->has != 0)
        node = aref->first;
    for (; node != 0; node = node->next) {
        CRef *operand = &node->ref;
        switch (acc.tagk) {
        case 0x16: {
            float divisor;
            if (operand->tagk != 0x15) {
                if (operand->tagk != 0x16) break;
                divisor = operand->g;
                fInt = 0;
            } else
                divisor = (float)operand->n;
            float current;
            asm("lwc1 %0, %1\n\tnop" : "=f" (current) : "m" (acc.g));
            acc.g = current / divisor;
            break;
        }
        case 0x1A: {
            register QW v2 asm("vf2");
            float *pvec;
            switch (operand->tagk) {
            case 0x15: {
                QW junkA[1];
                float divisor = (float)operand->n;
                pvec = acc.pg;
                float recip = 1.0f / divisor;
                asm("mfc1 $3, %1\n\tqmtc2.ni $3, vf2" : "=j" (v2) : "f" (recip) : "$3");
                asm("sqc2 vf2, %0" : "=m" (junkA[0]) : "j" (v2));
                break;
            }
            case 0x16: {
                QW junkB[1];
                float divisor = operand->g;
                pvec = acc.pg;
                float recip = 1.0f / divisor;
                asm("mfc1 $3, %1\n\tqmtc2.ni $3, vf2" : "=j" (v2) : "f" (recip) : "$3");
                asm("sqc2 vf2, %0" : "=m" (junkB[0]) : "j" (v2));
                break;
            }
            default:
                continue;
            }
            asm volatile("lqc2 vf1, 0(%1)\n\tvmulx.xyzw vf2, vf1, vf2x" : "+j" (v2) : "r" (pvec) : "memory");
            asm volatile("sqc2 vf2, %0" : "=m" (*(QW *)pvec) : "j" (v2));
            break;
        }
        case 0x1B: {
            if (operand->tagk == 0x15) {
                QW junk[1];
                float scaled[16];
                float recip = 1.0f / (float)operand->n;
                float *pmat = acc.pg;
                QW wide = Word(recip);
                junk[0] = wide;
                asm("" : : "m" (junk[0]));
                float scale = Lane(wide);
                float *src = pmat;
                register float *dst asm("$4") = scaled;
                register int count asm("$6") = 15;
                do {
                    *dst++ = scale * *src++;
                } while (--count >= 0);
                *(M4 *)pmat = *(M4 *)scaled;
            } else if (operand->tagk == 0x16) {
                float scaled[16];
                QW junk[1];
                float recip = 1.0f / operand->g;
                float *pmat = acc.pg;
                QW wide = Word(recip);
                junk[0] = wide;
                asm("" : : "m" (junk[0]));
                float scale = Lane(wide);
                float *src = pmat;
                register float *dst asm("$4") = scaled;
                register int count asm("$6") = 15;
                do {
                    *dst++ = scale * *src++;
                } while (--count >= 0);
                *(M4 *)pmat = *(M4 *)scaled;
            }
            break;
        }
        case 0x1C: {
            if (operand->tagk == 0x15) {
                float recip = 1.0f / (float)operand->n;
                float *pclq = acc.pg;
                __8VU_FLOATf(&scalarA, recip);
                QW scalarCopy = scalarA;
                __9VU_VECTORRC6VECTOR(&vectorA, pclq);
                QW product = __ml__FG8VU_FLOATG9VU_VECTOR(scalarCopy, vectorA);
                __as__6VECTORG9VU_VECTOR(pclq, product);
            } else if (operand->tagk == 0x16) {
                float recip = 1.0f / operand->g;
                float *pclq = acc.pg;
                __8VU_FLOATf(&scalarB, recip);
                QW scalarCopy = scalarB;
                __9VU_VECTORRC6VECTOR(&vectorB, pclq);
                QW product = __ml__FG8VU_FLOATG9VU_VECTOR(scalarCopy, vectorB);
                __as__6VECTORG9VU_VECTOR(pclq, product);
            }
            break;
        }
        case 0x1D: {
            float divisor;
            if (operand->tagk == 0x15) divisor = (float)operand->n;
            else if (operand->tagk == 0x16) divisor = operand->g;
            else break;
            float recip = 1.0f / divisor;
            float *plimit = acc.pg;
            float low = plimit[0];
            float high = plimit[1];
            plimit[0] = low * recip;
            plimit[1] = high * recip;
            break;
        }
        }
    }
    if (fInt != 0 && acc.tagk == 0x16)
        CRef_SetS32(&acc, (int)acc.g);
    CRef_CopyConstruct(pret, &acc);
    CRef_Destruct(&acc);
    return pret;
}
