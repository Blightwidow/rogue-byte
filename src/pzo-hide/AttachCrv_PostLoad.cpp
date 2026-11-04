typedef int s32;
typedef float f32;

struct AttachCrv {
    char pad0[0x38];
    f32 radius;
    char pad3C[0x190 - 0x3C];
    s32 transformOverride;
};

extern "C" {
void PostLoLoad();
f32 SRadiusCrv(AttachCrv*);
void SetTnTnsOverride(s32, s32);
extern f32 RO_002BE8B4;

void AttachCrv_PostLoad(AttachCrv* attach) {
    PostLoLoad();
    s32 overrideTransform = attach->transformOverride;
    if (overrideTransform != 0) {
        SetTnTnsOverride(overrideTransform, 0);
    }
    if (attach->radius == 1e10f) {
        attach->radius = SRadiusCrv(attach) + RO_002BE8B4;
    }
}
}
