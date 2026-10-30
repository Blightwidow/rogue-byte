typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Swarm_Update {
    /* 0x00 */ char pad0[0xC0];
};                                                  /* size = 0xC0 */
void FindCrvClosestPointAll(s32, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, M2C_UNK, s8 *);
void FindCrvClosestPointFromS(s32, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, M2C_UNK, s8 *, f32);
f32 GRandInRange(M2C_UNK, M2C_UNK);
f32 GSmoothA__FffffP4SMPAPf(M2C_UNK *, s8 *, f32, f32, f32, f32);
void GetPathPosFromS(s32, s8 *, s8 *, f32);
s32 PosLoWorld(s32);
f32 SMaxCrv(s32);
void SwarmGroup_UpdateTargets(s8 *, s8 *);
void Swarm_UpdateRiderState(s8 *, s8 *);
void UpdateSo();
extern M2C_UNK D_002BE888;
extern f32 D_FLT_002BE898;
extern f32 D_FLT_002BE89C;
extern f32 D_FLT_002BE8A0;
extern f32 D_FLT_002BE8A4;
extern M2C_UNK g_2dded0;
extern s32 g_2dfb80;
void Swarm_Update(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f3;
    f32 temp_f5;
    f32 temp_f7;
    f32 temp_f7_2;
    f32 var_f13;
    s32 temp_s3;
    s32 var_s1;
    s8 *temp_s0;
    s8 *var_s0;
    UpdateSo();
    if (M2C_FIELD(arg0, s32 *, 0x1C0) != 0) {
        var_s1 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
            do {
                temp_s0 = arg0 + ((var_s1 * 0x30) + 0x1CC);
                temp_s3 = M2C_FIELD(temp_s0, s32 *, 0x24);
                SMaxCrv(temp_s3);
                if (M2C_FIELD(temp_s0, f32 *, 0x2C) < M2C_FIELD(&g_2dded0, f32 *, 0)) {
                    s64 vu_1;
                    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(g_2dfb80)));
                    FindCrvClosestPointAll(temp_s3, vu_1, 0, 0, sp, 0, temp_s0 + 0x28);
                    temp_f20 = M2C_FIELD(&g_2dded0, f32 *, 0);
                    M2C_FIELD(temp_s0, f32 *, 0x2C) = (f32) (temp_f20 + GRandInRange(0x3F000000, 0x3F400000));
                } else {
                    s64 vu_2;
                    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(PosLoWorld(g_2dfb80)));
                    FindCrvClosestPointFromS(temp_s3, vu_2, 0, 0, sp, 0, temp_s0 + 0x28, M2C_FIELD(temp_s0, f32 *, 0x28));
                }
                SwarmGroup_UpdateTargets(arg0, temp_s0);
                var_s0 = M2C_FIELD(temp_s0, s8 **, 0x10);
                if (var_s0 != NULL) {
                    var_f13 = M2C_FIELD(var_s0, f32 *, 0x40);
loop_8:
                    temp_f0 = GSmoothA__FffffP4SMPAPf(&D_002BE888, var_s0 + 0x40, M2C_FIELD(var_s0, f32 *, 0x3C), var_f13, M2C_FIELD(var_s0, f32 *, 0x44), M2C_FIELD(&g_2dded0, f32 *, 4));
                    M2C_FIELD(var_s0, f32 *, 0x3C) = temp_f0;
                    GetPathPosFromS(temp_s3, var_s0, var_s0 + 0x10, temp_f0);
                    temp_f7 = M2C_FIELD(var_s0, f32 *, 0x50);
                    temp_f3 = M2C_FIELD(var_s0, f32 *, 0x58);
                    temp_f5 = M2C_FIELD(var_s0, f32 *, 0x5C);
                    temp_f0_2 = temp_f3 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((D_FLT_002BE898 * temp_f7) + (D_FLT_002BE89C * temp_f3)));
                    M2C_FIELD(var_s0, f32 *, 0x58) = temp_f0_2;
                    temp_f7_2 = temp_f7 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((temp_f3 + temp_f0_2) * 0.5f));
                    M2C_FIELD(var_s0, f32 *, 0x50) = temp_f7_2;
                    temp_f1 = temp_f5 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((D_FLT_002BE8A0 * M2C_FIELD(var_s0, f32 *, 0x54)) + (D_FLT_002BE8A4 * temp_f5)));
                    M2C_FIELD(var_s0, f32 *, 0x5C) = temp_f1;
                    M2C_FIELD(var_s0, f32 *, 0x50) = (f32) (temp_f7_2 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((temp_f5 + temp_f1) * 0.5f)));
                    Swarm_UpdateRiderState(arg0, var_s0);
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
                    if (var_s0 != NULL) {
                        var_f13 = M2C_FIELD(var_s0, f32 *, 0x40);
                        goto loop_8;
                    }
                }
                var_s1 += 1;
            } while (var_s1 < M2C_FIELD(arg0, s32 *, 0x1C8));
        }
    }
}
}
