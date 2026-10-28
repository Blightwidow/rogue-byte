// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, void *, int); };
struct JVT { char pad[0x2C0]; short delta; short index; void (*fn)(void *, int); };
struct JT { char pad[0xC]; JVT *vt; };
struct HBSK { char pad[0xC]; VT *vt; char pad2[0x16C]; int hbsks; char pad3[0x10]; JT *pjt; };
struct WKR { char pad[0x44]; unsigned flags; };
extern "C" int FAbsorbSoWkr(HBSK *, WKR *);
extern "C" char B_003DD490;
extern "C" QW PosLoWorld(HBSK *);
extern "C" void SpawnSwHitFx(void *, int, QW, HBSK *);
extern "C" void SetBinocState(void *, int);
extern "C" void SetHbskHbsks(HBSK *, int);
int FAbsorbHbskWkr(HBSK *phbsk, WKR *pwkr)
{
    if (FAbsorbSoWkr(phbsk, pwkr) == 0)
        return 0;
    if (phbsk->hbsks != 3) {
        if ((pwkr->flags & 8) != 0) {
            SpawnSwHitFx(&B_003DD490, 0, PosLoWorld(phbsk), phbsk);
            JT *pjt = phbsk->pjt;
            if (pjt != 0) {
                SetBinocState((char *)pjt + 0xF00, -1);
                JT *pjt2 = phbsk->pjt;
                pjt2->vt->fn((char *)pjt2 + pjt2->vt->delta, 0);
            }
            SetHbskHbsks(phbsk, 3);
            void *args[2];
            args[0] = pwkr;
            args[1] = (char *)pwkr + 0xC;
            phbsk->vt->fn((char *)phbsk + phbsk->vt->delta, 0xB, 0, 2, args, 0);
        }
    }
    return 1;
}
