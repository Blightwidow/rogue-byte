struct BASE { int pad0[3]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();  virtual int Query(int); };
struct JOY { char pad0[0x1C]; float axis; char pad1[0x10]; int flags; };
struct JT : BASE {
    char pad1[0x150 - 0x10]; JOY *pjoy; char pad2[0x20C - 0x154]; float tJump; char pad3[0x4C8 - 0x210]; int jmpState;
    char pad4[0x1030 - 0x4CC]; int asega; int sma; char pad5[0x13D0 - 0x1038]; int state; float tState;
    char pad6[0x16B4 - 0x13D8]; int pslot; char pad7[0x1870 - 0x16B8]; int gadget;
};
extern "C" {
void CarryThrow_Update(void *);
void ClearVjoyPresses(void *, int);
int FAsegaGone(int);
int FAttachGroundTarget(void *, int, int);
int FButtonPressedWithin(void *, int, float);
int FJtInFocusRange(void *, int);
int FSmaRetracted(int);
int GrfbtnVjoyPressedWithin(void *, int, float);
int PslotBentleyGadget(void *, int);
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
void UpdateBentleyActive(JT *self)
{
    unsigned stateOld;
    do {
        stateOld = self->state;
        switch (stateOld) {
        case 2: case 4: case 6: case 8: case 9: case 10: case 11: case 13: case 14:
            break;
        case 3:
            if (self->jmpState != 1 && self->jmpState != 0xC && g_2dded0 - self->tJump > 0.1f)
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
            else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x400, 0.15f) && self->Query(3)) {
                ClearVjoyPresses(self->pjoy, 0x400);
                StartBinoc((char *)self + 0xF00, 0, 0, 0);
            } else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x10, 0.15f) && self->Query(self->gadget)) {
                ClearVjoyPresses(self->pjoy, 0x10);
                self->pslot = PslotBentleyGadget(self, self->gadget);
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
            if (GrfbtnVjoyPressedWithin(self->pjoy, 0x10, 0.15f) && self->Query(self->gadget)) {
                ClearVjoyPresses(self->pjoy, 0x10);
                self->pslot = PslotBentleyGadget(self, self->gadget);
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
                else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x400, 0.15f) && self->Query(3)) {
                    ClearVjoyPresses(self->pjoy, 0x400);
                    StartBinoc((char *)self + 0xF00, 0, 0, 0);
                } else if (FButtonPressedWithin(self->pjoy, 0x20, 0.2f))
                    FAttachGroundTarget((char *)self + 0x4C0, 0xF8FE, 0);
                else if (GrfbtnVjoyPressedWithin(self->pjoy, 0x10, 0.15f) && self->Query(self->gadget)) {
                    ClearVjoyPresses(self->pjoy, 0x10);
                    self->pslot = PslotBentleyGadget(self, self->gadget);
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
            if (self->asega == 0 || FAsegaGone(self->asega) == 0) {
                if (self->sma != 0 && FSmaRetracted(self->sma) != 0)
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
