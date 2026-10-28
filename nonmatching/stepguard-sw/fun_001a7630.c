#include "m2c_macros.h"

M2C_UNK CdPath__FPcT0i(); /* extern */
M2C_UNK FCdCompleted__Fi();                  /* extern */
s32 FValidCdMmode__Fv();                            /* extern */
M2C_UNK FlushCache(); /* extern */
M2C_UNK SetCdMmode__Fv();                           /* extern */
M2C_UNK func_00238BD0();                            /* extern */
s32 func_00238C58();                 /* extern */
M2C_UNK func_00238D40();                         /* extern */
M2C_UNK func_002425F0();                     /* extern */
M2C_UNK sceCdInit();                         /* extern */
M2C_UNK sceFsReset();                               /* extern */
M2C_UNK sceSifInitRpc();                     /* extern */
M2C_UNK sceSifLoadFileReset();                      /* extern */
s32 sceSifLoadModule();                /* extern */
s32 sceSifRebootIop();                        /* extern */
s32 sceSifSetDma();                  /* extern */
s32 sceSifSyncIop();                                /* extern */
extern s32 B_002E2058;
extern u32 D_004E5D80;
extern u32 D_004E5E38;

void func_001A7630(void) {
    char sp[0x400];
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_a2;
    s32 var_s1;
    s32 var_s3;
    u8 *var_a1;
    u8 *var_s2;

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
        CdPath__FPcT0i(sp, "ioprp300.img", 1);
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
            temp_v0 = *var_a1;
            var_a1 += 0x14;
            var_a2 = (temp_v0 >= var_a2) ? temp_v0 : var_a2;
        } while (var_a1 < (u32) D_004E5E38);
    }
    temp_s4 = func_00238C58(var_a2, (s32 *) var_a1, var_a2);
    var_s2 = D_004E5D80;
    if (var_s2 < (u32) D_004E5E38) {
        var_s1 = *var_s2;
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
            var_s1 = *var_s2;
            goto loop_15;
        }
    }
    func_00238D40(temp_s4);
}
