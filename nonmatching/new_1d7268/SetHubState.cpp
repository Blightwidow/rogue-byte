typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetHubState {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s8 *sp10;                         /* inferred */
    /* 0x014 */ char pad14[0x7C];                   /* maybe part of sp10[0x20]? */
    /* 0x090 */ s8 *sp90;                         /* inferred */
    /* 0x094 */ char pad94[0x7C];                   /* maybe part of sp90[0x20]? */
    /* 0x110 */ M2C_UNK sp110;                      /* inferred */
    /* 0x110 */ char pad110[4];
    /* 0x114 */ s32 sp114;                          /* inferred */
    /* 0x118 */ char pad118[0x98];
};                                                  /* size = 0x1B0 */
#define sp114 (*(s32 *)(sp + 0x114))
void CRef_Destruct(M2C_UNK *);
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 **);
void DeliverJtLoot(s8 *);
s32 IsmsFindSmOptional__FP2SM3OID(s32, s32);
s32 OidFromSmIsms(s32, M2C_UNK);
void StepHubState(s8 *, M2C_UNK);
void bevy_jobs_162e38(s8 *);
void bevy_player_p18_gadget_refill(s8 *, M2C_UNK);
void func_00187E78(M2C_UNK *);
void func_001D8A38(M2C_UNK *, M2C_UNK *, M2C_UNK);
void func_001F1448(s32, s8 *, s32, M2C_UNK, s8 *);
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_002E0D00;
extern M2C_UNK B_003DD490;
extern s32 g_2dfbc0;
void SetHubState(s8 *arg0, s32 arg1) {
    s8 sp[0x100] __attribute__((aligned(16)));
    s8 *sp10;
    s8 *sp90;
    M2C_UNK sp110;
    M2C_UNK *var_a0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s2;
    s32 var_v0;
    s8 **var_s1;
    s8 **var_s1_2;
    s8 **var_s1_3;
    s8 *temp_a1;
    s8 *temp_v0_2;
    s8 *temp_v0_5;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    s8 *var_a2;
    s8 *var_s0;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x180);
    if (temp_v0 != arg1) {
        if (temp_v0 == 1) {
            func_001F1448(0, arg0, -1, 0, arg0 + 0x188);
            temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x18), 6, 0, 0, 0, 0);
        }
        M2C_FIELD(arg0, s32 *, 0x180) = arg1;
        if (arg1 == 1) {
            if ((M2C_FIELD(&B_003DD490, s8 **, 0x3B0C) != NULL) && (M2C_FIELD(M2C_FIELD(&B_003DD490, s8 **, 0x3B0C), s32 *, 0x74) == 0)) {
                bevy_jobs_162e38(M2C_FIELD(&B_003DD490, s8 **, 0x3B0C));
            }
            temp_v0_3 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0, 3, (s8 **)(sp));
            if (temp_v0_3 > 0) {
                var_s2 = temp_v0_3;
                var_s1 = (s8 **)(sp);
                var_s0 = (s8 *)(*sp);
loop_9:
                var_s2 -= 1;
                var_s1 += 4;
                DeliverJtLoot(var_s0);
                bevy_player_p18_gadget_refill(var_s0, 1);
                if (var_s2 != 0) {
                    var_s0 = *var_s1;
                    goto loop_9;
                }
            }
            temp_v0_4 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x64, 0, 0x20, &sp10);
            if (temp_v0_4 > 0) {
                var_s1_2 = &sp10;
                var_s0_2 = temp_v0_4;
                var_a2 = *var_s1_2;
loop_14:
                var_s1_2 += 4;
                var_s0_2 -= 1;
                temp_v0_5 = M2C_FIELD(var_a2, s8 **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x264)(var_a2 + M2C_FIELD(temp_v0_5, s16 *, 0x260), 4, var_a2);
                if (var_s0_2 != 0) {
                    var_a2 = *var_s1_2;
                    goto loop_14;
                }
            }
            temp_v0_6 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x4F, 0, 0x20, &sp90);
            if (temp_v0_6 > 0) {
                var_s1_3 = &sp90;
                var_s0_3 = temp_v0_6;
                do {
                    temp_a1 = *var_s1_3;
                    var_s0_3 -= 1;
                    var_s1_3 += 4;
                    temp_v0_7 = M2C_FIELD(temp_a1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_7, M2C_UNK (**)(s8 *, s8 *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_7, s16 *, 0x48), temp_a1);
                } while (var_s0_3 != 0);
            }
            if (M2C_FIELD(arg0, s32 *, 0x184) != 0) {
                func_001D8A38(&sp110, (M2C_UNK *)("oidPoCurrent"), 0);
                CRef_Destruct(&sp110);
                var_v0 = sp114;
                if (IsmsFindSmOptional__FP2SM3OID(M2C_FIELD(arg0, s32 *, 0x184), sp114) == -1) {
                    var_v0 = OidFromSmIsms(M2C_FIELD(arg0, s32 *, 0x184), 0);
                }
            } else {
                var_v0 = -1;
            }
            func_001F1448(M2C_FIELD(arg0, s32 *, 0x184), arg0, var_v0, 0, arg0 + 0x188);
            StepHubState(arg0, 0);
            if (g_2dfbc0 & 2) {
                var_a0 = &B_002DFC00;
            } else {
                var_a0 = &B_002E0D00;
            }
            func_00187E78(var_a0);
            temp_v0_8 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_8, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_8, s16 *, 0x18), 5, 0, 0, 0, 0);
        }
    }
}
}
