typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateHub {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
s32 FActiveCplcy(M2C_UNK *);                        /* extern */
s32 FJoyButtonPressed(M2C_UNK *, s32);              /* extern */
s32 GetSmaCur(s32);                                 /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s8 *); /* extern */
M2C_UNK ShopMenu_SetPage(M2C_UNK *, M2C_UNK, s32);  /* extern */
M2C_UNK StartJsg(s32, M2C_UNK);                     /* extern */
M2C_UNK StepHubState(s8 *, s32);                  /* extern */
s32 UpdateJoyNavX(M2C_UNK *);                       /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK B_002DE2E0;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_002E0D00;
extern M2C_UNK B_003DA150;
extern M2C_UNK B_003DD490;
extern s32 g_2dfbc0;
void UpdateHub(s8 *arg0) {
    M2C_UNK *var_s3;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s2;
    s8 *var_s0;
    UpdateSo();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x180);
    if (temp_v1 != 0) {
        if ((temp_v1 == 1) && (M2C_FIELD(arg0, s32 *, 0x188) != 0) && (FActiveCplcy(&B_002DE2E0) == 0)) {
            if (g_2dfbc0 & 2) {
                var_s3 = &B_002DFC00;
            } else {
                var_s3 = &B_002E0D00;
            }
            temp_v0 = UpdateJoyNavX(var_s3);
            if (temp_v0 == 0) {
                var_s2 = 0;
                var_s0 = arg0 + 0x190;
loop_11:
                if (var_s2 < M2C_FIELD(arg0, s32 *, 0x18C)) {
                    if ((M2C_FIELD(var_s0, s32 *, 0) == GetSmaCur(M2C_FIELD(arg0, s32 *, 0x188))) && (FJoyButtonPressed(var_s3, M2C_FIELD(var_s0, s32 *, 4)) != 0) && (temp_a2 = M2C_FIELD(var_s0, s32 *, 8), (temp_a2 != -1))) {
                        if (temp_a2 == 0x378) {
                            ShopMenu_SetPage(&B_003DA150, 0, temp_a2);
                        } else {
                            temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 4, temp_a2, arg0);
                            if (temp_v0_2 == 0) {
                                goto block_10;
                            }
                            StartJsg(temp_v0_2, 0);
                        }
                    } else {
block_10:
                        var_s0 += 0xC;
                        var_s2 += 1;
                        goto loop_11;
                    }
                }
            } else {
                StepHubState(arg0, temp_v0);
            }
        }
    }
}
}
