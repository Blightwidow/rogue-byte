typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandleMurrayMessage {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
void CarryThrow_Launch(s8 *);
void HandleJtMessage();
s32 PosLoWorld(s8 *);
void SetMurrayLiftState(s8 *, M2C_UNK);
void SetMurrayState(s8 *, M2C_UNK);
s32 SpawnSwHitFx(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
void ThrowMurrayObject(s8 *);
void func_001B6DA8(s8 *, M2C_UNK);
void func_001B7AE8(s8 *);
extern M2C_UNK B_003DD490;
extern M2C_UNK D_FLT_002C0990;
extern f32 D_FLT_002C099C;
void HandleMurrayMessage(s8 *arg0, s32 arg1, s8 *arg2) {
    f32 temp_f0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    HandleJtMessage();
    switch (arg1) {                                 /* switch 1; irregular */
    case 9:                                         /* switch 1 */
        temp_v1 = M2C_FIELD(arg2, s32 *, 0);
        if ((temp_v1 == M2C_FIELD(arg0, s32 *, 0x1030)) || (temp_v1 == M2C_FIELD(arg0, s32 *, 0x190C))) {
            temp_v1_2 = M2C_FIELD(arg2, s32 *, 8);
            switch (temp_v1_2) {                    /* switch 2; irregular */
            case 0x1A4:                             /* switch 2 */
                func_001B6DA8(arg0, 1);
                break;
            case 0x1A5:                             /* switch 2 */
                s64 vu_1;
                asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(arg0)));
                SpawnSwHitFx(&B_003DD490, 0, vu_1, arg0);
                break;
            case 0x1EB:                             /* switch 2 */
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x13D0);
                switch (temp_v1_3) {                /* switch 3; irregular */
                case 7:                             /* switch 3 */
                    ThrowMurrayObject(arg0);
                    break;
                case 8:                             /* switch 3 */
                    func_001B7AE8(arg0);
                    break;
                case 15:                            /* switch 3 */
                    CarryThrow_Launch(arg0 + 0x1910);
                    break;
                }
                break;
            case 0x1C6:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1448) = 1;
                break;
            case 0x1C8:                             /* switch 2 */
                if (M2C_FIELD(arg0, s32 *, 0x1450) == 0) {
                    s64 vu_2;
                    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(PosLoWorld(arg0)));
                    SpawnSwHitFx(&B_003DD490, 0, vu_2, arg0);
                    SetMurrayLiftState(arg0, 1);
                }
                break;
            case 0x1C7:                             /* switch 2 */
                if (M2C_FIELD(arg0, s32 *, 0x1450) == 1) {
                    SetMurrayLiftState(arg0, 2);
                }
                break;
            case 0x240:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1818) = 1;
                break;
            case 0x241:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x181C) = 1;
                break;
            case 0x242:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1820) = 1;
                break;
            }
        } else {
            return;
        }
        break;
    case 10:                                        /* switch 1 */
        if ((M2C_FIELD(arg2, s32 *, 0) == M2C_FIELD(arg0, s32 *, 0x1034)) && (M2C_FIELD(arg0, s32 *, 0x13D0) == 6)) {
            temp_v1_4 = M2C_FIELD(arg2, s32 *, 8);
            if (temp_v1_4 != M2C_FIELD(arg2, s32 *, 4)) {
                switch (temp_v1_4) {                /* switch 4; irregular */
                case 0x1D0:                         /* switch 4 */
                    /* fallthrough */
                case 0x1CA:                         /* switch 4 */
                    SetMurrayState(arg0, 0);
                    break;
                default:                            /* switch 4 */
                    temp_f0 = *((M2C_FIELD(arg0, s32 *, 0x1534) * 4) + &D_FLT_002C0990);
                    M2C_FIELD(arg0, f32 *, 0x1528) = temp_f0;
                    M2C_FIELD(arg0, f32 *, 0x1524) = temp_f0;
                    M2C_FIELD(arg0, s32 *, 0x152C) = (s32) (D_FLT_002C099C * temp_f0);
                    break;
                }
            }
        }
        break;
    }
}
}
