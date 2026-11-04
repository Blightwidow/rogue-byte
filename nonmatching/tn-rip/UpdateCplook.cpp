#include "sly2.h"
struct CRef { int tagk; int n; };
struct LM;
struct SMP;
struct AMB { char pad[0x4E]; short cpause; };
struct CPLOOK {
    char pad0[0x10];
    float radPan;
    float radTilt;
    float dradPan;
    float dradTilt;
    float u;
    float du;
    char pad28[4];
    float fovMin;
    float fovMax;
    AMB *pamb;
    char pad38[4];
    float radPanMin;
    float radPanMax;
    float radTiltMin;
    float radTiltMax;
};
struct JOY { char pad0[0x103C]; float x; float y; char pad1044[0x1074 - 0x1044]; float yZoom; };
struct CLOCK { float t; float dt; };
struct CM { char pad[0x20]; float rFov; };
struct GS { char pad[0x3B4C]; void *pvSave; char pad3b50[0x4750 - 0x3B50]; float tLook; };
extern "C" {
void UpdateCplcy(CPLOOK *, void *, JOY *);
float GLimitLm__FP2LMf(LM *, float);
float GLimitAbs__Fff(float, float);
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void SetAmbPitch(AMB *, float);
void SetAmbVolume(AMB *, float);
void ContinueAmb(AMB *);
void PauseAmb(AMB *);
void SetCmFov(CM *, float);
void SetCmLookAt(CM *, QW, QW, float, float);
QW PosCplookEye(CPLOOK *);
QW PosCplookAnchor(CPLOOK *);
CRef *RefGetGameSaveValue(CRef *, void *, void *);
void CRef_Destruct(CRef *);
float RadNormalize__Ff(float);
extern float D_002BD980[3];
extern float D_002BD990;
extern float D_002BD994;
extern float D_002BD998;
extern float D_002BD99C;
extern float D_002BD9B0[2];
extern LM D_002BBB68;
extern LM g_2bbb60;
extern SMP D_002BD9A0;
extern CLOCK g_2dded0;
extern CM B_002DDF40;
extern GS B_003DD490;
extern char B_003D4A60[];
}

static inline float GClamp(float g, float gMin, float gMax)
{
    if (g < gMin)
        return gMin;
    if (gMax < g)
        return gMax;
    return g;
}

extern "C" void UpdateCplook(CPLOOK *pcplook, void *pv, JOY *pjoy)
{
    UpdateCplcy(pcplook, pv, pjoy);
    float u = pcplook->u;
    float yZoom = pjoy->yZoom;
    float du = (D_002BD980[0] + u * (D_002BD980[1] + u * D_002BD980[2])) * yZoom * fabsf(yZoom);
    pcplook->du = du;
    u = u + du * g_2dded0.dt;
    u = GClamp(u, 0.0f, 1.0f);
    pcplook->u = u;
    if (pcplook->du != 0.0f && 0.0f < u && u < 1.0f) {
        AMB *pamb = pcplook->pamb;
        SetAmbPitch(pamb, GLimitLm__FP2LMf(&D_002BBB68, fabsf(pcplook->du)));
        pamb = pcplook->pamb;
        SetAmbVolume(pamb, GLimitLm__FP2LMf(&g_2bbb60, fabsf(pcplook->du) * 0.5f + 0.5f));
        if (pcplook->pamb->cpause > 0)
            ContinueAmb(pcplook->pamb);
    } else if (pcplook->pamb->cpause <= 0) {
        PauseAmb(pcplook->pamb);
    }
    float t = 1.0f - pcplook->u;
    SetCmFov(&B_002DDF40, (1.0f - t) * pcplook->fovMin + t * pcplook->fovMax);
    float x = pjoy->x;
    float y = pjoy->y;
    float dradPan = -fabsf(x) * x * D_002BD990;
    float dradTilt = -fabsf(y) * y * D_002BD994;
    CRef ref;
    RefGetGameSaveValue(&ref, B_003DD490.pvSave, B_003D4A60);
    int fInvert = ref.n;
    CRef_Destruct(&ref);
    if (fInvert)
        dradTilt = -dradTilt;
    dradPan = pcplook->dradPan + GLimitAbs__Fff(dradPan - pcplook->dradPan, D_002BD998 * g_2dded0.dt);
    dradTilt = pcplook->dradTilt + GLimitAbs__Fff(dradTilt - pcplook->dradTilt, D_002BD99C * g_2dded0.dt);
    float dtHalf = g_2dded0.dt * 0.5f;
    float radMin;
    float radMax;
    GSmooth__FfffP3SMPPf(pcplook->radPan, pcplook->radPanMin, dtHalf, &D_002BD9A0, &radMin);
    GSmooth__FfffP3SMPPf(pcplook->radPan, pcplook->radPanMax, dtHalf, &D_002BD9A0, &radMax);
    pcplook->dradPan = GClamp(dradPan, radMin, radMax);
    GSmooth__FfffP3SMPPf(pcplook->radTilt, pcplook->radTiltMin, dtHalf, &D_002BD9A0, &radMin);
    GSmooth__FfffP3SMPPf(pcplook->radTilt, pcplook->radTiltMax, dtHalf, &D_002BD9A0, &radMax);
    float drad = GClamp(dradTilt, radMin, radMax);
    pcplook->dradTilt = drad;
    float rFov = B_002DDF40.rFov;
    float s = (1.0f - rFov) * D_002BD9B0[0] + rFov * D_002BD9B0[1];
    pcplook->radPan = pcplook->radPan + s * pcplook->dradPan * g_2dded0.dt;
    pcplook->radTilt = pcplook->radTilt + s * drad * g_2dded0.dt;
    if (pcplook->radPanMax - pcplook->radPanMin >= 6.2831855f)
        pcplook->radPan = RadNormalize__Ff(pcplook->radPan);
    QW posEye = PosCplookEye(pcplook);
    SetCmLookAt(&B_002DDF40, posEye, PosCplookAnchor(pcplook), 0.0f, 0.0f);
    B_003DD490.tLook = g_2dded0.t;
}
