#include "m2c_macros.h"

M2C_UNK CancelSwCallbacks(M2C_UNK *, M2C_UNK, void *, M2C_UNK); /* extern */
M2C_UNK RemoveLoHierarchy();                        /* extern */
M2C_UNK RemoveSoGeomsFromOxa(void *);               /* extern */
M2C_UNK func_001F37C8(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;
extern void *g_2dd2fc;

void RemoveSoLoHierarchy(void *arg0) {
    char sp[0x400];
    void **sp4;
    s32 sp8;
    void *spC;
    s32 temp_v0_2;
    s32 var_v1;
    void **temp_v1;
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;
    void *temp_v1_2;
    void *var_a2;
    void *var_v0;

    RemoveLoHierarchy();
    RemoveSoGeomsFromOxa(arg0);
    var_v1 = 0;
    temp_v0 = M2C_FIELD(arg0, void **, 0xE8);
    M2C_FIELD(arg0, s32 *, 0x130) = 0;
    M2C_FIELD(arg0, f32 *, 0x12C) = 1.0f;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, s32 *, 0xDC);
    }
    if (var_v1 != 0) {
        M2C_ERROR(/* unknown instruction: ldl $a3, %lo(RO_002A8277)($v0) */);
        CancelSwCallbacks(&B_003DD490, 3, arg0, M2C_ERROR(/* unknown instruction: ldr $a3, %lo(RO_002A8270)($v0) */));
        func_001F37C8(arg0, 0);
    }
    temp_v1 = arg0 + 0x64;
    sp4 = temp_v1;
    temp_a1 = g_2dd2fc;
    temp_v0_2 = M2C_FIELD(temp_v1, s32 *, 8);
    g_2dd2fc = sp;
    spC = temp_a1;
    temp_v1_2 = M2C_FIELD(arg0, void **, 0x64);
    sp8 = temp_v0_2;
    var_a2 = temp_v1_2;
    sp4 = temp_v1_2 + temp_v0_2;
    if (var_a2 != NULL) {
        if (!(M2C_FIELD(var_a2, s64 *, 0x28) & (0x8000 << 0x29))) {
            var_v0 = M2C_FIELD(var_a2, void **, 0xC);
loop_7:
            M2C_FIELD(var_v0, M2C_UNK (**)(void *), 0x64)(var_a2 + M2C_FIELD(var_v0, s16 *, 0x60));
            temp_a0 = *sp4;
            var_a2 = temp_a0;
            sp4 = temp_a0 + sp8;
            if (temp_a0 != NULL) {
                if (!(M2C_FIELD(temp_a0, s64 *, 0x28) & (0x8000 << 0x29))) {
                    var_v0 = M2C_FIELD(var_a2, void **, 0xC);
                    goto loop_7;
                }
            }
        }
    }
    g_2dd2fc = spC;
}
