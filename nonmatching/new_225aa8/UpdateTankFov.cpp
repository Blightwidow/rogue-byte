// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SMPA_225E98 { float a, b, c, d; };
struct SMPABytes_225E98 { char bytes[16]; };
struct Shape_225E98 { char pad0[0x30]; float radius; };
struct Target_225E98 { char pad0[0x60]; void *xf; char pad64[0x88]; Shape_225E98 *shape; };
struct Driver_225E98 { char pad0[0x24]; float g; };
struct Tank_225E98 {
    char pad0[0x150]; Driver_225E98 *driver; char pad154[0x2C];
    Target_225E98 *target; int pad184; int active; char pad18C[0x20];
    float lo; float hi; float cur; float sv; float out;
};
struct M4_225E98 { QW row[4]; };
struct Locals_225E98 {
    M4_225E98 mat;
    QW predicted;
    QW delta;
    QW local;
    float view[4];
    SMPABytes_225E98 smpa;
    QW goal;
    QW spill;
};
extern "C" {
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
void PredictXfTransform(void *, void *, float, M4_225E98 *, M4_225E98 *);
float atanf(float);
float GLimitLm__FP2LMf(void *, float);
float GSmoothA__FffffP4SMPAPf(float, float, float, float, SMPA_225E98 *, float *);
extern char g_2bbb60[];
extern float g_2dded0[];
extern float g_2dded4;
extern float B_002DDF7C;
extern float D_002C4418[];
extern float D_002C4420[];
extern const SMPABytes_225E98 RO_002A97B0;
}
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
extern "C" void UpdateTankFov(Tank_225E98 *tank)
{
    if (tank->target && tank->active) {
        Locals_225E98 l;
        float radius = 0.0f;
        if (tank->target->shape) radius = tank->target->shape->radius;
        QW pos = PosLoWorld(tank);
        asm("qmtc2.ni %1, vf1\n\tsqc2 vf1, %0" : "=m"(l.spill) : "r"(pos));
        QW other = PosLoWorld(tank->target);
        QW dist;
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\t"
            "vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
            : "=r"(dist) : "m"(l.spill), "r"(other));
        float fov = atanf(radius / (Lane0(dist) * 0.5f));
        fov = fov + fov;
        PredictXfTransform(tank->target->xf, 0, g_2dded0[1], &l.mat, 0);
        fov = fov > tank->lo ? fov : tank->lo;
        asm("lqc2 vf1, %2\n\tsqc2 vf1, %0\n\tsqc2 vf1, %1" : "=m"(l.predicted), "=m"(l.spill) : "m"(l.mat.row[3]));
        other = PosLoWorld(tank->target);
        asm("lqc2 vf1, %2\n\tqmtc2.ni %3, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\t"
            "vadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tsqc2 vf1, %1\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tqmfc2.ni %0, vf2"
            : "=r"(dist), "=m"(l.delta) : "m"(l.spill), "r"(other));
        l.goal = l.predicted;
        float reach = radius + Lane0(dist);
        pos = PosLoWorld(tank);
        asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf3\n\tvsub.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m"(l.local) : "m"(l.goal), "r"(pos));
        QW *pmat = PmatLoWorld(tank);
        asm("lqc2 vf3, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %0\n\tvmul.xyzw vf7, vf2, vf4\n\tvmaxw.xyzw vf8, vf0, vf0w\n\t"
            "vmul.xyzw vf6, vf1, vf4\n\tvmul.xyzw vf5, vf3, vf4\n\tvadday.x ACC, vf7, vf7y\n\tvmaddz.x vf2, vf8, vf7z\n\t"
            "vaddax.y ACC, vf6, vf6x\n\tvmaddz.y vf2, vf8, vf6z\n\tvaddax.z ACC, vf5, vf5x\n\tvmaddy.z vf2, vf8, vf5y\n\tsqc2 vf2, %0"
            : "+m"(l.local) : "m"(pmat[2]), "m"(pmat[0]), "m"(pmat[1]));
        float *local = (float *)&l.local;
        float forward = local[0];
        l.view[2] = forward;
        l.view[1] = local[2];
        l.view[0] = -local[1];
        float angle;
        if (forward > 0.0001f) {
            float side = atanf((__builtin_fabsf(l.view[0]) + reach) / (forward * B_002DDF7C));
            side = side + side;
            float up = atanf((__builtin_fabsf(l.view[1]) + reach) / l.view[2]);
            up = up + up;
            angle = up > side ? up : side;
            angle = tank->hi < angle ? tank->hi : angle;
        } else {
            angle = tank->hi;
        }
        angle = fov > angle ? fov : angle;
        float *range = &tank->lo;
        float t;
        if (range[0] == range[1]) t = 0.0f;
        else t = (angle - range[0]) / (range[1] - range[0]);
        float goal = GLimitLm__FP2LMf(g_2bbb60, 1.0f - t);
        float cur = tank->cur;
        l.smpa = RO_002A97B0;
        float diff = __builtin_fabsf(goal - cur);
        float scale = (1.0f - diff) * D_002C4418[0] + diff * D_002C4418[1];
        SMPA_225E98 *psmpa = (SMPA_225E98 *)&l.smpa;
        psmpa->b *= scale;
        psmpa->d *= scale;
        psmpa->a *= scale;
        tank->cur = GSmoothA__FffffP4SMPAPf(cur, tank->sv, goal, g_2dded0[1], psmpa, &tank->sv);
    } else if (tank->driver) {
        float cur = tank->cur;
        float g = tank->driver->g;
        float sv = (D_002C4420[0] + cur * (D_002C4420[1] + cur * D_002C4420[2])) * g * __builtin_fabsf(g);
        tank->sv = sv;
        tank->cur = GLimitLm__FP2LMf(g_2bbb60, cur + sv * g_2dded4);
    }
    float u = 1.0f - tank->cur;
    tank->out = (1.0f - u) * tank->lo + u * (&tank->lo)[1];
}
