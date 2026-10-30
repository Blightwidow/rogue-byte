extern "C" {
double __floatsidf(int);
double __muldf3(double, double);
double __adddf3(double, double);
double __floatdidf(long value) {
    double high = __floatsidf((int)(value >> 32));
    high = __muldf3(high, 65536.0);
    high = __muldf3(high, 65536.0);
    int low = (int)(value & 0xFFFFFFFFUL);
    double result = __floatsidf(low);
    if (low < 0) {
        result = __adddf3(result, 4294967296.0);
    }
    return __adddf3(high, result);
}
}
