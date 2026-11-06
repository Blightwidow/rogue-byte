struct Curve { char pad0[0xE4]; int wraps; };
float SMaxCrv();
float SDiffCrv(struct Curve *curve, float from, float to) {
    float difference = to - from;
    float maximum;
    if (curve->wraps != 0) {
        maximum = SMaxCrv();
        if ((maximum * 0.5f) < difference) {
            difference -= maximum;
        } else if (difference < (maximum * -0.5f)) {
            difference += maximum;
        }
    }
    return difference;
}
