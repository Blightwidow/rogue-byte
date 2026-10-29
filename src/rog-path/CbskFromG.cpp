extern "C" const float RO_002C0C00;

int CbskFromG(float gDist)
{
    float f0 = RO_002C0C00;
    if (f0 < gDist) {
        return 0;
    }
    if (gDist < -f0) {
        return 1;
    }
    return 2;
}
