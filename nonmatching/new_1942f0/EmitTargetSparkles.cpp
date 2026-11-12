#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
union VU_SCALE { QW q; VECTOR v; };
struct Member;
struct VT {
    char pad0[0x28]; short delta; short index; void (*randomPoint)(void *, float, QW *, QW *);
};
struct Member { char pad[0x20]; VT *vt; };
struct Target { int plo; Member *pmember; float sDist; int nPriority; int pindicator; float tStart; float u; int du; QW pos; };
struct Sub {
    float speed[2]; char pad0[0x3C - 8]; float life; char pad1[0x48 - 0x40];
    float advance[2]; float age[2];
};
struct EmitB { char pad[0x50]; Sub sub; };
struct Emitter { char pad0[0xE0]; int changed; EmitB *emitb; char pad1[0xFC - 0xE8]; float rate; char pad2[0x150 - 0x100]; int blipg; };
struct JT { char pad[0x12F8]; Emitter *emitter; };
struct EmitG { void *ppblipg; int unused4; Emitter *owner; };
extern "C" {
float GRandInRange(float, float);
extern struct { float time; float dt; } g_2dded0;
}
void OnEmitterValuesChanged__FP7EMITTER(Emitter *);
void EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3(EmitB *, EmitG *, int, QW *, QW *, float *, float *, void *, void *);
static inline float RandRange(float *range) { return GRandInRange(range[0], range[1]); }

void EmitTargetSparkles(void *unused, JT *jt, int ctarget, Target *atarget)
{
    Emitter *emitter = jt->emitter;
    if (emitter == 0)
        return;
    if (emitter->changed != 0)
        OnEmitterValuesChanged__FP7EMITTER(emitter);
    Sub *sub = &emitter->emitb->sub;
    QW apos[10];
    QW avel[10];
    float atBorn[12];
    float atDie[12];
    unsigned cblip = 0;
    int itarget;
    for (itarget = 0; itarget < ctarget; itarget++) {
        struct { QW pos, normal, vel; } l;
        VU_SCALE scale;
        Target *target = atarget + itarget;
        if (target->nPriority == -1)
            continue;
        float blips = emitter->rate * g_2dded0.dt;
        int count = (int)blips;
        if (GRandInRange(0.0f, 1.0f) < blips - (float)count)
            count++;
        QW *pposOut = &apos[cblip];
        float *pbornOut = &atBorn[cblip];
        float *pdieOut = &atDie[cblip];
        for (; count > 0; count--) {
            Member *member = target->pmember;
            VT *vt = member->vt;
            vt->randomPoint((char *)member + vt->delta, target->u, &l.pos, &l.normal);
            float speed = RandRange(sub->speed);
            scale.q = VectorFromFloat(speed);
            l.vel = VectorScaleX(l.normal, scale.q);
            float tNow = g_2dded0.time;
            float born = tNow - RandRange(sub->age);
            *pbornOut++ = born;
            *pdieOut++ = born + sub->life;
            if (sub->advance[0] != sub->advance[1]) {
                QW start = l.pos;
                float advance = RandRange(sub->advance);
                scale.q = VectorFromFloat(advance);
                l.pos = ScaleAddX(start, l.vel, scale.q);
            }
            pposOut[0] = l.pos;
            pposOut[10] = l.vel;
            pposOut++;
            cblip++;
            if (cblip > 9)
                goto done;
        }
    }
done:
    if ((int)cblip > 0) {
        EmitG emitg;
        memset(&emitg, 0, 0xC);
        emitg.owner = emitter;
        emitg.ppblipg = &emitter->blipg;
        EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3(emitter->emitb, &emitg, cblip, apos, avel, atBorn, atDie, 0, 0);
    }
}
