#include "sly2.h"
struct M4 { QW row[4]; };
struct M3 { QW row[3]; };
struct Frame { M4 a; M4 b; M4 c; QW shake; };
struct Cm { char pad[0x618]; float tJolt; };
extern "C" {
extern float g_2dded0;
extern float D_FLT_002BD850;
extern float D_FLT_002BD854;
extern float D_002BD860[3];
extern float g_2bbb60[2];
extern QW D_002BD880;
extern QW D_002BD870;
extern QW D_002BD890;
extern QW D_002BD8A0;
extern QW RO_002A2DE0;
void CombineEyeLookAtProj(M4 *, M4 *, M4 *);
void BuildFrustrum(float, float, M4 *, M4 *);
void BuildSimpleProjectionMatrix__FffffffP7MATRIX4(float, float, float, float, float, float, M4 *);
void FInvertMatrix4__FP7MATRIX4T0(M4 *, M4 *);
void LoadRotateMatrix(M4 *, QW);
M4 *__as__6VECTORG9VU_VECTOR(M4 *, QW);
void MulMat(M4 *, const M4 *, const M4 *) asm("__ml__FRC7MATRIX4T0");
void func_0014E078(Cm *);
float sinf(float);
void UpdateCmMat4(Cm *pcm)
{
    char *base = (char *)pcm;
    float dt = g_2dded0 - pcm->tJolt;
    M4 *pmatCam = (M4 *)(base + 0x60);
    M4 *pmatProj = (M4 *)(base + 0x100);
    M4 *pmatWorldToClip = (M4 *)(base + 0x140);
    if (D_FLT_002BD850 < dt) {
        CombineEyeLookAtProj(pmatCam, pmatProj, pmatWorldToClip);
    } else {
        float u = dt / D_FLT_002BD850;
        float env = D_002BD860[0] + u * (D_002BD860[1] + u * D_002BD860[2]);
        if (env < g_2bbb60[0])
            env = g_2bbb60[0];
        else if (g_2bbb60[1] < env)
            env = g_2bbb60[1];
        float shake = sinf(dt * D_FLT_002BD854) * env;
        Frame fr;
        M4 &matShake = fr.a;
        M4 &matRoll = fr.b;
        QW qShake;
        asm("mfc1 %0, %1" : "=r"(qShake) : "f"(shake));
        fr.shake = qShake;
        QW rot;
        asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r"(rot) : "r"(qShake), "m"(D_002BD880));
        LoadRotateMatrix(&matRoll, rot);
        QW move;
        asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvmulx.xyzw vf2, vf1, vf2x\n\tqmfc2.ni %0, vf2" : "=r"(move) : "r"(qShake), "m"(D_002BD870));
        __as__6VECTORG9VU_VECTOR((M4 *)&matShake.row[3], move);
        matShake.row[0] = matRoll.row[0];
        matShake.row[1] = matRoll.row[1];
        matShake.row[2] = matRoll.row[2];
        float *pw = (float *)&matShake;
        pw[3] = 0; pw[7] = 0; pw[11] = 0;
        pw[15] = 1.0f;
        MulMat(&fr.b, pmatCam, &matShake);
        fr.a = fr.b;
        asm("lqc2 vf3, %2\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf2, vf3x\n\tsqc2 vf1, %0\n\tlqc2 vf1, %5\n\tvmulx.xyzw vf1, vf1, vf3x\n\tsqc2 vf1, %1" : "=m"(fr.b.row[0]), "=m"(fr.b.row[1]) : "m"(fr.shake), "m"(D_002BD890), "m"(RO_002A2DE0), "m"(D_002BD8A0));
        float *ps = (float *)&fr.b.row[0];
        float *pc = (float *)&fr.b.row[1];
        BuildSimpleProjectionMatrix__FffffffP7MATRIX4(ps[0] * 512.0f / (*(float *)(base + 0x40) * 4096.0f), ps[1] * 224.0f / (*(float *)(base + 0x44) * 4096.0f), pc[0], pc[1], *(float *)(base + 0x4C), *(float *)(base + 0x50), &fr.c);
        CombineEyeLookAtProj(&fr.a, &fr.c, pmatWorldToClip);
    }
    FInvertMatrix4__FP7MATRIX4T0(pmatWorldToClip, (M4 *)(base + 0x180));
    float *frustum = (float *)(base + 0x1C0);
    float *wide0 = (float *)(base + 0x200);
    float *wide1 = (float *)(base + 0x210);
    float *wide2 = (float *)(base + 0x220);
    float *wide3 = (float *)(base + 0x230);
    BuildFrustrum(*(float *)(base + 0x40), *(float *)(base + 0x44), pmatCam, (M4 *)frustum);
    {
        float *dst = (float *)(base + 0xA0);
        float *n0 = frustum, *n1 = (float *)(base + 0x1D0), *n2 = (float *)(base + 0x1E0), *n3 = (float *)(base + 0x1F0);
        for (int i = 2; i >= 0; i--) {
            dst[0] = *n0++;
            dst[1] = *n1++;
            dst[2] = *n2++;
            dst[3] = *n3++;
            dst += 4;
        }
    }
    BuildFrustrum(*(float *)(base + 0x40) * 7.93f, *(float *)(base + 0x44) * 18.1f, pmatCam, (M4 *)wide0);
    {
        float *dst = (float *)(base + 0xD0);
        float *n0 = wide0, *n1 = wide1, *n2 = wide2, *n3 = wide3;
        for (int i = 2; i >= 0; i--) {
            dst[0] = *n0++;
            dst[1] = *n1++;
            dst[2] = *n2++;
            dst[3] = *n3++;
            dst += 4;
        }
    }
    func_0014E078(pcm);
}
}
