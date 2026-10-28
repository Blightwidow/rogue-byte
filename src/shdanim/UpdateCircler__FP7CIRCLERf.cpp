struct SLE { int x; };
struct CIRCLER { char pad0[0x34]; int sl[7]; float sw; float sRadius; float du; float dv; };
extern "C" int FIsSlEmpty(void *);
extern float g_2dded0;
extern "C" float RadNormalize__Ff(float);
extern "C" void CalculateSinCos__FfPfT1(float, float *, float *);
extern "C" void SetSaiDuDv(float, float, void *);
extern "C" void UpdateCircler__FP7CIRCLERf(CIRCLER *pcircler, float dt)
{
    if (FIsSlEmpty(&pcircler->sl[0]) != 0)
        return;
    float rad = RadNormalize__Ff(g_2dded0 * pcircler->sw);
    float sc[2];
    CalculateSinCos__FfPfT1(rad, &sc[0], &sc[1]);
    float du = sc[0] * pcircler->sRadius + pcircler->du;
    float dv = sc[1] * pcircler->sRadius + pcircler->dv;
    sc[0] = du; sc[1] = dv;
    SetSaiDuDv(du, dv, pcircler);
}
