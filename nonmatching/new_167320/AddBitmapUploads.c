#include "m2c_macros.h"

M2C_UNK AddDmaCall__4DMASP2QW(s32, s32);            /* extern */
M2C_UNK func_0016E1A8();                            /* extern */
extern s32 B_003DCFA0;
extern s32 B_003DCFA8;

void AddBitmapUploads(s32 arg0) {
    s32 *var_s1;
    s32 temp_a1;
    s32 var_s0;

    var_s0 = 0;
    func_0016E1A8();
    if (B_003DCFA0 > 0) {
        var_s1 = &B_003DCFA8;
        do {
            temp_a1 = *var_s1;
            var_s0 += 1;
            var_s1 += 4;
            AddDmaCall__4DMASP2QW(arg0, temp_a1);
        } while (var_s0 < B_003DCFA0);
    }
}
