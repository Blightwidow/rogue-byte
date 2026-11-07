struct MathException {
    int type;
    const char *name;
    double firstArgument;
    double secondArgument;
    double returnValue;
    int errorNumber;
};

extern int D_002AC138;
extern float __ieee754_fmodf(float x, float y);
extern int func_0024A0C0(float value);
extern int *func_002401C8(void);
extern int matherr(struct MathException *exception);
extern float func_0023DFA0(double value);

float fmodf(float x, float y)
{
    struct MathException exception;
    float result;
    int version;

    result = __ieee754_fmodf(x, y);
    version = D_002AC138;
    if (version != -1 && !func_0024A0C0(y) && !func_0024A0C0(x) && y == 0.0f) {
        exception.type = 1;
        exception.name = "fmodf";
        exception.errorNumber = 0;
        exception.firstArgument = x;
        exception.secondArgument = y;
        if (version == 0) {
            exception.returnValue = x;
        } else {
            exception.returnValue = 0.0 / 0.0;
        }
        if (D_002AC138 == 2 || !matherr(&exception)) {
            *func_002401C8() = 33;
        }
        if (exception.errorNumber) {
            *func_002401C8() = exception.errorNumber;
        }
        return func_0023DFA0(exception.returnValue);
    }
    return result;
}
