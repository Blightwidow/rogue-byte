#include "sly2.h"
struct LM { float lo; float hi; };
struct SCALER { char pad[0x20]; float scale; };
struct TUNING { char pad0[0x10]; int mode; float yawLimit; float pitchLimit; };
struct PLAYER { char pad0[0x31C]; LM turn; LM tilt; char pad1[0x3CC - 0x32C]; TUNING *tuning; char pad2[0xFBC - 0x3D0]; int mode; char pad3[0xFC4 - 0xFC0]; SCALER *scaler; };
struct GUARD { char pad0[0x10]; PLAYER *player; };
extern "C" {
void ClosestPointOnSegment(QW, QW, QW, void *, float *, float *);
int ClsgClipEdgeToPathzoneObstacles(int, QW, QW, int);
void DecomposeCylind(QW, float *, float *, int);
int FCheckLm__FP2LMf(LM *, float);
float GLimitAbs__Fff(float, float);
float GLimitLm__FP2LMf(LM *, float);
QW PosLoWorld(void *);
float RadNormalize__Ff(float);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
int func_001C0B50(int, QW, void *);
static inline QW AddVec(QW a, QW b) {
    QW out;
    asm("qmtc2.ni %1, vf1\n\tqmtc2.ni %2, vf2\n\tvadd.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (out) : "r" (a), "r" (b));
    return out;
}
static inline QW SubVec(QW a, QW b) {
    QW out;
    asm("qmtc2.ni %1, vf1\n\tqmtc2.ni %2, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (out) : "r" (a), "r" (b));
    return out;
}
QW func_0017BFF8(GUARD *self, int graph, QW origin, float heading) {
    char frame[0x390] __attribute__((aligned(16)));
#define result (*(QW *)(frame + 0x00))
#define turnLm (*(LM *)(frame + 0x10))
#define tiltLm (*(LM *)(frame + 0x20))
#define pick (*(float *)(frame + 0x30))
#define pickEnd (*(float *)(frame + 0x34))
#define closest (*(QW *)(frame + 0x40))
#define segments ((QW *)(frame + 0x50))
#define yawA (*(float *)(frame + 0x350))
#define pitchA (*(float *)(frame + 0x354))
#define yawB (*(float *)(frame + 0x358))
#define pitchB (*(float *)(frame + 0x35C))
#define dist (*(float *)(frame + 0x360))
#define start (*(QW *)(frame + 0x370))
#define count (*(int *)(frame + 0x380))
    PLAYER *player = self->player;
    start = origin;
    turnLm = player->turn;
    tiltLm = player->tilt;
    int mode = player->mode;
    if (mode == 8 || mode == 0xD) {
        SCALER *scaler = player->scaler;
        if (scaler != 0) {
            float scale = scaler->scale;
            turnLm.lo *= scale;
            turnLm.hi *= scale;
            tiltLm.lo *= scale;
            tiltLm.hi *= scale;
        }
    }
    TUNING *tuning = self->player->tuning;
    QW pos = PosLoWorld(self->player);
    DecomposeCylind(SubVec(pos, start), &yawA, &pitchA, 0);
    float aim = heading + GLimitAbs__Fff(RadNormalize__Ff(yawA - heading), tuning->yawLimit);
    QW candidate = AddVec(start, SetVectorCylind__FP6VECTORfff(aim, GLimitLm__FP2LMf(&turnLm, pitchA), 0));
    if (func_001C0B50(graph, candidate, frame) == 0 ||
        (DecomposeCylind(SubVec(result, start), &yawB, &pitchB, 0), !(__builtin_fabsf(RadNormalize__Ff(yawB - heading)) < tuning->pitchLimit)) ||
        FCheckLm__FP2LMf(&tiltLm, pitchB) == 0) {
        int phase = 0;
        float spread;
        float best;
        QW bestPoint;
        do {
            switch (phase) {
            case 0:
                *(long *)&pick = *(long *)&turnLm;
                count = 10;
                spread = tuning->yawLimit;
                break;
            case 1:
                *(long *)&pick = *(long *)&tiltLm;
                count = 10;
                spread = tuning->pitchLimit;
                break;
            case 2:
                count = 15;
                pick = 0;
                pickEnd = tiltLm.hi;
                spread = 3.1415927f;
                break;
            }
            if (tuning->mode == -1) spread = 3.1415927f;
            best = 3.4028235e38f;
            for (int index = 0; index < count; index++) {
                QW dir = SetVectorCylind__FP6VECTORfff(heading + (((float)index / ((float)(count - 1) * 0.5f)) + -1.0f) * spread, 1.0f, 0);
                QW nearPoint = AddVec(start, dir);
                QW farPoint = AddVec(start, dir);
                int found = ClsgClipEdgeToPathzoneObstacles(graph, farPoint, nearPoint, 8);
                QW *segment = segments;
                for (int each = 0; each < found; each++) {
                    ClosestPointOnSegment(pos, segment[0], segment[1], &closest, &dist, 0);
                    if (dist < best) {
                        bestPoint = closest;
                        best = dist;
                    }
                    segment += 6;
                }
            }
            phase++;
            if (best == 3.4028235e38f) {
                if (phase >= 3) {
                    if (func_001C0B50(graph, start, frame) == 0) return start;
                    return result;
                }
            } else {
                return bestPoint;
            }
        } while (1);
    }
    return result;
}
}
