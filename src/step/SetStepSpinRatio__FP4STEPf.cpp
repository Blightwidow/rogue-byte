// SPDX-License-Identifier: GPL-3.0-or-later
struct B8 { char b[8]; };
struct Vec12_204D48 { B8 head; int tail; };
struct Step204D48 {
    char pad0[0x1F0];
    float spinRatio;
    float spinX;
    float spinY;
    float spinZ;
};
static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" const Vec12_204D48 D_002C3CB8;
extern "C" void SetStepSpinRatio__FP4STEPf(Step204D48 *step, float ratio)
{
    *(Vec12_204D48 *)&step->spinX = D_002C3CB8;
    step->spinX = step->spinX * ratio;
    step->spinY = step->spinY * ratio;
    float root = Sqrt(ratio);
    float inverse = 1.0f / root;
    step->spinRatio = ratio;
    step->spinZ = step->spinZ * inverse;
}
