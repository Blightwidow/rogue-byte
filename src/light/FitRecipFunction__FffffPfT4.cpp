int FFloatsNear(float, float, float);

void FitRecipFunction(float x0, float y0, float x1, float y1, float *pdu, float *pru)
{
    float epsilon = 0.0001f;
    if (FFloatsNear(x0, x1, epsilon) != 0 || __builtin_fabsf(x0) < epsilon || __builtin_fabsf(x1) < epsilon) {
        *pru = 0.0f;
        *pdu = y0;
    } else {
        float ru = (x0 * x1 * (y1 - y0)) / (x0 - x1);
        *pru = ru;
        *pdu = y0 - ru / x0;
    }
}
