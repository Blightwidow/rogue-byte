#include "sly2.h"
struct B8 { char b[8]; };
struct Plook {
    void *psoFocus; char pad4[0xC]; float radPan; float radTilt; int swPan; int swTilt; int uZoom; int svuZoom;
    float rZoomMax; float radFovMin; float radFovMax; void *pambZoom; void *pambBinoc; float lim[4];
    float panSaved; float tiltSaved; int cActivate;
};
extern "C" {
struct Cm { char pad[0x24]; float fov; char pad28[0x60 - 0x28]; char mat[0x30]; };
extern Cm B_002DDF40;
extern const B8 D_002BD950, D_002BD958, D_002BD968, D_002BD970;
extern char D_002BD960[];
extern float B_FLT_003E1BE0;
extern float g_2dded0;
void ActivateCplcy(Plook *, void *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, void *);
void VirtualRefPtr_Assign(void *, void *);
void PauseAmb(void *);
void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(void *, float *, float *);
int FIsBasicDerivedFrom(void *, int);
void *PmatLoWorld(void *);
float GLimitLm__FP2LMf(void *, float);
void SetCmNearClip(void *, float);
}
extern "C" void ActivateCplook(Plook *pcplook, void *psoFocus, void *pv)
{
    Cm *pcm = &B_002DDF40;
    ActivateCplcy(pcplook, psoFocus);
    void *emitter = NewEmitter(0x26);
    SetEmitterUnpositioned(emitter, 0);
    VirtualRefPtr_Assign(&pcplook->pambZoom, emitter);
    emitter = NewEmitter(0x25);
    SetEmitterUnpositioned(emitter, 0);
    VirtualRefPtr_Assign(&pcplook->pambBinoc, emitter);
    PauseAmb(pcplook->pambZoom);
    DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(pcm->mat, &pcplook->radPan, &pcplook->radTilt);
    if (FIsBasicDerivedFrom(pcplook->psoFocus, 0x34)) {
        *(B8 *)&pcplook->lim[0] = D_002BD950;
        *(B8 *)&pcplook->lim[2] = D_002BD958;
        pcplook->swPan = 0;
    } else {
        *(B8 *)&pcplook->lim[0] = D_002BD968;
        *(B8 *)&pcplook->lim[2] = D_002BD970;
        pcplook->panSaved = pcplook->radPan;
        pcplook->tiltSaved = pcplook->radTilt;
        void *viewer = PmatLoWorld(pcplook->psoFocus);
        DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(viewer, &pcplook->radPan, &pcplook->radTilt);
        float radTilt = GLimitLm__FP2LMf(D_002BD960, pcplook->radTilt);
        pcplook->radTilt = radTilt;
        pcplook->lim[0] += pcplook->radPan;
        pcplook->lim[1] += pcplook->radPan;
        pcplook->lim[2] += radTilt;
        pcplook->lim[3] += radTilt;
        pcplook->lim[2] = GLimitLm__FP2LMf(D_002BD960, radTilt);
        pcplook->lim[3] = GLimitLm__FP2LMf(D_002BD960, pcplook->radTilt);
        pcplook->swPan = 0;
    }
    pcplook->swTilt = 0;
    pcplook->uZoom = 0;
    pcplook->svuZoom = 0;
    pcplook->radFovMin = pcm->fov / pcplook->rZoomMax;
    pcplook->radFovMax = pcm->fov;
    SetCmNearClip(pcm, 49.0f);
    pcplook->cActivate = pcplook->cActivate + 1;
    B_FLT_003E1BE0 = g_2dded0;
}
