#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct SW; struct LO;
struct RECON { char p0[0x20]; QW posEye; char p1[0xB8 - 0x30]; int fInVolume; };
extern char B_003DD490[];
extern "C" int CploFindSwObjectsByClass(void *, unsigned, int, LO *, int, LO **);
extern "C" int func_00227C90(LO *, QW);
extern "C" void bevy_ui_binoc_recon_201f90(RECON *recon)
{
    LO *aplo[16];
    recon->fInVolume = 0;
    int count = CploFindSwObjectsByClass(B_003DD490, 0x505, 0x19, 0, 0x10, aplo);
    LO **plo = aplo;
    for (int index = 0; index < count; plo++, index++) {
        if (func_00227C90(*plo, recon->posEye) != 0) {
            recon->fInVolume = 1;
            break;
        }
    }
}
