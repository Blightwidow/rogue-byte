#include "sly2.h"
struct STRM { char pad[0x40]; int f40; char pad2[0x0C]; unsigned short f50; unsigned short f52; char pad3[0x14]; unsigned long cycles; };
struct STREAM { char pad[0x200]; STRM *pamb; char pad2[0x4C - 0x4]; float saved; };

float TStream(STREAM *pstream)
{
    if (pstream->pamb == 0)
        return 0.0f;
    float sPlayed = (float)pstream->pamb->cycles * 3.390842e-09f;
    STRM *pamb = pstream->pamb;
    if (sPlayed == 0.0f) {
        int fIdle = 0;
        if (pamb->f40 == 0 && (pamb->f52 != 0 || (fIdle = 1, (pamb->f50 & 1) != 0)))
            fIdle = fIdle ^ 1;
        if (fIdle)
            return pstream->saved;
    }
    return (float)pamb->cycles * 3.390842e-09f;
}
