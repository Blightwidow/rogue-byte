#include "m2c_macros.h"

M2C_UNK FlushCache(M2C_UNK);                        /* extern */
M2C_UNK func_00233828();                            /* extern */
M2C_UNK func_002396C0(M2C_UNK *, M2C_UNK, M2C_UNK, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK main(s32, s32 *);                           /* extern */
extern s128 B_002DD280;
extern s32 B_002DD380;
extern M2C_UNK D_00472200;

void entry(void) {
    s128 *var_v0;

    M2C_ERROR(/* unknown instruction: padduw $at, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $v0, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $v1, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $a0, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $a1, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $a2, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $a3, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t0, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t1, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t2, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t3, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t4, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t5, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t6, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t7, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s0, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s1, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s2, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s3, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s4, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s5, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s6, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $s7, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t8, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $t9, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $gp, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $sp, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $fp, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: padduw $ra, $zero, $zero */);
    M2C_ERROR(/* unknown instruction: mtsah $zero, 0x0 */);
    M2C_ERROR(/* unknown instruction: adda.s $f0, $f1 */);
    M2C_ERROR(/* unknown instruction: sync.p */);
    var_v0 = &B_002DD280;
loop_1:
    if ((s32) var_v0 & 0xF) {
        *var_v0 = 0;
        var_v0 += 1;
        goto loop_1;
    }
loop_4:
    if (var_v0 != ((s32) &D_00472200 & 0xFFFFFFF0)) {
        *var_v0 = 0;
        var_v0 += 0x10;
        goto loop_4;
    }
loop_6:
    if (var_v0 != &D_00472200) {
        *var_v0 = 0;
        var_v0 += 1;
        goto loop_6;
    }
    M2C_ERROR(/* unknown instruction: syscall 0x0 */);
    M2C_ERROR(/* unknown instruction: syscall 0x0 */);
    func_002396C0(&D_00472200, -1, 0x20000, &B_002DD380, 0, 0, 0, 0, 0, 0, 0, 0);
    FlushCache(0);
    M2C_ERROR(/* unknown instruction: ei */);
    main(B_002DD380, &B_002DD380 + 4);
    func_00233828();
}
