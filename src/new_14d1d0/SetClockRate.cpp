extern "C" void RecalcClockRate(void *);
extern "C" void SetClockRate(float *clocks, int index, float rate)
{
    float *p = clocks + index; p[6] = rate;
    RecalcClockRate(clocks);
}
