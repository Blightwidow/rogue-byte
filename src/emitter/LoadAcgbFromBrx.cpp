#include "sly2.h"
struct CBinaryInputStream { int pad; unsigned U16Read(); float F32Read(); };
struct ALLOCREQ { int cb; int cbAlign; };
struct KGB { float t; float g; float a; float b; };
struct ACGB { int unk0; int ckgb; KGB *akgb; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);

void LoadAcgbFromBrx(ACGB *pacgb, CBinaryInputStream *pbis)
{
    int ikgb = 0;
    int ckgb = pbis->U16Read();
    ALLOCREQ allocreq;
    allocreq.cb = ckgb << 4;
    allocreq.cbAlign = 0x10;
    pacgb->ckgb = ckgb;
    pacgb->akgb = (KGB *)PvAllocSwClearImpl__Fi(&allocreq);
    while (ikgb < pacgb->ckgb) {
        KGB *pkgb = &pacgb->akgb[ikgb];
        ikgb++;
        int frame = pbis->U16Read();
        float fframe;
        asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (fframe) : "r" (frame));
        pkgb->t = fframe * 0.016666668f;
        pkgb->g = pbis->F32Read();
        pkgb->a = pbis->F32Read();
        pkgb->b = pbis->F32Read();
    }
}
