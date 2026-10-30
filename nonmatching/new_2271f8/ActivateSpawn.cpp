typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ActivateSpawn {
    /* 0x00 */ char pad0[0xF0];
};                                                  /* size = 0xF0 */
M2C_UNK ApplyTaskStateRequests(M2C_UNK *, s32, s8 *, s8 *); /* extern */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s8 *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s8 *); /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK TriggerRsmg(M2C_UNK *, s32, s8 *, s8 *); /* extern */
M2C_UNK Warp_SetState(s8 *, M2C_UNK);             /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
void ActivateSpawn(s8 *arg0) {
    s8 sp[0x60] __attribute__((aligned(16)));
    s32 var_s0;
    s32 var_s3;
    s8 **var_s1_2;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1;
    s8 *var_s1;
    var_s3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x148) > 0) {
        var_s1 = arg0 + 0x14C;
        do {
            temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s1, s32 *, 0), arg0);
            if (temp_v0 != NULL) {
                temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s1, s32 *, 4), arg0);
                if (temp_v0_2 != NULL) {
                    temp_v0_3 = M2C_FIELD(temp_v0, s8 **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x134)(temp_v0 + M2C_FIELD(temp_v0_3, s16 *, 0x130), temp_v0_2);
                }
            }
            var_s3 += 1;
            var_s1 += 8;
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x148));
    }
    TriggerRsmg(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xE0), arg0 + 0xE4, arg0);
    ApplyTaskStateRequests(&B_002DEB30, M2C_FIELD(arg0, s32 *, 0x124), arg0 + 0x128, arg0);
    var_s0 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x1A, 0) - 1;
    if (var_s0 >= 0) {
        var_s1_2 = (s8 **)((var_s0 * 4) + sp);
        do {
            temp_a0 = *var_s1_2;
            if (M2C_FIELD(temp_a0, s32 *, 0x13C) != 2) {
                Warp_SetState(temp_a0, 0);
            }
            var_s0 -= 1;
            var_s1_2 -= 4;
        } while (var_s0 >= 0);
    }
    SetResetFlag__FP2CM(&B_002DDF40);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 5, 0, 0);
}
}
