// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"

struct SAFEPT { void *pbasic; s32 field4; u8 unknown_0x8[8]; QW second; };
struct JTVT { u8 unknown_0x0[0xE8]; s16 deltaE8; u8 pad[2]; void (*pfnEC)(void *, QW); s16 deltaF0; u8 pad2[2]; void (*pfnF4)(void *, void *); };
struct JTX { u8 unknown_0x0[0xC]; JTVT *vt; };

struct CMG { u8 unknown_0x0[0x60]; QW dir; };
extern CMG B_002DDF40;
extern u8 B_003DD490[];
extern f32 D_FLT_002BF940;

extern "C" {
void FindBestSafePoint(void *, void *);
void *PpoSwFocusBase(void *);
QW func_0019F3F8(void *, void *, float);
float DtSolveJumpLaunch(QW, QW, float, float, float, float);
void SetStepRadTargetDir(void *, QW);
int SetResetFlag__FP2CM(void *);
void SetJmpState(void *, int, int, int);
int FIsBasicDerivedFrom(void *, int);
void JtbsChooseJtLanding(void *, void *);
void func_00148300(void *, void *);
void StartFade(int);
}

void WarpJtToSafePoint(u8 *pjt, SAFEPT *ppoint)
{
    SAFEPT point;
    QW launch;
    if (ppoint == 0) {
        FindBestSafePoint(pjt + 0x9E0, &point);
        ppoint = &point;
        if (pjt == PpoSwFocusBase(B_003DD490)) {
            launch = func_0019F3F8(pjt, &point, 0.0f);
            QW toward = VectorSub(launch, *(QW *)(*(u8 **)(pjt + 0x58) + 0x70));
            float reach = DtSolveJumpLaunch(toward, *(QW *)(*(u8 **)(pjt + 0xE8) + 0x80), 1000.0f, -1000.0f, 1.0f, -1.0f);
            if (D_FLT_002BF940 < reach) {
                JTX *pjtx = (JTX *)pjt;
                u8 *pjmp = pjt + 0x2C0;
                u8 *pjmpLand = pjmp;
                JTVT *pvt = pjtx->vt;
                QW offset = VectorSub(launch, *(QW *)(pjt + 0x240));
                s32 saved = *(s32 *)(pjt + 0x9E4);
                pvt->pfnEC(pjt + pvt->deltaE8, offset);
                *(s32 *)(pjt + 0x9E4) = saved;
                SetStepRadTargetDir(pjt, B_002DDF40.dir);
                pvt = pjtx->vt;
                pvt->pfnF4(pjt + pvt->deltaF0, pjt + 0x1B0);
                SetResetFlag__FP2CM(&B_002DDF40);
                SetJmpState(pjmp, 0xB, 0, 0);
                if (point.field4 != 0 &&
                    (FIsBasicDerivedFrom(point.pbasic, 0x13) || FIsBasicDerivedFrom(point.pbasic, 0xB) ||
                     FIsBasicDerivedFrom(point.pbasic, 0xD) || FIsBasicDerivedFrom(point.pbasic, 0x27) ||
                     FIsBasicDerivedFrom(point.pbasic, 0xC) || FIsBasicDerivedFrom(point.pbasic, 0x22) ||
                     FIsBasicDerivedFrom(point.pbasic, 0x26))) {
                    func_00148300(B_003DD490, point.pbasic);
                    JtbsChooseJtLanding(pjmpLand, point.pbasic);
                }
                StartFade(*(s32 *)(B_003DD490 + 0x3E60));
                return;
            }
        }
    }
    *(QW *)(pjt + 0x490) = *(QW *)ppoint;
    *(QW *)(pjt + 0x4A0) = ppoint->second;
    SetJmpState(pjt + 0x2C0, 0xA, 0, 0);
}
