#include "types.h"
#include "ps2inline.h"
struct JT { char pad[0x10F8]; void *field_10F8; int field_10FC; };
extern "C" {
QW PosLoWorld(void *);
QW ConvertAloPos(void *, JT *, QW);
float atan2f(float, float);
extern float D_FLT_002BD2C0;
extern float D_FLT_002BD2C4;
}
extern "C" int func_001430C8(JT *pjt)
{
    int quadrant;
    if (pjt->field_10F8) {
        QW pos = ConvertAloPos(0, pjt, PosLoWorld(pjt->field_10F8));
        float x = LaneX(pos);
        float y = LaneX(RotateWords3(pos));
        float angle = atan2f(y, x);
        float magnitude = angle < 0.0f ? -angle : angle;
        if (magnitude < D_FLT_002BD2C0)
            quadrant = 0;
        else if (D_FLT_002BD2C4 < magnitude)
            quadrant = 3;
        else if (0.0f < angle)
            quadrant = 1;
        else
            quadrant = 2;
    }
    int mask = 8;
    switch (pjt->field_10FC) {
    case -1:
    case 0: break;
    case 1: mask = 0x10 << quadrant; break;
    case 2: mask = 0x100 << quadrant; break;
    case 3: mask = 0x1000; break;
    case 4: mask = 0x100; break;
    }
    return mask;
}
