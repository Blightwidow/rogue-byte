// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
enum UPK { UPK_DUMMY };
struct VIFS {
    char pad[0xC];
    char *m_pb;
    void UnpackHelper(UPK upk, int c, int uAddr, int *pcb, unsigned **ppb);
    void AddVifUnpack(UPK upk, int c, void *pvSrc, int uAddr);
};
void VIFS::AddVifUnpack(UPK upk, int c, void *pvSrc, int uAddr)
{
    int cb;
    unsigned *pbDest;
    UnpackHelper(upk, c, uAddr, &cb, &pbDest);
    unsigned *src = (unsigned *)pvSrc;
    unsigned *dst = pbDest;
    int n = (cb + 3) >> 2;
    int rem = n & 3;
    int full = n - rem;
    int i;
    if (rem != 0) {
        i = rem;
        do {
            *dst++ = *src++;
        } while (--i != 0);
    }
    i = 0;
    if (full > 0) {
        do {
            unsigned w0 = src[0];
            unsigned w1 = src[1];
            unsigned w2 = src[2];
            unsigned w3 = src[3];
            i += 4;
            dst[0] = w0;
            dst[1] = w1;
            dst[2] = w2;
            dst[3] = w3;
            src += 4;
            dst += 4;
        } while (i < full);
    }
}
