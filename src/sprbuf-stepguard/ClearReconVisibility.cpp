struct TARGET { char pad[0x108]; int vis; };
struct RECON { char pad[0x30]; int ctarget; TARGET *atarget[1]; };
extern "C" void ClearReconVisibility(RECON *precon)
{
    for (int itarget = 0; itarget < precon->ctarget; ++itarget)
        precon->atarget[itarget]->vis = 0;
}
