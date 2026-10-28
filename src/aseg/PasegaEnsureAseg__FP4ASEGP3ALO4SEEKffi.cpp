struct ASEG; struct ALO; enum SEEK { SEEK_dummy }; struct ASEGA;
void EnsureAseg(ASEG *, ALO *, SEEK, float, float, int, ASEGA **);
ASEGA *PasegaEnsureAseg(ASEG *a, ALO *b, SEEK c, float d, float e, int f)
{
    ASEGA *result;
    EnsureAseg(a, b, c, d, e, f, &result);
    return result;
}
