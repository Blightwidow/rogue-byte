#include "sly2.h"
struct U32 { int v; } __attribute__((packed));
struct CPLCY;
struct SO;
enum CPP { CPP_DEFAULT = 1 };
struct CM {
    char pad0[0x10]; int field10; int field14; float f18, f1C, f20, f24; char pad28[4]; float f2C;
    char pad30[0x3C - 0x30]; float f3C; char pad40[0x4C - 0x40]; float f4C; float f50;
    char pad54[0x60 - 0x54]; float mat[16]; char pad_a0[0x240 - 0xA0]; float f240, f244, f248; U32 packed24C;
    char pad250[0x30C - 0x250]; int field30C; char pad310[0x3A0 - 0x310]; char cptn[0x10];
    char pad3B0[0x618 - 0x3B0]; float f618; int field61C;
};
extern int B_002DDF30;
extern int B_002DDF34;
extern float RO_002BD81C, RO_002BD820, RO_002BD824;
extern QW D_002BD830, D_002BD840;
extern "C" {
void CPLCY_Destruct(void *);
void CPLCY_Destruct_thunk(void *);
void bevy_camera_follow_new(void *);
void SetCmLookAt(CM *, QW, QW, float, float);
}
void RecalcCmFrustrum(CM *);
void SetResetFlag(CM *);
void SetCmPolicy(CM *, CPP, CPLCY *, SO *, void *);
extern "C" void InitCm(CM *cm)
{
    if (B_002DDF34 == 0) {
        B_002DDF34 = 1;
        B_002DDF30 = 0x80303030;
    }
    float *vec = (float *)((char *)cm + 0x2C);
    float *mat = cm->mat;
    char *cptn = cm->cptn;
    cm->f4C = 100.0f;
    cm->f240 = RO_002BD81C;
    cm->f244 = RO_002BD820;
    cm->f248 = RO_002BD824;
    cm->f3C = 1.2987015f;
    cm->f50 = 100000.0f;
    cm->f1C = 1.0f;
    cm->f18 = 1.0f;
    cm->f24 = 1.0f;
    cm->f20 = 1.0f;
    cm->packed24C = *(U32 *)&B_002DDF30;
    cm->f2C = 0.5f;
    vec[3] = 10.0f;
    vec[2] = 0.1f;
    *(int *)&vec[1] = 0;
    memset(mat, 0, 0x40);
    mat[15] = 1.0f;
    mat[10] = 1.0f;
    mat[5] = 1.0f;
    cm->mat[0] = 1.0f;
    RecalcCmFrustrum(cm);
    SetCmLookAt(cm, D_002BD830, D_002BD840, 0.0f, 0.0f);
    SetResetFlag(cm);
    cm->field30C = 0;
    CPLCY_Destruct_thunk(cptn);
    bevy_camera_follow_new((char *)cm + 0x3B0);
    CPLCY_Destruct((char *)cm + 0x450);
    CPLCY_Destruct((char *)cm + 0x4A8);
    CPLCY_Destruct((char *)cm + 0x4C0);
    CPLCY_Destruct((char *)cm + 0x500);
    CPLCY_Destruct((char *)cm + 0x520);
    CPLCY_Destruct((char *)cm + 0x5F0);
    cm->field10 = 0;
    cm->field14 = 0xFF;
    SetCmPolicy(cm, (CPP)0, (CPLCY *)cptn, 0, 0);
    cm->field61C = -1;
    cm->f618 = -10.0f;
}
