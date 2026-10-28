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
        int *mpidzg = dzg->adz[index].mpidzg;
        if (mpidzg != 0) {
            QW *vec = (QW *)((ipxp << 4) + (int)dzg->adzx[index].mpipxpdv);
            int result;
            asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tqmfc2.ni %0, vf2" : "=r" (result) : "m" (dzx->dir), "m" (*vec));
            mpidzg[dzg->cdz] = result;
        }
        index++;
    } while (index < dzg->cdz);
    AppendDlEntry(&dzg->dl, dz);
    dzg->cdz = dzg->cdz + 1;
}
