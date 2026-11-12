// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
/* the record handed to matherr: kind of error, function name, both arguments, the value to return, an errno to set */
struct MathException {
    int type;
    const char *name;
    double arg1;
    double arg2;
    double retval;
    int err;
};
double __ieee754_pow(double, double);
int dpcmp(double, double);
int *func_002401C8(void);
int func_00249C60(double);
int func_00249C80(double);
int matherr(MathException *);
double rint(double);
extern const char RO_002AB8D0[];
extern const double RO_002AB8D8;
extern const double RO_002AC130;
extern const int RO_002AC138;

double pow(double x, double y)
{
    MathException exc;
    double z = __ieee754_pow(x, y);
    if (RO_002AC138 == -1 || func_00249C80(y) != 0) {
        return z;
    }
    if (func_00249C80(x) != 0) {
        if (dpcmp(y, 0.0) == 0) {
            exc.type = 1;
            exc.name = RO_002AB8D0;
            exc.err = 0;
            exc.arg1 = x;
            exc.arg2 = y;
            exc.retval = x;
            if (RO_002AC138 == 2) {
                exc.retval = 1.0;
            } else if (matherr(&exc) == 0) {
                *func_002401C8() = 0x21;
            }
            if (exc.err != 0) {
                *func_002401C8() = exc.err;
            }
            return exc.retval;
        }
        return z;
    }
    if (dpcmp(x, 0.0) == 0) {
        if (dpcmp(y, 0.0) == 0) {
            exc.type = 1;
            exc.name = RO_002AB8D0;
            exc.err = 0;
            exc.arg1 = x;
            exc.arg2 = y;
            exc.retval = 0.0;
            if (RO_002AC138 != 0) {
                exc.retval = 1.0;
            } else if (matherr(&exc) == 0) {
                *func_002401C8() = 0x21;
            }
            if (exc.err != 0) {
                *func_002401C8() = exc.err;
            }
            return exc.retval;
        }
        if (func_00249C60(y) != 0 && dpcmp(y, 0.0) < 0) {
            exc.type = 1;
            exc.name = RO_002AB8D0;
            exc.err = 0;
            exc.arg1 = x;
            exc.arg2 = y;
            if (RO_002AC138 == 0) {
                exc.retval = 0.0;
            } else {
                exc.retval = 0.0 - RO_002AC130;
            }
            if (RO_002AC138 == 2) {
                *func_002401C8() = 0x21;
            } else if (matherr(&exc) == 0) {
                *func_002401C8() = 0x21;
            }
            if (exc.err != 0) {
                *func_002401C8() = exc.err;
            }
            return exc.retval;
        }
        return z;
    }
    if (func_00249C60(z) == 0 && func_00249C60(x) != 0 && func_00249C60(y) != 0) {
        if (func_00249C80(z) != 0) {
            exc.type = 1;
            exc.name = RO_002AB8D0;
            exc.err = 0;
            exc.arg1 = x;
            exc.arg2 = y;
            if (RO_002AC138 == 0) {
                exc.retval = 0.0;
            } else {
                exc.retval = RO_002AB8D8;
            }
            if (RO_002AC138 == 2 || matherr(&exc) == 0) {
                *func_002401C8() = 0x21;
            }
        } else {
            exc.type = 3;
            exc.name = RO_002AB8D0;
            exc.err = 0;
            exc.arg1 = x;
            exc.arg2 = y;
            if (RO_002AC138 == 0) {
                exc.retval = 3.40282346638528859812e+38;
                y *= 0.5;
                if (dpcmp(x, 0.0) < 0 && dpcmp(rint(y), y) != 0) {
                    exc.retval = -3.40282346638528859812e+38;
                }
            } else {
                exc.retval = RO_002AC130;
                y *= 0.5;
                if (dpcmp(x, 0.0) < 0 && dpcmp(rint(y), y) != 0) {
                    exc.retval = 0.0 - RO_002AC130;
                }
            }
            if (RO_002AC138 == 2) {
                *func_002401C8() = 0x22;
            } else if (matherr(&exc) == 0) {
                *func_002401C8() = 0x22;
            }
        }
        if (exc.err != 0) {
            *func_002401C8() = exc.err;
        }
        return exc.retval;
    }
    if (dpcmp(z, 0.0) == 0 && func_00249C60(x) != 0 && func_00249C60(y) != 0) {
        exc.type = 4;
        exc.name = RO_002AB8D0;
        exc.err = 0;
        exc.arg1 = x;
        exc.arg2 = y;
        exc.retval = 0.0;
        if (RO_002AC138 == 2) {
            *func_002401C8() = 0x22;
        } else if (matherr(&exc) == 0) {
            *func_002401C8() = 0x22;
        }
        if (exc.err != 0) {
            *func_002401C8() = exc.err;
        }
        return exc.retval;
    }
    return z;
}
}
