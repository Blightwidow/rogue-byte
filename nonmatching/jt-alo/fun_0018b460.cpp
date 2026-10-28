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
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline QW Word(float f) { QW q; asm volatile("mfc1 %0, %1" : "=r" (q) : "f" (f)); return q; }
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
                float dt = uLook < D_002BF380 ? uLook : D_002BF380;
                PredictXfTransform(*(void **)(*(char **)(*(char **)(jt + 0x10DC) + 0x494) + 0x150), 0, dt, &l.mat, 0);
                register QW c3 asm("vf3") = D_002BF390;
                register QW c5 asm("vf5") = l.mat.row[0];
                register QW c4 asm("vf4") = l.mat.row[1];
                register QW c2 asm("vf2") = l.mat.row[2];
                register QW c1 asm("vf1") = l.mat.row[3];
                register QW c6 asm("vf6");
                asm("vmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddaz.xyz ACC, vf2, vf3z\n\tvmaddw.xyz vf6, vf1, vf0w" : "=j" (c6) : "j" (c3), "j" (c5), "j" (c4), "j" (c2), "j" (c1));
                QW posAim = ConvertXfPos(0, *(void **)(jt + 0x60), c6);
                float radAim = atan2f(-LaneZ(posAim), D_002BF3A0 * LaneX(posAim));
                float radPan = GLimitLm((LM *)D_002BF3A8, radAim);
                QW eulPan = __builtin_pcpyld(Word(zero), __builtin_pextlw(Word(radPan), Word(zero)));
                l.vecAim = eulPan;
                register QW e1 asm("vf1") = *(QW *)(jt + 0x1C10);
                register QW e2 asm("vf2") = eulPan;
                register QW e2o asm("vf2");
                asm("vadd.xyzw vf2, vf1, vf2" : "=j" (e2o) : "j" (e1), "j" (e2));
                LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&l.eul, e2o);
                M4 *pnode = &l.node;
                QW head = *(QW *)(jt + 0x1C00);
                __as__6VECTORG9VU_VECTOR(&l.node.row[3], head);
                l.node.row[0] = l.eul.row[0];
                pnode->row[1] = l.eul.row[1];
                pnode->row[2] = l.eul.row[2];
                ((float *)&l.node.row[0])[3] = zero;
                ((float *)&l.node.row[1])[3] = zero;
                ((float *)&l.node.row[2])[3] = zero;
                ((float *)&pnode->row[3])[3] = 1.0f;
                char *part = *(char **)(*(char **)(jt + 0x19A0) + 0x58);
                register QW a6 asm("vf6");
                asm("qmtc2.ni %1, vf6" : "=j" (a6) : "r" (posAim));
                register QW n4 asm("vf4") = *(QW *)(jt + 0x1C20);
                register QW n2 asm("vf2") = l.node.row[2];
                register QW n5 asm("vf5") = l.node.row[0];
                register QW n3 asm("vf3") = l.node.row[1];
                register QW n1 asm("vf1") = l.node.row[3];
                register QW h1 asm("vf1");
                asm("vmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddaz.xyz ACC, vf2, vf4z\n\tvmaddw.xyz vf1, vf1, vf0w" : "=j" (h1) : "j" (n4), "j" (n2), "j" (n5), "j" (n3), "j" (n1));
                void *pxfShift = *(void **)(part + 0xA0);
                register QW t6 asm("vf6");
                asm("vsub.xyzw vf6, vf6, vf1" : "=j" (t6) : "j" (a6), "j" (h1));
                asm volatile("sqc2 vf6, %0" : "=m" (l.toAim) : "j" (t6));
                float xShift = LaneX(ConvertXfVec(*(void **)(jt + 0x60), pxfShift, l.toAim));
                float sShift = GLimitLm((LM *)D_002BF3B0, xShift);
                QW vecShift = Word(sShift);
                vecShift = __builtin_pextlw(Word(zero), vecShift);
                vecShift = __builtin_pcpyld(Word(zero), vecShift);
                l.vecAim = vecShift;
                QW conv = ConvertXfVec(pxfShift, *(void **)(jt + 0x60), vecShift);
                register QW f1 asm("vf1") = l.toAim;
                register QW f2 asm("vf2");
                asm("qmtc2.ni %1, vf2\n\tvsub.xyzw vf2, vf1, vf2" : "=j" (f2) : "r" (conv), "j" (f1));
                l.dposFree = f2;
                register QW r1 asm("vf1") = *(QW *)(jt + 0x1C00);
                register QW r2 asm("vf2") = *(QW *)(jt + 0x1BF0);
                float dist;
                int bits;
                asm("vadd.xyzw vf1, vf1, vf2" : "=j" (r1) : "j" (r1), "j" (f2));
                asm("vsub.xyzw vf1, vf1, vf2" : "=j" (r1) : "j" (r1), "j" (r2));
                asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "j" (r1));
                asm("mtc1 %1, %0" : "=f" (dist) : "r" (bits));
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
    if (uFade < dtLeftAfter)
        uFade = dtLeftAfter / dtLeft;
    int uBits;
    asm("mfc1 %0, %1" : "=r" (uBits) : "f" (uFade));
    l.uFadeQ = uBits;
    char *act = *(char **)(jt + 0x19F8);
    QW scaled;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r" (scaled) : "r" (l.uFadeQ), "m" (*(QW *)(act + 0x20)));
    SetActadjOffset(act, scaled);
    act = *(char **)(jt + 0x19EC);
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r" (scaled) : "r" (l.uFadeQ), "m" (*(QW *)(act + 0x20)));
    SetActadjOffset(act, scaled);
    act = *(char **)(jt + 0x19FC);
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r" (scaled) : "r" (l.uFadeQ), "m" (*(QW *)(act + 0x20)));
    SetActadjOffset(act, scaled);
    *(int *)(jt + 0x1BD4) = 0;
}
