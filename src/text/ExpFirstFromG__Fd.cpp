#include "sly2.h"
extern "C" double logf(double);
extern "C" int ExpFirstFromG__Fd(double g)
{
    int exp;
    if (g > 0.0) {
        double gLog = logf(g);
        exp = (int)gLog;
        if (gLog < 0.0) {
            if (gLog != (double)exp)
                exp = exp - 1;
        }
    } else
        exp = 0;
    return exp;
}
