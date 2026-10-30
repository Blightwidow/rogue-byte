extern "C" {
static const float huge = 1.0e30f;
float floorf(float x) {
    int i0, j0;
    unsigned i;
    i0 = *(int *)&x;
    j0 = ((i0 >> 23) & 0xff) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge + x > (float)0.0) {
                if (i0 >= 0) {
                    i0 = 0;
                } else if ((i0 & 0x7fffffff) != 0) {
                    i0 = 0xbf800000;
                }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge + x > (float)0.0) {
                if (i0 < 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        if (j0 == 0x80) return x + x;
        else return x;
    }
    *(int *)&x = i0;
    return x;
}
}
