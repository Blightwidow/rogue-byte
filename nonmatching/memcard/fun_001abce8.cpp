typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001ABCE8 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
void CreateMemcardThread__FP7MEMCARDii(s8 *, M2C_UNK);
void SnapshotSaveData(M2C_UNK *, s32);
void StoreAudioModeInSave();
extern M2C_UNK B_003E0EA8;
extern M2C_UNK RO_002A6C8F;
void func_001ABCE8(s8 *arg0) {
    StoreAudioModeInSave();
    SnapshotSaveData(&B_003E0EA8, M2C_FIELD(arg0, s32 *, 0xFD50));
    s32 vu_1;
    asm volatile("ldl %0, %%lo(RO_002A6C8F)(%1)" : "=r"(vu_1) : "r"(&RO_002A6C8F));
    s32 vu_2;
    asm volatile("ldr %0, %%lo(g_2a6c88)(%1)" : "=r"(vu_2) : "r"(&RO_002A6C8F), "0"(vu_1));
    CreateMemcardThread__FP7MEMCARDii(arg0 + 0xFD5C, vu_2);
}
}
