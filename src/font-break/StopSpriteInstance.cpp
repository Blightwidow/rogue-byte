struct AMB;
struct SPRITEINST { char pad[8]; short ilabel; short pad2; float t; int fPaused; AMB *pamb; };
struct STAMP218660 { unsigned long v; };
struct SPRITE { char pad[8]; SPRITEINST *ainst; STAMP218660 stamp; float tStopped; int ilabelStopped; int ilabelPending; };
extern "C" {
extern STAMP218660 g_2ddf18;
void StopAmb(AMB *, float);
void VirtualRefPtr_Assign(AMB **, AMB *);
void ClearSpriteInstance(SPRITE *, int);
}
static inline void StopAmbRef(AMB **ppamb)
{
    if (ppamb != 0) {
        if (*ppamb != 0) {
            StopAmb(*ppamb, 0.0f);
            VirtualRefPtr_Assign(ppamb, 0);
        }
    }
}
extern "C" void StopSpriteInstance(SPRITE *psprite, int iinst)
{
    SPRITEINST *pinst = (SPRITEINST *)(iinst * 0x18 + (int)psprite->ainst);
    if (pinst->ilabel >= 0) {
        int ilabel = pinst->ilabel;
        float t = pinst->t;
        psprite->ilabelStopped = ilabel;
        psprite->tStopped = t;
        psprite->stamp = g_2ddf18;
        psprite->ilabelPending = -1;
        pinst->fPaused = 0;
        pinst->ilabel = -1;
        StopAmbRef(&pinst->pamb);
    }
    ClearSpriteInstance(psprite, iinst);
}
