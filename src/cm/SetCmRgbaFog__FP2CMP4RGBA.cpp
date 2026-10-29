extern "C" {
struct RGBA4_14F6F0 { char c[4]; };
struct CM_14F6F0 { char pad[0x24C]; struct RGBA4_14F6F0 fog; };
void FilterColorRgba8_1ed278(void *);
void RecalcCmFrustrum__FP2CM(void *);

void SetCmRgbaFog__FP2CMP4RGBA(void *pCm, const void *pRgba)
{
    struct CM_14F6F0 *pCmStruct = (struct CM_14F6F0 *)pCm;
    pCmStruct->fog = *(const struct RGBA4_14F6F0 *)pRgba;
    FilterColorRgba8_1ed278(&pCmStruct->fog);
    RecalcCmFrustrum__FP2CM(pCm);
}
}
