// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[8]; short delta; short index; void (*fn)(void *, int); };
struct DMAS { int a0; unsigned ab; unsigned *pqwCnt; unsigned *pb; int fPad; int fEndPrim; VT *vt; };
void EndDmaCnt__4DMAS(DMAS *dmas)
{
    if (dmas->fPad) {
        unsigned *cursor = dmas->pb;
        if ((unsigned)cursor & 0xF) {
            *cursor = 0;
            while ((unsigned)++cursor & 0xF)
                *cursor = 0;
        }
        dmas->pb = cursor;
    } else if (dmas->fEndPrim) {
        dmas->vt->fn((char *)dmas + dmas->vt->delta, 0);
    }
    unsigned *cnt = dmas->pqwCnt;
    if (cnt) {
        *cnt = *cnt | (((int)dmas->pb - (int)cnt) >> 4) - 1;
        dmas->pqwCnt = 0;
    }
}
