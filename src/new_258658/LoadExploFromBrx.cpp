#include "sly2.h"
struct ALLOCREQ { int size; int align; };
struct EMITMESH;
struct CBinaryInputStream;
struct EMITB { char pad0[0x10]; int emitok; char pad1[0x1C]; EMITMESH *pemitmesh; };
struct EMITTER { char pad[0xE4]; EMITB *pemitb; };
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" void InitEmitb(void *);
extern "C" void LoadXfmFromBrx(EMITTER *, CBinaryInputStream *);
void LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream(EMITMESH *, CBinaryInputStream *);
extern "C" void LoadEmitblipColors(EMITTER *, CBinaryInputStream *);

extern "C" void LoadExploFromBrx(EMITTER *pemitter, CBinaryInputStream *pbis)
{
    ALLOCREQ allocreq;
    allocreq.size = 0x100;
    allocreq.align = 0x10;
    void *pvEmitb = PvAllocSwImpl__Fi(&allocreq);
    pemitter->pemitb = (EMITB *)pvEmitb;
    InitEmitb(pvEmitb);
    LoadXfmFromBrx(pemitter, pbis);
    EMITB *pemitb = pemitter->pemitb;
    if (pemitb->emitok == 3)
        LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream(pemitb->pemitmesh, pbis);
    LoadEmitblipColors(pemitter, pbis);
}
