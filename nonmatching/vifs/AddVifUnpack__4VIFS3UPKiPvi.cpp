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
    int cWord = (cb + 3) >> 2;
    unsigned *dest = pbDest;
    unsigned *pbSrc = (unsigned *)pvSrc;
    int rem = cWord & 3;
    int bulk = cWord - rem;
    int left = rem;
    if (rem != 0) {
        do {
            *dest++ = *pbSrc++;
        } while (--left != 0);
    }
    if (bulk > 0) {
        int index = 0;
        do {
            index += 4;
            unsigned a = pbSrc[0], b = pbSrc[1], c2 = pbSrc[2], d = pbSrc[3];
            pbSrc += 4;
            dest[0] = a; dest[1] = b; dest[2] = c2; dest[3] = d;
            dest += 4;
        } while (index < bulk);
    }
}
