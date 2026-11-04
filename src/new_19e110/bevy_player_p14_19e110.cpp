typedef int s32;
struct CurveOwner {
    char pad[0xE4];
    s32 disabled;
};
struct CurveSpan {
    char pad0[0xC];
    CurveOwner *owner;
    char pad1[0x8];
    s32 reversed;
};
extern "C" {
float SMinCrv(CurveOwner *);
float SMaxCrv(CurveOwner *);
}
extern "C" void bevy_player_p14_19e110(CurveSpan *span, float *range)
{
    CurveOwner *owner = span->owner;
    if (owner->disabled != 0) {
        range[0] = -3.402823466e+38f;
        range[1] = 3.402823466e+38f;
        return;
    }
    if (span->reversed != 0) {
        range[0] = SMinCrv(owner) + 35.0f;
        range[1] = SMaxCrv(span->owner) - 100.0f;
    } else {
        range[0] = SMinCrv(owner) + 100.0f;
        range[1] = SMaxCrv(span->owner) - 35.0f;
    }
}
