#include "sly2.h"
struct M3 { QW row[3]; };
struct M4 { QW row[4]; };
struct LM;
struct ASEGA { char pad[0x1C]; float field1c; char pad1[0x20]; float field40; };
struct JT { char pad[0x60]; void *pxfRoot; };
extern "C" {
QW ConvertXfPos(void *, void *, QW);
QW ConvertXfVec(void *, void *, QW);
void PredictXfTransform(void *, void *, float, M4 *, void *);
void func_002046F0(void *, void *);
void SetActadjOffset(void *, QW);
float atan2f(float, float);
void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(M3 *, QW);
void __as__6VECTORG9VU_VECTOR(void *, QW);
}
float GLimitLm(LM *, float);
extern const float D_002BF380;
extern const float D_002BF3A0;
extern const float D_002BF3BC;
extern const float D_002BF3B8;
extern QW D_002BF390;
extern char D_002BF3A8[];
extern char D_002BF3B0[];
extern float g_2dded0[];
// lane 0 of a QW into an FP register
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
// same, with the assembler hazard nop retail has before a direct use of the register
static inline float LaneXNop(QW q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
// float into lane 0 of a QW (mfc1 writes the low word, sign-extended)
static inline QW QwFromFloat(float f) { QW q; asm("mfc1 %0, %1" : "=r" (q) : "f" (f)); return q; }
static inline float LaneZ(QW q) { float f; asm("pextuw %0, $0, %1" : "=r" (f) : "r" (q)); return f; }
// (0, low, 0, 0)-style builders: mfc1 each float into a GPR, pextlw packs words 0/1, pcpyld sets the high doubleword
static inline QW Pextlw(float low, float high) { QW q; long t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0" : "=&r" (q), "=&r" (t) : "f" (low), "f" (high)); return q; }
static inline QW Pcpyld(float high, QW low) { long t; asm("mfc1 %1, %2\n\tpcpyld %0, %1, %0" : "+r" (low), "=&r" (t) : "f" (high)); return low; }
struct LOC {
    M4 mat;       // 0x00 (lq/vector input at 0)
    M4 node;      // 0x40
    QW vecAim;    // 0x80
    M3 eul;       // 0x90
    QW toAim;     // 0xC0
    QW dposFree;  // 0xD0
    QW uFadeQ;    // 0xE0
};
void func_0018B460(char *jt)
{
    LOC l;
    ASEGA *pasega = *(ASEGA **)(jt + 0x1030);
    float uLook = (*(float *)(jt + 0x1BD8) - pasega->field1c) / pasega->field40;
    char *ploFocus = *(char **)(jt + 0x10DC);
    if (ploFocus) {
        void *ploLook = *(void **)(ploFocus + 0x494);
        if (ploLook) {
            float zero = 0.0f;
            if (zero < uLook) {
                func_002046F0(jt, ploLook);
                float dt = D_002BF380 < uLook ? D_002BF380 : uLook;
                PredictXfTransform(*(void **)(*(char **)(*(char **)(jt + 0x10DC) + 0x494) + 0x150), 0, dt, &l.mat, 0);
                asm("lqc2 vf5, %0" : : "m" (l.mat.row[0]));
                asm("lqc2 vf4, %0" : : "m" (l.mat.row[1]));
                asm("lqc2 vf2, %0" : : "m" (l.mat.row[2]));
                asm("lqc2 vf1, %0" : : "m" (l.mat.row[3]));
                asm("lqc2 vf3, %0" : : "m" (D_002BF390));
                asm("vmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddaz.xyz ACC, vf2, vf3z\n\tvmaddw.xyz vf6, vf1, vf0w");
                QW c6;
                asm("qmfc2.ni %0, vf6" : "=r" (c6));
                QW posAim = ConvertXfPos(0, *(void **)(jt + 0x60), c6);
                float radAim = atan2f(-LaneZ(posAim), D_002BF3A0 * LaneXNop(posAim));
                float radPan = GLimitLm((LM *)D_002BF3A8, radAim);
                QW eulPan = Pcpyld(zero, Pextlw(zero, radPan));
                asm("lqc2 vf1, %0" : : "m" (*(QW *)(jt + 0x1C10)));
                asm("qmtc2.ni %0, vf2" : : "r" (eulPan));
                asm("vadd.xyzw vf2, vf1, vf2");
                l.vecAim = eulPan;
                QW e2o;
                asm("qmfc2.ni %0, vf2" : "=r" (e2o));
                                LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&l.eul, e2o);
                M4 *pnode = &l.node;
                QW head = *(QW *)(jt + 0x1C00);
                __as__6VECTORG9VU_VECTOR(&l.node.row[3], head);
                l.node.row[0] = l.eul.row[0];
                pnode->row[1] = l.eul.row[1];
                pnode->row[2] = l.eul.row[2];
                ((float *)&l.node.row[2])[3] = zero;
                ((float *)&l.node.row[1])[3] = zero;
                ((float *)&l.node.row[0])[3] = zero;
                ((float *)&pnode->row[3])[3] = 1.0f;
                char *part = *(char **)(*(char **)(jt + 0x19A0) + 0x58);
                asm("qmtc2.ni %0, vf6" : : "r" (posAim));
                asm("lqc2 vf4, %0" : : "m" (*(QW *)(jt + 0x1C20)));
                asm("lqc2 vf2, %0" : : "m" (l.node.row[2]));
                asm("lqc2 vf5, %0" : : "m" (l.node.row[0]));
                asm("lqc2 vf3, %0" : : "m" (l.node.row[1]));
                asm("lqc2 vf1, %0" : : "m" (l.node.row[3]));
                asm("vmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddaz.xyz ACC, vf2, vf4z\n\tvmaddw.xyz vf1, vf1, vf0w");
                                void *pxfShift = *(void **)(part + 0xA0);
                asm("vsub.xyzw vf6, vf6, vf1");
                asm volatile("sqc2 vf6, %0" : "=m" (l.toAim));
                float xShift = LaneX(ConvertXfVec(*(void **)(jt + 0x60), pxfShift, l.toAim));
                float sShift = GLimitLm((LM *)D_002BF3B0, xShift);
                QW vecShift = Pcpyld(zero, Pextlw(sShift, zero));
                l.vecAim = vecShift;
                QW conv = ConvertXfVec(pxfShift, *(void **)(jt + 0x60), vecShift);
                asm("lqc2 vf1, %0" : : "m" (l.toAim));
                asm("qmtc2.ni %0, vf2\n\tvsub.xyzw vf2, vf1, vf2" : : "r" (conv));
                asm("sqc2 vf2, %0" : "=m" (l.dposFree));
                asm("lqc2 vf1, %0" : : "m" (*(QW *)(jt + 0x1C00)));
                asm("vadd.xyzw vf1, vf1, vf2");
                asm("lqc2 vf2, %0" : : "m" (*(QW *)(jt + 0x1BF0)));
                asm("vsub.xyzw vf1, vf1, vf2");
                QW distBits;
                asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (distBits));
                float dist = LaneXNop(distBits);
                                int inReach = dist < D_002BF3B8;
                if (inReach) {
                    SetActadjOffset(*(void **)(jt + 0x19F8), eulPan);
                    SetActadjOffset(*(void **)(jt + 0x19EC), l.dposFree);
                    SetActadjOffset(*(void **)(jt + 0x19FC), vecShift);
                    *(int *)(jt + 0x1BD4) = 1;
                    *(float *)(jt + 0x1BDC) = g_2dded0[0];
                    return;
                }
            }
        }
    }
    float dtLeft = *(float *)(jt + 0x1BDC) + D_002BF3BC - g_2dded0[0];
    float dtLeftAfter = dtLeft - g_2dded0[1];
    float uFade = 0.0f;
    if (0.0f < dtLeftAfter)
        uFade = dtLeftAfter / dtLeft;
    l.uFadeQ = QwFromFloat(uFade);
    char *act = *(char **)(jt + 0x19F8);
    QW scaled;
    QW uf = l.uFadeQ;
    l.mat.row[0] = uf;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r" (scaled) : "r" (uf), "m" (*(QW *)(act + 0x20)));
    SetActadjOffset(act, scaled);
    act = *(char **)(jt + 0x19EC);
    uf = l.uFadeQ;
    l.mat.row[0] = uf;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r" (scaled) : "r" (uf), "m" (*(QW *)(act + 0x20)));
    SetActadjOffset(act, scaled);
    act = *(char **)(jt + 0x19FC);
    uf = l.uFadeQ;
    l.mat.row[0] = uf;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r" (scaled) : "r" (uf), "m" (*(QW *)(act + 0x20)));
    SetActadjOffset(act, scaled);
    *(int *)(jt + 0x1BD4) = 0;
}
