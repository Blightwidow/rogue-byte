void *memset(void *, int, unsigned int);
struct MATRIX4 { float m[4][4]; };
struct XFM { char pad0[0x10]; XFM *pxfmParent; char pad1[0x50 - 0x14]; int field50; char pad2[0x60 - 0x54]; MATRIX4 mat; };
extern "C" void InitLo(void *);
extern "C" void InvalidateXfmMatWorld(XFM *);
extern "C" void InitXfm(XFM *pxfm)
{
    InitLo(pxfm);
    if (pxfm->pxfmParent != 0)
        pxfm->field50 = *(int *)&pxfm->pxfmParent->mat;
    MATRIX4 *pmat = &pxfm->mat;
    memset(pmat, 0, 0x40);
    pmat->m[3][3] = 1.0f;
    pmat->m[2][2] = 1.0f;
    pmat->m[1][1] = 1.0f;
    pxfm->mat.m[0][0] = 1.0f;
    InvalidateXfmMatWorld(pxfm);
}
