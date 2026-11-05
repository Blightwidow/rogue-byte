#include "sly2.h"
struct SMP { float a; float b; float c; };
struct AMB { char pad[0x38]; AMB *pambNext; };
struct SND {
    char pad0[0x4C]; AMB *pambFirst; char pad1[0x58 - 0x50]; int fPaused;
    char pad2[0x15C - 0x5C]; float gTarget;
    char pad3[0x1F0 - 0x160]; long tickCur; long tickPrev;
    AMB *pambA; int cStack; AMB *apambStack[8]; AMB *pambC;
};
struct CLOCK { char pad[4]; float dt; char pad1[0x40 - 8]; float gScale; };
extern "C" {
extern CLOCK g_2dded0;
extern int g_2bd4c0;
extern SMP RO_002A8288;
long TickReadCount(CLOCK *);
void func_001FDA48(SND *);
void func_001FDBA8(SND *);
void func_001FDEC0(SND *);
int func_001FE5E0(SND *);
void ContinueAmb(AMB *);
void PauseAmb(AMB *);
void UpdateSndMix(SND *);
void UpdateStreamCues(SND *);
void UpdateAmb(AMB *);
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void SetSndbankVolumeFactor(SND *, int, float, int);
void snd_FlushSoundCommands(void);
}
extern "C" void UpdateSnd(SND *self)
{
    self->tickPrev = self->tickCur;
    self->tickCur = TickReadCount(&g_2dded0);
    func_001FDA48(self);
    func_001FDBA8(self);
    AMB *pambTop = self->cStack > 0 ? ((AMB **)&self->cStack)[self->cStack] : 0;
    if (g_2bd4c0 == 3) {
        if (self->fPaused) {
            if (pambTop)
                ContinueAmb(pambTop);
            if (self->pambC)
                ContinueAmb(self->pambC);
            if (self->pambA)
                ContinueAmb(self->pambA);
            self->fPaused = 0;
        }
    } else if (!self->fPaused) {
        if (pambTop)
            PauseAmb(pambTop);
        if (self->pambC)
            PauseAmb(self->pambC);
        if (self->pambA)
            PauseAmb(self->pambA);
        self->fPaused = 1;
    }
    float gMute = 1.0f;
    UpdateSndMix(self);
    func_001FDEC0(self);
    UpdateStreamCues(self);
    SMP smp = RO_002A8288;
    if (func_001FE5E0(self)) {
        if (g_2dded0.dt == 0.0f)
            gMute = 0.0f;
    }
    float gVolume = GSmooth__FfffP3SMPPf(self->gTarget, gMute, g_2dded0.gScale, &smp, 0);
    SetSndbankVolumeFactor(self, 0, gVolume, 2);
    SetSndbankVolumeFactor(self, 1, gVolume, 2);
    SetSndbankVolumeFactor(self, 2, gMute, 2);
    AMB *pamb = self->pambFirst;
    AMB *pambCur = pamb;
    if (pamb) {
        do {
            pamb = pamb->pambNext;
            UpdateAmb(pambCur);
            pambCur = pamb;
        } while (pamb);
    }
    snd_FlushSoundCommands();
}
