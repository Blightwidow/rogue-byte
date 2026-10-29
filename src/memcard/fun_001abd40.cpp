typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001ABD40 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
struct Continuation { long value; } __attribute__((packed));
void CreateMemcardThread__FP7MEMCARDii(s8 *, long);
void SnapshotSaveData(M2C_UNK *, s32);
void StoreAudioModeInSave();
extern M2C_UNK B_003E0EA8;
extern Continuation RO_002A6C90;
void func_001ABD40(s8 *arg0) {
    StoreAudioModeInSave();
    SnapshotSaveData(&B_003E0EA8, M2C_FIELD(arg0, s32 *, 0xFD50));
    CreateMemcardThread__FP7MEMCARDii(arg0 + 0xFD5C, RO_002A6C90.value);
}
}
