#include "sly2.h"
struct R { char p0[0x74]; int count; int list[5]; char p1[0xAC-0x8C]; int blot; };
extern int D_002C3588[];
extern "C" int FReconTargetDone(int);
extern "C" void func_00213BD8(int, int, int);
extern "C" void bevy_ui_binoc_recon_2021f8(R *recon)
{
    for (int ilist = 0; ilist < recon->count; ++ilist) {
        int target = recon->list[ilist];
        int id = D_002C3588[ilist];
        if (FReconTargetDone(target) != 0)
            func_00213BD8(recon->blot, 0x33A, id);
        else
            func_00213BD8(recon->blot, 0x33B, id);
    }
}