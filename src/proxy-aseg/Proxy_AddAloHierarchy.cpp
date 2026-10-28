#include "sly2.h"
struct SND { int sfxid; float sStart; float sFull; float uVolume; float uPitch; };
struct PROXY { char pad[0xE4]; int csnd; SND *asnd; void **aref; };
extern "C" void func_001A6178(PROXY *);
extern "C" void *NewEmitter(int);
extern "C" void SetEmitterUnpositioned(void *, PROXY *);
extern "C" void SetAmbRange(void *, float, float);
extern "C" void SetAmbVolume(void *, float);
extern "C" void SetAmbPitch(void *, float);
extern "C" void VirtualRefPtr_Assign(void **, void *);

extern "C" void Proxy_AddAloHierarchy(PROXY *pproxy)
{
    func_001A6178(pproxy);
    for (int isnd = 0; isnd < pproxy->csnd; isnd++) {
        SND *psnd = &pproxy->asnd[isnd];
        void *pamb = NewEmitter(psnd->sfxid);
        SetEmitterUnpositioned(pamb, pproxy);
        SetAmbRange(pamb, psnd->sStart, psnd->sFull);
        SetAmbVolume(pamb, psnd->uVolume);
        SetAmbPitch(pamb, psnd->uPitch);
        VirtualRefPtr_Assign((void **)(isnd * 4 + (int)pproxy->aref), pamb);
    }
}
