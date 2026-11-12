typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00241C98 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 PollSema(s32);                                  /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK func_00236960(...);         /* extern */
M2C_UNK func_00241A30();                            /* extern */
s32 sceCdSync(M2C_UNK);                             /* extern */
s32 sceSifBindRpc(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK sceSifInitRpc(M2C_UNK);                     /* extern */
extern s32 D_002C6750;
extern s32 D_002C675C;
extern s32 D_002C6768;
extern s32 D_002C677C;
extern M2C_UNK D_002C7910;
s32 func_00241C98(s32 arg0) {
    s32 var_v0;
    s32 var_v0_2;
    func_00241A30();
    if (D_002C6768 != PollSema(D_002C6768)) {
        if (D_002C6750 > 0) {
            func_00236960((M2C_UNK *)("Ncmd fail sema cur_cmd:%d keep_cmd:%d\n"), arg0, D_002C675C);
            return 0;
        }
        goto block_5;
    }
    D_002C675C = arg0;
    if (sceCdSync(1) != 0) {
        SignalSema(D_002C6768);
block_5:
        return 0;
    }
    sceSifInitRpc(0);
    if (D_002C677C < 0) {
loop_10:
        if (sceSifBindRpc(&D_002C7910, 0x80000595, 0) < 0) {
            var_v0 = 0x100000;
            if (D_002C6750 > 0) {
                func_00236960((M2C_UNK *)("Libcdvd bind err N CMD\n"));
                var_v0 = 0x100000;
            }
            do {
                var_v0 -= 1;
            } while (var_v0 != -1);
            goto loop_10;
        }
        if (M2C_FIELD(&D_002C7910, s32 *, 0x24) == 0) {
            var_v0_2 = 0x100000;
            do {
                var_v0_2 -= 1;
            } while (var_v0_2 != -1);
            goto loop_10;
        }
        D_002C677C = 0;
    }
    return 1;
}
}
