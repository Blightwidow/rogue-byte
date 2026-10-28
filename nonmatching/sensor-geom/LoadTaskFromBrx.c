#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct();              /* extern */
M2C_UNK CStackFrame_Destructor();    /* extern */
M2C_UNK LoadLoFromBrx();                 /* extern */
s32 PvAllocStackImpl__Fi();                    /* extern */
s32 PvAllocSwClearImpl__Fi();                  /* extern */
s32 PvAllocSwCopyImpl__FiPv();   /* extern */
s32 PvAllocSwImpl__Fi();                       /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
s32 U8Read__18CBinaryInputStream();              /* extern */
M2C_UNK Unknown1__18CBinaryInputStream();        /* extern */

void LoadTaskFromBrx(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    u8 *temp_v1;
    u8 *temp_v1_2;
    s32 var_s1;
    s32 var_s3;

    var_s3 = 0;
    CStackFrame_Construct(sp);
    sp10 = 0x200;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xAC) = PvAllocStackImpl__Fi(&sp10);
    sp10 = 0x300;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xB4) = PvAllocStackImpl__Fi(&sp10);
    LoadLoFromBrx(arg0, arg1);
    sp10 = M2C_FIELD(arg0, s32 *, 0xA8) * 0x10;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xAC) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0xAC));
    sp10 = M2C_FIELD(arg0, s32 *, 0xB0) * 0x18;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xB4) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0xB4), 0x18);
    temp_v0 = U8Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x94) = temp_v0;
    sp10 = temp_v0 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x98) = PvAllocSwClearImpl__Fi(&sp10);
    sp10 = M2C_FIELD(arg0, s32 *, 0x94) * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x90) = PvAllocSwImpl__Fi(&sp10);
    if (M2C_FIELD(arg0, s32 *, 0x94) > 0) {
        do {
            temp_v1 = var_s3 * 4;
            var_s3 += 1;
            *(temp_v1 + M2C_FIELD(arg0, s32 *, 0x90)) = S32Read__18CBinaryInputStream(arg1);
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x94));
    }
    temp_v0_2 = U8Read__18CBinaryInputStream(arg1);
    var_s1 = 0;
    M2C_FIELD(arg0, s32 *, 0xA0) = temp_v0_2;
    sp10 = temp_v0_2 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xA4) = PvAllocSwClearImpl__Fi(&sp10);
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    sp10 = M2C_FIELD(arg0, s32 *, 0xA0) * 4;
    M2C_FIELD(arg0, s32 *, 0x9C) = PvAllocSwImpl__Fi(&sp10);
    if (M2C_FIELD(arg0, s32 *, 0xA0) > 0) {
        do {
            temp_v1_2 = var_s1 * 4;
            var_s1 += 1;
            *(temp_v1_2 + M2C_FIELD(arg0, s32 *, 0x9C)) = S32Read__18CBinaryInputStream(arg1);
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0xA0));
    }
    Unknown1__18CBinaryInputStream(arg1);
    CStackFrame_Destructor(sp, 2);
}
