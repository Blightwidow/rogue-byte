extern "C" {
struct RGBA4_215D00 { char c[4]; };
struct MOVIETEXT_215D00 { char pad[0x14]; struct RGBA4_215D00 colorShadow; struct RGBA4_215D00 base; };
void CMovieText_UpdateFont(void *);

void CMovieText_SetBaseColor(void *pThis, const void *pColor)
{
    struct MOVIETEXT_215D00 *pText = (struct MOVIETEXT_215D00 *)pThis;
    pText->base = *(const struct RGBA4_215D00 *)pColor;
    pText->colorShadow = pText->base;
    CMovieText_UpdateFont(pThis);
}
}
