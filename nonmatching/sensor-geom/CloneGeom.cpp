#include "sly2.h"
struct GEOM { int cvertex; char *avertex; int csurf; char *asurf; int a10; int a14; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" {
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
void InitPlaneFromNormalPos(void *, QW, QW);
}

extern "C" void CloneGeom(GEOM *pgeomSrc, float *pmat, GEOM *pgeomDst)
{
    int cvertex = pgeomSrc->cvertex;
    pgeomDst->cvertex = cvertex;
    ALLOCREQ req;
    req.cb = cvertex << 4;
    req.cbAlign = 0x10;
    pgeomDst->avertex = (char *)PvAllocSwCopyImpl__FiPv(&req, pgeomSrc->avertex);
    int csurf = pgeomSrc->csurf;
    pgeomDst->csurf = csurf;
    req.cb = csurf << 5;
    req.cbAlign = 0x10;
    pgeomDst->asurf = (char *)PvAllocSwCopyImpl__FiPv(&req, pgeomSrc->asurf);
    pgeomDst->a10 = pgeomSrc->a10;
    pgeomDst->a14 = pgeomSrc->a14;
    if (pmat == 0)
        return;
    float rows[16];
    for (int i = 0; i < 16; i++)
        rows[i] = pmat[i];
    for (int ivertex = 0; ivertex < pgeomDst->cvertex; ivertex++) {
        float *pv = (float *)(pgeomDst->avertex + ivertex * 16);
        float x = pv[0], y = pv[1], z = pv[2];
        pv[0] = rows[0] * x + rows[4] * y + rows[8] * z + rows[12];
        pv[1] = rows[1] * x + rows[5] * y + rows[9] * z + rows[13];
        pv[2] = rows[2] * x + rows[6] * y + rows[10] * z + rows[14];
        pv[3] = rows[3] * x + rows[7] * y + rows[11] * z + rows[15];
    }
    for (int isurf = 0; isurf < pgeomDst->csurf; isurf++) {
        char *psurf = pgeomDst->asurf + isurf * 0x20;
        float *pn = (float *)psurf;
        float nx = pn[0], ny = pn[1], nz = pn[2];
        float n0 = rows[0] * nx + rows[4] * ny + rows[8] * nz;
        float n1 = rows[1] * nx + rows[5] * ny + rows[9] * nz;
        float n2 = rows[2] * nx + rows[6] * ny + rows[10] * nz;
        float len = __builtin_sqrtf(n0 * n0 + n1 * n1 + n2 * n2);
        float inv = 1.0f / len;
        (void)inv;
        int idxVertex = *(int *)(psurf + 0x1C);
        float *pvOn = (float *)(pgeomDst->avertex + idxVertex * 16);
        (void)pvOn;
    }
}
