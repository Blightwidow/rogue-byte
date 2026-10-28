#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
union AFF { float f[8]; QW q[2]; };
struct MAT { float f[16]; };
struct CMovieText { char pad[0x7C]; float rxScale; float ryScale; float dyLine; float gScale; };
extern "C" void CMovieText_BuildGsMatrix(CMovieText*, MAT*, AFF*);
extern "C" void CMovieText_DrawGlyphs(CMovieText*, MAT*, void*);
extern "C" void CMovieText_DrawAffine(CMovieText* ptext, AFF* paff, void* pdc)
{
    AFF aff = *paff;
    float gA = aff.f[0];
    float gD = aff.f[3];
    ptext->ryScale = gD;
    aff.f[3] = gD * ptext->gScale;
    aff.f[0] = gA * ptext->gScale;
    ptext->rxScale = gA;
    aff.f[5] = aff.f[5] + ptext->dyLine * gD;
    MAT mat;
    CMovieText_BuildGsMatrix(ptext, &mat, &aff);
    CMovieText_DrawGlyphs(ptext, &mat, pdc);
}
