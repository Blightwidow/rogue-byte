#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK LoadSoFromBrx(void *, s32);                 /* extern */
s32 PvAllocStackClearImpl__Fi(s32 *);               /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */
s32 PvAllocSwCopyImpl__FiPv(s32 *, s32);            /* extern */

void LoadStgSwitchFromBrx(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 sp10;
    s32 sp14;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s2;
    void *temp_s0;
    void *temp_s1;

    CStackFrame_Construct(sp);
    sp10 = 0x40;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x154) = PvAllocStackImpl__Fi(&sp10);
    sp10 = 0x200;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x164) = (s32) (PvAllocStackClearImpl__Fi(&sp10) + 0x10);
    LoadSoFromBrx(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x15C) = 0;
    sp10 = M2C_FIELD(arg0, s32 *, 0x150) * 8;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x160);
    M2C_FIELD(arg0, s32 *, 0x154) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0x154));
    if (temp_v1 != 0) {
        sp14 = 0x10;
        sp10 = (temp_v1 * 0x10) + 0x10;
        var_s0 = -1;
        M2C_FIELD(arg0, s32 *, 0x164) = (s32) (PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0x164) - 0x10) + 0x10);
        if (M2C_FIELD(arg0, s32 *, 0x160) > -1) {
loop_3:
            temp_s1 = M2C_FIELD(arg0, s32 *, 0x164) + (var_s0 * 0x10);
            var_s2 = 0;
            sp14 = 0x10;
            sp10 = M2C_FIELD(temp_s1, s32 *, 8) * 8;
            M2C_FIELD(temp_s1, s32 *, 0xC) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(temp_s1, s32 *, 0xC));
            if (M2C_FIELD(temp_s1, s32 *, 8) > 0) {
                do {
                    temp_s0 = M2C_FIELD(temp_s1, s32 *, 0xC) + (var_s2 * 8);
                    if (M2C_FIELD(temp_s0, s32 *, 0) == 0xC) {
                        sp10 = 8;
                        M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                        M2C_FIELD(temp_s0, s32 *, 4) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(temp_s0, s32 *, 4));
                    }
                    var_s2 += 1;
                } while (var_s2 < M2C_FIELD(temp_s1, s32 *, 8));
            }
            var_s0 += 1;
            if (var_s0 < M2C_FIELD(arg0, s32 *, 0x160)) {
                goto loop_3;
            }
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x164) = 0;
    }
    CStackFrame_Destructor(sp, 2);
}
