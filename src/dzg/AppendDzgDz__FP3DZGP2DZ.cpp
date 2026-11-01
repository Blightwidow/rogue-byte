#include "sly2.h"
struct DZ { char pad[0x18]; int *mpidzg; char pad2[0x28 - 0x1C]; };
struct XP { char pad[0xA8]; int ipxp; };
struct DZX { char pad[0x40]; QW dir; char pad2[0x50 - 0x50]; XP *xp; };
struct DZXROW { char pad[0x54]; QW *mpipxpdv; char pad2[0x60 - 0x58]; };
struct DZG { int pad0; int cdz; DZ *adz; char pad1[0x30 - 0xC]; int dl[0x30/4]; DZXROW *adzx; };
extern "C" void AppendDlEntry(void *, void *);
void AppendDzgDz(DZG *dzg, void *dz, DZX *dzx)
{
    int ipxp = dzx->xp->ipxp;
    int index = 0;
    if (index < dzg->cdz) do {
        DZ *pdz = &dzg->adz[index];
        int *mpidzg = pdz->mpidzg;
        if (mpidzg != 0) {
            DZXROW *prow = &dzg->adzx[index];
            int cdz = dzg->cdz;
            asm("lqc2 vf2, %0" : : "m" (dzx->dir));
            int *dst = (int *)((cdz << 2) + (int)mpidzg);
            QW *vec = (QW *)((ipxp << 4) + (int)prow->mpipxpdv);
            int result;
            asm("lqc2 vf1, %1\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tqmfc2.ni %0, vf2" : "=r" (result) : "m" (*vec));
            *dst = result;
        }
        index++;
    } while (index < dzg->cdz);
    AppendDlEntry(&dzg->dl, dz);
    dzg->cdz = dzg->cdz + 1;
}
