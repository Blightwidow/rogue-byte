extern "C" float UNoise__Fi(int n)
{
    int t = (n << 13) ^ n;
    int poly = t * t * 0x3D73 + 0xC0AE5;
    return (float)((poly * t + 0x5208DD0D) & 0x7FFFFFFF) * 4.656613e-10f;
}
