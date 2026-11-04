struct MRSG { float t; float w; };
int ImrsgLookUp(float t, float period, int cmrsg, MRSG *amrsg, float *pdt)
{
    int imrsg;
    for (imrsg = 0; imrsg < cmrsg; imrsg++) {
        MRSG *pmrsg = &amrsg[imrsg];
        float w = pmrsg->w;
        if (w == 0.0f)
            continue;
        float d = t - pmrsg->t;
        if (d < 0.0f)
            d += period;
        if (d < w + 0.0001f) {
            if (pdt != 0)
                *pdt = d;
            break;
        }
    }
    return imrsg;
}