#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct EMITB { int refs; int pk; int pad[2]; QW a[4]; QW b[7]; };
struct BLK { QW q[4]; };
struct BLK2 { QW q[7]; };
extern "C" BLK g_2de5b0;
extern "C" BLK2 B_002DE5F0;

extern "C" void InitEmitb(EMITB *pemitb)
{
    memset(pemitb, 0, 0x100);
    pemitb->refs = 1;
    pemitb->pk = -1;
    *(BLK *)&pemitb->a[0] = g_2de5b0;
    *(BLK2 *)&pemitb->b[0] = B_002DE5F0;
}
