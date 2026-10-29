// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;
typedef float f32;

extern "C" {
void RecalcCmFrustrum__FP2CM(void *camera);

void SetCmFov(char *camera, f32 fov) {
    s32 fovChanged;

    fovChanged = (__builtin_fabsf(fov - *(f32 *)(camera + 0x20)) > 0.0001f) ? 1 : 0;
    *(f32 *)(camera + 0x20) = fov;
    *(f32 *)(camera + 0x24) = fov;
    *(s32 *)(camera + 0x28) = 0;
    if (fovChanged != 0) {
        RecalcCmFrustrum__FP2CM(camera);
    }
}
}
