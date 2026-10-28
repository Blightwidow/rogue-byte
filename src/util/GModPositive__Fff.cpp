extern "C" float fmodf(float, float);
float GModPositive(float g, float modulus)
{
    float rem = fmodf(g, modulus);
    if (rem < 0.0f)
        rem = rem + modulus;
    return rem;
}
