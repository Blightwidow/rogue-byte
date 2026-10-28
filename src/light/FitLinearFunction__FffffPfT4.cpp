#include "sly2.h"
int FFloatsNear(float, float, float);
void FitLinearFunction(float x0, float y0, float x1, float y1, float *pdu, float *pru)
{
    if (FFloatsNear(x0, x1, 0.0001f) != 0) {
        *pru = 0.0f;
        *pdu = y0;
    } else {
        float dy = y1 - y0;
        float dx = x1 - x0;
        asm("nop"); /* the binary has a nop between the subtract and the divide */
        float ru = dy / dx;
        *pru = ru;
        *pdu = y0 - ru * x0;
    }
}
