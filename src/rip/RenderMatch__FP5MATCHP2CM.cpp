extern "C" float g_2dded0;
extern "C" void RenderRip(void *, void *);
extern "C" void RenderMatch__FP5MATCHP2CM(char *match, void *cm)
{
    float limit = g_2dded0;
    float value = *(float *)(match + 0x14);
    if (limit < value)
        return;
    RenderRip(match, cm);
}
