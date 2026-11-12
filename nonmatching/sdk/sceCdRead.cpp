typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sceCdRead {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
void SignalSema(s32);
void func_00236960(M2C_UNK *);
void func_0023B170(...);
s32 func_00241C98(M2C_UNK);
s32 func_00241DF0();
s32 sceSifCallRpc(M2C_UNK *, M2C_UNK, M2C_UNK, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32 *);
extern s32 D_002C6750;
extern s32 D_002C6768;
extern s32 D_002C6774;
extern s32 D_002C6778;
extern s32 D_002C67A0;
extern s32 D_002C6840;
extern s32 D_002C7840;
extern s32 D_002C7900;
extern M2C_UNK D_002C7910;
extern M2C_UNK T_00241978;
s32 sceCdRead(s32 arg0, s32 arg1, s32 *arg2, s8 *arg3) {
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_a3;
    if ((D_002C6778 & 1) || (var_v0 = 0, (func_00241DF0() != 6))) {
        if (func_00241C98(4) != 0) {
            M2C_FIELD(&D_002C6840, s32 *, 0) = arg0;
            M2C_FIELD(&D_002C6840, s32 *, 4) = arg1;
            M2C_FIELD(&D_002C6840, s32 **, 8) = arg2;
            M2C_FIELD(&D_002C6840, u8 *, 0xC) = (u8) M2C_FIELD(arg3, u8 *, 0);
            M2C_FIELD(&D_002C6840, u8 *, 0xD) = (u8) M2C_FIELD(arg3, u8 *, 1);
            M2C_FIELD(&D_002C6840, s32 **, 0x10) = &D_002C7840;
            M2C_FIELD(&D_002C6840, u8 *, 0xE) = (u8) M2C_FIELD(arg3, u8 *, 2);
            M2C_FIELD(&D_002C6840, s32 **, 0x14) = &D_002C7900;
            temp_a3 = M2C_FIELD(arg3, u8 *, 2);
            if (temp_a3 != 1) {
                var_a1 = arg1 << 0xB;
                if ((s32) temp_a3 >= 2) {
                    var_v0_2 = 0x924;
                    if (temp_a3 != 2) {
                    } else {
                        goto block_8;
                    }
                }
            } else {
                var_v0_2 = 0x918;
block_8:
                var_a1 = arg1 * var_v0_2;
            }
            D_002C7900 = 0;
            if (!(D_002C6778 & 2)) {
                func_0023B170(arg2, var_a1, 1, temp_a3, &D_002C7900);
            }
            func_0023B170(&D_002C7840, 0x90);
            func_0023B170(&D_002C6840, 0x18);
            func_0023B170(&D_002C7900, 4);
            if (D_002C6750 > 0) {
                func_00236960((M2C_UNK *)("call cdread cmd\n"));
            }
            D_002C67A0 = 1;
            D_002C6774 = 1;
            if (sceSifCallRpc(&D_002C7910, 1, 1, &D_002C6840, 0x18, 0, 0, &T_00241978, &D_002C7840) >= 0) {
                var_v0 = 1;
                if (D_002C6750 > 0) {
                    func_00236960((M2C_UNK *)("cdread end\n\0\0\0\0\0sceCdChgSys: Illegal_function_call\n\0\0\0\0\0libpad: tPadDma Structure Invalid\n"));
                    var_v0 = 1;
                }
                /* Duplicate return node #20. Try simplifying control flow for better match */
                return var_v0;
            }
            D_002C67A0 = 0;
            D_002C6774 = 0;
            SignalSema(D_002C6768);
            goto block_17;
        }
block_17:
        return 0;
    }
    return var_v0;
}
}
