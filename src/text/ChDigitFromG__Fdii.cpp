#include "sly2.h"
extern const unsigned char D_002C40C8[];
double GTrunc(double);
extern "C" double pow(double, double);
extern "C" double __floatsidf(int);
extern "C" double __muldf3(double, double);
extern "C" double mul_dl(double, long) __asm__("__muldf3");
extern "C" double __subdf3(double, double);
extern "C" int __fixdfsi(double);

unsigned char ChDigitFromG(double g, int first, int exp)
{
    int digit;
    if (first < exp || exp <= first - 15) {
        digit = 0;
    } else {
        double scaled = GTrunc(__muldf3(g, pow(10.0, __floatsidf(-exp))));
        double tenths = GTrunc(mul_dl(scaled, 0x3FB999999999999AL));
        digit = __fixdfsi(__subdf3(scaled, __muldf3(tenths, 10.0)));
    }
    return D_002C40C8[digit];
}
