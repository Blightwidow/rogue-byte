typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSnd {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
void ContinueAmb(...);
f32 GSmooth__FfffP3SMPPf(s8 *, M2C_UNK, f32, f32, f32);
void PauseAmb(...);
void SetSndbankVolumeFactor(s8 *, M2C_UNK, M2C_UNK, f32);
s32 TickReadCount(M2C_UNK *);
void UpdateAmb(s8 *);
void UpdateSndMix(s8 *);
void UpdateStreamCues(s8 *);
void func_001FDA48(s8 *);
void func_001FDBA8(s8 *);
void func_001FDEC0(s8 *);
s32 func_001FE5E0(s8 *, s32, f32);
s32 snd_FlushSoundCommands(s8 *);
extern M2C_UNK RO_002A8288;
extern s32 g_2bd4c0;
extern M2C_UNK g_2dded0;
void UpdateSnd(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    M2C_UNK temp_v1;
    f32 temp_f0;
    f32 var_f21;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s8 *var_a0;
    s8 *var_s0;
    M2C_FIELD(arg0, s64 *, 0x1F8) = (s64) M2C_FIELD(arg0, s64 *, 0x1F0);
    M2C_FIELD(arg0, s64 *, 0x1F0) = TickReadCount(&g_2dded0);
    func_001FDA48(arg0);
    func_001FDBA8(arg0);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x204);
    if (temp_v0 > 0) {
        var_a1 = M2C_FIELD(((temp_v0 * 4) + arg0), s32 *, 0x204);
    } else {
        var_a1 = 0;
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x58);
    if (g_2bd4c0 == 3) {
        if (temp_v0_2 != 0) {
            if (var_a1 != 0) {
                ContinueAmb(var_a1, var_a1);
            }
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x228);
            if (temp_a0 != 0) {
                ContinueAmb(temp_a0);
            }
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x200);
            if (temp_a0_2 == 0) {
                M2C_FIELD(arg0, s32 *, 0x58) = 0;
            } else {
                ContinueAmb(temp_a0_2);
                M2C_FIELD(arg0, s32 *, 0x58) = 0;
            }
        }
    } else if (temp_v0_2 == 0) {
        if (var_a1 != 0) {
            PauseAmb(var_a1, var_a1);
        }
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x228);
        if (temp_a0_3 != 0) {
            PauseAmb(temp_a0_3);
        }
        temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x200);
        if (temp_a0_4 != 0) {
            PauseAmb(temp_a0_4);
        }
        M2C_FIELD(arg0, s32 *, 0x58) = 1;
    }
    var_f21 = 1.0f;
    UpdateSndMix(arg0);
    func_001FDEC0(arg0);
    UpdateStreamCues(arg0);
    s32 vu_1;
    asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(&RO_002A8288));
    s32 vu_2;
    asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(&RO_002A8288), "0"(vu_1));
    temp_v1 = vu_2;
    asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v1), "r"(sp));
    asm volatile("sdr %0, (%1)" : : "r"(temp_v1), "r"(sp));
    if (func_001FE5E0(arg0, M2C_FIELD(&RO_002A8288, s32 *, 8), M2C_FIELD(&RO_002A8288, s32 *, 8)) != 0) {
        if (M2C_FIELD(&g_2dded0, f32 *, 4) == 0.0f) {
            var_f21 = 0.0f;
        }
    }
    temp_f0 = GSmooth__FfffP3SMPPf(sp, 0, M2C_FIELD(arg0, f32 *, 0x15C), var_f21, M2C_FIELD(&g_2dded0, f32 *, 0x40));
    SetSndbankVolumeFactor(arg0, 0, 2, temp_f0);
    SetSndbankVolumeFactor(arg0, 1, 2, temp_f0);
    var_s0 = M2C_FIELD(arg0, s8 **, 0x4C);
    SetSndbankVolumeFactor(arg0, 2, 2, var_f21);
    var_a0 = var_s0;
    if (var_s0 != NULL) {
        do {
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x38);
            UpdateAmb(var_a0);
            var_a0 = var_s0;
        } while (var_s0 != NULL);
    }
    snd_FlushSoundCommands(var_a0);
}
}
