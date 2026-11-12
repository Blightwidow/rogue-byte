#include "types.h"

extern "C" {
s32 dpcmp(f64, f64);
f64 __muldf3(f64, f64);
f64 __subdf3(f64, f64);
f64 __adddf3(f64, f64);
f64 __floatdidf(s64);
u32 func_0023DED0(f64);
}

extern "C" s64 __fixunsdfdi(f64 value) {
    f64 floored;
    f64 rest;
    s64 result = 0;

    if (dpcmp(value, 0.0) < 0) {
        return 0;
    }
    result = (s64)func_0023DED0(__muldf3(value, 2.3283064365386963e-10)) << 32;
    if (result >= 0) {
        floored = __floatdidf(result);
    } else {
        floored = __floatdidf((result >> 1) | (result & 1));
        floored = __adddf3(floored, floored);
    }
    rest = __subdf3(value, floored);
    if (dpcmp(rest, 0.0) < 0) {
        result -= (u32)func_0023DED0(__subdf3(0.0, rest));
    } else {
        result += (u32)func_0023DED0(rest);
    }
    return result;
}
