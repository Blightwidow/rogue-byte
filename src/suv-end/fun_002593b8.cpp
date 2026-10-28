#include "sly2.h"
struct BLK { char b[0x40]; } __attribute__((aligned(16)));
struct EMITB { int pad0; int emitpk; char pad[0xB8]; BLK blk; };
struct EMITTER;
extern "C" BLK D_002BDE70;
extern "C" BLK B_002DE720;
extern "C" EMITB *func_002590F0(EMITTER *, int);

extern "C" BLK *func_002593B8(EMITTER *pemitter, int ensk)
{
    EMITB *pemitb = func_002590F0(pemitter, ensk);
    if (ensk == 1 && pemitb->emitpk == -1) {
        pemitb->emitpk = ensk;
        pemitb->blk = D_002BDE70;
    }
    if (pemitb->emitpk != 1)
        return &B_002DE720;
    return &pemitb->blk;
}
