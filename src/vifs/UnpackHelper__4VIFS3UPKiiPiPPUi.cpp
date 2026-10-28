// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
enum UPK { UPK_DUMMY };
struct VIFS {
    char pad[0xC];
    char *m_pb;
    void UnpackHelper(UPK upk, int c, int uAddr, int *pcb, unsigned **ppb);
};
extern "C" int VIFS_AddUnpackCommand(VIFS *, UPK, int, int);
void VIFS::UnpackHelper(UPK upk, int c, int uAddr, int *pcb, unsigned **ppb)
{
    if (c == 0) {
        if (ppb != 0)
            *ppb = 0;
        if (pcb != 0)
            *pcb = 0;
        return;
    }
    int cb = VIFS_AddUnpackCommand(this, upk, c, uAddr);
    if (ppb != 0)
        *ppb = (unsigned *)m_pb;
    m_pb = m_pb + ((cb + 3) / 4) * 4;
    if (pcb != 0)
        *pcb = cb;
}
