typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C8730 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK DecrementSwBinocCount(M2C_UNK *);           /* extern */
M2C_UNK DecrementSwShowCount(M2C_UNK *);            /* extern */
M2C_UNK IncrementSwBinocCount(M2C_UNK *);           /* extern */
M2C_UNK IncrementSwShowCount(M2C_UNK *);            /* extern */
M2C_UNK SetGadgetAcquired(s32, M2C_UNK);            /* extern */
M2C_UNK StartJsg(s32, s8 *);                      /* extern */
s32 StartStream(M2C_UNK *, s32, M2C_UNK);           /* extern */
M2C_UNK StopJsg(s32);                               /* extern */
M2C_UNK StopStream(M2C_UNK *);                      /* extern */
M2C_UNK func_001C8918(s8 *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD040;
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;
void func_001C8730(s8 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v1;
    s8 *temp_a2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x180)) {
        if (M2C_FIELD(arg0, s32 *, 0x1A4) != 0) {
            StopStream(&B_003DD040);
            M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
        }
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x19C);
        if (temp_a0 != 0) {
            StopJsg(temp_a0);
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x180);
        switch (temp_v1) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if (M2C_FIELD(arg0, s8 **, 0x190) != NULL) {
                IncrementSwBinocCount(&B_003DD490);
            }
            break;
        case 3:                                     /* switch 1 */
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x200);
            if (temp_a0_2 != -1) {
                SetGadgetAcquired(temp_a0_2, 1);
            }
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x1FC);
            if (temp_a1 != 0) {
                M2C_FIELD(arg0, s32 *, 0x1A4) = StartStream(&B_003DD040, temp_a1, 1);
            }
            break;
        case 2:                                     /* switch 1 */
            func_001C8918(arg0, -1);
            DecrementSwShowCount(&B_003DD490);
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x180) = arg1;
        M2C_FIELD(arg0, f32 *, 0x184) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 2 */
        case 2:                                     /* switch 2 */
            M2C_FIELD(arg0, s32 *, 0x194) = 5;
            func_001C8918(arg0, 1);
            IncrementSwShowCount(&B_003DD490);
            temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x1F4);
            if (temp_a1_2 != 0) {
                M2C_FIELD(arg0, s32 *, 0x1A4) = StartStream(&B_003DD040, temp_a1_2, 0);
            }
        default:                                    /* switch 2 */
block_29:
            temp_a0_3 = M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0x180) * 4)), s32 *, 0x20C);
            M2C_FIELD(arg0, s32 *, 0x19C) = temp_a0_3;
            if (temp_a0_3 != 0) {
                StartJsg(temp_a0_3, M2C_FIELD(arg0, s8 **, 0x190));
            }
            break;
        case 1:                                     /* switch 2 */
            temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x278), 1);
            goto block_29;
        case 0:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
            temp_a2 = M2C_FIELD(arg0, s8 **, 0x190);
            if (temp_a2 != NULL) {
                temp_v0_2 = M2C_FIELD(temp_a2, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x27C)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0x278), 1, temp_a2);
                M2C_FIELD(arg0, s8 **, 0x190) = NULL;
                DecrementSwBinocCount(&B_003DD490);
            }
            goto block_29;
        }
    }
}
}
