#include "sly2.h"
struct CRef { int tagk; union { int n; float g; float *pg; }; CRef &operator=(const CRef &); };
struct NODE_11FEC8 { int unk0; int unk4; CRef ref; NODE_11FEC8 *next; };
struct ARG_11FEC8 { int tagk; int n; int has; NODE_11FEC8 *first; };
union VF_11FEC8 { float f; QW q; };
extern "C" {
void CRef_SetF32(CRef *, float);
void CRef_SetS32(CRef *, int);
void CRef_RefClone(CRef *, CRef *, int, int);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void __8VU_FLOATf(QW *, float);
void __9VU_VECTORRC6VECTOR(QW *, float *);
QW __ml__FG8VU_FLOATG9VU_VECTOR(QW, QW);
void __as__6VECTORG9VU_VECTOR(float *, QW);
}
/* VU_FLOAT: a float held in lane 0 of a 128-bit general register (mfc1 in, mtc1 out) */
static inline QW WordOf(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
static inline float LaneOf(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
struct VUF_11FEC8 { QW q; VUF_11FEC8(float x) { q = WordOf(x); } float F() const { return LaneOf(q); } };
static inline void ScaleMatrix(float *pmat, float k)
{
    MATRIX4 res;
    float *src = pmat;
    float *dst = &res.mat[0][0];
    for (int i = 0; i < 16; i++)
        dst[i] = k * src[i];
    *(MATRIX4 *)pmat = res;
}
static inline void ScaleMatrixLate(float *pmat, float f)
{
    MATRIX4 res;
    QW vufSlot[1];
    vufSlot[0] = WordOf(f);
    float k = LaneOf(vufSlot[0]);
    float *src = pmat;
    float *dst = &res.mat[0][0];
    for (int i = 0; i < 16; i++)
        dst[i] = k * src[i];
    *(MATRIX4 *)pmat = res;
}
#define SCALEM(p, f) { float vufK; { QW vufSlot[1]; vufSlot[0] = WordOf(f); vufK = LaneOf(vufSlot[0]); } ScaleMatrix(p, vufK); }
static inline void LoadVuFloat(float f)
{
    QW s[1];
    asm volatile("qmtc2.ni %0, vf2" : : "r" (f));
    asm volatile("sqc2 vf2, %0" : "=m" (s[0]));
}
static inline void ScaleClq(float *pclq, float scale)
{
    QW vf, vv;
    __8VU_FLOATf(&vf, scale);
    QW f = vf;
    __9VU_VECTORRC6VECTOR(&vv, pclq);
    __as__6VECTORG9VU_VECTOR(pclq, __ml__FG8VU_FLOATG9VU_VECTOR(f, vv));
}
extern "C" CRef *RefOpDiv(CRef *pret, int carg, ARG_11FEC8 *aref)
{
    CRef acc;
    int fInt = 0;
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
    NODE_11FEC8 *node = 0;
    if (aref->has != 0)
        node = aref->first;
    for (; node != 0; node = node->next) {
        CRef *op = &node->ref;
        switch (acc.tagk) {
        case 0x16: {
            float divisor;
            if (op->tagk != 0x15) {
                if (op->tagk != 0x16)
                    break;
                divisor = op->g;
                fInt = 0;
            } else
                divisor = (float)op->n;
            acc.g = acc.g / divisor;
            break;
        }
        case 0x1A: {
            float *pvec;
            switch (op->tagk) {
            case 0x15: {
                pvec = acc.pg;
                LoadVuFloat(1.0f / (float)op->n);
                break;
            }
            case 0x16: {
                pvec = acc.pg;
                LoadVuFloat(1.0f / op->g);
                break;
            }
            default:
                continue;
            }
            asm volatile("lqc2 vf1, %0" : : "m" (*(QW *)pvec));
            asm volatile("vmulx.xyzw vf2, vf1, vf2x");
            asm volatile("sqc2 vf2, %0" : "=m" (*(QW *)pvec));
            break;
        }
        case 0x1B:
            switch (op->tagk) {
            case 0x15:
                SCALEM(acc.pg, 1.0f / (float)op->n);
                break;
            case 0x16:
                ScaleMatrixLate(acc.pg, 1.0f / op->g);
                break;
            }
            break;
        case 0x1C:
            switch (op->tagk) {
            case 0x15:
                ScaleClq(acc.pg, 1.0f / (float)op->n);
                break;
            case 0x16:
                ScaleClq(acc.pg, 1.0f / op->g);
                break;
            }
            break;
        case 0x1D: {
            float divisor;
            switch (op->tagk) {
            case 0x15:
                divisor = (float)op->n;
                break;
            case 0x16:
                divisor = op->g;
                break;
            default:
                continue;
            }
            float recip = 1.0f / divisor;
            float *plimit = acc.pg;
            plimit[0] = plimit[0] * recip;
            plimit[1] = plimit[1] * recip;
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
