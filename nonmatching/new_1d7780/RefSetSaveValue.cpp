typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefSetSaveValue {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0x68];
};                                                  /* size = 0x80 */
#define sp14 (*(s32 *)(sp + 0x14))
M2C_UNK CRef_CopyConstruct(s32, s8 *);            /* extern */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
s32 FFindSaveVar(s32, s32, s8 **);                /* extern */
M2C_UNK SetTag__4CRef4TAGK(s8 *, M2C_UNK);        /* extern */
s32 RefSetSaveValue(s32 arg0, s32 arg1, s32 arg2, s8 *arg3, s32 arg4) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *sp10;
    M2C_UNK temp_a0_2;
    M2C_UNK temp_a2;
    s32 temp_v0;
    s32 temp_v1;
    s8 temp_a0;
    u8 *temp_a4_2;
    s8 **temp_a4;
    s8 *temp_a0_3;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1_2;
    SetTag__4CRef4TAGK(sp, 0x24);
    if (FFindSaveVar(arg1, arg2, &sp10) != 0) {
        temp_a0 = M2C_FIELD(sp10, s8 *, 2);
        if (temp_a0 != -1) {
            temp_a4 = (s8 **)(arg4 + M2C_FIELD(sp10, u16 *, 4));
            switch (temp_a0) {
            case 0:
            case 1:
            case 2:
            case 9:
            case 10:
                *((sp14 * 4) + temp_a4) = M2C_FIELD(arg3, s8 **, 4);
                break;
            case 3:
                *((sp14 * 4) + temp_a4) = M2C_FIELD(arg3, s8 **, 4);
                break;
            case 4:
                if (M2C_FIELD(sp10, u8 *, 3) != 0) {
                    temp_v0 = (s32) ((sp14 > -1) ? sp14 : (sp14 + 7)) >> 3;
                    temp_a4_2 = (u8 *)(temp_a4 + temp_v0);
                    temp_v1 = (1 << (sp14 - (temp_v0 * 8))) & 0xFF;
                    if (M2C_FIELD(arg3, s8 **, 4) != NULL) {
                        *temp_a4_2 |= temp_v1;
                    } else {
                        *temp_a4_2 &= ~temp_v1;
                    }
                } else {
                    *temp_a4 = M2C_FIELD(arg3, s8 **, 4);
                }
                break;
            case 5:
            case 6:
                *((sp14 * 0x10) + temp_a4) = (s8 *)(M2C_FIELD(M2C_FIELD(arg3, s8 **, 4), s128 *, 0));
                break;
            case 7:
                temp_v1_2 = M2C_FIELD(arg3, s8 **, 4);
                temp_v0_2 = (s8 *)((sp14 * 8) + temp_a4);
                s32 vu_1;
                asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(temp_v1_2));
                s32 vu_2;
                asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(temp_v1_2), "0"(vu_1));
                temp_a0_2 = vu_2;
                asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_a0_2), "r"(temp_v0_2));
                asm volatile("sdr %0, (%1)" : : "r"(temp_a0_2), "r"(temp_v0_2));
                break;
            case 8:
                temp_a0_3 = M2C_FIELD(arg3, s8 **, 4);
                temp_v0_3 = (s8 *)((sp14 * 0xC) + temp_a4);
                s32 vu_3;
                asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_3) : "r"(temp_a0_3));
                s32 vu_4;
                asm volatile("ldr %0, (%1)" : "=r"(vu_4) : "r"(temp_a0_3), "0"(vu_3));
                temp_a2 = vu_4;
                asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_a2), "r"(temp_v0_3));
                asm volatile("sdr %0, (%1)" : : "r"(temp_a2), "r"(temp_v0_3));
                M2C_FIELD(temp_v0_3, s32 *, 8) = (s32) M2C_FIELD(temp_a0_3, s32 *, 8);
                break;
            }
            CRef_CopyConstruct(arg0, sp);
            CRef_Destruct(sp);
        } else {
            goto block_4;
        }
    } else {
block_4:
        CRef_CopyConstruct(arg0, sp);
        CRef_Destruct(sp);
    }
    return arg0;
}
}
