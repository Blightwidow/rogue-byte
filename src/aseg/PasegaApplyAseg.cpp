extern "C" void ApplyAseg(void *, void *, void *, void *);
extern "C" int PasegaApplyAseg(void *a, void *b, void *c)
{
    int result;
    ApplyAseg(a, b, c, &result);
    return result;
}
