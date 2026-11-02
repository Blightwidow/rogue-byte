#include "sly2.h"
struct VT { char pad[0x10]; short delta; short unused; void (*fn)(void *, void *); };
struct VT1 { char pad[0x10]; short delta; short unused; void (*fn)(void *); };
struct SOBJ1 { VT1 *vt; };
struct SOBJ { VT *vt; };
struct CDEF { char pad0[0x74]; float total; char pad1[0x48]; int stride; int count; char *base; char pad2[8]; int index; };
struct MIDX { int off; int param; char *table; };
struct ACSB { char pad0[4]; CDEF *pdef; MIDX *pm; SOBJ **apobj; QW vec; };
struct ELT { float weight; CDEF *pdef; };
struct OUT {
    char pad0[0x80]; int i80; float f84; float *p88; float *p8C; char pad1[0xA]; short s9A; char pad2[0x24];
    QW q0; union { QW qD0; struct { int d0, d4, d8; }; }; QW qE0; int f0, f4, f8;
};
struct FRAME {
    QW pos; float v10, v14, v18; int pad1C;
    char blk[0x100];
};
extern "C" void EvaluateBezierPos__FfffP6VECTORN63(QW, QW, QW, QW, float, float, float, void *, void *, int);
extern "C" int ImrsgLookUp__FffiP4MRSGPf(float, float, int, void *, float *);
extern "C" void EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3(ACSB *pacsb, OUT *pout)
{
    char sp[0x160] __attribute__((aligned(16)));
    CDEF *pdef = pacsb->pdef;
    int index = pdef->index;
    if (index >= 0) {
        SOBJ *pobj = pacsb->apobj[index];
        if (pobj != 0) {
            VT1 *vt = ((SOBJ1 *)pobj)->vt;
            vt->fn((char *)pobj + vt->delta);
        } else {
            QW vec = pacsb->vec;
            pout->s9A = 2;
            int *pa = &pout->d0;
            *pa = 0;
            int *pf = &pout->f0;
            pout->q0 = vec;
            pout->i80 = 0;
            pa[1] = 0;
            pf[2] = 0;
            pa[2] = 0;
            pout->p8C = &pout->f84;
            pf[1] = 0;
            pout->p88 = (float *)&pout->i80;
            *pf = 0;
            pout->f84 = 1.0f;
            pout->qE0 = vec;
        }
        return;
    }
    MIDX *pm = pacsb->pm;
    float rate = *pout->p88;
    int imrsg = 0;
    float ratio;
    if (pm == 0) {
        ratio = rate / pdef->total;
    } else {
        imrsg = ImrsgLookUp__FffiP4MRSGPf(rate, pdef->total, pm->param, pm->table, (float *)(sp + 0x130));
        ratio = *(float *)(sp + 0x130) / *(float *)(pacsb->pm->table + imrsg * 8 + 4);
    }
    asm volatile("vsub.xyzw vf1, vf0, vf0");
    asm volatile("sqc2 vf1, 0x140(%0)" : : "r"(sp));
    QW zero;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(zero));
    *(QW *)(sp + 0x150) = zero;
    int cbez = 0;
    CDEF *pd = pacsb->pdef;
    if (pd->count > 0) {
        do {
            ELT *pelt = (ELT *)(pd->base + cbez * pd->stride);
            if (pelt->weight != 0.0f) {
                SOBJ *pobj = pacsb->apobj[cbez];
                float len;
                if (pobj == 0) {
                    *(float *)(sp + 0x10) = 0.0f;
                    *(float *)(sp + 0x18) = 0.0f;
                    *(float *)(sp + 0x14) = 0.0f;
                    *(QW *)sp = pacsb->vec;
                } else {
                    MIDX *pmidx = pacsb->pm;
                    float pos;
                    if (pmidx == 0) {
                        float total = pelt->pdef->total;
                        len = total / pacsb->pdef->total;
                        *(float *)(sp + 0x134) = ratio * total;
                    } else {
                        int off = imrsg * 8;
                        char *ent = (char *)pelt + pmidx->off + off;
                        float total = pelt->pdef->total;
                        float step = *(float *)(ent + 4);
                        pos = *(float *)ent + ratio * step;
                        *(float *)(sp + 0x134) = pos;
                        if (total < pos)
                            *(float *)(sp + 0x134) = pos - total;
                        len = step / *(float *)(pmidx->table + off + 4);
                    }
                    memset(sp + 0x20, 0, 0x100);
                    *(float **)(sp + 0xA8) = (float *)(sp + 0x134);
                    VT *vt = pobj->vt;
                    vt->fn((char *)pobj + vt->delta, sp + 0x20);
                    float base = *(float *)(sp + 0xA0);
                    EvaluateBezierPos__FfffP6VECTORN63(*(QW *)(sp + 0xE0), *(QW *)(sp + 0xF0), *(QW *)(sp + 0x100), *(QW *)(sp + 0x110),
                        *(float *)(sp + 0xA4) - base, *(float *)(sp + 0x134) - base, len, sp, sp + 0x10, 0);
                }
                asm volatile("qmtc2.ni %0, vf1" : : "r"(*(int *)pelt));
                asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x140(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf3, vf0");
                asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
                asm volatile("sqc2 vf1, 0x120(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x140(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0x150(%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf2, vf0");
                asm volatile("vmaddx.xyzw vf2, vf3, vf1x");
                asm volatile("sqc2 vf2, 0x150(%0)" : : "r"(sp));
            }
            cbez += 1;
            pd = pacsb->pdef;
        } while (cbez < pd->count);
    }
    pout->s9A = 4;
    pout->q0 = *(QW *)(sp + 0x140);
    pout->qD0 = *(QW *)(sp + 0x150);
}
