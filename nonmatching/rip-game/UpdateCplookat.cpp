#include "sly2.h"
struct Frame {
    QW vecAB;
    QW posFocus;
    QW posEye;
    QW posCamera;
    QW sBack;
    QW matCamera[4];
    QW matLook[3];
    QW posA;
    QW weight;
    QW posA2;
    QW oneMinus;
};
struct SO;
struct Cplookat { char pad[0x10]; SO *psoA; SO *psoB; };
static inline float GPoly(float s, const float *a, const float *r)
{
    float v = a[0] + s * (a[1] + s * a[2]);
    if (v < r[0]) return r[0];
    if (r[1] < v) return r[1];
    return v;
}
extern "C" {
extern float D_002BDACC;
extern float D_FLT_002BDAD0[3];
extern float D_FLT_002BDAE0[2];
extern float D_FLT_002BDAF0[3];
extern float D_FLT_002BDB00[2];
extern float D_FLT_002BDB10[3];
extern float D_FLT_002BDB20[2];
extern float D_FLT_002BDB30[3];
extern float D_FLT_002BDB40[2];
extern QW g_2a2dc0;
extern char B_002DDF40;
void UpdateCplcy(void *);
QW PosLoWorld(SO *);
void LoadLookAtMatrix(QW *, QW);
QW *__as__6VECTORG9VU_VECTOR(QW *, QW);
void SetCmPosMat(void *, QW *);
void SetCmFov(void *, float);
void UpdateCplookat(Cplookat *pcp)
{
    Frame f;
    UpdateCplcy(pcp);
    f.posA = PosLoWorld(pcp->psoA);
    QW posB = PosLoWorld(pcp->psoB);
        asm("qmtc2.ni %3, vf3\n\tlqc2 vf2, %2\n\tlw %1, %4\n\tvsub.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m"(f.vecAB), "=r"(f.posEye) : "m"(f.posA), "r"(posB), "m"(D_002BDACC));
    f.weight = f.posEye;
    ((float *)&f.vecAB)[2] = 0;
    float sHorizontal;
    asm("lqc2 vf1, %1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(sHorizontal) : "m"(f.vecAB));
    f.posA2 = PosLoWorld(pcp->psoA);
    float oneMinus = 1.0f - D_002BDACC;
    asm("mfc1 %0, %1" : "=r"(f.posEye) : "f"(oneMinus));
    f.oneMinus = f.posEye;
    QW posB2 = PosLoWorld(pcp->psoB);
    asm("qmtc2.ni %2, vf5\n\tlqc2 vf2, %3\n\tlqc2 vf3, %4\n\tlqc2 vf4, %5\n\tvmulax.xyzw ACC, vf3, vf2x\n\tvmaddx.xyzw vf1, vf5, vf4x\n\tsqc2 vf1, %0" : "=m"(f.posFocus), "=m"(f.posFocus) : "r"(posB2), "m"(f.weight), "m"(f.posA2), "m"(f.oneMinus));
    ((float *)&f.posFocus)[2] = 150.0f;
    f.posEye = f.posFocus;
    float height = D_FLT_002BDAD0[0] + sHorizontal * (D_FLT_002BDAD0[1] + sHorizontal * D_FLT_002BDAD0[2]);
    if (height < D_FLT_002BDAE0[0]) height = D_FLT_002BDAE0[0];
    else if (D_FLT_002BDAE0[1] < height) height = D_FLT_002BDAE0[1];
    ((float *)&f.posEye)[2] += height;
    float back = D_FLT_002BDAF0[0] + sHorizontal * (D_FLT_002BDAF0[1] + sHorizontal * D_FLT_002BDAF0[2]);
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf1, vf2, vf1\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf1, vf1, Q" : "=m"(f.sBack) : "m"(g_2a2dc0), "m"(f.vecAB));
    if (back < D_FLT_002BDB00[0]) back = D_FLT_002BDB00[0];
    else if (D_FLT_002BDB00[1] < back) back = D_FLT_002BDB00[1];
    QW backBits;
    asm("mfc1 %0, %1" : "=r"(backBits) : "f"(back));
    asm("qmtc2.ni %1, vf3\n\tvmulx.xyzw vf2, vf1, vf3x\n\tlqc2 vf1, %2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf3, %3\n\tsqc2 vf1, %0" : "=m"(f.posCamera) : "r"(backBits), "m"(f.posFocus), "m"(f.sBack));
    float rise = D_FLT_002BDB10[0] + sHorizontal * (D_FLT_002BDB10[1] + sHorizontal * D_FLT_002BDB10[2]);
    if (rise < D_FLT_002BDB20[0]) rise = D_FLT_002BDB20[0];
    else if (D_FLT_002BDB20[1] < rise) rise = D_FLT_002BDB20[1];
    ((float *)&f.posCamera)[2] += rise;
    QW look;
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf3, vf2, vf1\n\tqmfc2.ni %0, vf3" : "=r"(look) : "m"(f.posEye), "m"(f.posCamera));
    LoadLookAtMatrix(f.matLook, look);
    __as__6VECTORG9VU_VECTOR(&f.matCamera[3], f.posCamera);
    f.matCamera[0] = f.matLook[0];
    f.matCamera[1] = f.matLook[1];
    f.matCamera[2] = f.matLook[2];
    ((float *)f.matCamera)[3] = 0;
    ((float *)f.matCamera)[7] = 0;
    ((float *)f.matCamera)[11] = 0;
    ((float *)f.matCamera)[15] = 1.0f;
    SetCmPosMat(&B_002DDF40, f.matCamera);
    float fov = D_FLT_002BDB30[0] + sHorizontal * (D_FLT_002BDB30[1] + sHorizontal * D_FLT_002BDB30[2]);
    if (fov < D_FLT_002BDB40[0]) fov = D_FLT_002BDB40[0];
    else if (D_FLT_002BDB40[1] < fov) fov = D_FLT_002BDB40[1];
    SetCmFov(&B_002DDF40, fov);
}
}
