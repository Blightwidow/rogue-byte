typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PostSlyLoad {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
void BuildPlainBlend(s8 *, s8 *, s8 *);
s32 CreateXfActadj(s8 *, s32, M2C_UNK);
void EnsureAsegBlendDynamic(s8 *, M2C_UNK, M2C_UNK, s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s8 *);
void InitJtLookRig(s8 *, M2C_UNK);
void PostJtLoad();
s32 PostJtLoadSwing(s8 *, s8 *, s8 *);
void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(s8 *);
s32 PsmaApplySm(s32, s32, M2C_UNK, M2C_UNK);
void RemoveXfAct(s8 *, s32, s32);
void SetJtState(s8 *, M2C_UNK, M2C_UNK);
void SetSoProperties(s8 *, M2C_UNK, M2C_UNK *);
s32 func_0012DC18(s8 *, s32, M2C_UNK, M2C_UNK, M2C_UNK, s128);
void func_0018B348(s8 *);
void func_001A6CA8(s8 *, M2C_UNK);
void func_001CC5E8(s8 *, s8 *, s8 *);
s32 func_001F4C58(s8 *, M2C_UNK, M2C_UNK);
extern M2C_UNK D_002BF1B0;
extern s128 g_2a2dd0;
void PostSlyLoad(s8 *arg0) {
    s32 temp_a0_2;
    s32 temp_v0;
    s8 *temp_a0;
    PostJtLoad();
    SetSoProperties(arg0, 0x12, &D_002BF1B0);
    M2C_FIELD(arg0, s32 *, 0x10B8) = func_001F4C58(arg0, 0x138, 1);
    M2C_FIELD(arg0, s32 *, 0x19E0) = func_001F4C58(arg0, 0x18, 6);
    M2C_FIELD(arg0, s32 *, 0x19DC) = func_001F4C58(arg0, 0x19, 6);
    M2C_FIELD(arg0, s32 *, 0x19D8) = func_001F4C58(arg0, 0x13, 1);
    M2C_FIELD(arg0, s32 *, 0x19D4) = func_001F4C58(arg0, 0x12, 1);
    M2C_FIELD(arg0, s32 *, 0x19D0) = func_001F4C58(arg0, 0x1C, 6);
    M2C_FIELD(arg0, s32 *, 0x19CC) = func_001F4C58(arg0, 0x1D, 6);
    M2C_FIELD(arg0, s32 *, 0x19C8) = func_001F4C58(arg0, 0xD, 1);
    M2C_FIELD(arg0, s32 *, 0x19C4) = func_001F4C58(arg0, 0xC, 1);
    M2C_FIELD(arg0, s32 *, 0x19C0) = func_001F4C58(arg0, 0xC, 6);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(arg0 + 0x1320);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(arg0 + 0x1C30);
    BuildPlainBlend(arg0, arg0 + 0x1AC0, arg0 + 0x1BC0);
    PostJtLoadSwing(arg0, arg0 + 0x1970, arg0 + 0x1994);
    BuildPlainBlend(arg0, arg0 + 0x1E10, arg0 + 0x1F10);
    M2C_FIELD(arg0, s32 *, 0x19E4) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x10B8), 5);
    M2C_FIELD(arg0, s32 *, 0x19E8) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19C8), 5);
    M2C_FIELD(arg0, s32 *, 0x19EC) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19C4), 5);
    M2C_FIELD(arg0, s32 *, 0x19F0) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19D8), 7);
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x19A0);
    M2C_FIELD(arg0, s32 *, 0x19F4) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19D4), 7);
    M2C_FIELD(arg0, s32 *, 0x19FC) = CreateXfActadj(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x58), 5);
    M2C_FIELD(arg0, s32 *, 0x19F8) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19C0), 5);
    temp_v0 = func_0012DC18(arg0, M2C_FIELD(arg0, s32 *, 0x19C0), 5, 5, 2, g_2a2dd0);
    M2C_FIELD(arg0, s32 *, 0x1A00) = temp_v0;
    RemoveXfAct(arg0, M2C_FIELD(arg0, s32 *, 0x19C0), temp_v0);
    InitJtLookRig(arg0, 0x17);
    func_0018B348(arg0);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A04, 0, 0, 0, arg0 + 0x1A1C);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A20, 0, 0, 0, arg0 + 0x1A38);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A3C, 0, 0, 0, arg0 + 0x1A54);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A58, 0, 0, 0, arg0 + 0x1A70);
    BuildPlainBlend(arg0, arg0 + 0x13D0, arg0 + 0x14D0);
    EnsureAsegBlendDynamic(arg0, 0xC, 4, arg0 + 0x1F60, 0, 0, 0, arg0 + 0x1F90);
    EnsureAsegBlendDynamic(arg0, 0xC, 3, arg0 + 0x2014, 0, 0, 0, arg0 + 0x2038);
    M2C_FIELD(arg0, s32 *, 0x1804) = (s32) M2C_FIELD(arg0, s32 *, 0x19A4);
    func_001CC5E8(arg0 + 0x17D0, arg0, arg0 + 0x18E0);
    SetJtState(arg0, 0, -1);
    func_001A6CA8(arg0, 1);
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1D24);
    if (temp_a0_2 != 0) {
        M2C_FIELD(arg0, s32 *, 0x1D28) = PsmaApplySm(temp_a0_2, M2C_FIELD(arg0, s32 *, 0x1D20), -1, 1);
    }
}
}
