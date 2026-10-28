#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct VT { char pad[0x108]; short delta; short index; QW (*getVelocity)(void *); };
struct Obj { char pad0[0xC]; VT *vt; };
struct Xf { char pad[0xB0]; QW omega; char pad1[0x30]; QW alpha; };
struct Phys { char pad[0x80]; QW gravity; };
struct JT { char pad0[0xC]; VT *vt; char pad1[0x5C - 0x10]; Xf *xf; char pad2[0xE8 - 0x60]; Phys *phys; char pad3[0x190 - 0xEC]; QW wish; };
struct Jmp {
    JT *pjt; int kind; char pad0[0x10]; float launch; int state; char pad1[0x34 - 0x20]; float g34;
    char pad2[0xA0 - 0x38]; QW wish; char pad3[0x1C0 - 0xB0]; float g1c0; float g1c4;
};
struct Clock { float time; float dt; };
extern "C" {
extern Clock g_2dded0;
extern QW g_2a2dd0;
extern QW g_2a2da0;
extern QW g_2a2dc0;
extern char D_002BF7A8[], D_002BF7B8[], D_002BF7C8[];
extern float RO_002BF7D4;
extern float RO_002BF7E0[];
extern float RO_002BF7F0, RO_002BF7F4, RO_002BF7F8;
extern float RO_002BF800[];
extern float RO_002BF810, RO_002BF814;
extern float g_2bbb60[];
QW bevy_camera_follow_track_heading_weight(int, void *, QW);
void LoadRotateMatrix(void *, QW);
void *PmatLoWorld(void *);
float GSmooth__FfffP3SMPPf(float, float, float, void *, float *);
QW LimitVectorLength__FP6VECTORfT0(QW, float);
void AddSoAcceleration(void *, QW);
void AccelSoTowardPosSpring(void *, QW, void *, QW, void *);
void LoadLookAtMatrix(void *, QW);
void LimitJmpAccelByContacts(Jmp *, QW *);
}
struct Rows { QW row[3]; };

void bevy_player_p18_gadget_glide_force(Jmp *jmp)
{
    register QW zeroReg asm("$0");
    switch (jmp->state) {
    case 6: case 8: case 9: case 10: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11: case 0x12:
    case 0x13: case 0x15:
        break;
    case 0x14: {
        float zero = 0.0f;
        struct { QW local; QW spill; Rows next; Rows step; Rows copy; QW velocity; } l;
        JT *pjt = jmp->pjt;
        VT *vt = pjt->vt;
        QW velocity = vt->getVelocity((char *)pjt + vt->delta);
        l.velocity = velocity;
        l.local = bevy_camera_follow_track_heading_weight(0, jmp->pjt, velocity);
        Clock *pclock = &g_2dded0;
        float half = 0.5f;
        Xf *xf = jmp->pjt->xf;
        float dt = pclock->dt;
        register QW v5 asm("vf5") = Word(dt);
        register QW v2 asm("vf2") = xf->omega;
        asm volatile("sqc2 vf5, %0" : "=m" (l.spill));
        float halfDt = dt * half;
        register QW v4 asm("vf4") = Word(halfDt);
        register QW v3 asm("vf3") = xf->alpha;
        asm volatile("sqc2 vf4, %0" : "=m" (l.spill));
        asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf3, vf5x" : "+j" (v2) : "j" (v3), "j" (v5));
        register QW v1 asm("vf1") = xf->omega;
        asm("vadd.xyzw vf1, vf1, vf2" : "+j" (v1) : "j" (v2));
        asm("vmulx.xyzw vf2, vf1, vf4x" : "=j" (v2) : "j" (v1), "j" (v4));
        LoadRotateMatrix(&l.step, v2);
        Rows *pworld = (Rows *)PmatLoWorld(jmp->pjt);
        v3 = pworld->row[0];
        register QW v5m asm("vf5") = l.step.row[2];
        register QW v4m asm("vf4") = l.step.row[0];
        register QW v6 asm("vf6") = l.step.row[1];
        asm("vmulax.xyz ACC, vf4, vf3x\n\tvmadday.xyz ACC, vf6, vf3y\n\tvmaddz.xyz vf3, vf5, vf3z" : "+j" (v3) : "j" (v4m), "j" (v5m), "j" (v6));
        l.next.row[0] = v3;
        register QW r2 asm("vf2") = pworld->row[1];
        asm("vmulax.xyz ACC, vf4, vf2x\n\tvmadday.xyz ACC, vf6, vf2y\n\tvmaddz.xyz vf2, vf5, vf2z" : "+j" (r2) : "j" (v4m), "j" (v5m), "j" (v6));
        l.next.row[1] = r2;
        l.copy.row[0] = v3;
        register QW r1 asm("vf1") = pworld->row[2];
        asm("vmulax.xyz ACC, vf4, vf1x\n\tvmadday.xyz ACC, vf6, vf1y\n\tvmaddz.xyz vf4, vf5, vf1z" : "=j" (v4m) : "j" (r1), "j" (v5m), "j" (v6), "0" (v4m));
        l.copy.row[1] = r2;
        l.next.row[2] = v4m;
        l.copy.row[2] = v4m;
        float forward = GSmooth__FfffP3SMPPf(((float *)&l.local)[0], jmp->g1c0, pclock->dt, D_002BF7A8, 0);
        ((float *)&l.local)[0] = forward;
        float lateral = GSmooth__FfffP3SMPPf(((float *)&l.local)[1], zero, pclock->dt, D_002BF7B8, 0);
        ((float *)&l.local)[1] = lateral;
        float vertical = GSmooth__FfffP3SMPPf(((float *)&l.local)[2], jmp->g1c4, pclock->dt, D_002BF7C8, 0);
        ((float *)&l.local)[2] = vertical;
        register QW t2 asm("vf2") = l.next.row[2];
        register QW t5 asm("vf5") = l.next.row[0];
        register QW t3 asm("vf3") = l.next.row[1];
        register QW t1 asm("vf1") = l.local;
        asm("vmulax.xyz ACC, vf5, vf1x\n\tvmadday.xyz ACC, vf3, vf1y\n\tvmaddz.xyz vf1, vf2, vf1z" : "+j" (t1) : "j" (t2), "j" (t3), "j" (t5));
        int dtInt = *(int *)&pclock->dt;
        register QW u2 asm("vf2") = l.velocity;
        register QW u4 asm("vf4");
        asm("qmtc2.ni %1, vf4" : "=j" (u4) : "r" (dtInt));
        asm("vsub.xyzw vf1, vf1, vf2" : "+j" (t1) : "j" (u2));
        float maxAccel = RO_002BF7D4;
        register QW accelIn asm("vf2");
        asm("vdiv Q, vf0w, vf4x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q" : "=j" (accelIn) : "j" (t1), "j" (u4));
        asm volatile("sqc2 vf4, %0" : "=m" (l.spill));
        QW accel = LimitVectorLength__FP6VECTORfT0(accelIn, maxAccel);
        if (Lane(__builtin_pextuw(zeroReg, accel)) < zero) {
            QW low = __builtin_pextlw(Word(Lane(__builtin_prot3w(accel))), Word(Lane(accel)));
            accel = __builtin_pcpyld(Word(zero), low);
            l.spill = accel;
        }
        AddSoAcceleration(jmp->pjt, accel);
        break;
    }
    case 0x16: {
        QW spill;
        float *clq = RO_002BF7E0;
        float minusOne = -1.0f;
        JT *pjt = jmp->pjt;
        float inverse = minusOne / clq[1];
        register QW wishReg asm("vf1") = pjt->wish;
        register QW minusReg asm("vf2") = Word(minusOne);
        asm volatile("sqc2 vf2, %0" : "=m" (spill));
        register QW scaled asm("vf2");
        asm("vmulx.xyzw vf2, vf1, vf2x" : "=j" (scaled) : "j" (wishReg), "j" (minusReg));
        register QW invReg asm("vf3") = Word(inverse);
        Phys *phys = pjt->phys;
        asm volatile("sqc2 vf3, %0" : "=m" (spill));
        register QW gravReg asm("vf1") = phys->gravity;
        register QW target asm("vf4");
        asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf4, vf1, vf3x" : "=j" (target) : "j" (scaled), "j" (gravReg), "j" (invReg));
        AccelSoTowardPosSpring(pjt, g_2a2dd0, 0, target, clq);
        break;
    }
    default: {
        struct { QW dir; Rows look; QW q[4]; } l;
        JT *pjt = jmp->pjt;
        VT *vt = pjt->vt;
        l.dir = vt->getVelocity((char *)pjt + vt->delta);
        ((float *)&l.dir)[2] = 0.0f;
        register QW v3 asm("vf3");
        register QW v1 asm("vf1");
        register QW v2 asm("vf2");
        asm("qmtc2.ni %1, vf3" : "=j" (v3) : "r" (l.dir));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1), "=j" (v2) : "j" (v3));
        asm(".word 0x4A0103BD\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "+j" (v2) : "j" (v1));
        QW lengthBits;
        asm("qmfc2.ni %0, vf2" : "=r" (lengthBits) : "j" (v2));
        if (Lane(lengthBits) < 0.0001f) {
            l.dir = g_2a2da0;
        } else {
            register QW v1b asm("vf1");
            asm("nop\n\tnop\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q" : "=j" (v1b) : "j" (v2), "j" (v3));
            l.dir = v1b;
        }
        QW speedBits;
        asm("qmfc2.ni %0, vf2" : "=r" (speedBits) : "j" (v2));
        float speed = Lane(speedBits);
        LoadLookAtMatrix(&l.q[0], l.dir);
        Clock *pclock = &g_2dded0;
        register QW look0 asm("vf2") = l.q[0];
        register QW look1 asm("vf3") = l.q[1];
        register QW look2 asm("vf4") = l.q[2];
        float dt = pclock->dt;
        register QW wish asm("vf1") = jmp->wish;
        float one = 1.0f;
        asm("vmul.xyzw vf7, vf2, vf1\n\tvmaxw.xyzw vf8, vf0, vf0w\n\tvmul.xyzw vf6, vf3, vf1\n\tvmul.xyzw vf5, vf4, vf1\n\tvadday.x ACC, vf7, vf7y\n\tvmaddz.x vf1, vf8, vf7z\n\tvaddax.y ACC, vf6, vf6x\n\tvmaddz.y vf1, vf8, vf6z\n\tvaddax.z ACC, vf5, vf5x\n\tvmaddy.z vf1, vf8, vf5y" : "+j" (wish) : "j" (look0), "j" (look1), "j" (look2));
        int state = jmp->state;
        l.q[0] = wish;
        float gain = one / dt;
        l.look.row[0] = look0;
        l.look.row[1] = look1;
        l.look.row[2] = look2;
        float gAlong, gSide;
        if (state == 0 || state == 2) {
            gSide = gain;
            gAlong = gSide;
        } else {
            if (((float *)&l.q[0])[0] < speed)
                gAlong = RO_002BF7F4;
            else
                gAlong = RO_002BF7F0;
            gSide = RO_002BF7F8;
        }
        ((float *)&l.q[1])[2] = 0.0f;
        ((float *)&l.q[1])[1] = gSide * ((float *)&l.q[0])[1];
        ((float *)&l.q[1])[0] = gAlong * (((float *)&l.q[0])[0] - speed);
        float scale;
        if (jmp->kind == 0xC) {
            float elapsed = pclock->time - jmp->launch;
            scale = RO_002BF800[0] + elapsed * (RO_002BF800[1] + elapsed * RO_002BF800[2]);
            if (scale < g_2bbb60[0])
                scale = g_2bbb60[0];
            else if (g_2bbb60[1] < scale)
                scale = g_2bbb60[1];
        } else {
            scale = jmp->g34;
        }
        register QW sc asm("vf5");
        asm("qmtc2.ni %1, vf5" : "=j" (sc) : "r" (Word(scale)));
        register QW force asm("vf2") = l.q[1];
        asm("vmulx.xyzw vf2, vf2, vf5x" : "+j" (force) : "j" (sc));
        register QW row0 asm("vf1") = l.look.row[0];
        register QW row1 asm("vf4") = l.look.row[1];
        register QW row2 asm("vf3") = l.look.row[2];
        asm("vmulax.xyz ACC, vf1, vf2x\n\tvmadday.xyz ACC, vf4, vf2y\n\tvmaddz.xyz vf1, vf3, vf2z" : "+j" (row0) : "j" (force), "j" (row1), "j" (row2));
        l.q[3] = sc;
        l.q[2] = row0;
        l.q[1] = force;
        LimitJmpAccelByContacts(jmp, &l.q[2]);
        if (jmp->state != 5) {
            JT *pjt2 = jmp->pjt;
            VT *vt2 = pjt2->vt;
            l.dir = vt2->getVelocity((char *)pjt2 + vt2->delta);
            float terminal = RO_002BF810;
            float vz = ((float *)&l.dir)[2];
            if (vz < terminal) {
                float over = vz - terminal;
                float push = RO_002BF814 * over;
                register QW acc asm("vf2") = l.q[2];
                register QW grav asm("vf3") = g_2a2dc0;
                register QW pushReg asm("vf1");
                asm("qmtc2.ni %1, vf1" : "=j" (pushReg) : "r" (Word(push)));
                asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf3, vf1x" : "+j" (acc) : "j" (grav), "j" (pushReg));
                l.q[3] = pushReg;
                l.q[2] = acc;
            }
        }
        AddSoAcceleration(jmp->pjt, l.q[2]);
        break;
    }
    }
}
