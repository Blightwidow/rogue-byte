#include "bentley.h"
struct JOY { char pad0[0x1C]; float axis; char pad1[0x10]; int flags; };
extern "C" {
void CarryThrow_Update(void *);
void ClearVjoyPresses(void *, int);
int FAsegaGone(void *);
int FAttachGroundTarget(void *, int, int);
int FButtonPressedWithin(void *, int, float);
int FJtInFocusRange(void *, int);
int FSmaRetracted(void *);
int GrfbtnVjoyPressedWithin(void *, int, float);
BENTLEYSLOT *PslotBentleyGadget(void *, int);
void SetBentleyState(void *, int);
void SetJmpState(void *, int, int, int);
void StartBinoc(void *, int, int, int);
void UpdateAttachInput(void *);
void UpdateBentleyAim(void *);
void UpdateBentleyGadget(void *);
void UpdateJmpBodyState(void *);
void UpdateJtActivePipe(void *);
void UpdateZap(void *);
void func_001367D8(void *);
extern float D_002BC930;
extern float g_2dded0;
void UpdateBentleyActive(BENTLEY *self)
{
    unsigned stateOld;
    do {
        stateOld = self->state;
        switch (stateOld) {
        case 2: case 4: case 6: case 8: case 9: case 10: case 11: case 13: case 14:
            break;
        case 3:
            if (self->attachKind != 1 && self->attachKind != 0xC && g_2dded0 - self->tJump > 0.1f)
                SetJmpState((char *)self + 0x2C0, 0, 0, 0);
            break;
        default:
            if (g_2dded0 - self->tJump > 0.1f)
                SetJmpState((char *)self + 0x2C0, 0, 0, 0);
            break;
        }
        switch (self->state) {
        case 0: case 1: case 7:
            if (!(self->pjoy->flags & 8) && FJtInFocusRange(self, 0))
                SetBentleyState(self, 5);
            else if (FButtonPressedWithin(self->pjoy, 0x40, 0.1f))
                SetJmpState((char *)self + 0x2C0, 1, 0, 0);
            else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x400, 0.15f) && self->FCanUseGadget(3)) {
                ClearVjoyPresses(self->pjoy, 0x400);
                StartBinoc((char *)self + 0xF00, 0, 0, 0);
            } else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x10, 0.15f) && self->FCanUseGadget(self->field_0x1870)) {
                ClearVjoyPresses(self->pjoy, 0x10);
                self->pslotActive = PslotBentleyGadget(self, self->field_0x1870);
                SetBentleyState(self, 6);
            } else if (FButtonPressedWithin(self->pjoy, 0x20, 0.2f))
                FAttachGroundTarget((char *)self + 0x4C0, 0xF8FE, 0);
            else {
                float axis = self->pjoy->axis;
                if (self->state == 0 ? axis > 0.1f : axis > 0.0f) {
                    if (self->pjoy->flags & 8)
                        SetBentleyState(self, 1);
                    else
                        SetBentleyState(self, 7);
                } else
                    SetBentleyState(self, 0);
            }
            break;
        case 2:
            UpdateJmpBodyState((char *)self + 0x2C0);
            if (GrfbtnVjoyPressedWithin(self->pjoy, 0x10, 0.15f) && self->FCanUseGadget(self->field_0x1870)) {
                ClearVjoyPresses(self->pjoy, 0x10);
                self->pslotActive = PslotBentleyGadget(self, self->field_0x1870);
                SetBentleyState(self, 6);
            }
            break;
        case 3:
            UpdateAttachInput((char *)self + 0x4C0);
            break;
        case 4:
            UpdateZap((char *)self + 0xDF0);
            break;
        case 5:
            if (!(self->pjoy->flags & 8) && FJtInFocusRange(self, 1)) {
                if (FButtonPressedWithin(self->pjoy, 0x40, 0.1f))
                    SetJmpState((char *)self + 0x2C0, 1, 0, 0);
                else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x400, 0.15f) && self->FCanUseGadget(3)) {
                    ClearVjoyPresses(self->pjoy, 0x400);
                    StartBinoc((char *)self + 0xF00, 0, 0, 0);
                } else if (FButtonPressedWithin(self->pjoy, 0x20, 0.2f))
                    FAttachGroundTarget((char *)self + 0x4C0, 0xF8FE, 0);
                else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x10, 0.15f) && self->FCanUseGadget(self->field_0x1870)) {
                    ClearVjoyPresses(self->pjoy, 0x10);
                    self->pslotActive = PslotBentleyGadget(self, self->field_0x1870);
                    SetBentleyState(self, 6);
                }
            } else
                SetBentleyState(self, 0);
            break;
        case 13:
            UpdateJtActivePipe((char *)self + 0xF50);
            break;
        case 6:
            UpdateBentleyGadget(self);
            break;
        case 8:
            func_001367D8(self);
            break;
        case 12:
            CarryThrow_Update((char *)self + 0x11B0);
            break;
        case 10:
            if (self->field_0x1030 == 0 || FAsegaGone(self->field_0x1030) == 0) {
                if (self->field_0x1034 != 0 && FSmaRetracted(self->field_0x1034) != 0)
                    SetBentleyState(self, 0);
            } else
                SetBentleyState(self, 0);
            break;
        case 14:
            if (D_002BC930 < g_2dded0 - self->tState)
                SetBentleyState(self, 0);
            break;
        }
        UpdateBentleyAim(self);
    } while ((unsigned)self->state != stateOld);
}
}
