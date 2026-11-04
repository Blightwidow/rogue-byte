extern "C" {
int FFloatsNear(float, float, float);
}
extern "C" void FitLinearFunction__FffffPfT4(float x0, float y0, float x1, float y1, float *pIntercept, float *pSlope)
{
    float epsilon = 0.0001f;
    if (FFloatsNear(x0, x1, epsilon) != 0) {
        *pSlope = 0.0f;
        *pIntercept = y0;
    } else {
        float slope = (y1 - y0) / (x1 - x0);
        *pSlope = slope;
        *pIntercept = y0 - slope * x0;
    }
}
