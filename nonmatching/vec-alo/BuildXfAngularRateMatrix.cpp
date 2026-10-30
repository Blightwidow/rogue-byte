typedef int QW __attribute__((mode(TI)));
extern "C" {
void BuildXfSpinRateMatrix(void *, int, int, QW);
QW ConvertDeulToW__FP6VECTORN20(QW, QW);
void *memcpy(void *, const void *, unsigned);

void *BuildXfAngularRateMatrix(void *out, int arg1, int arg2, QW euler, QW rate) {
    char sp[0x40];
    QW w = ConvertDeulToW__FP6VECTORN20(euler, rate);
    BuildXfSpinRateMatrix(sp, arg1, arg2, w);
    memcpy(out, sp, 0x40);
    return out;
}
}
