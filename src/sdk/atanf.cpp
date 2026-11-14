extern "C" {
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i, d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
typedef union { float value; int bits; } FloatBits;
extern float D_002AB860[4];
extern float D_002AB870[4];
extern float D_002AB880[16];
float func_00244EF8(float); // fabsf, called out of line (the compiler inlines the fabsf name)
float atanf(float x) {
    float result, weight, square, odd, even;
    int highWord, absoluteWord, id;
    GET_FLOAT_WORD(highWord, x);
    absoluteWord = highWord & 0x7FFFFFFF;
    if (absoluteWord > 0x507FFFFF) {
        if (absoluteWord > 0x7F800000) {
            return x + x;
        }
        if (highWord > 0) {
            return D_002AB860[3] + D_002AB870[3];
        }
        return -D_002AB860[3] - D_002AB870[3];
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
    odd = square * (D_002AB880[0] + weight * (D_002AB880[2] + weight * (D_002AB880[4] + weight * (D_002AB880[6] + weight * (D_002AB880[8] + weight * D_002AB880[10])))));
    even = weight * (D_002AB880[1] + weight * (D_002AB880[3] + weight * (D_002AB880[5] + weight * (D_002AB880[7] + weight * D_002AB880[9]))));
    if (id < 0) {
        return x - x * (odd + even);
    }
    result = D_002AB860[id] - ((x * (odd + even) - D_002AB870[id]) - x);
    return highWord < 0 ? -result : result;
}
}
