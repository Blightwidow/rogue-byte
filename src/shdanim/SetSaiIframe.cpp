struct SAI { char pad0[0x1C]; int cframe; char pad20[8]; unsigned short iframe; char pad2A[2]; int fDirty; char pad30[4]; char sl[1]; };
extern "C" int FIsSlEmpty(void *);
extern "C" void SetSaiIframe(SAI *sai, int iframe)
{
    if (FIsSlEmpty(sai->sl) != 0)
        return;
    int top = sai->cframe - 1;
    int clamped;
    if (iframe < 0)
        clamped = 0;
    else if (iframe > top)
        clamped = top;
    else
        clamped = iframe;
    unsigned short value = clamped;
    if (sai->iframe != value) {
        sai->iframe = value;
        sai->fDirty = 1;
    }
}
