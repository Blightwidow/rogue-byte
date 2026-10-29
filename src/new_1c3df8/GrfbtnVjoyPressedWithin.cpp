typedef signed char s8; typedef short s16; typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" {
extern f32 g_2dded0;

s32 GrfbtnVjoyPressedWithin(s8 *arg0, u32 arg1, f32 fparg0) {
    f32 limit;
    f32 *var_a0;
    s32 var_a2;
    s32 var_v1;
    u32 var_a1;

    limit = g_2dded0;
    var_a1 = arg1;
    var_a2 = 0;
    var_v1 = 0;
    if (var_a1 != 0) {
        var_a0 = (f32 *)(arg0 + 0x88);
        do {
            if ((var_a1 & 1) && ((limit - *var_a0) <= fparg0)) {
                var_a2 |= 1 << var_v1;
            }
            var_a1 = var_a1 >> 1;
            var_a0 += 1;
            var_v1 += 1;
        } while (var_a1 != 0);
    }
    return var_a2;
}

}
