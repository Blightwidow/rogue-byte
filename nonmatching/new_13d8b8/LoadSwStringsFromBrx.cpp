typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadSwStringsFromBrx {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
s32 PvAllocSwImpl__Fi(s8 *, s32, f32);            /* extern */
M2C_UNK ResolveStringTable(M2C_UNK *);              /* extern */
s32 S16Read__18CBinaryInputStream(void);             /* extern */
s32 U8Read__18CBinaryInputStream(s32);              /* extern */
M2C_UNK Unknown1__18CBinaryInputStream(s32);        /* extern */
M2C_UNK func_00118380(s32, s8 *, M2C_UNK *, M2C_UNK); /* extern */
extern s32 B_002E1E54;
extern M2C_UNK B_003E1C20;
extern M2C_UNK g_2dd590;
void LoadSwStringsFromBrx(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 *temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s4;
    var_s0 = 0;
    var_s4 = 0;
    temp_v0 = U8Read__18CBinaryInputStream(arg1);
    if (temp_v0 > 0) {
        do {
            var_s4 = ((U8Read__18CBinaryInputStream(arg1) ^ B_002E1E54) == 0) ? var_s0 : var_s4;
            var_s0 += 1;
        } while (var_s0 < temp_v0);
    }
    var_s0_2 = 0;
    temp_v0_2 = S16Read__18CBinaryInputStream();
    M2C_FIELD(arg0, s32 *, 0x4640) = temp_v0_2;
    M2C_FIELD(arg0, s32 *, 0x4644) = PvAllocSwImpl__Fi(sp, temp_v0_2 * 8, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x4640) > 0) {
loop_5:
        temp_s1 = (s32 *)(M2C_FIELD(arg0, s32 *, 0x4644) + (var_s0_2 * 8));
        var_s0_3 = 0;
        *temp_s1 = S16Read__18CBinaryInputStream();
        if (temp_v0 > 0) {
            do {
                if (var_s0_3 == var_s4) {
                    func_00118380(arg1, (s8 *)((s8 *)temp_s1 + 4), &g_2dd590, 0x2E);
                } else {
                    Unknown1__18CBinaryInputStream(arg1);
                }
                var_s0_3 += 1;
            } while (var_s0_3 < temp_v0);
        }
        var_s0_2 += 1;
        if (var_s0_2 < M2C_FIELD(arg0, s32 *, 0x4640)) {
            goto loop_5;
        }
    }
    ResolveStringTable(&B_003E1C20);
}
}
