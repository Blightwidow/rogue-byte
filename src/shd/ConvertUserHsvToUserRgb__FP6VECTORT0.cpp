typedef int QW __attribute__((mode(TI)));
struct V4_11DFA0 { float x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
void ConvertHsvToRgb__FP6VECTORT0(V4_11DFA0 *, float *);
void ConvertUserHsvToUserRgb__FP6VECTORT0(QW *arg0, float *arg1) {
    V4_11DFA0 tmp;
    *(QW *)&tmp = *arg0;
    tmp.y *= 0.003921569f;
    tmp.z *= 0.003921569f;
    ConvertHsvToRgb__FP6VECTORT0(&tmp, arg1);
    arg1[0] = arg1[0] * 255.0f;
    arg1[1] = arg1[1] * 255.0f;
    arg1[2] = arg1[2] * 255.0f;
}
}
