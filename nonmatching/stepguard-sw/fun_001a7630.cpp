typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A7630 {
    /* 0x000 */ char pad0[0x180];
};                                                  /* size = 0x180 */
M2C_UNK CdPath__FPcT0i(s8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK FCdCompleted__Fi(M2C_UNK);                  /* extern */
s32 FValidCdMmode__Fv();                            /* extern */
M2C_UNK FlushCache(M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK SetCdMmode__Fv();                           /* extern */
M2C_UNK func_00238BD0();                            /* extern */
s32 func_00238C58(s32, s32 *, s32);                 /* extern */
M2C_UNK func_00238D40(s32);                         /* extern */
M2C_UNK func_002425F0(M2C_UNK);                     /* extern */
M2C_UNK sceCdInit(M2C_UNK);                         /* extern */
M2C_UNK sceFsReset();                               /* extern */
M2C_UNK sceSifInitRpc(M2C_UNK);                     /* extern */
M2C_UNK sceSifLoadFileReset();                      /* extern */
s32 sceSifLoadModule(s32, s32, s32);                /* extern */
s32 sceSifRebootIop(s8 *);                        /* extern */
s32 sceSifSetDma(s8 *, M2C_UNK);                  /* extern */
s32 sceSifSyncIop();                                /* extern */
extern s32 B_002E2058;
extern u32 D_004E5D80;
extern u32 D_004E5E38;
void func_001A7630(void) {
    s8 sp[0xf0] __attribute__((aligned(16)));
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_a2;
    s32 var_s1;
    s32 var_s3;
    u32 var_a1;
    u32 var_s2;
    sceSifInitRpc(0);
    sceSifLoadFileReset();
    sceCdInit(0);
    if (FValidCdMmode__Fv() == 0) {
loop_2:
        goto loop_2;
    }
    SetCdMmode__Fv();
    sceFsReset();
    if (B_002E2058 == 0) {
        CdPath__FPcT0i(sp, (M2C_UNK *)("ioprp300.img"), 1);
        do {
        } while (sceSifRebootIop(sp) == 0);
        do {
        } while (sceSifSyncIop() == 0);
        sceSifInitRpc(0);
        sceSifLoadFileReset();
        sceCdInit(0);
        if (FValidCdMmode__Fv() == 0) {
loop_8:
            goto loop_8;
        }
        SetCdMmode__Fv();
        sceFsReset();
        goto block_10;
    }
block_10:
    func_002425F0(0);
    FCdCompleted__Fi(1);
    func_00238BD0();
    var_a1 = D_004E5D80;
    var_a2 = 0;
    if (var_a1 < (u32) D_004E5E38) {
        do {
            temp_v0 = *(s32 *)var_a1;
            var_a1 += 0x14;
            var_a2 = (temp_v0 >= var_a2) ? temp_v0 : var_a2;
        } while (var_a1 < (u32) D_004E5E38);
    }
    temp_s4 = func_00238C58(var_a2, (s32 *) var_a1, var_a2);
    var_s2 = D_004E5D80;
    if (var_s2 < (u32) D_004E5E38) {
        var_s1 = *(s32 *)var_s2;
loop_15:
        var_s3 = 0;
        if (var_s1 != 0) {
            do {
                temp_a1 = temp_s4 + var_s3;
                temp_s0 = (var_s1 < 0xFFFC0) ? var_s1 : 0xFFFC0;
                FlushCache(0, temp_a1, M2C_FIELD(var_s2, s32 *, 4) + var_s3, temp_a1, temp_s0, 0);
loop_18:
                if (sceSifSetDma(sp, 1) == 0) {
                    goto loop_18;
                }
                var_s1 -= temp_s0;
                var_s3 += temp_s0;
            } while (var_s1 != 0);
        }
        do {
        } while (sceSifLoadModule(temp_s4, M2C_FIELD(var_s2, s32 *, 8), M2C_FIELD(var_s2, s32 *, 0xC)) < 0);
        var_s2 += 0x14;
        if (var_s2 < (u32) D_004E5E38) {
            var_s1 = *(s32 *)var_s2;
            goto loop_15;
        }
    }
    func_00238D40(temp_s4);
}
}
