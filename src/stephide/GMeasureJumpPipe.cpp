#include "sly2.h"
struct Mjp { int jump; void *curve; };
struct Mjt { int jump; void *parent; char pad[8]; QW local; };
struct Frame { QW position; Mjt target; float measure; };
extern "C" void GetPathPosFromS(float, void *, QW *, void *);
extern "C" QW ConvertAloPos(void *, void *, QW);
extern "C" float GMeasureJumpTargetTime(void *, float);
float MinimizeRange(float (*)(void *, float), void *, float, float, float, float, float *, float *);

extern "C" float GMeasureJumpPipe(Mjp *pipe, float s)
{
    Frame frame;
    void *curve = pipe->curve;
    GetPathPosFromS(s, curve, &frame.position, 0);
    frame.target.jump = pipe->jump;
    frame.target.parent = curve;
    frame.target.local = ConvertAloPos(0, curve, frame.position);
    MinimizeRange(GMeasureJumpTargetTime, &frame.target, 0.5f, 0.25f, 0.25f, 3.0f, 0, &frame.measure);
    return frame.measure;
}
