#include "sly2.h"
static inline float Lane196928(QW q) { float f; asm("pextuw %1, $0, %1" : "+r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float GMax196928(float a, float b) { return b > a ? b : a; }
static inline float Sqrt196928(float value) { float result; asm("sqrt.s %0, %1" : "=&f" (result) : "f" (value)); return result; }
extern "C" int CSolveQuadratic__FfffPf(float, float, float, float *);
struct Locals196928 { float roots0[4]; float roots1[4]; QW delta; };
extern "C" float DtSolveJumpLaunch(QW delta, QW gravity, float arg0, float arg1, float arg2, float arg3)
{
    Locals196928 l;
    float half = Lane196928(gravity) * 0.5f;
    l.delta = delta;
    float dz = Lane196928(delta);
    float best = 0.0f;
    int count = CSolveQuadratic__FfffPf(-half, -arg0, dz, l.roots0);
    if (count > 0)
        best = GMax196928(l.roots0[count - 1], best);
    count = CSolveQuadratic__FfffPf(half, -arg1, dz, l.roots1);
    if (count > 0)
        best = GMax196928(l.roots1[count - 1], best);
    float length;
    int token;
    asm("lqc2 vf2, %1\n\tvmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y" : "=r" (token) : "m" (l.delta));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (length) : "r" (token) : "$2");
    float time = (arg2 * length - dz) / -half;
    if (time > 0.0f)
        best = GMax196928(Sqrt196928(time), best);
    time = (arg3 * length - dz) / half;
    if (time > 0.0f)
        best = GMax196928(Sqrt196928(time), best);
    return best;
}
