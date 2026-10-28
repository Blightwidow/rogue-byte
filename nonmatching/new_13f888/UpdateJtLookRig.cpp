#include "sly2.h"
extern "C" {
void ScheduleJtGlance(void *);
void SetJtLookTarget(void *, int, void *);
void GetJtFocusScore(void *, void *, void *, float *, float *);
int FCheckLm__FP2LMf(void *, float);
void AddLookat(void *);
void RemoveLookat(void *);
QW PosLoWorld(void *);
QW ConvertAloPos(void *, void *, QW);
void CalculateVectorPanTilt__FP6VECTORPfT1(QW, float *, float *);
float RadLimitLm(void *, float);
void LoadRotateMatrixPanTilt(void *, float, float);
void LoadRotateMatrixRad(void *, QW, float);
void ConvertXfMat(void *, void *, void *, void *);
void InvertMatrix3(void *, void *);
QW DecomposeRotateMatrixEuler(void *);
void func_0012D108(void *, QW);
float fabsf(float);
extern float g_2dded0;
extern int g_2dd640;
extern char B_003E1474[];
extern char B_003DD490[];
extern float g_2a4d68;
extern QW g_2a2da0;
}
struct Rows3 { QW row[3]; };
struct Frame {
    Rows3 look;
    Rows3 rel;
    Rows3 goal;
    Rows3 pt;
    Rows3 roll;
    Rows3 junk;
    float sBest, sScore, dz, sExtra, dzExtra, radPan, radTilt;
};
void UpdateJtLookRig(char *self)
{
    Frame f;
    int c1, c2, c3, c4;
    char *act = *(char **)(self + 0x10F4);
    if (!act)
        return;
    int fLimits = 0;
    if (*(float *)(self + 0x1120) < *(float *)(self + 0x1124) || *(float *)(self + 0x1128) < *(float *)(self + 0x112C))
        fLimits = 1;
    if (*(int *)(self + 0xF04) != -1)
        fLimits = 0;
    if (*(float *)(self + 0x114C) < g_2dded0) {
        int glance = *(int *)(self + 0x1148);
        if (glance || fLimits) {
            *(int *)(self + 0x1148) = glance == 0;
            ScheduleJtGlance(self);
        }
    }
    if (*(int *)(self + 0x1100) == 0) {
        if (g_2dd640) {
            SetJtLookTarget(self, -1, 0);
        } else {
            char *best = *(char **)(self + 0x10DC);
            int nBest = *(int *)(self + 0x10E4);
            if (best)
                GetJtFocusScore(self, best, self + 0x10F8, &f.sBest, 0);
            else
                f.sBest = g_2a4d68;
            for (char *look = *(char **)B_003E1474; look; look = *(char **)(look + 0xE0)) {
                if (*(int *)(look + 0xF4) < nBest)
                    continue;
                GetJtFocusScore(self, look, self + 0x10F8, &f.sScore, &f.dz);
                float scoreNow = f.sScore;
                float range = *(float *)(look + 0xE8);
                if (range < scoreNow)
                    continue;
                if (!FCheckLm__FP2LMf(look + 0xEC, f.dz))
                    continue;
                int priority = *(int *)(look + 0xF4);
                if (nBest < priority || (priority == nBest && f.sScore < f.sBest)) {
                    best = look;
                    f.sBest = f.sScore;
                    nBest = *(int *)(best + 0xF4);
                }
            }
            char *base = B_003DD490;
            if (*(int *)(base + 0x4678) > 0) {
                if (nBest < 3) {
                    char *extra = *(char **)(base + 0x4690);
                    if (extra) {
                        GetJtFocusScore(self, extra, self + 0x10F8, &f.sExtra, &f.dzExtra);
                        if (nBest < 2 || (nBest == 2 && f.sExtra < f.sBest)) {
                            best = extra;
                            nBest = 2;
                            f.sBest = f.sExtra;
                        }
                    }
                }
            }
            SetJtLookTarget(self, nBest, best);
        }
    }
    float roll;
    if (*(int *)(self + 0x1104)) {
        AddLookat(*(void **)(self + 0x10F4));
        f.radPan = *(float *)(self + 0x1110);
        f.radTilt = *(float *)(self + 0x1114);
        roll = *(float *)(self + 0x1118);
    } else {
        if (!*(int *)(self + 0x10F8) || !*(int *)(self + 0x1148) || !fLimits) {
            RemoveLookat(*(void **)(self + 0x10F4));
            return;
        }
        AddLookat(*(void **)(self + 0x10F4));
        QW pos = PosLoWorld(*(void **)(self + 0x10F8));
        QW local = ConvertAloPos(0, self, pos);
        CalculateVectorPanTilt__FP6VECTORPfT1(local, &f.radPan, &f.radTilt);
        f.radPan = RadLimitLm(self + 0x1120, f.radPan);
        f.radTilt = RadLimitLm(self + 0x1128, f.radTilt);
        float panMax = *(float *)(self + 0x1124);
        float panMin = *(float *)(self + 0x1120);
        float u;
        if (panMax == panMin)
            u = 0.5f;
        else
            u = (f.radPan - panMin) / (panMax - panMin);
        float w = u * fabsf(u);
        roll = (1.0f - w) * *(float *)(self + 0x1130) + w * *(float *)(self + 0x1134);
    }
    Rows3 *ppt = &f.pt;
    Rows3 *pgoal = &f.goal;
    Rows3 *rest = (Rows3 *)(self + 0x1150);
    LoadRotateMatrixPanTilt(ppt, f.radPan, f.radTilt);
    LoadRotateMatrixRad(&f.roll, g_2a2da0, roll);
    asm("lqc2 vf4, %0\n\tlqc2 vf1, %1\n\tlqc2 vf3, %2\n\tlqc2 vf5, %3\n\tlqc2 vf6, %4\n\tvmulax.xyz ACC, vf3, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddz.xyz vf5, vf1, vf5z\n\tvmulax.xyz ACC, vf3, vf6x\n\tvmadday.xyz ACC, vf4, vf6y\n\tvmaddz.xyz vf6, vf1, vf6z\n\tlqc2 vf2, %5\n\tvmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf4, vf2y\n\tvmaddz.xyz vf3, vf1, vf2z"
        : : "m" (f.pt.row[1]), "m" (f.pt.row[2]), "m" (f.pt.row[0]), "m" (f.roll.row[0]), "m" (f.roll.row[1]), "m" (f.roll.row[2]));
    asm("sqc2 vf5, %0\n\tsqc2 vf6, %1\n\tsqc2 vf3, %2\n\tsqc2 vf5, %3\n\tsqc2 vf6, %4\n\tsqc2 vf3, %5"
        : "=m" (f.look.row[0]), "=m" (f.look.row[1]), "=m" (f.look.row[2]), "=m" (f.goal.row[0]), "=m" (f.goal.row[1]), "=m" (f.goal.row[2]));
    asm("sqc2 vf5, %0\n\tsqc2 vf6, %1\n\tsqc2 vf3, %2" : "=m" (f.junk.row[0]), "=m" (f.junk.row[1]), "=m" (f.junk.row[2]));
    ConvertXfMat(pgoal, 0, *(void **)(self + 0x60), *(char **)(*(char **)(self + 0x10F4) + 8) + 0x40);
    f.rel = f.goal;
    InvertMatrix3(ppt, rest);
    asm("lqc2 vf1, %0\n\tlqc2 vf6, %1\n\tlqc2 vf5, %2\n\tlqc2 vf4, %3\n\tvmulax.xyz ACC, vf1, vf4x\n\tvmadday.xyz ACC, vf6, vf4y\n\tvmaddz.xyz vf4, vf5, vf4z"
        : : "m" (f.rel.row[0]), "m" (f.rel.row[1]), "m" (f.rel.row[2]), "m" (f.pt.row[0]));
    asm("sqc2 vf4, %0" : "=m" (f.rel.row[0]));
    asm("lqc2 vf2, %0\n\tvmulax.xyz ACC, vf1, vf2x\n\tvmadday.xyz ACC, vf6, vf2y\n\tvmaddz.xyz vf2, vf5, vf2z\n\tlqc2 vf3, %1\n\tvmulax.xyz ACC, vf1, vf3x\n\tvmadday.xyz ACC, vf6, vf3y\n\tvmaddz.xyz vf1, vf5, vf3z\n\tsqc2 vf2, %2\n\tsqc2 vf1, %3"
        : "=m" (f.rel.row[1]), "=m" (f.rel.row[2]) : "m" (f.pt.row[1]), "m" (f.pt.row[2]));
    asm("sqc2 vf4, %0\n\tsqc2 vf4, %1\n\tsqc2 vf2, %2\n\tsqc2 vf2, %3\n\tsqc2 vf1, %4\n\tsqc2 vf1, %5"
        : "=m" (f.roll.row[0]), "=m" (f.goal.row[0]), "=m" (f.roll.row[1]), "=m" (f.goal.row[1]), "=m" (f.roll.row[2]), "=m" (f.goal.row[2]));
    float *lk = (float *)&f.look.row[0];
    float *rl = (float *)&f.rel.row[0];
    if (lk[0] + rl[0] < 0.0f && lk[1] * rl[1] < 0.0f) {
        f.goal = *rest;
    } else {
        asm("lqc2 vf6, %0\n\tlqc2 vf4, %1\n\tlqc2 vf1, %2\n\tlqc2 vf3, %3\n\tlqc2 vf2, %4\n\tlqc2 vf5, %5\n\tvmulax.xyz ACC, vf1, vf6x\n\tvmadday.xyz ACC, vf3, vf6y\n\tvmaddz.xyz vf6, vf2, vf6z\n\tvmulax.xyz ACC, vf1, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddz.xyz vf4, vf2, vf4z\n\tsqc2 vf6, %6\n\tvmulax.xyz ACC, vf1, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddz.xyz vf1, vf2, vf5z"
            : "=m" (f.goal.row[2]) : "m" (rest->row[2]), "m" (rest->row[0]), "m" (f.look.row[0]), "m" (f.look.row[1]), "m" (f.look.row[2]), "m" (rest->row[1]));
    }
    ConvertXfMat(ppt, *(void **)(self + 0x60), *(void **)(*(char **)(*(char **)(self + 0x10F4) + 8) + 0xA0), pgoal);
    f.goal = f.pt;
    QW euler = DecomposeRotateMatrixEuler(pgoal);
    func_0012D108(*(void **)(self + 0x10F4), euler);
}
