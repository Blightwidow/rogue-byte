extern "C" {
typedef int s32; typedef signed char s8; typedef float f32;
s32 func_00157A50(s8 **arg0, s8 **arg1) {
    s8 *left = *arg0;
    s8 *right = *arg1;
    f32 leftKey = *(f32 *)(left + 4);
    f32 rightKey = *(f32 *)(right + 4);
    if (rightKey < leftKey) {
        return -1;
    }
    if (leftKey < rightKey) {
        return 1;
    }
    return (s32)(left - right) >> 4;
}
}
