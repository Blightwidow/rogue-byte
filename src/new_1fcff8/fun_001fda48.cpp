typedef int s32;
typedef float f32;
typedef long s64;
typedef int QW __attribute__((mode(TI)));
struct HitFxTarget {
    char pad0[0x54];
    f32 x;
    f32 negZ;
    f32 z;
};
struct FocusBlock {
    char pad0[0x4034];
    HitFxTarget *target;
};
struct HitFxEvent {
    char pad0[0x10];
    s32 active;
    char pad1[0x6C - 0x14];
    s32 started;
    f32 progress;
    char hitFxArgument[0xC];
    f32 curveX[3];
    char pad3[4];
    f32 curveZ[3];
};
extern "C" {
extern FocusBlock B_003DD490;
extern s32 func_001FCF70;
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
int ReplaceHitFx(void *, QW, void *, void *);
void func_002330D0(s32, s32, s32, s32, s32, s32, s32, void *, s64);
}
extern "C" void func_001FDA48(HitFxEvent *event)
{
    if (event->active == 0) {
        *(s32 *)&event->progress = 0;
    } else if (event->started == 0) {
        event->started = 1;
        func_002330D0(0x524B5553, 0xB, 0, 0, 0, 0, 0, &func_001FCF70, (s64)event);
    }
    HitFxTarget *target = 0;
    QW position;
    void *focus = PpoSwFocusBase(&B_003DD490);
    if (focus != 0) {
        if (FIsBasicDerivedFrom(focus, 0x34) != 0) {
            if (0.5f < event->progress) {
                target = B_003DD490.target;
                position = PosLoWorld(focus);
                f32 progress = event->progress;
                f32 *curveX = event->curveX;
                f32 *curveZ = event->curveZ;
                target->x = curveX[0] + progress * (curveX[1] + progress * curveX[2]);
                f32 depth = curveZ[0] + event->progress * (curveZ[1] + event->progress * curveZ[2]);
                target->z = depth;
                target->negZ = -depth;
            }
        }
    }
    ReplaceHitFx(target, position, focus, event->hitFxArgument);
}
