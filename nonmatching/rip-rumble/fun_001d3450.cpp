#include "sly2.h"
struct VEHICLE { char pad[4]; };
struct VEnt { short delta; short index; QW *(*fn)(void *); };
struct VTX { char pad[0xF8]; VEnt slotF8; };
struct VEHICLEX { char pad[0xC]; VTX *vptr; };
extern "C" QW ConvertAloPos(void *, void *, QW);
extern "C" void __as__6VECTORG9VU_VECTOR(void *, QW);
extern "C" void InvertMatrix4Affine(void *, void *);
extern "C" void InitPlaneFromNormalPos(void *, QW, QW);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackImpl__Fi(void *);
extern "C" int PruneBsp__FP3BSPP6VECTORfPP3BSP(void *, void *, float, QW, int *, void **);
extern "C" int ClsgClipEdgeToBsp(void *, void *, QW, QW, int, void *);
extern "C" QW TransformPlane(void *, QW);
extern "C" void PxpAdd(float, void *, void *, void *, QW, QW, int, void *, void *, void *);
extern "C" void func_002564B8(void *);
extern "C" void func_002564C0(void *);
extern "C" QW g_2a2dc0;
extern "C" char B_003DD490[];
extern "C" const QW D_002C2150[5];
struct VECTOR_;

#define F(type, base, off) (*(type *)((char *)(base) + (off)))
#define Q(off) (*(QW *)(buf + (off)))
#define FL(off) (*(float *)(buf + (off)))
#define P(off) (*(char **)(buf + (off)))
#define I(off) (*(int *)(buf + (off)))

void func_001D3450(VEHICLEX *pv, char *pwheel, char *pgeomOther, int cbspPruned, void *abspPruned, void *pbspPruned, void *ppxpFirst)
{
    char buf[0xF60] __attribute__((aligned(16)));
    QW planeWheel, pos0, pos1, posBest, posContact, travelQ, radiusQ;
    QW spill6, spill7, spill8;
    VEnt *pent = &pv->vptr->slotF8;
    QW *pmatOrient = pent->fn((char *)pv + pent->delta);
    __as__6VECTORG9VU_VECTOR(buf + 0x40, ConvertAloPos(pv, 0, F(QW, pwheel, 0x50)));
    Q(0x10) = pmatOrient[0];
    Q(0x20) = pmatOrient[1];
    Q(0x30) = pmatOrient[2];
    I(0x3C) = 0x3F800000;
    I(0x2C) = 0; I(0x1C) = 0; I(0x0C) = 0;
    InvertMatrix4Affine(buf + 0x90, buf + 0x10);
    float sTravel = F(float, pwheel, 0x28) - F(float, pwheel, 0x24);
    float sRadius = F(float, pwheel, 0x20);
    Q(0x60) = Q(0xA0); Q(0x50) = Q(0x90); Q(0x70) = Q(0xB0); Q(0x80) = Q(0xC0);
    InitPlaneFromNormalPos(buf + 0x90, Q(0x20), Q(0x40));
    planeWheel = Q(0x90);
    memset(buf + 0xD0, 0, 0x800);
    CStackFrame_Construct(buf + 0x8D0);
    I(0x90) = 0xFFFC; I(0x94) = 0x10;
    char *abspFirst = (char *)PvAllocStackImpl__Fi(buf + 0x90);
    I(0xEE4) = (int)abspFirst; I(0xEE0) = 0x1555;
    if (PruneBsp__FP3BSPP6VECTORfPP3BSP(pbspPruned, (void *)0x7FFFFFFF, __builtin_sqrtf(sRadius * sRadius + sTravel * sTravel), Q(0x40), (int *)(buf + 0xEE0), (void **)(buf + 0xEE4)) != 2) {
        CStackFrame_Destructor(buf + 0x8D0, 2);
        return;
    }
    int cbsp = (I(0xEE4) - (int)abspFirst) / 12;
    I(0xEE4) = I(0xEE4) - 12;
    char *asurf = F(char *, pgeomOther, 0x9C);
    int ccross = 0;
    int travelBits = *(int *)&sTravel, radiusBits = *(int *)&sRadius;
    radiusQ = radiusBits; travelQ = travelBits;
    for (int ibsp = 0; ibsp < cbsp; ibsp++)
        F(unsigned, F(char *, abspFirst + ibsp * 12, 8), 0x18) |= 0x400;
    for (int ibsp = 0; ibsp < cbsp; ibsp++) {
        char *psurf = F(char *, abspFirst + ibsp * 12, 8);
        if (F(unsigned, psurf, 0x18) & 0x800) continue;
        F(unsigned, psurf, 0x18) |= 0x800;
        for (char *pedge = F(char *, psurf, 0x10); pedge != 0; pedge = F(char *, pedge, 8)) {
            char *psurfOther = asurf + F(unsigned short, pedge, 4) * 0x20;
            if (psurfOther == psurf) psurfOther = asurf + F(unsigned short, pedge, 6) * 0x20;
            if ((F(unsigned, psurfOther, 0x18) & 0x400) == 0) continue;
            char *apos = F(char *, pgeomOther, 0x94);
            pos0 = *(QW *)(apos + F(unsigned short, pedge, 0) * 16);
            pos1 = *(QW *)(apos + F(unsigned short, pedge, 2) * 16);
            func_002564B8(buf + 0xEF0);
            func_002564B8(buf + 0xF00);
            asm("lqc2 vf3, %0" : : "m"(planeWheel));
            asm("lqc2 vf4, %0" : : "m"(pos0));
            asm("vmul.xyz vf1, vf3, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf3w");
            int d0bits;
            asm("qmfc2.ni %0, vf1" : "=r"(d0bits));
            float sDist0;
            asm("mtc1 %1, %0" : "=f"(sDist0) : "r"(d0bits));
            asm("sqc2 vf2, %0" : "=m"(Q(0xF00)));
            asm("sqc2 vf1, %0" : "=m"(Q(0xEF0)));
            func_002564B8(buf + 0xF10);
            func_002564B8(buf + 0xF20);
            asm("lqc2 vf3, %0" : : "m"(planeWheel));
            asm("lqc2 vf4, %0" : : "m"(pos1));
            asm("vmul.xyz vf1, vf3, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf3w");
            int d1bits;
            asm("qmfc2.ni %0, vf1" : "=r"(d1bits));
            float sDist1;
            asm("mtc1 %1, %0" : "=f"(sDist1) : "r"(d1bits));
            asm("sqc2 vf2, %0" : "=m"(Q(0xF20)));
            float u = sDist0 / (sDist0 - sDist1);
            asm("sqc2 vf1, %0" : "=m"(Q(0xF10)));
            if (u < 0.0f) continue;
            if (1.0f < u) continue;
            float uInv = 1.0f - u;
            asm("lqc2 vf1, %0" : : "m"(pos0));
            asm("qmtc2.ni %0, vf6" : : "r"(u));
            asm("lqc2 vf2, %0" : : "m"(pos1));
            asm("qmtc2.ni %0, vf4" : : "r"(uInv));
            asm("lqc2 vf7, %0" : : "m"(Q(0x50)));
            asm("vmulax.xyzw ACC, vf1, vf4x\n\tvmaddx.xyzw vf5, vf2, vf6x");
            asm("lqc2 vf3, %0" : : "m"(Q(0x60)));
            asm("lqc2 vf2, %0" : : "m"(Q(0x70)));
            asm("lqc2 vf1, %0" : : "m"(Q(0x80)));
            asm("vmulax.xyz ACC, vf7, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf1, vf1, vf0w");
            asm("sqc2 vf4, %0" : "=m"(Q(0xB0)));
            asm("sqc2 vf1, %0" : "=m"(Q(0xA0)));
            asm("sqc2 vf6, %0" : "=m"(Q(0xB0)));
            asm("sqc2 vf5, %0" : "=m"(Q(0x90)));
            if (0.0f < FL(0xA8)) {
                float ax = FL(0xA0);
                if (sRadius < __builtin_fabsf(ax)) continue;
            } else {
                asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
                float sRadiusSquared = sRadius * sRadius;
                int lbits;
                asm("qmfc2.ni %0, vf1" : "=r"(lbits));
                float gLen;
                asm("mtc1 %1, %0\n\tnop" : "=f"(gLen) : "r"(lbits));
                if (sRadiusSquared < gLen) continue;
            }
            func_002564C0(buf + 0xF30);
            char *pcross = buf + 0xD0 + ccross * 0x20;
            ccross++;
            asm("lqc2 vf2, %0" : : "m"(pos0));
            asm("lqc2 vf3, %0" : : "m"(pos1));
            asm("lqc2 vf4, %0" : : "m"(planeWheel));
            asm("vsub.xyzw vf1, vf2, vf3\n\tvmul.xyz vf1, vf4, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
            int pbits;
            asm("qmfc2.ni %0, vf1" : "=r"(pbits));
            float gSide;
            asm("mtc1 %1, %0" : "=f"(gSide) : "r"(pbits));
            QW planeCopy;
            asm("qmfc2.ni %0, vf4" : "=r"(planeCopy));
            Q(0xF30) = planeCopy;
            if (gSide < 0.0f) {
                F(char *, pcross, 0x14) = psurfOther;
                F(char *, pcross, 0x10) = psurf;
            } else {
                F(char *, pcross, 0x10) = psurfOther;
                F(char *, pcross, 0x14) = psurf;
            }
            *(QW *)pcross = Q(0xA0);
        }
    }
    for (int ibsp = 0; ibsp < cbsp; ibsp++)
        F(unsigned, F(char *, abspFirst + ibsp * 12, 8), 0x18) &= ~0xC00u;
    asm("lqc2 vf1, %0" : : "m"(g_2a2dc0));
    asm("lqc2 vf2, %0" : : "m"(D_002C2150[0]));
    asm("lqc2 vf7, %0" : : "m"(radiusQ));
    asm("lqc2 vf8, %0" : : "m"(travelQ));
    Q(0x90) = travelQ;
    asm("vmulax.xyzw ACC, vf2, vf7x\n\tvmaddx.xyzw vf2, vf1, vf8x");
    asm("lqc2 vf5, %0" : : "m"(Q(0x10)));
    asm("lqc2 vf4, %0" : : "m"(Q(0x20)));
    asm("lqc2 vf3, %0" : : "m"(Q(0x30)));
    asm("lqc2 vf1, %0" : : "m"(Q(0x40)));
    asm("vmulax.xyz ACC, vf5, vf2x\n\tvmadday.xyz ACC, vf4, vf2y\n\tvmaddaz.xyz ACC, vf3, vf2z\n\tvmaddw.xyz vf6, vf1, vf0w");
    for (unsigned iprobe = 0; iprobe < 6; iprobe++) {
        if (iprobe < 5) {
            asm("sqc2 vf7, %0" : "=m"(Q(0x90)));
            asm("lqc2 vf1, %0" : : "m"(D_002C2150[iprobe]));
            asm("vmulx.xyzw vf5, vf1, vf7x");
        } else {
            asm("lqc2 vf2, %0" : : "m"(D_002C2150[4]));
            asm("lqc2 vf1, %0" : : "m"(g_2a2dc0));
            asm("sqc2 vf8, %0" : "=m"(Q(0x90)));
            asm("vmulax.xyzw ACC, vf2, vf7x\n\tvmaddx.xyzw vf5, vf1, vf8x");
        }
        asm("lqc2 vf3, %0" : : "m"(Q(0x20)));
        asm("lqc2 vf2, %0" : : "m"(Q(0x30)));
        asm("lqc2 vf1, %0" : : "m"(Q(0x40)));
        asm("lqc2 vf4, %0" : : "m"(Q(0x10)));
        QW prev, next;
        asm("qmfc2.ni %0, vf6" : "=r"(prev));
        asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf6, vf1, vf0w");
        asm("qmfc2.ni %0, vf6" : "=r"(next));
        asm("sqc2 vf6, %0" : "=m"(spill6));
        asm("sqc2 vf7, %0" : "=m"(spill7));
        asm("sqc2 vf8, %0" : "=m"(spill8));
        int clsg = ClsgClipEdgeToBsp((void *)I(0xEE4), (void *)0x7FFFFFFF, prev, next, 16, buf + 0x8E0);
        asm("lqc2 vf6, %0" : : "m"(spill6));
        asm("lqc2 vf7, %0" : : "m"(spill7));
        asm("lqc2 vf8, %0" : : "m"(spill8));
        char *plsg = buf + 0x8E0;
        for (int ilsg = 0; ilsg < clsg; ilsg++, plsg += 0x60) {
            if (F(int, plsg, 0x4C) != 0) {
                char *pcross = buf + 0xD0 + ccross * 0x20;
                ccross++;
                F(int, pcross, 0x14) = F(int, plsg, 0x4C);
                asm("lqc2 vf5, %0" : : "m"(*(QW *)plsg));
                asm("lqc2 vf2, %0" : : "m"(Q(0x50)));
                asm("lqc2 vf4, %0" : : "m"(Q(0x60)));
                asm("lqc2 vf3, %0" : : "m"(Q(0x70)));
                asm("lqc2 vf1, %0" : : "m"(Q(0x80)));
                asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w");
                asm("sqc2 vf2, %0" : "=m"(*(QW *)pcross));
            }
            if (F(int, plsg, 0x50) != 0) {
                char *pcross = buf + 0xD0 + ccross * 0x20;
                ccross++;
                F(int, pcross, 0x10) = F(int, plsg, 0x50);
                asm("lqc2 vf5, %0" : : "m"(*(QW *)(plsg + 0x10)));
                asm("lqc2 vf2, %0" : : "m"(Q(0x50)));
                asm("lqc2 vf4, %0" : : "m"(Q(0x60)));
                asm("lqc2 vf3, %0" : : "m"(Q(0x70)));
                asm("lqc2 vf1, %0" : : "m"(Q(0x80)));
                asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w");
                asm("sqc2 vf2, %0" : "=m"(*(QW *)pcross));
            }
        }
    }
    float gLiftBest = 0.0f;
    for (int ipass = 0; ipass < 2; ipass++) {
        for (int icross = 0; icross < ccross; icross++) {
            char *pcross = buf + 0xD0 + icross * 0x20;
            float xLow, xHigh;
            char *psurf;
            if (ipass == 0) {
                int psurfIn = F(int, pcross, 0x14);
                if (psurfIn == 0) continue;
                xLow = -3.402823466e+38f;
                if (F(int, pcross, 0x10) != 0) xLow = F(float, pcross, 0);
                xHigh = 3.402823466e+38f;
                char *pcrossEnd = 0;
                for (int icrossEnd = 0; icrossEnd < ccross; icrossEnd++) {
                    char *pother = buf + 0xD0 + icrossEnd * 0x20;
                    if (F(int, pother, 0x10) == psurfIn && xLow < F(float, pother, 0) && F(float, pother, 0) < xHigh) {
                        xHigh = F(float, pother, 0);
                        pcrossEnd = pother;
                    }
                }
                if (pcrossEnd != 0) F(int, pcrossEnd, 0x18) = 1;
                psurf = (char *)psurfIn;
            } else {
                if (F(int, pcross, 0x10) == 0) continue;
                if (F(int, pcross, 0x18) != 0) continue;
                xLow = -3.402823466e+38f;
                if (F(int, pcross, 0x14) != 0) xHigh = F(float, pcross, 0);
                else xHigh = 3.402823466e+38f;
                psurf = (char *)F(int, pcross, 0x10);
            }
            Q(0x90) = TransformPlane(buf + 0x50, *(QW *)psurf);
            if (FL(0x98) < 0.0f) continue;
            float gSlope = -FL(0x90) / FL(0x98);
            float sRadiusSquared = sRadius * sRadius;
            float x = __builtin_sqrtf(sRadiusSquared * gSlope * gSlope / (gSlope * gSlope + 1.0f));
            if (gSlope < 0.0f) x = -x;
            if (x < xLow) x = xLow;
            else if (xHigh < x) x = xHigh;
            float z = -__builtin_sqrtf(sRadiusSquared - x * x);
            FL(0xA0) = x; I(0xA4) = 0; FL(0xA8) = z;
            func_002564B8(buf + 0xF40);
            func_002564B8(buf + 0xF50);
            asm("lqc2 vf1, %0" : : "m"(Q(0xA0)));
            asm("lqc2 vf2, %0" : : "m"(Q(0x90)));
            asm("vmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddaz.x ACC, vf3, vf2z\n\tvmsubw.x vf2, vf3, vf2w");
            int dbits;
            asm("qmfc2.ni %0, vf2" : "=r"(dbits));
            float gDot;
            asm("mtc1 %1, %0" : "=f"(gDot) : "r"(dbits));
            float gLift = -gDot / FL(0x98);
            if (sTravel < gLift) gLift = sTravel;
            if (gLiftBest < gLift) {
                gLiftBest = gLift;
                FL(0xB0) = x; FL(0xB4) = 0.0f; FL(0xB8) = z + gLiftBest; FL(0xBC) = 0.0f;
                posBest = Q(0xB0);
            }
        }
    }
    if (0.0f < gLiftBest) {
        asm("lqc2 vf3, %0" : : "m"(Q(0x40)));
        asm("lqc2 vf4, %0" : : "m"(Q(0x10)));
        asm("lqc2 vf2, %0" : : "m"(Q(0x20)));
        asm("lqc2 vf1, %0" : : "m"(Q(0x30)));
        asm("lqc2 vf5, %0" : : "m"(posBest));
        asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddaz.xyz ACC, vf1, vf5z\n\tvmaddw.xyz vf5, vf3, vf0w");
        asm("sqc2 vf5, %0" : "=m"(posContact));
        func_002564C0(buf + 0xF60);
        PxpAdd(gLiftBest, B_003DD490, F(void *, pv, 0xE4), pgeomOther, posContact, planeWheel, 10, 0, 0, ppxpFirst);
    }
    CStackFrame_Destructor(buf + 0x8D0, 2);
}
