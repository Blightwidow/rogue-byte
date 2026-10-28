struct Policy;
struct Pso;
struct VTE { short delta; short index; void (*fn)(void *, void *, void *); };
struct VTP { char pad[0x30]; VTE entry; };
struct Policy { char pad[0xC]; VTP *vtable; };
struct VTS { char pad[0x190]; short delta; short index; void (*fn)(void *, void *); };
struct Pso { char pad[0xC]; VTS *vtable; };
struct CM {
    char pad0[0x20]; float radFov; float radFovTarget; float dradFov; char smpFov[0x260 - 0x2C];
    Pso *psoCpdefi; char pad264[0x270 - 0x264]; char cpdefi[0x300 - 0x270];
    int fCut; char pad304[0x30C - 0x304]; int ccpr; char pad310[4]; Policy *pcplcy; Pso *psoFocus;
    char pad31C[0x620 - 0x31C]; float sStereo; float sStereoTarget;
};
extern "C" {
extern char B_002DFC00[];
extern char B_002E0D00[];
struct SW { char pad[0x3E38]; int fStereo; };
extern SW B_003DD490;
extern char D_002BD810[];
void ResetCmAdjust__FP2CMP2SOP6CPDEFI(CM *, void *);
void AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI(CM *, Pso *, void *);
float GSmoothA__FffffP4SMPAPf(float, float, float, float, void *, void *);
float GSmooth__FfffP3SMPPf(float, float, float, void *, void *);
void RecalcCmFrustrum__FP2CM(CM *);
void SetCmFov(CM *, float);
}
extern int g_2dfbc0;
extern float g_2dded4;
extern float B_FLT_002DDEE0;

extern "C" void UpdateCmLast(CM *pcm)
{
    if (pcm->ccpr > 0) {
        Policy *pcplcy = pcm->pcplcy;
        Policy *pcplcyPrev = 0;
        Pso *psoDone = 0;
        if (pcplcy != 0) {
            do {
                Pso *pso = pcm->psoFocus;
                void *pcpdefi;
                if (pso != 0) {
                    pcpdefi = pcm->cpdefi;
                    if (pso != psoDone) {
                        pso->vtable->fn((char *)pso + pso->vtable->delta, pcpdefi);
                        if (pcplcyPrev != 0 || pso != pcm->psoCpdefi)
                            ResetCmAdjust__FP2CMP2SOP6CPDEFI(pcm, pcpdefi);
                        psoDone = pso;
                        AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI(pcm, pso, pcpdefi);
                        pcm->psoCpdefi = pso;
                    }
                } else {
                    pcm->psoCpdefi = 0;
                    pcpdefi = 0;
                    psoDone = 0;
                }
                VTE *entry = &pcplcy->vtable->entry;
                char *pad = B_002DFC00;
                if (!(g_2dfbc0 & 1))
                    pad = B_002E0D00;
                pcplcyPrev = pcplcy;
                entry->fn((char *)pcplcy + entry->delta, pcpdefi, pad);
            } while (pcm->ccpr > 0 && (pcplcy = pcm->pcplcy) != pcplcyPrev);
        }
    }
    if (pcm->fCut == 0) {
        float target = pcm->radFovTarget;
        float current = pcm->radFov;
        if (target != current) {
            pcm->radFov = GSmoothA__FffffP4SMPAPf(current, pcm->dradFov, target, g_2dded4, &pcm->smpFov[0x2C - 0x2C], &pcm->dradFov);
            RecalcCmFrustrum__FP2CM(pcm);
        }
    } else {
        SetCmFov(pcm, pcm->radFovTarget);
    }
    pcm->fCut = 0;
    if (B_003DD490.fStereo != 0)
        pcm->sStereo = GSmooth__FfffP3SMPPf(pcm->sStereo, pcm->sStereoTarget, B_FLT_002DDEE0, D_002BD810, 0);
}
