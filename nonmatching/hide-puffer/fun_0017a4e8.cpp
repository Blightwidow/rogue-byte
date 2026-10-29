typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017A4E8 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
void GoalFlinch_SetState(s8 *, M2C_UNK);
s32 PosLoWorld(s8 *);
void ReplaceSwHitFx(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
s32 ResetSensorStates(s32);
void func_00174950();
extern M2C_UNK B_003DD490;
void func_0017A4E8(s8 *arg0) {
    func_00174950();
    GoalFlinch_SetState(arg0, 0);
    ResetSensorStates(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF64));
    s128 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
    ReplaceSwHitFx(&B_003DD490, 1, vu_1, M2C_FIELD(arg0, s8 **, 0x10));
}
}
