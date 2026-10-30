typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddLightToBspRegions {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x10];
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ char pad40[0x50];
};                                                  /* size = 0x90 */
M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */
void AddLightToBspRegions(s8 *arg0, s8 *arg1, s128 arg2, s32 arg3, f32 fparg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s128 sp20;
    s128 sp30;
    f32 temp_v0;
    s32 *temp_a0;
    s32 *temp_a0_2;
    s8 *temp_a1;
    s8 *temp_a1_2;
    sp20 = arg2;
    sp30 = M2C_FIELD(arg1, s128 *, 0);
    func_002564B8((M2C_UNK *)(sp));
    func_002564B8(&sp10);
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf2, vf3, vf4");
    asm volatile("vaddw.x vf1, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddaz.x ACC, vf1, vf2z");
    asm volatile("vmsubw.x vf2, vf1, vf3w");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
    temp_v0 = vu_1;
    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    if (temp_v0 < fparg0) {
        temp_a1 = M2C_FIELD(arg1, s8 **, 0x10);
        if (temp_a1 != NULL) {
            AddLightToBspRegions(arg0, temp_a1, sp20, arg3, fparg0);
        } else {
            temp_a0 = (s32 *)((M2C_FIELD(arg1, s32 *, 0x18) << 5) + M2C_FIELD(arg0, s32 *, 0x4564) + (((s32) ((arg3 > -1) ? arg3 : (arg3 + 0x1F)) >> 5) * 4));
            *temp_a0 |= 1 << arg3;
        }
    }
    if (-fparg0 < temp_v0) {
        temp_a1_2 = M2C_FIELD(arg1, s8 **, 0x14);
        if (temp_a1_2 != NULL) {
            AddLightToBspRegions(arg0, temp_a1_2, sp20, arg3, fparg0);
            return;
        }
        temp_a0_2 = (s32 *)((M2C_FIELD(arg1, s32 *, 0x1C) << 5) + M2C_FIELD(arg0, s32 *, 0x4564) + (((s32) ((arg3 > -1) ? arg3 : (arg3 + 0x1F)) >> 5) * 4));
        *temp_a0_2 |= 1 << arg3;
    }
}
}
