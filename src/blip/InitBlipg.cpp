#include "sly2.h"
struct BLIPG { char pad[0x18]; int unk18; char pad2[0x1C]; float unk38; int pad3; unsigned unk40; };
extern "C" void InitXfm(BLIPG *);
extern "C" void InitDl__FP2DLi(void *, int);
extern "C" void func_001A6CA8(BLIPG *, int);

void InitBlipg(BLIPG *pblipg)
{
    InitXfm(pblipg);
    InitDl__FP2DLi((char *)pblipg + 0x448, 0x1090);
    pblipg->unk18 = -1;
    pblipg->unk38 = 1.0e10f;
    func_001A6CA8(pblipg, 1);
    unsigned tagged = pblipg->unk40;
    if (((tagged ^ 1) & 1) != 0) {
        unsigned *pu = (unsigned *)tagged;
        *pu = (*pu & 1) | 0xe;
    } else {
        pblipg->unk40 = (tagged & 1) | 0xe;
    }
}
