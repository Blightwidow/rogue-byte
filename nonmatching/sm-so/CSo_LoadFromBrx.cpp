typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CSo_LoadFromBrx {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
void AddSoGeomsToOxa(s8 *);
void AdjustSoMomint__FP2SOf(s8 *, M2C_UNK);
void CBinaryInputStream_ReadBspc(s32, s8 *, s8 *);
void CBinaryInputStream_ReadGeom(s32, s8 *);
void CBinaryInputStream_ReadMatrix(s32, s8 *);
void CloneGeom(s8 *, M2C_UNK, s8 *);
f32 F32Read__18CBinaryInputStream(s32);
void LoadAloFromBrx();
void LoadGlobsetFromBrx(s32, s8 *, s32);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(s8 *, s32);
void LoadSwObjectsFromBrx(s8 *, s32, M2C_UNK);
s32 *PvAllocSwClearImpl__Fi(...);
s32 S16Read__18CBinaryInputStream(s32);
s32 S32Read__18CBinaryInputStream(s32);
s32 S8Read__18CBinaryInputStream(s32);
s32 SetLoGrfzon(s8 *, s32);
s32 U32Read__18CBinaryInputStream(s32);
void func_001F2500(s8 *);
extern M2C_UNK D_002C44F0;
void CSo_LoadFromBrx(s8 *arg0, s32 arg1) {
    s8 sp[0xB0] __attribute__((aligned(16)));
    M2C_UNK temp_a0;
    M2C_UNK temp_v0_2;
    M2C_UNK temp_v1_3;
    s32 temp_fp;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_s4;
    s32 var_s4_2;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *temp_s5;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *var_a1;
    var_s4 = 0;
    LoadAloFromBrx();
    temp_fp = U32Read__18CBinaryInputStream(arg1);
    LoadGlobsetFromBrx((int)(arg0 + 0x80), arg0, arg1);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    temp_s6 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0x1FC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x1F8));
    temp_v0 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xE0) = temp_v0;
    M2C_FIELD(arg0, s8 **, 0xE4) = (s8 *)(PvAllocSwClearImpl__Fi(sp, 0xB0, (temp_v0 + temp_s6) * 0xB0, 0x10));
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        do {
            temp_s1 = M2C_FIELD(arg0, s8 **, 0xE4) + (var_s4 * 0xB0);
            M2C_FIELD(temp_s1, s8 **, 4) = arg0;
            temp_s5 = temp_s1 + 0x78;
            temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_s1, M2C_UNK **, 0) = M2C_FIELD(temp_v1_2, M2C_UNK *(**)(s8 *, s32), 0x19C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x198), S16Read__18CBinaryInputStream(arg1));
            M2C_FIELD(temp_s1, s32 *, 0xC) = S32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s1, s64 *, 0x10) = (s64) ((M2C_FIELD(temp_s1, s64 *, 0x10) & ((((((0xFFFE << 0x10) | 0xFFFF) << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)) | ((S8Read__18CBinaryInputStream(arg1) & 1) << 0x30));
            M2C_FIELD(temp_s1, s64 *, 0x10) = (s64) ((M2C_FIELD(temp_s1, s64 *, 0x10) & ((((((0xFFFD << 0x10) | 0xFFFF) << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)) | ((S8Read__18CBinaryInputStream(arg1) & 1) << 0x31));
            M2C_FIELD(temp_s1, f32 *, 8) = F32Read__18CBinaryInputStream(arg1);
            CBinaryInputStream_ReadGeom(arg1, temp_s5);
            temp_s0 = temp_s1 + 0x90;
            if (M2C_FIELD(temp_s1, M2C_UNK **, 0) == NULL) {
                M2C_FIELD(temp_s1, M2C_UNK **, 0) = &D_002C44F0;
                s32 vu_1;
                asm volatile("ldl %0, 0x7f(%1)" : "=r"(vu_1) : "r"(temp_s1));
                s32 vu_2;
                asm volatile("ldr %0, 0x78(%1)" : "=r"(vu_2) : "r"(temp_s1), "0"(vu_1));
                temp_v0_2 = vu_2;
                s32 vu_3;
                asm volatile("ldl %0, 0x87(%1)" : "=r"(vu_3) : "r"(temp_s1));
                s32 vu_4;
                asm volatile("ldr %0, 0x80(%1)" : "=r"(vu_4) : "r"(temp_s1), "0"(vu_3));
                temp_v1_3 = vu_4;
                s32 vu_5;
                asm volatile("ldl %0, 0x8f(%1)" : "=r"(vu_5) : "r"(temp_s1));
                s32 vu_6;
                asm volatile("ldr %0, 0x88(%1)" : "=r"(vu_6) : "r"(temp_s1), "0"(vu_5));
                temp_a0 = vu_6;
                asm volatile("sdl %0, 0x97(%1)" : : "r"(temp_v0_2), "r"(temp_s1));
                asm volatile("sdr %0, 0x90(%1)" : : "r"(temp_v0_2), "r"(temp_s1));
                asm volatile("sdl %0, 0x9f(%1)" : : "r"(temp_v1_3), "r"(temp_s1));
                asm volatile("sdr %0, 0x98(%1)" : : "r"(temp_v1_3), "r"(temp_s1));
                asm volatile("sdl %0, 0xa7(%1)" : : "r"(temp_a0), "r"(temp_s1));
                asm volatile("sdr %0, 0xa0(%1)" : : "r"(temp_a0), "r"(temp_s1));
                var_a1 = temp_s1 + 0x90;
            } else {
                CloneGeom(temp_s5, 0, temp_s0);
                var_a1 = temp_s0;
            }
            CBinaryInputStream_ReadBspc(arg1, var_a1, temp_s1 + 0x68);
            var_s4 += 1;
            M2C_FIELD(temp_s1, s32 *, 0x18) = U32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s1, s16 *, 0x14) = S16Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s1, s32 *, 0x1C) = S16Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s1, s64 *, 0x10) = (s64) ((M2C_FIELD(temp_s1, s64 *, 0x10) & ((((((0xFFFB << 0x10) | 0xFFFF) << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)) | ((S8Read__18CBinaryInputStream(arg1) & 1) << 0x32));
        } while (var_s4 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
    var_s4_2 = M2C_FIELD(arg0, s32 *, 0xE0);
    if (var_s4_2 < (var_s4_2 + temp_s6)) {
        var_a0 = var_s4_2 * 0xB0;
        do {
            var_s4_2 += 1;
            M2C_FIELD((M2C_FIELD(arg0, s8 **, 0xE4) + var_a0), s16 *, 0x14) = -0xA;
            var_a0 += 0xB0;
        } while (var_s4_2 < (M2C_FIELD(arg0, s32 *, 0xE0) + temp_s6));
    }
    AddSoGeomsToOxa(arg0);
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        temp_v0_3 = (s8 *)(PvAllocSwClearImpl__Fi(sp, 0xE0, 0x10));
        M2C_FIELD(arg0, s8 **, 0xE8) = temp_v0_3;
        M2C_FIELD(temp_v0_3, f32 *, 0xD0) = F32Read__18CBinaryInputStream(arg1);
        CBinaryInputStream_ReadMatrix(arg1, temp_v0_3);
        AdjustSoMomint__FP2SOf(arg0, 0x3F800000);
        temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *), 0x204)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x200));
    }
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(arg0, arg1);
    if (M2C_FIELD(arg0, s32 *, 0xB8) != 0) {
        temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x40);
        if ((temp_v1_4 ^ 1) & 1) {
            *(s32 *)temp_v1_4 = (s32) (*(s32 *)temp_v1_4 | 8);
        } else {
            M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_v1_4 | 8);
        }
    }
    func_001F2500(arg0);
    LoadSwObjectsFromBrx(arg0, arg1, 0);
    SetLoGrfzon(arg0, temp_fp);
}
}
