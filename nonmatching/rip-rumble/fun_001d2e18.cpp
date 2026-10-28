#include "sly2.h"
struct VEHICLE { char pad[4]; };
extern "C" void AddSoGravityAcceleration(VEHICLE *);
extern "C" void *PmatLoWorld(void *);
extern "C" void TiltMatUpright__FP7MATRIX3N20(void *, void *, void *);
extern "C" void AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(VEHICLE *, void *, void *, QW, int);
extern "C" void *func_001D2DD0(VEHICLE *, void *);
extern "C" QW VelocityXfAtPos(void *, void *, QW);
extern "C" void AddSoImpulseAtPos(VEHICLE *, QW, QW);
extern "C" QW ConvertXfVec(void *, void *, QW);
extern "C" float GLimitAbs__Fff(float, float);
extern "C" void AddSoAngularAcceleration(VEHICLE *, QW);
extern "C" void LoadRotateMatrixRad(void *, float, QW);
extern "C" QW LimitVectorLength__FP6VECTORfT0(QW, float);
extern "C" void AddSoAcceleration(VEHICLE *, QW);
extern "C" struct { float t; float dt; } g_2dded0;
extern "C" QW g_2a2dd0, g_2a2dc0;
extern "C" char D_002C2100[];
extern "C" float g_2c2120[3], g_2c2130[3], g_2c2110, g_2c2114, g_2c2140, g_2c2144, g_2c2148;

#define F(type, base, off) (*(type *)((char *)(base) + (off)))
#define Q(off) (*(QW *)(buf + (off)))
#define FL(off) (*(float *)(buf + (off)))

void AddVehicleGravityAcceleration(VEHICLE *pv)
{
    char buf[0x110] __attribute__((aligned(16)));
    AddSoGravityAcceleration(pv);
    if (3.0f < g_2dded0.t - F(float, pv, 0x5C0)) {
        TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(pv), 0, buf);
        AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(pv, buf, D_002C2100, g_2a2dd0, 0);
    }
    float gSusp = 0.0f;
    for (int iwheel = 0; iwheel < F(int, pv, 0x190); iwheel++) {
        char *pwheel = (char *)pv + 0x1A0 + iwheel * 0x60;
        char *pxp = (char *)func_001D2DD0(pv, pwheel);
        if (pxp == 0) continue;
        QW posContact = *(QW *)(pxp + 0x10);
        Q(0xD0) = ((QW *)PmatLoWorld(pv))[2];
        Q(0xE0) = VelocityXfAtPos(F(void *, pv, 0x60), 0, posContact);
        QW velOther = VelocityXfAtPos(F(void *, pxp, 0x44), 0, posContact);
        float uDepth = F(float, pxp, 0x90) / (F(float, pwheel, 0x28) - F(float, pwheel, 0x24));
        float uc = uDepth < 0.0f ? 0.0f : (1.0f < uDepth ? 1.0f : uDepth);
        asm("qmtc2.ni %0, vf1" : : "r"(velOther));
        asm("lqc2 vf3, %0" : : "m"(Q(0xE0)));
        asm("vsub.xyzw vf2, vf1, vf3");
        asm("lqc2 vf3, %0" : : "m"(Q(0xD0)));
        asm("vmul.xyz vf2, vf2, vf3\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z");
        int dotBits;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(dotBits));
        float gVelUp;
        asm volatile("mtc1 %1, %0" : "=f"(gVelUp) : "r"(dotBits));
        float gForce = gVelUp * (g_2c2120[0] + uc * (g_2c2120[1] + uc * g_2c2120[2])) * g_2c2110
                     + F(float, pxp, 0x90) * (g_2c2130[0] + uc * (g_2c2130[1] + uc * g_2c2130[2])) * g_2c2114;
        if (gForce < 0.0f) continue;
        float gMass = F(float, F(void *, pv, 0xE8), 0xD0);
        float gImpulse = gForce * gMass;
        int ibits = *(int *)&gImpulse;
        asm("qmtc2.ni %0, vf2" : : "r"(ibits));
        asm("vmulx.xyzw vf1, vf3, vf2x");
        QW impulse;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(impulse));
        asm("sqc2 vf2, %0" : "=m"(Q(0x0)));
        asm("sqc2 vf1, %0" : "=m"(Q(0x100)));
        AddSoImpulseAtPos(pv, posContact, impulse);
        asm("lqc2 vf1, %0" : : "m"(Q(0x100)));
        asm("lqc2 vf3, %0" : : "m"(Q(0xD0)));
        asm("vmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        int sbits;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(sbits));
        float gDot;
        asm volatile("mtc1 %1, %0\n\tnop" : "=f"(gDot) : "r"(sbits));
        gSusp += gDot;
    }
    float dt = g_2dded0.dt;
    void *pxfLinear = F(void *, pv, 0x58);
    float gNormal = F(float, pv, 0x53C) * gSusp / F(float, F(void *, pv, 0xE8), 0xD0);
    int dtBits = *(int *)&dt;
    asm("qmtc2.ni %0, vf3" : : "r"(dtBits));
    asm("lqc2 vf2, %0" : : "m"(F(QW, pxfLinear, 0xB0)));
    asm("sqc2 vf3, %0" : "=m"(Q(0x10)));
    asm("lqc2 vf1, %0" : : "m"(F(QW, pxfLinear, 0xF0)));
    asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf3x");
    QW velNext;
    asm("sqc2 vf2, %0" : "=m"(Q(0x0)));
    asm volatile("qmfc2.ni %0, vf2" : "=r"(velNext));
    float gCap = g_2c2140 < gNormal ? g_2c2140 : gNormal;
    Q(0x10) = ConvertXfVec(F(void *, pxfLinear, 0xA0), F(void *, pv, 0x5C), velNext);
    void *pxfAngular = F(void *, pv, 0x5C);
    asm("lqc2 vf4, %0" : : "m"(F(QW, pxfAngular, 0x20)));
    asm("lqc2 vf3, %0" : : "m"(F(QW, pxfAngular, 0xB0)));
    asm("lqc2 vf1, %0" : : "m"(F(QW, pxfAngular, 0x10)));
    asm("lqc2 vf2, %0" : : "m"(F(QW, pxfAngular, 0x0)));
    asm("vmul.xyzw vf7, vf2, vf3\n\tvmaxw.xyzw vf8, vf0, vf0w\n\tvmul.xyzw vf6, vf1, vf3\n\tvmul.xyzw vf5, vf4, vf3");
    asm("vadday.x ACC, vf7, vf7y\n\tvmaddz.x vf2, vf8, vf7z\n\tvaddax.y ACC, vf6, vf6x\n\tvmaddz.y vf2, vf8, vf6z\n\tvaddax.z ACC, vf5, vf5x\n\tvmaddy.z vf2, vf8, vf5y");
    asm("sqc2 vf2, %0" : "=m"(Q(0x20)));
    float gYawLimit = g_2c2144 * F(float, F(void *, pv, 0xE8), 0xD0) * F(float, pv, 0x4A0) / F(float, F(void *, pv, 0xE8), 0x28);
    FL(0x34) = 0.0f; FL(0x30) = 0.0f;
    float dradYaw = GLimitAbs__Fff((F(float, pv, 0x554) - FL(0x28)) / dt, gYawLimit * gCap);
    FL(0x38) = dradYaw;
    float gLoss = g_2c2148 * dradYaw / gYawLimit;
    void *pm = (char *)F(void *, pv, 0x5C) + 0x40;
    asm("lqc2 vf4, %0" : : "m"(F(QW, F(void *, pv, 0x5C), 0x40)));
    asm("lqc2 vf3, %0" : : "m"(F(QW, pm, 0x20)));
    asm("lqc2 vf2, %0" : : "m"(F(QW, pm, 0x10)));
    asm("lqc2 vf1, %0" : : "m"(Q(0x30)));
    asm("vmulax.xyz ACC, vf4, vf1x\n\tvmadday.xyz ACC, vf2, vf1y\n\tvmaddz.xyz vf1, vf3, vf1z");
    QW accAng;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(accAng));
    asm("sqc2 vf1, %0" : "=m"(Q(0x40)));
    gCap = gCap - __builtin_fabsf(gLoss);
    AddSoAngularAcceleration(pv, accAng);
    LoadRotateMatrixRad(buf + 0x90, (FL(0x28) + FL(0x38) * (dt * 0.5f)) * dt, g_2a2dc0);
    float gSpeedGoal = F(float, pv, 0x550);
    FL(0x84) = 0.0f; FL(0x88) = 0.0f;
    FL(0x80) = F(float, pv, 0x558) * gSpeedGoal;
    asm("lqc2 vf3, %0" : : "m"(Q(0x90)));
    asm("lqc2 vf4, %0" : : "m"(Q(0xA0)));
    asm("lqc2 vf2, %0" : : "m"(Q(0xB0)));
    asm("lqc2 vf1, %0" : : "m"(Q(0x80)));
    asm("vmulax.xyz ACC, vf3, vf1x\n\tvmadday.xyz ACC, vf4, vf1y\n\tvmaddz.xyz vf1, vf2, vf1z");
    asm("sqc2 vf1, %0" : "=m"(Q(0x80)));
    float uSpeed = FL(0x10) / F(float, pv, 0x51C);
    asm("sqc2 vf3, %0" : "=m"(Q(0x50)));
    asm("sqc2 vf4, %0" : "=m"(Q(0x60)));
    asm("sqc2 vf2, %0" : "=m"(Q(0x70)));
    float gLow, gHigh;
    if (0.0f <= gSpeedGoal) {
        float u;
        if (uSpeed < 0.0f) u = 0.0f;
        else { u = uSpeed; if (1.0f < uSpeed) u = 1.0f; }
        float gAccel = F(float, pv, 0x520) + u * (F(float, pv, 0x524) + u * F(float, pv, 0x528));
        if (gAccel < F(float, pv, 0x530)) gAccel = F(float, pv, 0x530);
        else if (F(float, pv, 0x534) < gAccel) gAccel = F(float, pv, 0x534);
        gLow = -F(float, pv, 0x538);
        gHigh = gAccel;
    } else {
        float un = -uSpeed;
        float u;
        if (un < 0.0f) u = 0.0f;
        else { u = un; if (1.0f < un) u = 1.0f; }
        float gAccel = F(float, pv, 0x520) + u * (F(float, pv, 0x524) + u * F(float, pv, 0x528));
        if (gAccel < F(float, pv, 0x530)) gAccel = F(float, pv, 0x530);
        else if (F(float, pv, 0x534) < gAccel) gAccel = F(float, pv, 0x534);
        gLow = -gAccel;
        gHigh = F(float, pv, 0x538);
    }
    asm("lqc2 vf2, %0" : : "m"(Q(0x80)));
    asm("lqc2 vf3, %0" : : "m"(Q(0x10)));
    int dtb = *(int *)&g_2dded0.dt;
    asm("vsub.xyzw vf2, vf2, vf3");
    asm("qmtc2.ni %0, vf1" : : "r"(dtb));
    asm("sqc2 vf1, %0" : "=m"(Q(0xC0)));
    asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf2, Q");
    asm("sqc2 vf1, %0" : "=m"(Q(0x90)));
    *(int *)(buf + 0x98) = 0;
    float ax = FL(0x90);
    if (ax < gLow) ax = gLow;
    else if (gHigh < ax) ax = gHigh;
    FL(0x90) = ax;
    QW limited = LimitVectorLength__FP6VECTORfT0(Q(0x90), gCap);
    Q(0xB0) = limited;
    QW world = ConvertXfVec(F(void *, pv, 0x5C), 0, limited);
    Q(0xA0) = world;
    AddSoAcceleration(pv, world);
}
