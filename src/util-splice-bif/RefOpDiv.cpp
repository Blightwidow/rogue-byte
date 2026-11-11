#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"
#include "cref.h"
struct CFrame;
/* a list cell of Splice: the argument after the first is held at +8, the next cell at +0x10 */
struct CPair { int m_cref; int m_unknown4; CRef m_ref; CPair *m_ppairNext; };
struct LM { float gMin; float gMax; };
union VU_SCALE { QW q; VECTOR v; };
struct VU_FLOAT { QW m_q; VU_FLOAT(float g); };
struct VU_VECTOR { QW m_q; VU_VECTOR(const VECTOR &vector); };
VU_VECTOR operator*(VU_FLOAT vuf, VU_VECTOR vuv);
extern "C" {
CRef *CRef_SetF32(CRef *pref, float g);
CRef *CRef_RefClone(CRef *pref, CRef *ref, CFrame *pframe, unsigned long ulArg);
VECTOR *__as__6VECTORG9VU_VECTOR(VECTOR *pvector, VU_VECTOR vuv);
}

static inline void DivideVector(VECTOR *pvector, float g)
{
    VU_SCALE scale;
    scale.q = VectorFromFloat(1.0f / g);
    *(QW *)pvector = VectorScaleX(*(QW *)pvector, scale.q);
}

static inline void DivideClq(CLQ *pclq, float g)
{
    __as__6VECTORG9VU_VECTOR((VECTOR *)pclq, VU_FLOAT(1.0f / g) * VU_VECTOR(*(VECTOR *)pclq));
}

static inline void DivideLm(LM *plm, float g)
{
    float gScale = 1.0f / g;
    plm->gMin = plm->gMin * gScale;
    plm->gMax = plm->gMax * gScale;
}

CRef RefOpDiv(int cref, CRef *aref)
{
    CRef ref;
    ref.m_tagk = TAGK_Nil;
    int fInteger = 0;
    switch (aref->m_tagk) {
    case TAGK_S32:
        CRef_SetF32(&ref, (float)aref->m_tag.m_n);
        fInteger = 1;
        break;
    case TAGK_F32:
    case TAGK_Vector:
    case TAGK_Matrix:
    case TAGK_Clq:
    case TAGK_Lm: {
        CRef refClone;
        CRef_RefClone(&refClone, aref, 0, 0);
        ref = refClone;
        break;
    }
    }
    CPair *ppair = 0;
    if (aref[1].m_tagk != 0)
        ppair = aref[1].m_tag.m_ppair;
    for (; ppair != 0; ppair = ppair->m_ppairNext) {
        CRef *prefArg = &ppair->m_ref;
        switch (ref.m_tagk) {
        case TAGK_F32:
            switch (prefArg->m_tagk) {
            case TAGK_F32:
                ref.m_tag.m_g = ref.m_tag.m_g / prefArg->m_tag.m_g;
                fInteger = 0;
                break;
            case TAGK_S32:
                ref.m_tag.m_g = ref.m_tag.m_g / (float)prefArg->m_tag.m_n;
                break;
            }
            break;
        case TAGK_Vector:
            switch (prefArg->m_tagk) {
            case TAGK_S32:
                DivideVector(ref.m_tag.m_pvector, (float)prefArg->m_tag.m_n);
                break;
            case TAGK_F32:
                DivideVector(ref.m_tag.m_pvector, prefArg->m_tag.m_g);
                break;
            }
            break;
        case TAGK_Matrix:
            switch (prefArg->m_tagk) {
            case TAGK_S32: {
                MATRIX4 *pmatrix = ref.m_tag.m_pmatrix;
                MATRIX4 matrix;
                VU_SCALE scale;
                scale.q = QuadFromFloat(1.0f / (float)prefArg->m_tag.m_n);
                float gScale = LaneX(scale.q);
                float *pgDst = &matrix.mat[0][0];
                float *pgSrc = &pmatrix->mat[0][0];
                for (int i = 0; i < 16; i++)
                    pgDst[i] = gScale * pgSrc[i];
                *pmatrix = matrix;
                break;
            }
            case TAGK_F32: {
                MATRIX4 *pmatrix = ref.m_tag.m_pmatrix;
                MATRIX4 matrix;
                VU_SCALE scale;
                scale.q = QuadFromFloat(1.0f / prefArg->m_tag.m_g);
                float gScale = LaneX(scale.q);
                float *pgDst = &matrix.mat[0][0];
                float *pgSrc = &pmatrix->mat[0][0];
                for (int i = 0; i < 16; i++)
                    pgDst[i] = gScale * pgSrc[i];
                *pmatrix = matrix;
                break;
            }
            }
            break;
        case TAGK_Clq:
            switch (prefArg->m_tagk) {
            case TAGK_S32:
                DivideClq(ref.m_tag.m_pclq, (float)prefArg->m_tag.m_n);
                break;
            case TAGK_F32:
                DivideClq(ref.m_tag.m_pclq, prefArg->m_tag.m_g);
                break;
            }
            break;
        case TAGK_Lm:
            switch (prefArg->m_tagk) {
            case TAGK_S32:
                DivideLm(ref.m_tag.m_plm, (float)prefArg->m_tag.m_n);
                break;
            case TAGK_F32:
                DivideLm(ref.m_tag.m_plm, prefArg->m_tag.m_g);
                break;
            }
            break;
        }
    }
    if (fInteger != 0 && ref.m_tagk == TAGK_F32)
        ref.SetS32((int)ref.m_tag.m_g);
    return ref;
}
