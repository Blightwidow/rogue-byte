typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadCrvFromBrx {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
void CBinaryInputStream_Read_thunk(s32, s32, s32);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(s8 *, s32);
void LoadXfmBaseFromBrx();
void MeasureCrv(s8 *);
s32 PvAllocSwImpl__Fi(s8 *, s32, s32);
void ReadVector__18CBinaryInputStreamP6VECTOR(s32, s32);
s32 S8Read__18CBinaryInputStream(s32);
s32 U16Read__18CBinaryInputStream(s32);
void LoadCrvFromBrx(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    LoadXfmBaseFromBrx();
    var_s2 = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = S8Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xE4) = S8Read__18CBinaryInputStream(arg1);
    temp_v0 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xE8) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0xEC) = PvAllocSwImpl__Fi(sp, temp_v0 * 4, 0x10);
    M2C_FIELD(arg0, s32 *, 0xF0) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0xE8) * 4, 0x10);
    M2C_FIELD(arg0, s32 *, 0xF4) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0xE8) * 0x10, 0x10);
    CBinaryInputStream_Read_thunk(arg1, M2C_FIELD(arg0, s32 *, 0xE8) * 4, M2C_FIELD(arg0, s32 *, 0xEC));
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
loop_2:
        temp_a1 = var_s2 * 0x10;
        var_s2 += 1;
        ReadVector__18CBinaryInputStreamP6VECTOR(arg1, M2C_FIELD(arg0, s32 *, 0xF4) + temp_a1);
        if (var_s2 < M2C_FIELD(arg0, s32 *, 0xE8)) {
            goto loop_2;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
        var_s2_2 = 0;
        M2C_FIELD(arg0, s32 *, 0x140) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0xE8) * 0x10, 0x10);
        M2C_FIELD(arg0, s32 *, 0x144) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0xE8) * 0x10, 0x10);
        if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
            do {
                temp_a1_2 = var_s2_2 * 0x10;
                var_s2_2 += 1;
                ReadVector__18CBinaryInputStreamP6VECTOR(arg1, M2C_FIELD(arg0, s32 *, 0x140) + temp_a1_2);
            } while (var_s2_2 < M2C_FIELD(arg0, s32 *, 0xE8));
        }
        var_s2_3 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
loop_10:
            temp_a1_3 = var_s2_3 * 0x10;
            var_s2_3 += 1;
            ReadVector__18CBinaryInputStreamP6VECTOR(arg1, M2C_FIELD(arg0, s32 *, 0x144) + temp_a1_3);
            if (var_s2_3 < M2C_FIELD(arg0, s32 *, 0xE8)) {
                goto loop_10;
            }
        }
    }
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(arg0, arg1);
    MeasureCrv(arg0);
}
}
