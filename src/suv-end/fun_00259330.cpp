#include "sly2.h"
struct BLK { char b[0x40]; } __attribute__((aligned(16)));
struct EMITB { int pad0; int emitpk; char pad[0xB8]; BLK blk; };
struct EMITTER;
extern "C" BLK D_002BDE10;
extern "C" BLK B_002DE720;
extern "C" EMITB *func_002590F0(EMITTER *, int);

extern "C" BLK *func_00259330(EMITTER *pemitter, int ensk)
{
    EMITB *pemitb = func_002590F0(pemitter, ensk);
    if (ensk == 1 && pemitb->emitpk == -1) {
        pemitb->emitpk = 0;
        pemitb->blk = D_002BDE10;
    }
    if (pemitb->emitpk != 0)
        return &B_002DE720;
    return &pemitb->blk;
}
