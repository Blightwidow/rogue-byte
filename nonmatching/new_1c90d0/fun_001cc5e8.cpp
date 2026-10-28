#include "sly2.h"
struct XF { char pad[0x94]; int dof; char pad2[8]; XF *pxfParent; };
struct ASEG { char pad[0x74]; float dur; };
struct MX { union { QW row[4]; float mat[4][4]; }; };
struct REQ { int cb; int align; };
struct ITEM { float g; ASEG *paseg; int pad; void *pcrvStart; void *pcrvEnd; };
struct JT { char pad[0x60]; XF *pxfRoot; };
struct VTF { char pad[0x100]; short delta; short idx; XF *(*fn)(void *, MATRIX4 *); };
struct VTC { char pad[0x48]; short delta; short idx; void (*fn)(void *); };
struct PLO { char pad[0xC]; VTF *vptr; };
struct CRV { char pad0[0xC]; VTC *vptr; char pad1[0xE0 - 0x10]; int crvk; int pade4; int cpoint; float *pu; float *pv; QW *ppos; };
struct CARRY {
    JT *pjt; void *ppasega; ITEM item[2]; void *pasegbl; PLO *palo; XF *pxfSource; char pad3c[4]; MATRIX4 matBase;
};
extern "C" CRV *PloNew(int, JT *, int, int);
extern "C" void *PvAllocSwImpl__Fi(REQ *);
extern "C" void MeasureCrv(void *);
extern "C" void PredictAsegEffect(float, float, ASEG *, JT *, XF *, XF *, MATRIX4 *, int);
extern "C" void EnsureAsegBlendDynamic(JT *, int, int, void *, int, int, int, void *);
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
extern int g_2c1ed0;

void func_001CC5E8(CARRY *pcarry, JT *pjt, void *ppasega)
{
    pcarry->pjt = pjt;
    pcarry->ppasega = ppasega;
    if (pcarry->palo) {
        MATRIX4 matSource;
        XF *pxfSource = pcarry->palo->vptr->fn((char *)pcarry->palo + pcarry->palo->vptr->delta, &matSource);
        pcarry->matBase = matSource;
        pcarry->pxfSource = pxfSource;
        if (pxfSource->dof != 6) {
            do {
                pcarry->matBase = *(MATRIX4 *)pcarry->pxfSource * pcarry->matBase;
                pcarry->pxfSource = pcarry->pxfSource->pxfParent;
            } while (pcarry->pxfSource->dof != 6);
        }
        int citem = 0;
        for (int iitem = 0; iitem < 2; iitem++) {
            ASEG *paseg = pcarry->item[iitem].paseg;
            if (paseg) {
                citem++;
                for (int icurve = 0; icurve < 2; icurve++) {
                    CRV *pcrv = PloNew(10, pcarry->pjt, 0xB2, -1);
                    pcrv->crvk = 0;
                    pcrv->cpoint = g_2c1ed0;
                    MX matAnchor;
                    {
                    REQ &req = *(REQ *)&matAnchor;
                    req.cb = g_2c1ed0 << 2;
                    req.align = 16;
                    pcrv->pu = (float *)PvAllocSwImpl__Fi(&req);
                    req.cb = g_2c1ed0 << 2;
                    req.align = 16;
                    pcrv->pv = (float *)PvAllocSwImpl__Fi(&req);
                    req.cb = g_2c1ed0 << 4;
                    req.align = 16;
                    pcrv->ppos = (QW *)PvAllocSwImpl__Fi(&req);
                    }
                    XF *pxfMeasure;
                    if (icurve == 0) {
                        matAnchor = *(MX *)&matSource;
                        pxfMeasure = pxfSource;
                    } else {
                        pxfMeasure = pcarry->pxfSource;
                        memset(&matAnchor, 0, 0x40);
                        matAnchor.mat[3][3] = 1.0f;
                        matAnchor.mat[2][2] = 1.0f;
                        matAnchor.mat[1][1] = 1.0f;
                        matAnchor.mat[0][0] = 1.0f;
                    }
                    for (int isample = 0; isample < g_2c1ed0; isample++) {
                        MX matBone;
                        float u = (float)isample / (float)(g_2c1ed0 - 1);
                        PredictAsegEffect(u * paseg->dur, 0.0f, paseg, pcarry->pjt, pxfMeasure, pcarry->pjt->pxfRoot, (MATRIX4 *)&matBone, 0);
                        pcrv->pu[isample] = u;
                        QW *pdest = &pcrv->ppos[isample];
                        asm("lqc2 vf5, %0" : : "m" (matAnchor.row[3]));
                        asm("lqc2 vf2, %0" : : "m" (matBone.row[0]));
                        asm("lqc2 vf4, %0" : : "m" (matBone.row[1]));
                        asm("lqc2 vf3, %0" : : "m" (matBone.row[2]));
                        asm("lqc2 vf1, %0" : : "m" (matBone.row[3]));
                        asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w");
                        asm("sqc2 vf2, %0" : "=m" (*pdest));
                    }
                    pcrv->vptr->fn((char *)pcrv + pcrv->vptr->delta);
                    MeasureCrv(pcrv);
                    if (icurve == 0)
                        pcarry->item[iitem].pcrvStart = pcrv;
                    else
                        pcarry->item[iitem].pcrvEnd = pcrv;
                }
            }
        }
        if (citem == 2) {
            pcarry->item[0].g = 1.0f;
            EnsureAsegBlendDynamic(pcarry->pjt, 0x14, 2, &pcarry->item[0], 0, 0, 0, &pcarry->pasegbl);
        }
    }
}
