#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void GoalStack_Init(s8 *, s8 *);
s32 InitPo();
void SetStepRadTarget(s8 *, f32);
f32 SetStepSpinRatio__FP4STEPf(s8 *, f32);

void InitStep(s8 *arg0) {
    InitPo();
    M2C_FIELD(arg0, s32 *, 0x264) = -1;
    M2C_FIELD(arg0, f32 *, 0x260) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x200) = 1.0f;
    SetStepSpinRatio__FP4STEPf(arg0, 1.0f);
    SetStepRadTarget(arg0, 0.0f);
    M2C_FIELD(arg0, f32 *, 0x220) = 30.0f;
    M2C_FIELD(arg0, f32 *, 0x214) = -50.0f;
    GoalStack_Init(arg0 + 0x26C, arg0);
}

}
