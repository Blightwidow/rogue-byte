// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#define FIELD(type, base, offset) (*(type *)((char *)(base) + (offset)))
struct VTE_135248 { short delta; short index; void *pfn; };
struct Clock_135248 { float time; float dt; };
extern "C" {
extern Clock_135248 g_2dded0;
extern QW g_2a2dd0;
void SetXfKind(void *, void *, int);
void ScheduleJtGlance(void *);
void ExplodeExpl(void *);
void SetJmpBodyState(void *, int, int);
void SetAttachSubstate(void *, int);
void SetJtZapState(void *, int);
void SetJtPipeState(void *, int);
void ReleaseBentleyGadget(void *);
void SetBentleyGadgetAnim(void *, int);
void func_00136530(void *, int);
void CarryThrow_SetState(void *, int);
int IsmsFindSmOptional__FP2SM3OID(void *, int);
int func_001430C8(void *);
void func_00142868(void *, int);
void ResetRunBlendFootsteps(void *);
void SetBinocState(void *, int);
void RetractAsegaHandle(void *);
void RetractSmaRef(void *);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
void func_001F14F8(void *, void *, int, int, int, void *);
}
static inline VTE_135248 *Vte(void *pobj, int offset) { return (VTE_135248 *)(FIELD(char *, pobj, 0xC) + offset); }

extern "C" void SetBentleyState(char *pbentley, int state)
{
    if (state == FIELD(int, pbentley, 0x13D0))
        return;
    switch (FIELD(int, pbentley, 0x13D0)) {
    case 0:
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x58), 2);
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x5C), 2);
        ScheduleJtGlance(pbentley);
        break;
    case 9: case 10: case 11:
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x58), 2);
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x5C), 2);
        break;
    case 2:
        if (FIELD(int, pbentley, 0x108C) == 0) {
            char *pexpl = 0;
            switch (state) {
            case 0: case 1:
                pexpl = FIELD(char *, pbentley, 0x16D0);
                break;
            case 3:
                switch (FIELD(int, pbentley, 0x4C8)) {
                case 1:
                    break;
                case 3: case 4:
                    pexpl = FIELD(char *, pbentley, 0x16D4);
                    break;
                default:
                    pexpl = FIELD(char *, pbentley, 0x16D0);
                    break;
                }
                break;
            }
            if (pexpl != 0) {
                VTE_135248 *pvte = Vte(pexpl, 0x40);
                ((void (*)(void *))pvte->pfn)(pexpl + pvte->delta);
                ExplodeExpl(pexpl);
                pvte = Vte(pexpl, 0x48);
                ((void (*)(void *))pvte->pfn)(pexpl + pvte->delta);
            }
        }
        SetJmpBodyState(pbentley + 0x2C0, -1, 0);
        break;
    case 3:
        SetAttachSubstate(pbentley + 0x4C0, -1);
        break;
    case 4:
        SetJtZapState(pbentley + 0xDF0, -1);
        break;
    case 13:
        SetJtPipeState(pbentley + 0xF50, -1);
        break;
    case 6: {
        char *pgadget = FIELD(char *, pbentley, 0x186C);
        if (pgadget != 0) {
            VTE_135248 *pvte = Vte(pgadget, 0x260);
            ((void (*)(void *, int))pvte->pfn)(pgadget + pvte->delta, 1);
            ReleaseBentleyGadget(pbentley);
        }
        SetBentleyGadgetAnim(pbentley, -1);
        break;
    }
    case 8: {
        func_00136530(pbentley, -1);
        VTE_135248 *pvte = Vte(pbentley, 0x278);
        ((void (*)(void *, int))pvte->pfn)(pbentley + pvte->delta, 1);
        break;
    }
    case 1: case 7: {
        char *pasega = FIELD(char *, pbentley, 0x1030);
        FIELD(float, pbentley, 0x1A0) = FIELD(float, pasega, 0x1C) / FIELD(float, FIELD(char *, pasega, 0x14), 0x74);
        break;
    }
    case 12:
        CarryThrow_SetState(pbentley + 0x11B0, -1);
        break;
    }
    int stateOld = FIELD(int, pbentley, 0x13D0);
    FIELD(int, pbentley, 0x13D0) = state;
    char *pasegNew = 0;
    void *psm = 0;
    int cAseg = 1;
    int oid = -1;
    int fSm = 4;
    float tLocal = 0.0f;
    float svt = 1.0f;
    char *pfootsteps;
    FIELD(float, pbentley, 0x13D4) = g_2dded0.time;
    switch (state) {
    case 0:
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x58), 1);
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x5C), 1);
        if (FIELD(int, pbentley, 0x181C) != 0) {
            pasegNew = FIELD(char *, pbentley, 0x1820);
            cAseg = 9;
        } else {
            psm = FIELD(void *, pbentley, 0x1028);
            oid = stateOld != 2 ? (stateOld != 7 ? 0x175 : 0x176) : 0x178;
            if (IsmsFindSmOptional__FP2SM3OID(psm, oid) < 0)
                oid = -1;
        }
        FIELD(QW, pbentley, 0x190) = g_2a2dd0;
        fSm = func_001430C8(pbentley);
        func_00142868(pbentley, 1);
        break;
    case 1:
        pasegNew = FIELD(char *, pbentley, 0x1324);
        pfootsteps = pbentley + 0x1320;
        goto blend;
    case 7:
        pasegNew = FIELD(char *, pbentley, 0x1604);
        pfootsteps = pbentley + 0x1600;
    blend:
        cAseg = 9;
        tLocal = FIELD(float, pbentley, 0x1A0) * FIELD(float, pasegNew, 0x74);
        ResetRunBlendFootsteps(pfootsteps);
        break;
    case 4:
        SetBinocState(pbentley + 0xF00, -1);
        break;
    case 5:
        pasegNew = FIELD(char *, pbentley, 0x14E0);
        cAseg = 9;
        break;
    case 13:
        SetJtPipeState(pbentley + 0xF50, 0);
        return;
    case 6:
        SetBentleyGadgetAnim(pbentley, 0);
        return;
    case 8:
        func_00136530(pbentley, 0);
        return;
    case 9:
        psm = FIELD(void *, pbentley, 0x102C);
    case 10: case 11:
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x58), 1);
        SetXfKind(pbentley, FIELD(void *, pbentley, 0x5C), 1);
        FIELD(QW, pbentley, 0x190) = g_2a2dd0;
        break;
    case 12:
        return;
    case 14:
        pasegNew = FIELD(char *, pbentley, 0x1878);
        if (pasegNew == 0) {
            pasegNew = FIELD(char *, pbentley, 0x1374);
            svt = 1.5f;
        }
        cAseg = 9;
        break;
    }
    char *phandle = pbentley + 0x1030;
    char *psmaref = pbentley + 0x1034;
    RetractAsegaHandle(phandle);
    RetractSmaRef(psmaref);
    ApplyAsegToHandle(pasegNew, pbentley, cAseg, phandle, tLocal, svt);
    func_001F14F8(psm, pbentley, oid, cAseg, fSm, psmaref);
    VTE_135248 *pvte = Vte(pbentley, 0x2D0);
    ((void (*)(void *))pvte->pfn)(pbentley + pvte->delta);
}
