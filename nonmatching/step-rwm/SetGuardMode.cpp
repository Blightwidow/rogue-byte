typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetGuardMode {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK AddGuardPriorityClass(s8 *, M2C_UNK);     /* extern */
s32 FCanSetGuardMode();                             /* extern */
M2C_UNK GoalBrain_ChooseNextCommand(...); /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK RemoveGuardPriorityClass(s8 *, M2C_UNK);  /* extern */
M2C_UNK SetAsegaMasterSpeed(s8 *, f32);           /* extern */
M2C_UNK func_0012D108(s32, s128);                   /* extern */
s8 *func_00205458(s8 *, M2C_UNK);               /* extern */
M2C_UNK func_00206DB0(s8 *);                      /* extern */
M2C_UNK func_00206E50(s8 *);                      /* extern */
s8 *func_00209518(s32);                           /* extern */
extern M2C_UNK B_003DD490;
extern s128 D_002C3D30;
extern s128 RO_002A2DE0;
extern f32 g_2dded0;
void SetGuardMode(s8 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_9;
    s32 var_v0;
    u32 var_v1;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    if (arg1 != M2C_FIELD(arg0, s32 *, 0xFBC)) {
        if (FCanSetGuardMode() != 0) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0xFBC);
            M2C_FIELD(arg0, s32 *, 0xFBC) = arg1;
            M2C_FIELD(arg0, f32 *, 0xFC0) = (f32) g_2dded0;
            switch (temp_v0) {                      /* switch 1 */
            case 8:                                 /* switch 1 */
            case 13:                                /* switch 1 */
                temp_a0 = M2C_FIELD(arg0, s32 *, 0xFC4);
                if (temp_a0 != 0) {
                    func_0012D108(temp_a0, RO_002A2DE0);
                }
            default:                                /* switch 1 */
block_15:
                var_v1 = arg1 - 8;
block_16:
                var_v0 = var_v1 < 0x1EU;
                break;
            case 34:                                /* switch 1 */
            case 37:                                /* switch 1 */
                RemoveGuardPriorityClass(arg0, 0x38);
                func_00206E50(arg0);
                goto block_15;
            case 14:                                /* switch 1 */
                temp_v0_2 = func_00205458(arg0, 0x9D);
                var_v1 = arg1 - 8;
                if (temp_v0_2 != NULL) {
                    temp_v0_3 = func_00209518(M2C_FIELD(temp_v0_2, s32 *, 0x40));
                    var_v1 = arg1 - 8;
                    if (temp_v0_3 != NULL) {
                        SetAsegaMasterSpeed(temp_v0_3, M2C_FIELD(M2C_FIELD(temp_v0_3, s8 **, 0x14), f32 *, 0x78));
                        goto block_15;
                    }
                }
                goto block_16;
            case 21:                                /* switch 1 */
                temp_v0_4 = func_00205458(arg0, 0x9C);
                if (temp_v0_4 != NULL) {
                    var_v1 = arg1 - 8;
                    if ((M2C_FIELD(temp_v0_4, s32 *, 0x30) == 0x12) && (var_v1 = arg1 - 8, (M2C_FIELD(temp_v0_4, s32 *, 0x40) == PpoSwFocusBase(&B_003DD490)))) {
                        var_v0 = var_v1 < 0x1EU;
                        if (M2C_FIELD(temp_v0_4, f32 *, 0x44) == 3.4028235e38f) {
                            GoalBrain_ChooseNextCommand(temp_v0_4);
                            goto block_15;
                        }
                    } else {
                        goto block_16;
                    }
                } else {
                    goto block_15;
                }
                break;
            }
            if (var_v0 != 0) {
                switch (var_v1) {                   /* switch 2 */
                case 0:                             /* switch 2 */
                case 5:                             /* switch 2 */
                    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xFC4);
                    if (temp_a0_2 != 0) {
                        func_0012D108(temp_a0_2, D_002C3D30);
                    }
                    break;
                case 26:                            /* switch 2 */
                case 29:                            /* switch 2 */
                    AddGuardPriorityClass(arg0, 0x38);
                    func_00206DB0(arg0);
                    break;
                case 6:                             /* switch 2 */
                    temp_v0_5 = func_00205458(arg0, 0x9D);
                    if (temp_v0_5 != NULL) {
                        temp_v0_6 = func_00209518(M2C_FIELD(temp_v0_5, s32 *, 0x40));
                        if (temp_v0_6 != NULL) {
                            SetAsegaMasterSpeed(temp_v0_6, 0.0f);
                        }
                    }
                    temp_v0_7 = arg0 + 0x190;
                    M2C_FIELD(temp_v0_7, s32 *, 4) = 0;
                    M2C_FIELD(temp_v0_7, s32 *, 8) = 0;
                    M2C_FIELD(arg0, s32 *, 0x190) = 0;
                    break;
                case 13:                            /* switch 2 */
                    temp_v0_8 = func_00205458(arg0, 0x9C);
                    if (temp_v0_8 != NULL) {
                        temp_v0_9 = M2C_FIELD(temp_v0_8, s32 *, 0x30);
                        switch (temp_v0_9) {        /* switch 3 */
                        case 1:                     /* switch 3 */
                        case 2:                     /* switch 3 */
                        case 3:                     /* switch 3 */
                        case 4:                     /* switch 3 */
                        case 12:                    /* switch 3 */
                        case 16:                    /* switch 3 */
                        case 17:                    /* switch 3 */
                        case 18:                    /* switch 3 */
                            GoalBrain_ChooseNextCommand(temp_v0_8, temp_v0_8);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
}
