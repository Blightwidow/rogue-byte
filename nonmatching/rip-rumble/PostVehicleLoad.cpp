#include "sly2.h"
void *memmove(void *, const void *, unsigned int);
struct WHEEL {
    int oid; char *pxf; char pad8[4]; float uSteer; float uSteerSide; char pad14[0x24 - 0x14]; int sTravelMin; int sTravelMax;
    char pad2c[4]; QW posRest; QW posTop; QW posBottom;
};
struct AXLE { int oid; char *pxf; int pact; char pad[0x14 - 0xC]; };
struct GUN { char pad0[0x18]; int oidSm; char pad1c[0x2C - 0x1C]; int oidXf; int oidMuzzle; char pad34[0]; };
struct GUNF { int pad0[0x1C / 4]; int ploPlo; int psmaPlo; };
struct VEHICLE {
    char pad0[0x190]; int cwheel; char pad194[0x1A0 - 0x194]; WHEEL awheel[1];
};
extern "C" void PostSoLoad(VEHICLE *);
extern "C" char *func_001F4C58(VEHICLE *, int, int);
extern "C" QW ConvertAloPos(void *, VEHICLE *, QW);
extern "C" int func_0012DC18(VEHICLE *, char *, int, int, int, QW);
extern "C" void *PloFindSwObject_thunk(void *, int, int, VEHICLE *);
extern "C" void *PsmaApplySm(void *, VEHICLE *, int, int);
extern "C" int PcrvNew(int, int);
extern "C" void func_001F1448(int, VEHICLE *, int, int, void *);
extern "C" void func_001D14C0(VEHICLE *);
extern "C" char B_003DD490[];
extern "C" QW g_2a2dc0, g_2a2dd0;

#define WHEELS(v) ((WHEEL *)((char *)(v) + 0x1A0))
#define AXLES(v) ((AXLE *)((char *)(v) + 0x4A8))
#define GUNS(v) ((char **)((char *)(v) + 0x4FC))
#define F32(v, off) (*(float *)((char *)(v) + (off)))
#define I32(v, off) (*(int *)((char *)(v) + (off)))

void PostVehicleLoad(VEHICLE *pv)
{
    struct { QW junk, posMax, posMin; } fr;
#define junk fr.junk
#define posMax fr.posMax
#define posMin fr.posMin
    QW posMinReg;
    asm("vsub.xyzw vf1, vf0, vf0\n\tqmfc2.ni %0, vf1\n\tsqc2 vf1, %1" : "=r"(posMinReg), "=m"(posMax));
    posMin = posMinReg;
    PostSoLoad(pv);
    int iwheel = 0;
    for (iwheel = 0; iwheel < pv->cwheel; iwheel++) {
        WHEEL *pwheel = &WHEELS(pv)[iwheel];
        pwheel->pxf = func_001F4C58(pv, pwheel->oid, 0xD);
        if (pwheel->pxf == 0) {
            memmove(pwheel, pwheel + 1, (pv->cwheel - iwheel) * 0x60 - 0x60);
            pv->cwheel = pv->cwheel - 1;
            iwheel--;
        } else {
            QW pos = ConvertAloPos(0, pv, *(QW *)(pwheel->pxf + 0x70));
            asm("qmtc2.ni %0, vf2\n\tsqc2 vf2, %1" : : "r"(pos), "m"(pwheel->posRest));
            int travelMax = pwheel->sTravelMax;
            asm("qmtc2.ni %0, vf3\n\tsqc2 vf3, %1" : : "r"(travelMax), "m"(junk));
            int travelMin = pwheel->sTravelMin;
            asm("qmtc2.ni %0, vf4" : : "r"(travelMin));
            asm("lqc2 vf1, %1\n\tvmini.xyz vf1, vf2, vf1\n\tlqc2 vf5, %2\n\tsqc2 vf1, %0" : "=m"(posMin) : "m"(posMin), "m"(posMax));
            asm("vmax.xyz vf5, vf2, vf5\n\tlqc2 vf1, %1\n\tsqc2 vf5, %0" : "=m"(posMax) : "m"(g_2a2dc0));
            asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf3, vf1, vf3x\n\tsqc2 vf3, %0" : "=m"(pwheel->posTop));
            asm("sqc2 vf4, %0\n\tlqc2 vf1, %1" : "=m"(junk) : "m"(g_2a2dc0));
            asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf4x\n\tsqc2 vf2, %0" : "=m"(pwheel->posBottom));
        }
    }
    float maxX, minX;
    asm("mtc1 %1, %0" : "=f"(maxX) : "r"(posMax));
    asm("mtc1 %1, %0" : "=f"(minX) : "r"(posMin));
    F32(pv, 0x4A0) = maxX - minX;
    float dxHalfMax, dyHalfMax;
    {
        float negMinX = -minX;
        dxHalfMax = maxX > negMinX ? maxX : negMinX;
        QW tmin, tmax;
        asm("prot3w %0, %1" : "=r"(tmin) : "r"(posMin));
        asm("prot3w %0, %1" : "=r"(tmax) : "r"(posMax));
        float minY, maxY;
        asm("mtc1 %1, %0" : "=f"(minY) : "r"(tmin));
        asm("mtc1 %1, %0" : "=f"(maxY) : "r"(tmax));
        minY = -minY;
        dyHalfMax = minY > maxY ? minY : maxY;
    }
    for (iwheel = 0; iwheel < pv->cwheel; iwheel++) {
        WHEEL *pwheel = &WHEELS(pv)[iwheel];
        float x = ((float *)&pwheel->posRest)[0];
        float y = ((float *)&pwheel->posRest)[1];
        pwheel->uSteer = x / dxHalfMax;
        pwheel->uSteerSide = y / dyHalfMax;
    }
    char *pslot = (char *)pv + 0x570;
    int iaxle;
    for (iaxle = 0; iaxle < I32(pv, 0x4A4); iaxle++) {
        AXLE *paxle = &AXLES(pv)[iaxle];
        paxle->pxf = func_001F4C58(pv, paxle->oid, 6);
        if (paxle->pxf == 0) {
            memmove(paxle, paxle + 1, (I32(pv, 0x4A4) - iaxle) * 0x14 - 0x14);
            I32(pv, 0x4A4) = I32(pv, 0x4A4) - 1;
            iaxle--;
        } else {
            paxle->pact = func_0012DC18(pv, paxle->pxf, 1, 7, 3, g_2a2dd0);
        }
    }
    int igun;
    for (igun = 0; igun < I32(pv, 0x4F8); igun++) {
        char **ppgun = &GUNS(pv)[igun];
        char *pgun = *ppgun;
        int *pact;
        I32(pgun, 0x1C) = (int)PloFindSwObject_thunk(B_003DD490, 1, I32(pgun, 0x18), pv);
        if (I32(pgun, 0x1C) == 0) goto removeGun;
        I32(pgun, 0x30) = (int)func_001F4C58(pv, I32(pgun, 0x2C), 6);
        if (I32(pgun, 0x30) == 0 && I32(pgun, 0x2C) != -1) goto removeGun;
        I32(pgun, 0x3C) = (int)PloFindSwObject_thunk(B_003DD490, 1, I32(pgun, 0x38), pv);
        if (I32(pgun, 0x3C) == 0 && I32(pgun, 0x38) != -1) goto removeGun;
        I32(pgun, 0x20) = (int)PsmaApplySm((void *)I32(pgun, 0x1C), pv, -1, 0);
        if (I32(pgun, 0x30) != 0)
            I32(pgun, 0x34) = func_0012DC18(pv, (char *)I32(pgun, 0x30), 1, 7, 3, g_2a2dd0);
        continue;
    removeGun:
        memmove(ppgun, &GUNS(pv)[igun + 1], (I32(pv, 0x4F8) - igun) * 4 - 4);
        I32(pv, 0x4F8) = I32(pv, 0x4F8) - 1;
        igun--;
    }
    I32(pv, 0x5AC) = PcrvNew(0x2C9, 0x10);
    func_001F1448(I32(pv, 0x56C), pv, -1, 0, pslot);
    func_001D14C0(pv);
}
