typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Swarm_PostLoad {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
void AddSoGeomsToOxa(s8 *, s32, M2C_UNK, s32);
s32 AppendDlEntry(s8 *, s8 *);
void InitDl__FP2DLi(s8 *, M2C_UNK);
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s8 *);
s32 *PvAllocSwClearImpl__Fi(s8 *, s32, s32);
void func_0017F138(s8 *);
extern M2C_UNK B_003DD490;
void Swarm_PostLoad(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_s1;
    s32 var_s4;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_v0_2;
    s8 *var_s0;
    var_s4 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
        var_s0 = arg0 + 0x1CC;
        do {
            temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s0, s32 *, 0), arg0);
            M2C_FIELD(var_s0, s32 *, 0x24) = temp_v0;
            if (temp_v0 == 0) {
                var_s0 -= 0x30;
                var_s4 -= 1;
                M2C_FIELD(arg0, s32 *, 0x1C8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C8) - 1);
            } else {
                temp_a0 = var_s0 + 0x10;
                var_s1 = 0;
                InitDl__FP2DLi(temp_a0, 0x60);
                if (M2C_FIELD(var_s0, s32 *, 4) > 0) {
                    do {
                        var_s1 += 1;
                        temp_v0_2 = (s8 *)(PvAllocSwClearImpl__Fi(sp, 0x70, 0x10));
                        M2C_FIELD(temp_v0_2, s8 **, 0x20) = var_s0;
                        M2C_FIELD(temp_v0_2, s32 *, 0x24) = -1;
                        AppendDlEntry(temp_a0, temp_v0_2);
                    } while (var_s1 < M2C_FIELD(var_s0, s32 *, 4));
                }
            }
            var_s4 += 1;
            var_s0 += 0x30;
        } while (var_s4 < M2C_FIELD(arg0, s32 *, 0x1C8));
    }
    func_0017F138(arg0);
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0xE0);
    temp_a1 = temp_v0_3 * 0xB0;
    temp_a3 = M2C_FIELD(arg0, s32 *, 0x60);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v0_3 + 1);
    temp_a0_2 = (s8 *)(M2C_FIELD(arg0, s32 *, 0xE4) + temp_a1);
    M2C_FIELD(temp_a0_2, s32 *, 0) = temp_a3;
    M2C_FIELD(temp_a0_2, s32 *, 0xC) = -1;
    M2C_FIELD(temp_a0_2, s8 **, 4) = arg0;
    M2C_FIELD(temp_a0_2, s64 *, 0x10) = (s64) (M2C_FIELD(temp_a0_2, s64 *, 0x10) | (0x8000 << 0x21) | (0x8000 << 0x22));
    if ((int)((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        AddSoGeomsToOxa(arg0, temp_a1, -1, temp_a3);
    }
}
}
