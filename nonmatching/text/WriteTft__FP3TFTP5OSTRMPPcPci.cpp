typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_WriteTft__FP3TFTP5OSTRMPPcPci {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
s32 CbWrite__5OSTRMPvi(...);
void WriteTftDouble__FP3TFTP5OSTRMd(...);
void WriteTftPchz__FP3TFTP5OSTRMPc(s8 *, s8 *, s32, u8 **);
void WriteTftUl__FP3TFTP5OSTRMUl(s8 *, s8 *, s64, u8 **, s64);
s32 fptodp(f32);
s32 strlen(...);
extern M2C_UNK RO_002A9500;
void WriteTft__FP3TFTP5OSTRMPPcPci(s8 *arg0, s8 *arg1, u8 **arg2, M2C_UNK *arg3, s32 arg4, u32 arg6) {
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK *temp_a0;
    M2C_UNK *temp_v0_2;
    M2C_UNK *temp_v1_6;
    M2C_UNK *temp_v1_7;
    f32 *var_s3;
    f32 temp_f12;
    s32 temp_a0_2;
    s32 temp_v1_3;
    s32 var_s0;
    s32 var_s0_2;
    u32 var_a6;
    u8 *temp_a1;
    u8 *temp_v0;
    u8 *temp_v1_10;
    u8 *temp_v1_11;
    u8 *temp_v1_2;
    u8 *temp_v1_4;
    u8 *temp_v1_5;
    u8 *temp_v1_8;
    u8 *temp_v1_9;
    u8 temp_a3;
    u8 temp_v1;
    var_a6 = arg6;
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x2C);
    switch (temp_v1) {                              /* switch 1 */
    case 0x25:                                      /* switch 1 */
        CbWrite__5OSTRMPvi(arg1, (M2C_UNK *)(arg0 + 0x2C), 1, arg2);
        return;
    case 0x63:                                      /* switch 1 */
        temp_v0 = *arg2;
        *arg2 = temp_v0 + 8;
        temp_a3 = *temp_v0;
        CbWrite__5OSTRMPvi(arg1, sp, 1, (u8 **) temp_a3, arg2, temp_a3);
        break;
    case 0x73:                                      /* switch 1 */
        temp_v1_2 = *arg2;
        *arg2 = temp_v1_2 + 8;
        WriteTftPchz__FP3TFTP5OSTRMPc(arg0, arg1, (s32) *temp_v1_2, arg2);
        break;
    case 0x70:                                      /* switch 1 */
        M2C_FIELD(arg0, s32 *, 0x1C) = 8;
        M2C_FIELD(arg0, u8 *, 0x2C) = 0x78U;
        M2C_FIELD(arg0, s32 *, 0x20) = 0;
        /* fallthrough */
    case 0x62:                                      /* switch 1 */
    case 0x64:                                      /* switch 1 */
    case 0x69:                                      /* switch 1 */
    case 0x6F:                                      /* switch 1 */
    case 0x75:                                      /* switch 1 */
    case 0x78:                                      /* switch 1 */
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x20);
        if (temp_v1_3 >= 0) {
            if (temp_v1_3 < 2) {
                temp_v1_4 = *arg2;
                *arg2 = temp_v1_4 + 8;
                var_a6 = (u32) *temp_v1_4;
            } else if (temp_v1_3 != 2) {
            } else {
                temp_v1_5 = *arg2;
                *arg2 = temp_v1_5 + 8;
                var_a6 = (u32) (s64) *temp_v1_5;
            }
        }
        WriteTftUl__FP3TFTP5OSTRMUl(arg0, arg1, (s64) var_a6, arg2, (s64) var_a6);
        break;
    case 0x65:                                      /* switch 1 */
    case 0x66:                                      /* switch 1 */
    case 0x67:                                      /* switch 1 */
        temp_v0_2 = (M2C_UNK *)("{ ");
        if (M2C_FIELD(arg0, s32 *, 0x24) != 0) {
            temp_a1 = *arg2;
            temp_v1_6 = (M2C_UNK *)(",\n");
            *arg2 = temp_a1 + 8;
            temp_v1_7 = (M2C_UNK *)(", ");
            temp_a0 = (M2C_UNK *)(" }");
            var_s3 = (f32 *) *temp_a1;
            if (M2C_FIELD(arg0, s32 *, 0x28) >= 2) {
                CbWrite__5OSTRMPvi(arg1, &RO_002A9500, strlen(&RO_002A9500, temp_a1, arg4, arg2));
            }
            var_s0 = 0;
            if (M2C_FIELD(arg0, s32 *, 0x28) > 0) {
                do {
                    if (var_s0 != 0) {
                        CbWrite__5OSTRMPvi(arg1, temp_v1_6, strlen(temp_v1_6));
                    }
                    var_s0_2 = 0;
                    CbWrite__5OSTRMPvi(arg1, temp_v0_2, strlen(temp_v0_2));
                    if (M2C_FIELD(arg0, s32 *, 0x24) > 0) {
                        do {
                            if (var_s0_2 != 0) {
                                CbWrite__5OSTRMPvi(arg1, temp_v1_7, strlen(temp_v1_7));
                            }
                            temp_f12 = *var_s3;
                            var_s0_2 += 1;
                            var_s3 += 4;
                            WriteTftDouble__FP3TFTP5OSTRMd(arg0, arg1, fptodp(temp_f12));
                        } while (var_s0_2 < M2C_FIELD(arg0, s32 *, 0x24));
                    }
                    var_s0 += 1;
                    CbWrite__5OSTRMPvi(arg1, temp_a0, strlen(temp_a0));
                } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x28));
            }
            if (M2C_FIELD(arg0, s32 *, 0x28) >= 2) {
                CbWrite__5OSTRMPvi(arg1, &RO_002A9500, strlen(&RO_002A9500));
            }
        } else {
            temp_v1_8 = *arg2;
            *arg2 = temp_v1_8 + 8;
            WriteTftDouble__FP3TFTP5OSTRMd(arg0, arg1, (s64) *temp_v1_8, arg2);
        }
        break;
    case 0x6E:                                      /* switch 1 */
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x20);
        switch (temp_a0_2) {                        /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            temp_v1_9 = *arg2;
            *arg2 = temp_v1_9 + 8;
            *(s32 *) *temp_v1_9 = M2C_FIELD(arg1, s32 *, 0x10);
            break;
        case 1:                                     /* switch 2 */
            temp_v1_10 = *arg2;
            *arg2 = temp_v1_10 + 8;
            *(s16 *) *temp_v1_10 = (s16) M2C_FIELD(arg1, s32 *, 0x10);
            break;
        case 2:                                     /* switch 2 */
            temp_v1_11 = *arg2;
            *arg2 = temp_v1_11 + 8;
            *(s64 *) *temp_v1_11 = (s64) M2C_FIELD(arg1, s32 *, 0x10);
            break;
        }
        break;
    default:                                        /* switch 1 */
        CbWrite__5OSTRMPvi(arg1, arg3, arg4, arg2);
        break;
    }
}
}
