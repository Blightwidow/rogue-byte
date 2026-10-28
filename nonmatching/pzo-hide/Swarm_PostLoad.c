#include "m2c_macros.h"

M2C_UNK AddSoGeomsToOxa(void *, s32, M2C_UNK, s32); /* extern */
M2C_UNK AppendDlEntry(void *, void *);              /* extern */
M2C_UNK InitDl__FP2DLi(void *, M2C_UNK);            /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
void *PvAllocSwClearImpl__Fi(void *, s32, s32);     /* extern */
M2C_UNK func_0017F138(void *);                      /* extern */
extern M2C_UNK B_003DD490;

void Swarm_PostLoad(void *arg0) {
    char sp[0x400];
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_s1;
    s32 var_s4;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_v0_2;
    void *var_s0;

    var_s4 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
        var_s0 = arg0 + 0x1CC;
        do {
            temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s0, s32 *, 0), arg0);
            M2C_FIELD(var_s0, s32 *, 0x24) = temp_v0;
            if (temp_v0 == 0) {
                var_s0 -= 0x30;
                var_s4 -= 1;
                M2C_FIELD(arg0, s32 *, 0x1C8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C8) - 1);
            } else {
                temp_a0 = var_s0 + 0x10;
                var_s1 = 0;
                InitDl__FP2DLi(temp_a0, 0x60);
                if (M2C_FIELD(var_s0, s32 *, 4) > 0) {
                    do {
                        var_s1 += 1;
                        temp_v0_2 = PvAllocSwClearImpl__Fi(sp, 0x70, 0x10);
                        M2C_FIELD(temp_v0_2, void **, 0x20) = var_s0;
                        M2C_FIELD(temp_v0_2, s32 *, 0x24) = -1;
                        AppendDlEntry(temp_a0, temp_v0_2);
                    } while (var_s1 < M2C_FIELD(var_s0, s32 *, 4));
                }
            }
            var_s4 += 1;
            var_s0 += 0x30;
        } while (var_s4 < M2C_FIELD(arg0, s32 *, 0x1C8));
    }
    func_0017F138(arg0);
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0xE0);
    temp_a1 = temp_v0_3 * 0xB0;
    temp_a3 = M2C_FIELD(arg0, s32 *, 0x60);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v0_3 + 1);
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xE4) + temp_a1;
    M2C_FIELD(temp_a0_2, s32 *, 0) = temp_a3;
    M2C_FIELD(temp_a0_2, s32 *, 0xC) = -1;
    M2C_FIELD(temp_a0_2, void **, 4) = arg0;
    M2C_FIELD(temp_a0_2, s64 *, 0x10) = (s64) (M2C_FIELD(temp_a0_2, s64 *, 0x10) | (0x8000 << 0x21) | (0x8000 << 0x22));
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        AddSoGeomsToOxa(arg0, temp_a1, -1, temp_a3);
    }
}
