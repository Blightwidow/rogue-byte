typedef int s32;
typedef float f32;
extern "C" {
s32 FFindCrvSInPathzone(s32, s32, f32 *, s32, f32, f32);
f32 SMaxCrv(s32);
s32 func_001BCAC0(s32, s32, s32, f32, f32);
extern f32 g_2c0ab8;
s32 func_001BCCE0(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, f32 fparg0) {
    f32 sp[2];
    f32 var_f20;
    f32 var_f21;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s2;
    s32 var_v0;
    if (((FFindCrvSInPathzone(arg0, arg1, &sp[0], 0, fparg0, SMaxCrv(arg0) * 0.5f) != 0) || (FFindCrvSInPathzone(arg0, arg1, &sp[0], 1, fparg0, SMaxCrv(arg0) * 0.5f) != 0)) && ((FFindCrvSInPathzone(arg0, arg1, &sp[1], 0, *arg2, SMaxCrv(arg0) * 0.5f) != 0) || (FFindCrvSInPathzone(arg0, arg1, &sp[1], 1, *arg2, SMaxCrv(arg0) * 0.5f) != 0))) {
        var_f21 = sp[1] - sp[0];
        *arg2 = sp[1];
        if (var_f21 < 0.0f) {
            var_f21 += SMaxCrv(arg0);
        }
        if (arg3 != 1) {
            if (arg3 == 2) {
                var_f20 = g_2c0ab8 + 1.0f;
            } else {
                var_f20 = 1.0f;
            }
        } else {
            var_f20 = 1.0f - g_2c0ab8;
        }
        var_s2 = 1;
        if (!(var_f21 < (SMaxCrv(arg0) * var_f20 * 0.5f))) {
            var_s2 = 0;
        }
        temp_s0 = func_001BCAC0(arg0, arg1, 1, sp[0], sp[1]);
        temp_v0 = func_001BCAC0(arg0, arg1, 0, sp[0], sp[1]);
        var_v0 = 1;
        if (temp_v0 >= temp_s0) {
            var_v0 = 2;
            if (temp_s0 >= temp_v0) {
                if (temp_s0 != 2) {
                    return (var_s2 != 0) ? 2 : 1;
                }
                return 4;
            }
        }
        return var_v0;
    }
    return 4;
}
}
