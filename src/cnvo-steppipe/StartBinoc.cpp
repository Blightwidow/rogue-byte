struct Binoc { char pad[4]; int state; char pad2[0x18]; int mode; char pad3[0x1C]; void *so; void *blot; };
extern "C" void SetBinocState(Binoc *, int);

extern "C" void StartBinoc(Binoc *binoc, int mode, void *so, void *blot)
{
    if (binoc->state != -1) {
        if (binoc->mode == 1)
            return;
        if (mode != 1)
            return;
        SetBinocState(binoc, 2);
        SetBinocState(binoc, -1);
    }
    binoc->mode = mode;
    binoc->so = so;
    binoc->blot = blot;
    SetBinocState(binoc, 0);
}
