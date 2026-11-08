// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SMP { float a, b, c, d; };
struct Rows { QW row[3]; };
struct M4x { Rows rot; QW pos; }; /* MATRIX4 viewed as three rotation rows and a position */
struct Amb { char pad[0x4E]; short count; };
struct Cam {
    char pad0[0x18]; float goal; char pad1c[0x4]; QW pos20; QW pos30; int mode; char pad44[0xC];
    QW pos50; QW euler60; float fov70; char pad74[0xC]; QW pos80; QW euler90; float radA0;
    float radA4; float radA8; float blendAC; float rateB0; char padB4[4]; float fovB8; float fovBC; Amb *amb;
};
static inline float Ratio(float value, float low, float high) {
    if (low == high) return 0.0f;
    return (value - low) / (high - low);
}
static inline float Clamp(float value, float low, float high) {
    if (value < low) return low;
    if (high < value) return high;
    return value;
}
extern "C" {
void ContinueAmb(Amb *);
QW DecomposeRotateMatrixEuler(Rows *);
void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(M4x *, float *, float *);
float GLimitLm__FP2LMf(void *, float);
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(Rows *, QW);
void PauseAmb(Amb *);
QW PosSmooth(QW, QW, SMP *, float *, float);
float RadSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void SetAmbPitch(Amb *, float);
void SetAmbVolume(Amb *, float);
void SetCmFov(void *, float);
void SetCmLookAt(void *, float, float, QW, QW);
void SetCmPosMat(void *, M4x *);
void SmoothMatrix(float, Rows *, Rows *, SMP *, Rows *, QW *);
void UpdateCplcy();
void __as__6VECTORG9VU_VECTOR(void *, QW);
QW bevy_classes_k30_cam_150780(Cam *);
QW bevy_classes_k30_cam_1507f8(Cam *);
extern char B_002DDF40[];
extern float B_003E1BE0;
extern SMP D_002BBB68;
extern SMP D_002BD9B8, D_002BD9C8, D_002BD9D8, D_002BD9E8, D_002BD9F8;
extern char g_2bbb60[];
extern float g_2dded0[];
// Retail (0x150A28): smooths the blend toward the goal and clamps it with the 1.0 bound in $f1 loaded before the
// first compare: a three-argument Clamp(value, low, high) helper, whose arguments are evaluated before its body,
// gives that order (Clamp01 with literals in the body loaded 1.0 after the branch). The camera matrix gets rows
// 1 and 2 and pos.w = 1.0 through a pointer register ($s1 = matrix, also SetCmPosMat's argument) while the three
// row w = 0 stores are $sp-relative: the rows and pos.w go through `matrix`, the w zeros through the stack object.
// The w zeros are written last to first (retail emits 0xEC, 0xDC, 0xCC). Still differs: rows 0 and 1 of the copy
// get $v0/$v1 swapped (score 4, local register allocation).
void bevy_classes_k30_cam_update(Cam *self) {
    Rows prev;
    Rows next;
    Rows out;
    Rows tmp;
    M4x placed;
    UpdateCplcy();
    if (g_2dded0[1] != 0.0f) {
        if (self->goal >= 0.0f) {
            float smoothed = GSmooth__FfffP3SMPPf(self->blendAC, self->goal, g_2dded0[1], &D_002BD9B8, 0);
            float clamped = Clamp(smoothed, 0.0f, 1.0f);
            float delta = clamped - self->blendAC;
            self->rateB0 = delta / g_2dded0[1];
            self->blendAC = clamped;
        }
        float rate = self->rateB0;
        if (rate != 0.0f) {
            Amb *ambA = self->amb;
            SetAmbPitch(ambA, GLimitLm__FP2LMf(&D_002BBB68, __builtin_fabsf(rate)));
            Amb *ambB = self->amb;
            SetAmbVolume(ambB, GLimitLm__FP2LMf(g_2bbb60, __builtin_fabsf(self->rateB0) * 0.5f + 0.5f));
            Amb *ambC = self->amb;
            if (ambC->count > 0) ContinueAmb(ambC);
        } else {
            Amb *amb = self->amb;
            if (amb->count <= 0) PauseAmb(amb);
        }
        if (self->mode != 0) {
            self->pos50 = PosSmooth(self->pos50, self->pos80, &D_002BD9C8, 0, g_2dded0[1]);
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&tmp, self->euler60);
            prev = tmp;
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&tmp, self->euler90);
            next = tmp;
            SmoothMatrix(g_2dded0[1], &prev, &next, &D_002BD9D8, &out, 0);
            self->euler60 = DecomposeRotateMatrixEuler(&out);
            self->fov70 = RadSmooth__FfffP3SMPPf(self->fov70, self->radA0, g_2dded0[1], &D_002BD9E8, 0);
            __as__6VECTORG9VU_VECTOR(&placed.pos, self->pos50);
            M4x *matrix = &placed;
            matrix->rot = out;
            ((float *)&placed.rot.row[2])[3] = 0.0f;
            ((float *)&placed.rot.row[1])[3] = 0.0f;
            ((float *)&placed.rot.row[0])[3] = 0.0f;
            ((float *)&matrix->pos)[3] = 1.0f;
            SetCmPosMat(B_002DDF40, matrix);
            SetCmFov(B_002DDF40, self->fov70);
            DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(&placed, &self->radA4, &self->radA8);
            self->blendAC = GLimitLm__FP2LMf(g_2bbb60, Ratio(self->fov70, self->fovB8, self->fovBC));
        } else {
            float inverse = 1.0f - self->blendAC;
            SetCmFov(B_002DDF40, (1.0f - inverse) * self->fovB8 + inverse * self->fovBC);
            QW old30 = self->pos30;
            QW goal30 = bevy_classes_k30_cam_1507f8(self);
            self->pos30 = PosSmooth(old30, goal30, &D_002BD9F8, 0, g_2dded0[1]);
            QW old20 = self->pos20;
            QW goal20 = bevy_classes_k30_cam_150780(self);
            QW look = PosSmooth(old20, goal20, &D_002BD9F8, 0, g_2dded0[1]);
            self->pos20 = look;
            SetCmLookAt(B_002DDF40, 0.0f, 0.0f, self->pos30, look);
        }
        B_003E1BE0 = g_2dded0[0];
    }
}
}
