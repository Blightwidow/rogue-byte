extern "C" float RadNormalize__Ff(float);
extern "C" float GLimitAbs__Fff(float, float);

float RadLimitLm(float *arg0, float arg1) {
    float low = arg0[0];
    float high = arg0[1];
    float center = (high + low) * 0.5f;
    float half = (high - low) * 0.5f;
    float value = RadNormalize__Ff(arg1 - center);
    value = GLimitAbs__Fff(value, half);
    return RadNormalize__Ff(center + value);
}
