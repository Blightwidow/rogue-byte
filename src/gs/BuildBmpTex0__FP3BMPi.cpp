#include "sly2.h"
struct TEX0 {
    unsigned long tbp0 : 14;
    unsigned long tbw : 6;
    unsigned long psm : 6;
    unsigned long tw : 4;
    unsigned long th : 4;
    unsigned long tcc : 1;
    unsigned long rest : 29;
};
struct BMP { char pad0[8]; unsigned short w; unsigned short h; unsigned char psm; unsigned char tbw; char pad[0x12]; TEX0 tex0; };
extern "C" unsigned NLog2__FUi(unsigned);

void BuildBmpTex0__FP3BMPi(BMP *pbmp, int iblock)
{
    pbmp->tex0.tbp0 = iblock;
    pbmp->tex0.tbw = pbmp->tbw;
    pbmp->tex0.psm = pbmp->psm;
    pbmp->tex0.tw = NLog2__FUi(pbmp->w);
    pbmp->tex0.th = NLog2__FUi(pbmp->h);
    pbmp->tex0.tcc = 1;
}
