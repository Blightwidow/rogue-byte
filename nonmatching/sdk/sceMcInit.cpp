typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sceMcInit {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[8];                       /* maybe part of sp18[3]? */
    /* 0x24 */ M2C_UNK *sp24;                       /* inferred */
    /* 0x28 */ char pad28[0x78];
};                                                  /* size = 0xA0 */
s32 CreateSema(M2C_UNK *);                          /* extern */
M2C_UNK DeleteSema(s32);                            /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK func_00236960(M2C_UNK *);                   /* extern */
M2C_UNK sceMcSync(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
s32 sceSifBindRpc(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
s32 sceSifCallRpc(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK sceSifInitRpc(M2C_UNK);                     /* extern */
extern M2C_UNK B_00450880;
extern M2C_UNK B_00450900;
extern M2C_UNK B_00451E40;
extern s32 D_002C8354;
extern s32 D_002C8358;
extern M2C_UNK RO_002AB7D8;
extern M2C_UNK RO_STR_002AB7F0;
extern M2C_UNK RO_STR_002AB818;
s32 sceMcInit(void) {
    M2C_UNK sp10;
    s32 sp14;
    s32 sp18;
    M2C_UNK *sp24;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v1;
    var_s1 = 0;
    if (D_002C8354 < 0) {
        sp18 = 1;
        sp24 = (M2C_UNK *)("sceMc_sema_regs");
        sp14 = 1;
        temp_v0 = CreateSema(&sp10);
        D_002C8354 = temp_v0;
        if (temp_v0 == -1) {
            return -0x65;
        }
        sp14 = 1;
        sp18 = 0;
        sp24 = (M2C_UNK *)("sceMc_sema_timer");
        temp_v0_2 = CreateSema(&sp10);
        D_002C8358 = temp_v0_2;
        if (temp_v0_2 == -1) {
            DeleteSema(D_002C8354);
            D_002C8354 = temp_v0_2;
            return -0x65;
        }
        goto block_5;
    }
block_5:
    sceMcSync(0, 0, 0);
    WaitSema(D_002C8354);
    sceSifInitRpc(0);
loop_10:
    if (sceSifBindRpc(&B_00450880, 0x80000400, 0) < 0) {
        func_00236960(&RO_002AB7D8);
loop_12:
        goto loop_12;
    }
    if (M2C_FIELD(&B_00450880, s32 *, 0x24) != 0) {
        temp_s0 = sceSifCallRpc(&B_00450880, 0xFE, 0, &B_00450900, 0x30, &B_00451E40, 0xC, 0, 0);
        SignalSema(D_002C8354);
        if (temp_s0 >= 0) {
            if (M2C_FIELD(&B_00451E40, s32 *, 4) < 0x20A) {
                func_00236960(&RO_STR_002AB7F0);
                M2C_FIELD(&B_00450880, s32 *, 0x24) = 0;
                return -0x78;
            }
            if (M2C_FIELD(&B_00451E40, s32 *, 8) < 0x20E) {
                func_00236960(&RO_STR_002AB818);
                M2C_FIELD(&B_00450880, s32 *, 0x24) = 0;
                return -0x79;
            }
            return M2C_FIELD(&B_00451E40, s32 *, 0);
        }
        M2C_FIELD(&B_00450880, s32 *, 0x24) = 0;
        return -0x5B;
    }
    var_v1 = 0x100000;
    do {
        var_v1 -= 1;
    } while (var_v1 != 0);
    var_s1 += 1;
    if (var_s1 < 0x200) {
        goto loop_10;
    }
    func_00236960(&RO_002AB7D8);
    return -0x5B;
}
}
