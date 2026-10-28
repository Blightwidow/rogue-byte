#include "sly2.h"
struct SMP;
struct XF { QW row[4]; char pad[0x70 - 0x40]; QW posWorld; char pad2[0x20]; XF *pxfParent; int generation; };
struct WHEEL {
    char pad0[4]; XF *pxf; char pad1[0xC]; float radSteer; float dradSpin; float radSpin; float sRadius; char pad2[0xC];
    float posRestX; float posRestY; char pad3[0x20]; float posBottomZ; char pad4[0x60 - 0x5C];
};
struct VTB { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct VEHICLE {
    char pad0[0xC]; VTB *vptr; char pad1[0x60 - 0x10]; XF *pxfRoot; char pad2[0x190 - 0x64];
    int cwheel; char pad3[0x1A0 - 0x194]; WHEEL awheel[1];
};
extern "C" QW bevy_camera_follow_track_heading_weight(void *, void *, QW);
extern "C" QW ConvertXfPos(void *, void *, QW);
extern "C" void *func_001D2DD0(VEHICLE *, WHEEL *);
extern "C" float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
extern "C" float RadNormalize__Ff(float);
extern "C" void LoadRotateMatrixRad(void *, float, QW);
extern "C" void UpdateAloXfWorld(VEHICLE *);
extern "C" void func_001F3C70(VEHICLE *);
extern "C" void __as__6VECTORG9VU_VECTOR(VECTOR *, QW);
extern "C" struct { float pad; float dt; } g_2dded0;
extern "C" struct { char pad[0x3D58]; int generation; } B_003DD490;
extern "C" float D_002C21CC;
extern "C" SMP D_002C21A0, D_002C21B0, D_002C21C0;
extern "C" QW g_2a2dc0, g_2a2db0;

#define VEL (*(QW *)(buf))
#define VELX (*(float *)(buf))
#define POSW (*(QW *)(buf + 0x10))
#define POSWZ (*(float *)(buf + 0x18))
#define STEER (buf + 0x80)
#define SPIN (buf + 0xB0)
#define RA ((QW *)(buf + 0x20))
#define RB ((QW *)(buf + 0xE0))
#define RC ((QW *)(buf + 0x50))

void RenderVehicleSelf(VEHICLE *pv)
{
    char buf[0x110] __attribute__((aligned(16)));
    VTB *vt = pv->vptr;
    VEL = bevy_camera_follow_track_heading_weight(0, pv, vt->fn((char *)pv + vt->delta));
    for (int iwheel = 0; iwheel < pv->cwheel; iwheel++) {
        WHEEL *pwheel = &pv->awheel[iwheel];
        POSW = ConvertXfPos(0, pv->pxfRoot, pwheel->pxf->posWorld);
        ((float *)&POSW)[0] = pwheel->posRestX;
        ((float *)&POSW)[1] = pwheel->posRestY;
        char *pxp = (char *)func_001D2DD0(pv, pwheel);
        float zTarget;
        if (pxp != 0) {
            float zSum = pwheel->posBottomZ + *(float *)(pxp + 0x90);
            if (POSWZ < zSum) {
                POSWZ = zSum;
                goto skip;
            }
            zTarget = zSum;
        } else {
            zTarget = pwheel->posBottomZ;
        }
        GSmooth__FfffP3SMPPf(POSWZ, zTarget, g_2dded0.dt, &D_002C21A0, 0);
        POSWZ = zTarget;
    skip:
        POSW = ConvertXfPos(pv->pxfRoot, pwheel->pxf->pxfParent, POSW);
        float dradGoal;
        if (iwheel < 2)
            dradGoal = 0.0f;
        else
            dradGoal = *(float *)((char *)pv + 0x550) / pwheel->sRadius;
        if (pxp != 0) {
            float dradRoll = VELX / pwheel->sRadius;
            if ((0.0f < dradGoal && dradRoll < D_002C21CC * dradGoal) || (dradGoal < 0.0f && D_002C21CC * dradGoal < dradRoll))
                pwheel->dradSpin = GSmooth__FfffP3SMPPf(pwheel->dradSpin, D_002C21CC * dradGoal, g_2dded0.dt, &D_002C21B0, 0);
            else
                pwheel->dradSpin = dradRoll;
        } else {
            SMP *psmp = (__builtin_fabsf(pwheel->dradSpin) < __builtin_fabsf(dradGoal)) ? &D_002C21B0 : &D_002C21C0;
            pwheel->dradSpin = GSmooth__FfffP3SMPPf(pwheel->dradSpin, dradGoal, g_2dded0.dt, psmp, 0);
        }
        pwheel->radSpin = RadNormalize__Ff(pwheel->radSpin + pwheel->dradSpin * g_2dded0.dt);
        LoadRotateMatrixRad(STEER, pwheel->radSteer, g_2a2dc0);
        LoadRotateMatrixRad(SPIN, pwheel->radSpin, g_2a2db0);
        asm("lqc2 vf3, %0" : : "m"(*(QW *)(STEER)));
        asm("lqc2 vf5, %0" : : "m"(*(QW *)(STEER + 0x10)));
        asm("lqc2 vf1, %0" : : "m"(*(QW *)(STEER + 0x20)));
        asm("lqc2 vf4, %0" : : "m"(*(QW *)(SPIN)));
        asm("lqc2 vf6, %0" : : "m"(*(QW *)(SPIN + 0x10)));
        asm("vmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf5, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z");
        XF *pxfOut = pwheel->pxf;
        asm("vmulax.xyz ACC, vf3, vf6x\n\tvmadday.xyz ACC, vf5, vf6y\n\tvmaddz.xyz vf6, vf1, vf6z");
        asm("lqc2 vf2, %0" : : "m"(*(QW *)(SPIN + 0x20)));
        asm("vmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf5, vf2y\n\tvmaddz.xyz vf3, vf1, vf2z");
        asm("sqc2 vf4, %0" : "=m"(RA[0]));
        asm("sqc2 vf6, %0" : "=m"(RA[1]));
        asm("sqc2 vf3, %0" : "=m"(RA[2]));
        asm("sqc2 vf4, %0" : "=m"(RB[0]));
        asm("sqc2 vf4, %0" : "=m"(RC[0]));
        asm("sqc2 vf6, %0" : "=m"(RB[1]));
        asm("sqc2 vf6, %0" : "=m"(RC[1]));
        asm("sqc2 vf3, %0" : "=m"(RB[2]));
        asm("sqc2 vf3, %0" : "=m"(RC[2]));
        __as__6VECTORG9VU_VECTOR((VECTOR *)&pxfOut->row[3], POSW);
        pxfOut->row[0] = RA[0];
        pxfOut->row[1] = RA[1];
        pxfOut->row[2] = RA[2];
        ((float *)&pxfOut->row[3])[3] = 1.0f;
        ((float *)&pxfOut->row[2])[3] = 0.0f;
        ((float *)&pxfOut->row[1])[3] = 0.0f;
        ((float *)&pxfOut->row[0])[3] = 0.0f;
        int generation = ++B_003DD490.generation;
        pwheel->pxf->generation = generation;
    }
    UpdateAloXfWorld(pv);
    func_001F3C70(pv);
}
