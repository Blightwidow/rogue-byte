typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_StartStreamAmb {
    /* 0x000 */ s32 sp0;                            /* inferred */
    /* 0x004 */ s32 sp4;                            /* inferred */
    /* 0x008 */ s32 sp8;                            /* inferred */
    /* 0x00C */ char padC[0x104];                   /* maybe part of sp8[0x42]? */
    /* 0x110 */ s32 sp110;                          /* inferred */
    /* 0x114 */ s32 sp114;                          /* inferred */
    /* 0x118 */ s32 sp118;                          /* inferred */
    /* 0x11C */ s32 sp11C;                          /* inferred */
    /* 0x120 */ s32 sp120;                          /* inferred */
    /* 0x124 */ s32 sp124;                          /* inferred */
    /* 0x128 */ char pad128[0x58];
};                                                  /* size = 0x180 */
M2C_UNK Clear__13CFileLocation(s8 *);             /* extern */
M2C_UNK PauseAmb(s8 *, s32);                      /* extern */
M2C_UNK SetAmbGrf(s8 *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_001FD080(M2C_UNK *, s8 *);               /* extern */
M2C_UNK func_00233130(M2C_UNK, M2C_UNK, M2C_UNK, s32 *, M2C_UNK *, s8 *); /* extern */
extern M2C_UNK B_003DD040;
extern M2C_UNK OnStreamAmbStarted;
void StartStreamAmb(s8 *arg0) {
    s8 sp[0x100] __attribute__((aligned(16)));
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 sp110;
    s32 sp114;
    s32 sp118;
    s32 sp11C;
    s32 sp120;
    s32 sp124;
    M2C_UNK var_a1_2;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_v0;
    s8 *temp_v0_2;
    s8 *var_a1;
    sp8 = 2;
    Clear__13CFileLocation(sp);
    var_a1 = M2C_FIELD(arg0, s8 **, 0x60);
    temp_s2 = func_001FD080(&B_003DD040, M2C_FIELD(arg0, s8 **, 0x60));
    if (var_a1 == NULL) {
        var_v0 = 0;
    } else {
        temp_a0 = M2C_FIELD(var_a1, s32 *, 0x34);
        temp_v0 = M2C_FIELD(var_a1, s32 *, 0);
        temp_v1 = M2C_FIELD(var_a1, s32 *, 4);
        var_a1 = M2C_FIELD(var_a1, s8 **, 0x3C);
        sp8 = 2;
        sp0 = (temp_v0 ^ temp_a0) + 0xCA0;
        sp4 = temp_v1 ^ (s32) var_a1;
        var_v0 = temp_v1 != (s32) var_a1;
    }
    if (var_v0 != 0) {
        if (sp8 != 2) {
            var_a1_2 = 0x1FFF;
        } else {
            sp110 = sp0;
            PauseAmb(arg0, (s32) var_a1);
            var_a2 = 0;
            sp120 = M2C_FIELD(arg0, s32 *, 0x3B8) | 1;
            sp118 = M2C_FIELD(arg0, s32 *, 0x14);
            sp114 = (s32) (M2C_FIELD(arg0, f32 *, 0x44) * 1024.0f);
            sp11C = temp_s2;
            if ((M2C_FIELD(&B_003DD040, s32 *, 0x10) != 0) && (temp_s2 == sp8)) {
                var_a2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x60), s32 *, 0x4C) == 0;
            }
            sp124 = var_a2;
            M2C_FIELD(arg0, s16 *, 0x52) = 1;
            temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK *, s32), 0xC)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 8), &B_003DD040, var_a2);
            func_00233130(0x524B5553, 1, 0x18, &sp110, &OnStreamAmbStarted, arg0);
            var_a1_2 = 0x3F;
        }
        SetAmbGrf(arg0, var_a1_2, 0);
        return;
    }
    SetAmbGrf(arg0, 0x1FFF, 0);
}
}
