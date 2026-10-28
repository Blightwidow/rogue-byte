struct BINOC { void *pjt; };
struct HUD { BINOC *pbinoc; int pad; int blotA; int blotB; int pad2; int recon; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int PloFindSwObject_thunk(void *, int, int, int);
extern "C" void SetBinocHudBlot(HUD *, int);
extern "C" void func_00201DC8(int);
extern "C" char B_003DD490[];
extern "C" void PostBinocHudLoad(HUD *phud)
{
    if (FIsBasicDerivedFrom(phud->pbinoc->pjt, 0x35) != 0) {
        phud->blotA = PloFindSwObject_thunk(B_003DD490, 0x405, 0x35F, 0);
        phud->blotB = PloFindSwObject_thunk(B_003DD490, 0x405, 0x368, 0);
    } else if (FIsBasicDerivedFrom(phud->pbinoc->pjt, 0x37) != 0) {
        phud->blotA = PloFindSwObject_thunk(B_003DD490, 0x405, 0x360, 0);
        phud->blotB = PloFindSwObject_thunk(B_003DD490, 0x405, 0x369, 0);
    } else if (FIsBasicDerivedFrom(phud->pbinoc->pjt, 0x36) != 0) {
        phud->blotA = PloFindSwObject_thunk(B_003DD490, 0x405, 0x361, 0);
        phud->blotB = PloFindSwObject_thunk(B_003DD490, 0x405, 0x36A, 0);
    }
    if (phud->recon != 0)
        func_00201DC8(phud->recon);
    SetBinocHudBlot(phud, phud->blotB);
}
