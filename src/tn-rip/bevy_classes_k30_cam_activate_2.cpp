// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct AMB;
// Layout follows bevy_classes_k30_cam_deactivate_2 (src/tn-rip): the two ambients at 0xC0/0xC4.
struct CPZ {
    char pad0[0xA4];
    float pan;      // 0xA4
    float tilt;     // 0xA8
    float field_ac; // 0xAC
    float field_b0; // 0xB0
    float field_b4; // 0xB4
    float field_b8; // 0xB8
    float fov;      // 0xBC
    AMB *pambZoom;  // 0xC0
    AMB *pambBinoc; // 0xC4
};
struct CM {
    char pad0[0x24];
    float fov;      // 0x24
    char pad28[0x38];
    MATRIX3 mat;    // 0x60
    char pad60[0x444 - sizeof(MATRIX3)];
    int field_4a4;  // 0x4A4
};
extern "C" {
extern CM B_002DDF40;
extern float g_2dded0;
extern float g_3e1be0;
void ActivateCplcy(CPZ *, void *, void *);
AMB *NewEmitter(int);
void SetEmitterUnpositioned(AMB *, int);
void VirtualRefPtr_Assign(AMB **, AMB *);
void PauseAmb(AMB *);
void SetCmNearClip(CM *, float);
void bevy_classes_k30_cam_150ef0(CPZ *);
void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(MATRIX3 *pmat, float *ppan, float *ptilt);

// Retail keeps &B_002DDF40 in $s0 from the DecomposeRotateMatrixPanTilt call on (matrix at +0x60, fov at
// +0x24, counter at +0x4A4) and computes &pan (a1) before &tilt (a2). A local camera pointer taken at the
// call with the matrix as a typed member, and the arguments in pan, tilt order, give that base register and
// that order; casting a char array member or writing the global directly moves the address arithmetic.
// ActivateCplcy gets the incoming arguments unchanged (retail never touches a1/a2 before the call).
void bevy_classes_k30_cam_activate_2(CPZ *pcpz, void *pso, void *pv)
{
    ActivateCplcy(pcpz, pso, pv);
    AMB *pamb = NewEmitter(0x26);
    SetEmitterUnpositioned(pamb, 0);
    VirtualRefPtr_Assign(&pcpz->pambZoom, pamb);
    pamb = NewEmitter(0x25);
    SetEmitterUnpositioned(pamb, 0);
    VirtualRefPtr_Assign(&pcpz->pambBinoc, pamb);
    PauseAmb(pcpz->pambZoom);
    CM *camera = &B_002DDF40;
    DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(&camera->mat, &pcpz->pan, &pcpz->tilt);
    pcpz->tilt = 0;
    pcpz->field_ac = 0;
    pcpz->field_b0 = 0;
    pcpz->field_b8 = camera->fov / pcpz->field_b4;
    pcpz->fov = camera->fov;
    SetCmNearClip(camera, 49.0f);
    bevy_classes_k30_cam_150ef0(pcpz);
    camera->field_4a4 += 1;
    g_3e1be0 = g_2dded0;
}
}
