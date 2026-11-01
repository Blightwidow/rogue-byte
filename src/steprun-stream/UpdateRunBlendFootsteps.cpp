#include "sly2.h"
struct FOOT_20BC08 { float uStart; float uEnd; };
struct STEP_20BC08 { int unk0; int unk4; FOOT_20BC08 *pfoot; };
struct LO_20BC08 { char pad[0x18]; void *plo; float u; };
struct ASEG_20BC08 { char pad[0x50]; LO_20BC08 *plo; char pad54[0x74 - 0x54]; float tPeriod; char pad78[0xD0 - 0x78]; STEP_20BC08 *asteps; };
struct RB_20BC08 { char pad[4]; ASEG_20BC08 *paseg; char pad8[0x50 - 8]; float uBlend; char pad54[0x90 - 0x54]; int sfxid; float uVolumeA; float uVolumeB; int afOn[2]; };
extern "C" float GModPositive__Fff(float, float);
extern "C" void *NewEmitter(int);
extern "C" void SetEmitterUnpositioned(void *, int);
extern "C" QW PosLoWorld(void *);
extern "C" void SetAmbPos(void *, QW);
extern "C" void SetAmbRange(void *, float, float);
extern "C" void SetAmbVolume(void *, float);

extern "C" void UpdateRunBlendFootsteps(RB_20BC08 *prb)
{
    LO_20BC08 *plo = prb->paseg->plo;
    float u = plo->u;
    for (int i = 0; i < 2; i++) {
        ASEG_20BC08 *paseg = prb->paseg;
        FOOT_20BC08 *pfoot = paseg->asteps[i].pfoot;
        int fOn = pfoot->uEnd <= GModPositive__Fff(u - pfoot->uStart, paseg->tPeriod);
        if (fOn != prb->afOn[i]) {
            if (fOn == 0) {
                float uBlend = prb->uBlend;
                float uVolume = uBlend * prb->uVolumeB + (1.0f - uBlend) * prb->uVolumeA;
                void *pamb = NewEmitter(prb->sfxid);
                SetEmitterUnpositioned(pamb, 0);
                SetAmbPos(pamb, PosLoWorld(plo->plo));
                SetAmbRange(pamb, 500.0f, 2000.0f);
                SetAmbVolume(pamb, uVolume);
            }
            prb->afOn[i] = fOn;
        }
    }
}
