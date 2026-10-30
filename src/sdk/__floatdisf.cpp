extern "C" {
double __floatsidf(int);
double __muldf3(double, double);
double __adddf3(double, double);
float func_0023DFA0(double);
float __floatdisf(long value) {
    if ((unsigned long)(value + 0x1FFFFFFFFFFFFFL) > 0x3FFFFFFFFFFFFEUL) {
        if ((int)value & 0x7FF) {
            value |= 0x800;
        }
    }
    double high = __floatsidf((int)(value >> 32));
    high = __muldf3(high, 65536.0);
    high = __muldf3(high, 65536.0);
    int low = (int)(value & 0xFFFFFFFFUL);
    double result = __floatsidf(low);
    if (low < 0) {
        result = __adddf3(result, 4294967296.0);
    }
    return func_0023DFA0(__adddf3(high, result));
}
}
