#include "sly2.h"
struct TEX0 {
    unsigned long tbp0 : 14;
    unsigned long tbw : 6;
    unsigned long psm : 6;
    unsigned long tw : 4;
    unsigned long th : 4;
    unsigned long tcc : 1;
    unsigned long tfx : 2;
    unsigned long cbp : 14;
    unsigned long cpsm : 4;
    unsigned long csm : 1;
    unsigned long csa : 5;
    unsigned long cld : 3;
};
struct CLUT { char pad0[8]; unsigned short count; char pad[0xE]; TEX0 tex0; };

void BuildClutTex2__FP4CLUTi(CLUT *pclut, int iblock)
{
    pclut->tex0.cbp = iblock;
    pclut->tex0.psm = pclut->count > 0x10 ? 0x13 : 0x14;
    pclut->tex0.csa = 0;
    pclut->tex0.cpsm = 0;
    pclut->tex0.cld = 1;
    pclut->tex0.csm = 0;
}
