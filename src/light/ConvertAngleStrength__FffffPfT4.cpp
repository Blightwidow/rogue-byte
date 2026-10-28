extern "C" float cosf(float);
void FitLinearFunction__FffffPfT4(float, float, float, float, float *, float *);

void ConvertAngleStrength__FffffPfT4(float deg0, float g0, float deg1, float g1, float *pdu, float *pru)
{
    float cos0 = cosf(deg0 * 0.008726647f);
    float lo = cos0 + cos0 * cos0 * cos0;
    float cos1 = cosf(deg1 * 0.008726647f);
    FitLinearFunction__FffffPfT4(lo, g0 * 0.003921569f, cos1 + cos1 * cos1 * cos1, g1 * 0.003921569f, pdu, pru);
}
