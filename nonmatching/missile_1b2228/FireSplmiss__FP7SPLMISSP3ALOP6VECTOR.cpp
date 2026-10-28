#include "sly2.h"
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct VT { char pad[0x108]; short d108; short i108; QW (*f108)(void *); };
struct SPLMISS { char pad0[0xC]; VT *vt; char pad1[0x270 - 0x10]; float dtOverride; float svMax; float tExpire; };
struct Clock { float time; float dt; };
struct Frame {
    QW q0; QW q10; V4 t20; QW q30; QW q40; char lsg[0x60]; QW qB0; QW qC0; QW qD0;
};
extern Clock g_2dded0;
extern "C" {
extern QW g_2a2dd0;
void FireMissile(SPLMISS *, void *, QW *);
void PosPredictMissileTarget(V4 *, SPLMISS *, float);
QW LimitVectorLength__FP6VECTORfT0(QW, float);
QW PosLoWorld(SPLMISS *);
int ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(QW, float, QW, QW, int, void *);
}
static inline QW Word(float f) { QW r; asm volatile("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }

void FireSplmiss__FP7SPLMISSP3ALOP6VECTOR(SPLMISS *p, void *alo, QW *pos)
{
    Frame f;
    f.q0 = *pos;
    FireMissile(p, alo, &f.q0);
    float result;
    float dtOverride = p->dtOverride;
    float zero;
    asm volatile("mtc1 $0,%0\n\tnop" : "=f"(zero));
    if (zero < dtOverride) {
        result = g_2dded0.time + dtOverride;
    } else {
        PosPredictMissileTarget(&f.t20, p, 0.5f);
        f.q10 = *(QW *)&f.t20;
        register QW v1 asm("vf1");
        register QW v2 asm("vf2");
        register QW v3 asm("vf3");
        register QW v4 asm("vf4");
        VT *vt = p->vt;
        QW half = Word(-0.5f);
        int delta = vt->d108;
        asm volatile("qmtc2.ni %1, vf1" : "=j" (v1) : "r" (half));
        asm volatile("sqc2 vf1, %0" : "=m" (f.q30) : "j" (v1));
        QW (*fn)(void *) = vt->f108;
        asm("sqc2 vf1, %0" : "=m" (f.qD0) : "j" (v1));
        QW vel = fn((char *)p + delta);
        float sv = p->svMax;
        asm volatile("qmtc2.ni %1, vf2" : "=j" (v2) : "r" (vel));
        float c75 = 0.75f;
        asm volatile("" : : "f" (c75));
        asm volatile("lqc2 vf1, %1" : "=j" (v1) : "m" (f.qD0));
        asm("vmulx.xyzw vf1, vf2, vf1x" : "=j" (v1) : "j" (v1), "j" (v2));
        asm volatile("sqc2 vf1, %0" : "=m" (f.t20) : "j" (v1));
        QW arg;
        asm("qmfc2.ni %0, vf1" : "=r" (arg) : "j" (v1));
        QW line0 = LimitVectorLength__FP6VECTORfT0(arg, sv * c75);
        asm volatile("qmtc2.ni %1, vf1" : "=j" (v1) : "r" (line0));
        f.qB0 = Word(1.5f);
        asm volatile("sqc2 vf1, %0" : "=m" (f.t20) : "j" (v1));
        f.qC0 = f.q10;
        asm volatile("sqc2 vf1, %0" : "=m" (f.qD0) : "j" (v1));
        f.q40 = f.qB0;
        QW world = PosLoWorld(p);
        asm volatile("lqc2 vf3, %1\n\tqmtc2.ni %2, vf4\n\tvsub.xyzw vf2, vf3, vf4\n\tlqc2 vf1, %3\n\tlqc2 vf3, %4\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf2, vf3x" : "=j" (v1) : "m" (f.qC0), "r" (world), "m" (f.qD0), "m" (f.qB0) : "memory");
        QW line1;
        asm volatile("qmfc2.ni %0, vf1" : "=r" (line1));
        asm volatile("sqc2 vf1, %0" : "=m" (f.q30) : "j" (v1));
        ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(g_2a2dd0, p->svMax, *(QW *)&f.t20, line1, 1, f.lsg);
        float hit = *(float *)(f.lsg + 0x44);
        float u = hit > 0.25f ? hit : 0.25f;
        result = g_2dded0.time + 1.0f / u;
    }
    p->tExpire = result;
}
