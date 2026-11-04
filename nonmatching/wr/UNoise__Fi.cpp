extern "C" float UNoise__Fi(int n)
{
    n = (n << 13) ^ n;
    n = (n * (n * n * 0x3D73 + 0xC0AE5) + 0x5208DD0D) & 0x7FFFFFFF;
    return (float)n * 4.656613e-10f;
}
