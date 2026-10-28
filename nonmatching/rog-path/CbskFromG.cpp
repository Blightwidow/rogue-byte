extern "C" const float D_FLT_002C0C00;

int CbskFromG(float gDist)
{
    float f0 = D_FLT_002C0C00;
    if (f0 < gDist) {
        return 0;
    }
    if (gDist < -f0) {
        return 0;
    }
    return 1;
}
