typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
s32 FFindDlEntry(M2C_UNK *, void *);
void ObstacleGroup_Dissolve(s32);
void Obstacle_RemoveFromPathzone(void *);
void RemoveDlEntry(M2C_UNK *, void *);
void RemoveLoHierarchy();
extern M2C_UNK B_003E1A4C;

void Obstacle_RemoveLoHierarchy(void *arg0) {
    s32 temp_a0;

    RemoveLoHierarchy();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1D8);
    if (temp_a0 != 0) {
        ObstacleGroup_Dissolve(temp_a0);
    }
    Obstacle_RemoveFromPathzone(arg0);
    if (FFindDlEntry(&B_003E1A4C, arg0) != 0) {
        RemoveDlEntry(&B_003E1A4C, arg0);
    }
}

}
