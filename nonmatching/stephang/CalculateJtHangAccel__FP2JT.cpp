#include "sly2.h"
struct SMPA;
struct OBJ { char pad[0xC]; char *vt; };
struct VT { char pad[0x100]; short delta; short idx; void *(*fn)(void *, int); };
struct VTV { char pad[0x108]; short delta; short idx; QW (*fn)(void *); };
struct OBJ1 { char pad[0xC]; VT *vt; };
struct OBJV { char pad[0xC]; VTV *vt; };
extern "C" {
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
QW VelocityXfAtPos(void *, void *, QW);
float SProjectVector__FP6VECTORT0(QW, QW, QW *, QW *);
float GSmoothA__FffffP4SMPAPf(float, float, float, float, SMPA *, float *);
void LoadRotateMatrix(void *, QW);
void AnticipateJtForce__FP2JTP2SOP6VECTORT2P2FX(void *, void *, void *, void *, void *);
}
extern QW g_2a2dc0;
extern QW g_2a2da0;
extern QW g_2a2db0;
extern QW g_2a2dd0;
extern float D_002BF4F0[];
extern float D_002BF500[];
extern float D_002BF508;
extern float D_002BF50C;
extern float D_002BF510;
extern float D_002BF514;
extern float D_002BF520[];
extern float g_2bbb60[];
extern float D_002BF530[];
extern float D_002BF540;
extern float D_002BF544;
extern float g_2dded0[];
static inline float LaneN(QW q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
struct LOC {
    QW posPivot;    // 0x00
    QW vecToJt;     // 0x10
    QW pivotVel;    // 0x20
    QW vecDir;      // 0x30
    QW matRow0;     // 0x40
    QW matRow1;     // 0x50
    QW matRow2;     // 0x60
    QW velRel;      // 0x70
    QW perp;        // 0x80
    QW along;       // 0x90
    QW axisSwing;   // 0xA0
    QW omega;       // 0xB0
    QW slotC0;      // 0xC0
    QW axisGrav;    // 0xD0
    QW alpha;       // 0xE0
    QW omegaDamped; // 0xF0
    QW along2;      // 0x100
    QW perp2;       // 0x110
    QW anchor;      // 0x120
    QW slot130, slot140, slot150, slot160, slot170, slot180;
    QW rot[3];      // 0x190
    QW slot1C0;
    QW ropeSpeed;   // 0x1D0
    QW slot1E0, slot1F0, slot200, slot210, slot220;
};
int CalculateJtHangAccel(char *jt)
{
    LOC l;
    l.posPivot = PosLoWorld(*(void **)(jt + 0x18C4));
    QW *pmat = PmatLoWorld(*(void **)(jt + 0x18C4));
    l.matRow0 = pmat[0];
    l.matRow1 = pmat[1];
    l.matRow2 = pmat[2];
    OBJ1 *pivot = *(OBJ1 **)(jt + 0x18C4);
    void *xf = pivot->vt->fn((char *)pivot + pivot->vt->delta, 0);
    l.pivotVel = VelocityXfAtPos(xf, 0, l.posPivot);
    QW posJt = PosLoWorld(jt);
    QW *pdefDir = &g_2a2dc0;
    register QW p2 asm("vf2");
    asm("qmtc2.ni %1, vf2" : "=j" (p2) : "r" (posJt));
    register QW p1 asm("vf1") = l.posPivot;
    register QW p3 asm("vf3");
    asm("vsub.xyzw vf3, vf2, vf1" : "=j" (p3) : "j" (p2), "j" (p1), "r" (pdefDir));
    register QW q1 asm("vf1");
    register QW q2 asm("vf2");
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (q1), "=j" (q2) : "j" (p3));
    l.vecDir = p3;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=j" (q2) : "j" (q1));
    l.vecToJt = p3;
    QW lenBits;
    asm("qmfc2.ni %0, vf2" : "=r" (lenBits) : "j" (q2));
    float lenCmp = LaneN(lenBits);
    if (lenCmp < 0.0001f) {
        l.vecDir = *pdefDir;
    } else {
        register QW d1 asm("vf1");
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q" : "=j" (d1) : "j" (q2), "j" (p3));
        l.vecDir = d1;
    }
    QW ropeBits;
    asm("qmfc2.ni %0, vf2" : "=r" (ropeBits) : "j" (q2));
    float sRope = LaneN(ropeBits);
    OBJV *pjv = (OBJV *)jt;
    QW vel = pjv->vt->fn(jt + pjv->vt->delta);
    register QW v3 asm("vf3");
    asm("qmtc2.ni %1, vf3" : "=j" (v3) : "r" (vel));
    register QW v1 asm("vf1") = l.pivotVel;
    register QW v2 asm("vf2");
    asm("vsub.xyzw vf2, vf3, vf1" : "=j" (v2) : "j" (v3), "j" (v1));
    l.velRel = v2;
    float gSpeedRadial = SProjectVector__FP6VECTORT0(v2, l.vecDir, &l.along, &l.perp);
    register QW x2 asm("vf2") = l.vecDir;
    register QW x1 asm("vf1") = l.perp;
    QW *pdefAxis = &g_2a2da0;
    register QW x3 asm("vf3");
    asm("vopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf3, vf1, vf2" : "=j" (x3) : "j" (x2), "j" (x1), "r" (pdefAxis));
    register QW y1 asm("vf1");
    register QW y2 asm("vf2");
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (y1), "=j" (y2) : "j" (x3));
    QW defAxis = *pdefAxis;
    asm("" : "+r" (defAxis));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (y1) : "j" (y1));
    QW bits2;
    asm("qmfc2.ni %0, vf1" : "=r" (bits2) : "j" (y1));
    float cmp2 = LaneN(bits2);
    register QW a4 asm("vf4") = defAxis;
    if (cmp2 < 0.0001f) {
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf4, vf3, Q" : "=j" (a4) : "j" (y1), "j" (x3), "j" (a4));
    }
    register QW z1 asm("vf1") = l.perp;
    register QW z2 asm("vf2");
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (z1), "=j" (z2) : "j" (z1));
    l.axisSwing = a4;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (z1) : "j" (z1));
    register QW dirv3 asm("vf3") = l.vecDir;
    QW sPerpBits;
    asm("qmfc2.ni %0, vf1" : "=r" (sPerpBits) : "j" (z1), "j" (dirv3));
    float sPerp;
    asm("mtc1 %1, %0" : "=f" (sPerp) : "r" (sPerpBits));
    char *phys = *(char **)(jt + 0xE8);
    float gOmega = sPerp / sRope;
    QW defGrav = g_2a2db0;
    asm("" : "+r" (defGrav));
    QW gOmegaQ;
    asm("mfc1 %0, %1" : "=r" (gOmegaQ) : "f" (gOmega));
    register QW g1 asm("vf1") = gOmegaQ;
    register QW om2 asm("vf2");
    asm("vmulx.xyzw vf2, vf4, vf1x" : "=j" (om2) : "j" (a4), "j" (g1));
    l.slotC0 = g1;
    l.omega = om2;
    register QW gr2 asm("vf2") = *(QW *)(phys + 0x80);
    register QW gr3 asm("vf3") = l.vecDir;
    register QW gr1 asm("vf1");
    register QW gr4 asm("vf4");
    asm("vmul.xyz vf1, vf2, vf3\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z" : "=j" (gr1), "=j" (gr4) : "j" (gr2), "j" (gr3));
    asm("vmulx.xyzw vf1, vf3, vf1x\n\tvsub.xyzw vf2, vf2, vf1" : "=j" (gr1), "=j" (gr2) : "j" (gr3), "j" (gr1), "j" (gr2));
    register QW tan4 asm("vf4");
    asm("vopmula.xyz ACC, vf3, vf2\n\tvopmsub.xyz vf4, vf2, vf3" : "=j" (tan4) : "j" (gr3), "j" (gr2));
    l.slotC0 = gr2;
    register QW t1 asm("vf1");
    register QW t3 asm("vf3");
    asm("vmul.xyz vf1, vf4, vf4\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : "=j" (t1), "=j" (t3) : "j" (tan4));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (t1) : "j" (t1));
    QW bits3;
    asm("qmfc2.ni %0, vf1" : "=r" (bits3) : "j" (t1));
    float cmp3 = LaneN(bits3);
    register QW a3 asm("vf3") = defGrav;
    if (cmp3 < 0.0001f) {
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf3, vf4, Q" : "=j" (a3) : "j" (t1), "j" (tan4), "j" (a3));
    }
    register QW u1 asm("vf1") = l.slotC0;
    register QW u2 asm("vf2");
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (u1), "=j" (u2) : "j" (u1));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (u1) : "j" (u1));
    QW lenGBits;
    asm("qmfc2.ni %0, vf1" : "=r" (lenGBits) : "j" (u1));
    float lenG;
    asm("mtc1 %1, %0\n\tnop" : "=f" (lenG) : "r" (lenGBits));
    float gAlpha = lenG / sRope;
    float gK = D_002BF4F0[0] + gOmega * (D_002BF4F0[1] + gOmega * D_002BF4F0[2]);
    l.axisGrav = a3;
    QW gAlphaQ;
    asm("mfc1 %0, %1" : "=r" (gAlphaQ) : "f" (gAlpha));
    register QW al2 asm("vf2") = gAlphaQ;
    register QW al1 asm("vf1");
    asm("vmulx.xyzw vf1, vf3, vf2x" : "=j" (al1) : "j" (a3), "j" (al2));
    l.alpha = al1;
    float gKAlong;
    if (gK < D_002BF500[0]) {
        l.omegaDamped = al2;
        gKAlong = D_002BF500[0];
    } else {
        l.omegaDamped = al2;
        if (D_002BF500[1] < gK)
            gKAlong = D_002BF500[1];
        else
            gKAlong = gK;
    }
    int jtbs = *(int *)(jt + 0x18D0);
    float gKAcross;
    if (jtbs == 0 || jtbs == 2)
        gKAcross = D_002BF508;
    else
        gKAcross = D_002BF50C;
    register QW c1 asm("vf1") = l.alpha;
    register QW c2 asm("vf2") = l.omega;
    QW row1 = l.matRow1;
    int dtBits = ((int *)g_2dded0)[1];
    register QW c3 asm("vf3");
    asm("qmtc2.ni %1, vf3" : "=j" (c3) : "r" (dtBits));
    register QW on2 asm("vf2");
    asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf3x" : "=j" (on2) : "j" (c2), "j" (c1), "j" (c3));
    l.anchor = c3;
    l.omegaDamped = on2;
    SProjectVector__FP6VECTORT0(on2, row1, &l.along2, &l.perp2);
    float dt = g_2dded0[1];
    float gA = gKAlong * dt + 1.0f;
    float gB = gKAcross * dt + 1.0f;
    QW gAq, gBq;
    asm("mfc1 %0, %1" : "=r" (gAq) : "f" (gA));
    asm("mfc1 %0, %1" : "=r" (gBq) : "f" (gB));
    register QW d4 asm("vf4") = l.along2;
    register QW d3 asm("vf3") = l.perp2;
    register QW d1 asm("vf1") = gAq;
    register QW d2 asm("vf2") = gBq;
    l.anchor = d1;
    asm("vmulax.xyzw ACC, vf4, vf1x\n\tvmaddx.xyzw vf1, vf3, vf2x" : "=j" (d1) : "j" (d4), "j" (d3), "j" (d1), "j" (d2));
    l.anchor = d2;
    l.omegaDamped = d1;
    jtbs = *(int *)(jt + 0x18D0);
    if (jtbs == 0 || jtbs == 2) {
        if (g_2dded0[0] - *(float *)(jt + 0x18D4) < D_002BF510) {
            float gPump = dt * D_002BF514;
            if (jtbs == 0)
                gPump = -gPump;
            if (*(int *)(jt + 0x18FC))
                gPump = -gPump;
            char *phys2 = *(char **)(jt + 0xE8);
            register QW e1 asm("vf1") = l.perp;
            register QW e2 asm("vf2");
            asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (e1), "=j" (e2) : "j" (e1));
            float gGravDown = *(float *)(phys2 + 0x88);
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (e1) : "j" (e1));
            QW sPerp2Bits;
            asm("qmfc2.ni %0, vf1" : "=r" (sPerp2Bits) : "j" (e1));
            gGravDown = -gGravDown;
            float sPerp2;
            asm("mtc1 %1, %0" : "=f" (sPerp2) : "r" (sPerp2Bits));
            float gHeight = (gGravDown * ((float *)&l.vecToJt)[2] + sPerp2 * (sPerp2 * 0.5f)) / gGravDown;
            float gEnergy = D_002BF520[0] + gHeight * (D_002BF520[1] + gHeight * D_002BF520[2]);
            if (gEnergy < g_2bbb60[0])
                gEnergy = g_2bbb60[0];
            else if (g_2bbb60[1] < gEnergy)
                gEnergy = g_2bbb60[1];
            gPump = gPump * gEnergy;
            register QW f1 asm("vf1") = l.omegaDamped;
            register QW f2 asm("vf2") = l.matRow1;
            QW gPumpQ;
            asm("mfc1 %0, %1" : "=r" (gPumpQ) : "f" (gPump));
            register QW f3 asm("vf3") = gPumpQ;
            asm("vadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf2, vf3x" : "=j" (f1) : "j" (f1), "j" (f2), "j" (f3));
            l.anchor = f3;
            l.omegaDamped = f1;
        }
    }
    float gGoalRope = D_002BF544 - *(float *)(*(char **)(jt + 0x18C4) + 0x134);
    float sRopeNew = GSmoothA__FffffP4SMPAPf(sRope, gSpeedRadial, gGoalRope, g_2dded0[1], (SMPA *)D_002BF530, (float *)&l.ropeSpeed);
    float cap = sRope < D_002BF544 ? sRope : D_002BF544;
    float floorRope = sRopeNew > D_002BF540 ? sRopeNew : D_002BF540;
    float ratio = cap / floorRope;
    register QW h2 asm("vf2") = l.omegaDamped;
    void *hangBody = *(void **)(jt + 0x1900);
    QW ratioQ;
    asm("mfc1 %0, %1" : "=r" (ratioQ) : "f" (ratio));
    register QW h1 asm("vf1") = ratioQ;
    asm("vmulx.xyzw vf2, vf2, vf1x" : "=j" (h2) : "j" (h2), "j" (h1));
    l.anchor = h1;
    l.omegaDamped = h2;
    if (hangBody) {
        void *pso = *(void **)((char *)hangBody + 4);
        QW dtQ;
        asm("lw %0, %1" : "=r" (dtQ) : "m" (((int *)g_2dded0)[1]));
        l.slot1F0 = dtQ;
        register QW k1 asm("vf1") = l.posPivot;
        register QW k2 asm("vf2") = g_2a2dd0;
        QW pv = l.pivotVel;
        l.slot200 = k1;
        l.slot130 = k2;
        l.slot140 = k2;
        l.slot210 = k2;
        l.slot1E0 = pv;
        l.slot150 = dtQ;
        QW posBody = PosLoWorld(pso);
        register QW m1 asm("vf1") = l.slot200;
        register QW m3 asm("vf3");
        asm("qmtc2.ni %1, vf3" : "=j" (m3) : "r" (posBody));
        register QW m2 asm("vf2") = l.slot210;
        asm("vsub.xyzw vf1, vf1, vf3" : "=j" (m1) : "j" (m1), "j" (m3));
        asm("vopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf1, vf1, vf2" : "=j" (m1) : "j" (m1), "j" (m2));
        register QW m4 asm("vf4") = l.slot1E0;
        register QW m5 asm("vf5") = l.slot1F0;
        asm("vadda.xyzw ACC, vf0, vf4\n\tvmaddax.xyzw ACC, vf2, vf5x\n\tvmaddx.xyzw vf1, vf1, vf5x" : "=j" (m1) : "j" (m1), "j" (m2), "j" (m4), "j" (m5));
        l.anchor = m1;
    } else {
        l.anchor = l.pivotVel;
    }
    float halfDt = g_2dded0[1] * 0.5f;
    register QW n1 asm("vf1") = l.omegaDamped;
    register QW n2 asm("vf2") = l.omega;
    asm("vadd.xyzw vf2, vf2, vf1" : "=j" (n2) : "j" (n2), "j" (n1));
    QW halfBits;
    asm("mfc1 %0, %1" : "=r" (halfBits) : "f" (halfDt));
    register QW n3 asm("vf3") = halfBits;
    asm("vmulx.xyzw vf1, vf2, vf3x" : "=j" (n1) : "j" (n2), "j" (n3));
    l.slot1C0 = n3;
    LoadRotateMatrix(&l.rot[0], n1);
    register QW r10 asm("vf10") = l.rot[0];
    register QW r9 asm("vf9") = l.rot[1];
    register QW r8 asm("vf8") = l.rot[2];
    QW ropeQ;
    asm("mfc1 %0, %1" : "=r" (ropeQ) : "f" (sRopeNew));
    register QW r4 asm("vf4") = l.vecDir;
    register QW r7 asm("vf7");
    asm("qmtc2.ni %1, vf7" : "=j" (r7) : "r" (ropeQ));
    asm("vmulax.xyz ACC, vf10, vf4x\n\tvmadday.xyz ACC, vf9, vf4y\n\tvmaddz.xyz vf4, vf8, vf4z" : "=j" (r4) : "j" (r10), "j" (r9), "j" (r8), "j" (r4));
    int speedBits = *(int *)&l.ropeSpeed;
    register QW r6 asm("vf6");
    asm("vmulx.xyzw vf6, vf4, vf7x" : "=j" (r6) : "j" (r4), "j" (r7));
    register QW w2 asm("vf2") = l.omegaDamped;
    register QW r11 asm("vf11");
    asm("qmtc2.ni %1, vf11" : "=j" (r11) : "r" (speedBits));
    asm("vopmula.xyz ACC, vf2, vf6\n\tvopmsub.xyz vf2, vf6, vf2" : "=j" (w2) : "j" (w2), "j" (r6));
    register QW q3 asm("vf3") = l.anchor;
    register QW q5 asm("vf5");
    asm("vmulx.xyzw vf5, vf4, vf11x" : "=j" (q5) : "j" (r4), "j" (r11));
    asm("vadd.xyzw vf3, vf3, vf2" : "=j" (q3) : "j" (q3), "j" (w2));
    register QW w1 asm("vf1") = l.posPivot;
    asm("vadd.xyzw vf3, vf3, vf5" : "=j" (q3) : "j" (q3), "j" (q5));
    asm("vadd.xyzw vf1, vf1, vf6" : "=j" (w1) : "j" (w1), "j" (r6));
    l.slot140 = w1;
    l.slot150 = q3;
    l.slot160 = r10;
    l.slot170 = r9;
    l.slot180 = r8;
    l.slot130 = r4;
    OBJV *pjv2 = (OBJV *)jt;
    l.rot[0] = r7;
    l.slot220 = q3;
    l.rot[0] = r11;
    QW vel2 = pjv2->vt->fn(jt + pjv2->vt->delta);
    int dtBits2 = ((int *)g_2dded0)[1];
    register QW s1v asm("vf1");
    asm("qmtc2.ni %1, vf1" : "=j" (s1v) : "r" (vel2));
    void *hb2 = *(void **)(jt + 0x1900);
    register QW s2v asm("vf2");
    asm("qmtc2.ni %1, vf2" : "=j" (s2v) : "r" (dtBits2));
    l.rot[0] = s2v;
    register QW s3v asm("vf3") = l.slot220;
    asm("vsub.xyzw vf3, vf3, vf1" : "=j" (s3v) : "j" (s3v), "j" (s1v));
    char *phys3 = *(char **)(jt + 0xE8);
    asm("nop\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q" : "=j" (s2v) : "j" (s2v), "j" (s3v));
    register QW s1w asm("vf1") = *(QW *)(phys3 + 0x80);
    asm("vsub.xyzw vf1, vf2, vf1" : "=j" (s1w) : "j" (s2v), "j" (s1w));
    l.slotC0 = s1w;
    if (hb2) {
        AnticipateJtForce__FP2JTP2SOP6VECTORT2P2FX(jt, *(void **)((char *)hb2 + 4), &l.posPivot, &l.slotC0, jt + 0x1910);
    } else {
        *(QW *)(jt + 0x1910) = s1w;
    }
    return 0;
}
