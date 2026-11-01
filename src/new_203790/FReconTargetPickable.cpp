struct Link_203790 { char pad0[0x54]; int state; };
struct Obj_203790 { char pad0[0x28]; unsigned long grf; };
struct Recon_203790 { char pad0[0x28]; unsigned long grf; char pad1[0xEC - 0x30]; Link_203790 *plink; char pad2[0x100 - 0xF0]; Obj_203790 *pother; };
extern "C" int FReconTargetPickable(Recon_203790 *recon)
{
    if (((int)(recon->grf >> 60) & 1) == 0)
        return 0;
    Obj_203790 *pother = recon->pother;
    if (pother != 0 && ((int)(pother->grf >> 60) & 1) != 0)
        return 0;
    Link_203790 *plink = recon->plink;
    if (plink != 0 && plink->state != 1)
        return 0;
    return 1;
}
