typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_snd_StartSoundSystem {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
void func_002325E0(M2C_UNK, M2C_UNK, s8 *, M2C_UNK *, M2C_UNK *, s32);
void printf(M2C_UNK *, M2C_UNK *, M2C_UNK);
s32 sceSifBindRpc(M2C_UNK *, s32, M2C_UNK);
void sceSifInitRpc(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK *);
extern M2C_UNK B_00443800;
extern s32 B_00443B80;
extern s32 B_00444B80;
extern M2C_UNK B_00445B80;
extern M2C_UNK B_00446B80;
extern M2C_UNK B_00447B80;
extern M2C_UNK B_00447FC0;
extern M2C_UNK B_00448400;
extern M2C_UNK B_00448440;
extern s32 B_00448480;
extern M2C_UNK D_002C4660;
extern M2C_UNK D_002C4668;
extern M2C_UNK D_002C4670;
extern M2C_UNK D_002C4678;
extern s32 D_002C4688;
extern M2C_UNK D_002C4690;
extern s32 D_002C46B8;
extern M2C_UNK RO_002AA100;
extern M2C_UNK RO_002AA128;
void snd_StartSoundSystem(s32 arg0) {
    s8 sp[0xB0] __attribute__((aligned(16)));
    s32 var_v0;
    s32 var_v0_2;
    M2C_FIELD(&D_002C4660, s32 **, 0) = &B_00443B80;
    M2C_FIELD(&D_002C4660, s32 **, 4) = &B_00444B80;
    M2C_FIELD(&D_002C4678, M2C_UNK **, 0) = &B_00447B80;
    M2C_FIELD(&D_002C4678, M2C_UNK **, 4) = &B_00447FC0;
    M2C_FIELD(&D_002C4670, M2C_UNK **, 0) = &B_00445B80;
    M2C_FIELD(&D_002C4670, M2C_UNK **, 4) = &B_00446B80;
    if (arg0 & 2) {
        D_002C46B8 = 1;
    } else {
        D_002C46B8 = 0;
    }
    sceSifInitRpc(0, &B_00447B80, &B_00447FC0, &B_00445B80);
loop_4:
    if (sceSifBindRpc(&B_00443800, 0x123456, 0) < 0) {
        printf(&RO_002AA100, &RO_002AA128, 0xB5);
loop_6:
        goto loop_6;
    }
    var_v0 = 0x270E;
    do {
        var_v0 -= 1;
    } while (var_v0 != -1);
    if (M2C_FIELD(&B_00443800, s32 *, 0x24) != 0) {
        D_002C4688 = 0;
        M2C_FIELD(&D_002C4690, s32 *, 0) = 0;
        M2C_FIELD(&D_002C4690, s64 *, 8) = 0;
        B_00448480 = 0;
loop_11:
        if (sceSifBindRpc(&B_00448440, 0x123457, 0) < 0) {
            printf(&RO_002AA100, &RO_002AA128, 0xCA);
loop_13:
            goto loop_13;
        }
        var_v0_2 = 0x270E;
        do {
            var_v0_2 -= 1;
        } while (var_v0_2 != -1);
        if (M2C_FIELD(&B_00448440, s32 *, 0x24) != 0) {
            M2C_FIELD(&B_00448400, s32 *, 0) = 0;
            M2C_FIELD(&D_002C4668, s32 *, 4) = 0xFFC;
            M2C_FIELD(&D_002C4668, s32 *, 0) = 0xFFC;
            B_00443B80 = 0;
            B_00444B80 = 0;
            M2C_FIELD(&B_00448400, s32 *, 0x10) = 0;
            func_002325E0(0, 8, sp, &B_00448400, &B_00448400, arg0);
            return;
        }
        goto loop_11;
    }
    goto loop_4;
}
}
