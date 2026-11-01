// SPDX-License-Identifier: GPL-3.0-or-later
// UpdateMurrayActive: per-frame state update of Murray's active states.
struct JOY_1B4AA0 { char pad0[0x1C]; float uStick; char pad1[0x30 - 0x20]; unsigned grfbtn; };
struct VT_1B4AA0 { char pad[0x318]; short delta; short index; int (*fn)(void *, int); };
struct JMP_1B4AA0 { char pad0[4]; int state; char pad1[0x2DC - 0x2C8]; int cjump; };
struct MURRAY_1B4AA0 {
    char pad0[0xC];
    VT_1B4AA0 *vt;
    char pad1[0x150 - 0x10];
    JOY_1B4AA0 *pjoy;
    char pad2[0x20C - 0x154];
    float tState;
    char pad3[0x2C0 - 0x210];
    char jmp[0x4C0 - 0x2C0];
    char attach[0x4C8 - 0x4C0];
    int attachState;
    char pad4[0xDF0 - 0x4CC];
    char zap[0xF00 - 0xDF0];
    char binoc[0xF50 - 0xF00];
    char pipe[0x1030 - 0xF50];
    int pasega;
    int psma;
    char pad5[0x13D0 - 0x1038];
    int murrays;
    char pad6[0x13E8 - 0x13D4];
    int unk13E8;
    int unk13EC;
    char pad7[0x144C - 0x13F0];
    int unk144C;
    char pad8[0x1840 - 0x1450];
    int unk1840;
    char pad9[0x1910 - 0x1844];
    char carry[4];
};

extern "C" {
extern float g_2dded0;
extern float D_002C08DC;
extern float D_002C08E0;
void CarryThrow_Update(void *);
void ClearVjoyPresses(JOY_1B4AA0 *, int);
int FAsegaGone(int);
int FAttachGroundTarget(void *, int, int);
int FButtonPressedWithin(JOY_1B4AA0 *, int, float);
int FJtInFocusRange(MURRAY_1B4AA0 *, int);
int FJtLandsWithin(MURRAY_1B4AA0 *, float);
int FMurrayAttackCanChain(MURRAY_1B4AA0 *);
int FMurrayTryGrabGuard(MURRAY_1B4AA0 *);
int FSmaRetracted(int);
int GrfbtnJtGadget(MURRAY_1B4AA0 *, int);
int GrfbtnVjoyPressedWithin(JOY_1B4AA0 *, int, float);
void SetJmpState(void *, int, int, int);
void SetMurrayState(MURRAY_1B4AA0 *, int);
void StartBinoc(void *, int, int, int);
void StartMurrayAttackA(MURRAY_1B4AA0 *);
void StartMurrayAttackB(MURRAY_1B4AA0 *);
void UpdateAttachInput(void *);
void UpdateJmpBodyState(void *);
void UpdateJtActivePipe(void *);
void UpdateMurrayAttack(MURRAY_1B4AA0 *);
void UpdateMurrayCarry(MURRAY_1B4AA0 *);
void UpdateMurrayLift(MURRAY_1B4AA0 *);
void UpdateMurrayMash(MURRAY_1B4AA0 *);
void UpdateZap(void *);
void func_001B5990(MURRAY_1B4AA0 *);
void func_001B6BA8(MURRAY_1B4AA0 *);
void func_001B8EC0(MURRAY_1B4AA0 *);

void UpdateMurrayActive(MURRAY_1B4AA0 *pmurray)
{
    int murraysStart;
    do {
        murraysStart = pmurray->murrays;
        switch (murraysStart) {
        case 2: case 3: case 4: case 6: case 7: case 8:
        case 14: case 15: case 16: case 17: case 18: case 20:
            break;
        default:
            if (g_2dded0 - pmurray->tState > 0.1f) {
                switch (pmurray->murrays) {
                case 5:
                    SetJmpState(pmurray->jmp, 16, 0, 0);
                    break;
                case 12:
                    if (pmurray->unk1840 == 3)
                        SetJmpState(pmurray->jmp, 11, 0, 0);
                    break;
                case 13:
                    if (pmurray->attachState != 1 && pmurray->attachState != 12)
                        SetJmpState(pmurray->jmp, 0, 0, 0);
                    break;
                default:
                    SetJmpState(pmurray->jmp, 0, 0, 0);
                    break;
                }
            }
            break;
        }

        switch (pmurray->murrays) {
        case 0: case 1: case 10:
            if (!(pmurray->pjoy->grfbtn & 8) && FJtInFocusRange(pmurray, 0)) {
                SetMurrayState(pmurray, 9);
            } else if (FButtonPressedWithin(pmurray->pjoy, 0x40, 0.1f)) {
                SetJmpState(pmurray->jmp, 1, 0, 0);
            } else if (GrfbtnVjoyPressedWithin(pmurray->pjoy, 0x400, 0.15f) &&
                       pmurray->vt->fn((char *)pmurray + pmurray->vt->delta, 3)) {
                ClearVjoyPresses(pmurray->pjoy, 0x400);
                StartBinoc(pmurray->binoc, 0, 0, 0);
            } else if (FMurrayAttackCanChain(pmurray) &&
                       FButtonPressedWithin(pmurray->pjoy, 0x10, D_002C08DC)) {
                StartMurrayAttackB(pmurray);
            } else if (!FMurrayTryGrabGuard(pmurray)) {
                if (FButtonPressedWithin(pmurray->pjoy, 0x20, 0.2f)) {
                    if (!FAttachGroundTarget(pmurray->attach, 0xF8FA, 0) && pmurray->unk13EC) {
                        pmurray->unk144C = 0;
                        SetMurrayState(pmurray, 4);
                    }
                } else if (FMurrayAttackCanChain(pmurray) &&
                           FButtonPressedWithin(pmurray->pjoy, 0x80, D_002C08DC)) {
                    StartMurrayAttackA(pmurray);
                } else {
                    float uStick = pmurray->pjoy->uStick;
                    if (pmurray->murrays == 0 ? uStick > 0.1f : uStick > 0.0f) {
                        if (pmurray->pjoy->grfbtn & 8)
                            SetMurrayState(pmurray, 1);
                        else
                            SetMurrayState(pmurray, 10);
                    } else {
                        SetMurrayState(pmurray, 0);
                    }
                }
            }
            break;
        case 2: {
            UpdateJmpBodyState(pmurray->jmp);
            switch (((JMP_1B4AA0 *)pmurray->jmp)->state) {
            case 0: case 11: case 15: case 16:
                break;
            default:
                if (GrfbtnVjoyPressedWithin(pmurray->pjoy, 0x90, D_002C08DC) &&
                    pmurray->vt->fn((char *)pmurray + pmurray->vt->delta, 2)) {
                    int cjump = ((JMP_1B4AA0 *)pmurray->jmp)->cjump;
                    if (cjump < 6) {
                        if (cjump > 0 && !FJtLandsWithin(pmurray, D_002C08E0)) {
                            ClearVjoyPresses(pmurray->pjoy, 0x90);
                            pmurray->unk13E8 = 0;
                            SetMurrayState(pmurray, 3);
                        }
                    }
                }
                break;
            }
            break;
        }
        case 13:
            UpdateAttachInput(pmurray->attach);
            break;
        case 14:
            UpdateZap(pmurray->zap);
            break;
        case 3:
            func_001B6BA8(pmurray);
            break;
        case 5:
            UpdateMurrayCarry(pmurray);
            break;
        case 6:
            UpdateMurrayMash(pmurray);
            break;
        case 4:
            UpdateMurrayLift(pmurray);
            break;
        case 7: case 8:
            if (FAsegaGone(pmurray->pasega))
                SetMurrayState(pmurray, 0);
            break;
        case 11:
            UpdateMurrayAttack(pmurray);
            break;
        case 9:
            func_001B5990(pmurray);
            break;
        case 12:
            func_001B8EC0(pmurray);
            break;
        case 15:
            CarryThrow_Update(pmurray->carry);
            break;
        case 20:
            UpdateJtActivePipe(pmurray->pipe);
            break;
        case 17:
            if (pmurray->pasega && FAsegaGone(pmurray->pasega))
                SetMurrayState(pmurray, 0);
            else if (pmurray->psma && FSmaRetracted(pmurray->psma))
                SetMurrayState(pmurray, 0);
            break;
        case 21:
            if (FButtonPressedWithin(pmurray->pjoy, 0x40, 0.0f))
                SetJmpState(pmurray->jmp, 13, 0, 0);
            else if (!(pmurray->pjoy->grfbtn & GrfbtnJtGadget(pmurray, 0x10)))
                SetMurrayState(pmurray, 0);
            break;
        }
    } while (pmurray->murrays != murraysStart);
}
}
