extern "C" {
typedef union { float value; int bits; } FloatBits;
extern float RO_FLT_002AB860[4];
extern float RO_FLT_002AB870[4];
extern float RO_FLT_002AB880[11];
float func_00244EF8(float); // fabsf, called out of line (the compiler inlines the fabsf name)
float atanf(float x) {
    float result, weight, square, odd, even;
    int highWord, absoluteWord, id;
    FloatBits bits;
    bits.value = x;
    highWord = bits.bits;
    absoluteWord = highWord & 0x7FFFFFFF;
    if (absoluteWord > 0x507FFFFF) {
        if (absoluteWord > 0x7F800000) {
            return x + x;
        }
        if (highWord > 0) {
            return RO_FLT_002AB860[3] + RO_FLT_002AB870[3];
        }
        return -RO_FLT_002AB860[3] - RO_FLT_002AB870[3];
    }
    if (absoluteWord < 0x3EE00000) {
        if (absoluteWord < 0x31000000) {
            if (1.0e30f + x > 1.0f) {
                return x;
            }
        }
        id = -1;
    } else {
        x = func_00244EF8(x);
        if (absoluteWord < 0x3F980000) {
            if (absoluteWord < 0x3F300000) {
                id = 0;
                x = (2.0f * x - 1.0f) / (2.0f + x);
            } else {
                id = 1;
                x = (x - 1.0f) / (x + 1.0f);
            }
        } else {
            if (absoluteWord < 0x401C0000) {
                id = 2;
                x = (x - 1.5f) / (1.0f + 1.5f * x);
            } else {
                id = 3;
                x = -1.0f / x;
            }
        }
    }
    square = x * x;
    weight = square * square;
    odd = square * (RO_FLT_002AB880[0] + weight * (RO_FLT_002AB880[2] + weight * (RO_FLT_002AB880[4] + weight * (RO_FLT_002AB880[6] + weight * (RO_FLT_002AB880[8] + weight * RO_FLT_002AB880[10])))));
    even = weight * (RO_FLT_002AB880[1] + weight * (RO_FLT_002AB880[3] + weight * (RO_FLT_002AB880[5] + weight * (RO_FLT_002AB880[7] + weight * RO_FLT_002AB880[9]))));
    if (id < 0) {
        return x - x * (odd + even);
    }
    result = RO_FLT_002AB860[id] - ((x * (odd + even) - RO_FLT_002AB870[id]) - x);
    return highWord < 0 ? -result : result;
}
}
