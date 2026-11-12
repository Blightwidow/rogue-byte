/* SPDX-License-Identifier: GPL-3.0-or-later */
/* PowF_245b58: x to the power y, with the library's error reporting (matherr, errno 33 or 34) for NaN, zero and overflowing
   or underflowing results */
struct MathException {
    int type;
    const char *name;
    double firstArgument;
    double secondArgument;
    double returnValue;
    int errorNumber;
};

extern const int RO_002AC138;
extern double RO_002AC130;
extern float __ieee754_powf(float x, float y);
extern int func_0024A0C0(float value);
extern int func_0024A098(float value);
extern int *func_002401C8(void);
extern int matherr(struct MathException *exception);
extern float func_0023DFA0(double value);
extern double rint(double value);

float PowF_245b58(float x, float y)
{
    struct MathException exception;
    float result;
    int version;

    result = __ieee754_powf(x, y);
    version = RO_002AC138;
    if (version == -1 || func_0024A0C0(y))
        return result;
    if (func_0024A0C0(x)) {
        if (y == 0.0f) {
            exception.type = 1;
            exception.name = "powf";
            exception.errorNumber = 0;
            exception.firstArgument = x;
            exception.secondArgument = y;
            exception.returnValue = x;
            if (version == 2) {
                exception.returnValue = 1.0;
            } else if (!matherr(&exception)) {
                *func_002401C8() = 33;
            }
            if (exception.errorNumber) {
                *func_002401C8() = exception.errorNumber;
            }
            return func_0023DFA0(exception.returnValue);
        }
        return result;
    }
    if (x == 0.0f) {
        if (y == 0.0f) {
            exception.type = 1;
            exception.name = "powf";
            exception.errorNumber = 0;
            exception.firstArgument = x;
            exception.secondArgument = y;
            exception.returnValue = 0.0;
            if (version != 0) {
                exception.returnValue = 1.0;
            } else if (!matherr(&exception)) {
                *func_002401C8() = 33;
            }
            if (exception.errorNumber) {
                *func_002401C8() = exception.errorNumber;
            }
            return func_0023DFA0(exception.returnValue);
        }
        if (func_0024A098(y) && y < 0.0f) {
            exception.type = 1;
            exception.name = "powf";
            exception.errorNumber = 0;
            exception.firstArgument = x;
            exception.secondArgument = y;
            if (version == 0) {
                exception.returnValue = 0.0;
            } else {
                exception.returnValue = -RO_002AC130;
            }
            if (RO_002AC138 == 2 || !matherr(&exception)) {
                *func_002401C8() = 33;
            }
            if (exception.errorNumber) {
                *func_002401C8() = exception.errorNumber;
            }
            return func_0023DFA0(exception.returnValue);
        }
        return result;
    }
    if (!func_0024A098(result)) {
        if (func_0024A098(x) && func_0024A098(y)) {
            if (func_0024A0C0(result)) {
                exception.type = 1;
                exception.name = "powf";
                exception.errorNumber = 0;
                exception.firstArgument = x;
                exception.secondArgument = y;
                if (version == 0) {
                    exception.returnValue = 0.0;
                } else {
                    exception.returnValue = 0.0 / 0.0;
                }
                if (RO_002AC138 == 2 || !matherr(&exception)) {
                    *func_002401C8() = 33;
                }
            } else {
                exception.type = 3;
                exception.name = "powf";
                exception.errorNumber = 0;
                exception.firstArgument = x;
                exception.secondArgument = y;
                if (version == 0) {
                    exception.returnValue = 3.40282346638528859812e+38;
                    y = func_0023DFA0(y * 0.5);
                    if (x < 0.0 && rint(y) != y) {
                        exception.returnValue = -3.40282346638528859812e+38;
                    }
                } else {
                    double huge = RO_002AC130;
                    exception.returnValue = huge;
                    y = func_0023DFA0(y * 0.5);
                    if (x < 0.0 && rint(y) != y) {
                        exception.returnValue = -huge;
                    }
                }
                if (RO_002AC138 == 2 || !matherr(&exception)) {
                    *func_002401C8() = 34;
                }
            }
            if (exception.errorNumber) {
                *func_002401C8() = exception.errorNumber;
            }
            return func_0023DFA0(exception.returnValue);
        }
    }
    if (result == 0.0f && func_0024A098(x) && func_0024A098(y)) {
        exception.type = 4;
        exception.name = "powf";
        exception.errorNumber = 0;
        exception.firstArgument = x;
        exception.secondArgument = y;
        exception.returnValue = 0.0;
        if (RO_002AC138 == 2 || !matherr(&exception)) {
            *func_002401C8() = 34;
        }
        if (exception.errorNumber) {
            *func_002401C8() = exception.errorNumber;
        }
        return func_0023DFA0(exception.returnValue);
    }
    return result;

}
