typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void OnDifficultyGameLoad__FP10DIFFICULTY(M2C_UNK *);
void ResetSaveKeepingOptions(M2C_UNK *, M2C_UNK);
s32 memset(s8 *, M2C_UNK, M2C_UNK);
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003D4A60;
extern s32 g_2e1e00;

void JobMgr_Construct(s8 *arg0) {
    memset(arg0, 0, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x10) = -1;
    M2C_FIELD(arg0, s32 *, 0x14) = -1;
    M2C_FIELD(arg0, s32 *, 0x18) = -1;
    ResetSaveKeepingOptions(&B_003D4A60, 0);
    OnDifficultyGameLoad__FP10DIFFICULTY(&B_002DE578);
    g_2e1e00 = 0;
}

}
