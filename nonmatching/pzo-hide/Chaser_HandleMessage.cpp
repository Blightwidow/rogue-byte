typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Chaser_HandleMessage {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x40];
};                                                  /* size = 0xA0 */
#define sp40 (*(s128 *)(sp + 0x40))
#define sp50 (*(s128 *)(sp + 0x50))
void HandlePoMessage();
s32 LoadRotateMatrixRad(s128 *, s128, f32);
s32 func_00204E38(s8 *, s32, s128, f32, s128, s128, s128);
extern s128 g_2a2dc0;
void Chaser_HandleMessage(s8 *arg0, s32 arg1, s8 *arg2) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 sp30;
    s32 temp_v1;
    s32 temp_v1_2;
    s8 *temp_v0;
    s8 *temp_v1_3;
    HandlePoMessage();
    if (arg1 == 9) {
        temp_v1 = M2C_FIELD(arg2, s32 *, 0);
        if ((temp_v1 == M2C_FIELD(arg0, s32 *, 0x194)) || ((temp_v0 = M2C_FIELD(arg0, s8 **, 0x198), (temp_v0 != NULL)) && (temp_v1 == M2C_FIELD(temp_v0, s32 *, 0x30)))) {
            temp_v1_2 = M2C_FIELD(arg2, s32 *, 8);
            switch (temp_v1_2) {                    /* irregular */
            case 0x15E:
                LoadRotateMatrixRad(&sp30, g_2a2dc0, M2C_FIELD(arg0, f32 *, 0x204));
                asm volatile("lqc2 vf4, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf5" : : "r"(func_00204E38(arg0, M2C_FIELD(arg2, s32 *, 0), sp30, M2C_FIELD(arg2, f32 *, 4), sp30, sp40, sp50)));
                temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                asm volatile("vmulax.xyz ACC, vf4, vf5x");
                asm volatile("vmadday.xyz ACC, vf2, vf5y");
                asm volatile("vmaddz.xyz vf3, vf1, vf5z");
                asm volatile("sqc2 vf3, 0x210(%0)" : : "r"(arg0));
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
                M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x118), vu_1);
                break;
            case 0x25:
                M2C_FIELD(arg0, s32 *, 0x1C8) = 1;
                break;
            case 0x26:
                M2C_FIELD(arg0, s32 *, 0x1C8) = 0;
                break;
            case 0x27:
                M2C_FIELD(arg0, s32 *, 0x1CC) = 1;
                break;
            case 0x28:
                M2C_FIELD(arg0, s32 *, 0x1CC) = 0;
                break;
            }
        }
    }
}
}
