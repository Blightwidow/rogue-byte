// SPDX-License-Identifier: GPL-3.0-or-later
#include "sw.h"
#include "lo.h"
#include "dl.h"

struct LOW;
struct WKR {
    LOW *plo;
    int field4;
    int idAlo;
    int field0C;
    char pad10[0x44 - 0x10];
    int grfic;
    LOW *ploAbsorbed;
    float field4C;
    DLE dle;
    char pad58[0x60 - 0x58];
} __attribute__((aligned(16)));

struct WKR;
struct LOW {
    char pad[0xC];
    virtual void Slot1();
    virtual void Slot2();
    virtual void HandleSpliceEvent(int, int, int, void *, int);
    virtual void PostMessage(int, void *, LOW *);
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual int FAbsorbWkr(WKR *, LOW *);
    LOW *next();
};
extern "C" {
LOW *func_001A5BF0(int);
int GrficFromAlo(LOW *, int);
void *PvAllocSlotheapImpl(void *);
void AppendDlEntry(DL *, void *);
void ClearDle__FP3DLE(DLE *);
extern DL B_003E15C0;
extern char B_003E15A8[];
extern float g_2dded0;

LOW *PaloAbsorbWkr(WKR *pwkr)
{
    struct EV { LO *a; LO *b; WKR *c; int d; };
    EV evDead;
    void *aargs[3];
    void *aargs2[2];
    LOW *palo = func_001A5BF0(pwkr->idAlo);
    while (palo != 0) {
        WKR *pwkrOther = (WKR *)B_003E15C0.head;
        while (pwkrOther != 0) {
            if (pwkrOther->plo == pwkr->plo && pwkrOther->field4 == pwkr->field4 && pwkrOther->field0C == pwkr->field0C && pwkrOther->ploAbsorbed == palo)
                return 0;
            pwkrOther = (WKR *)pwkrOther->dle.next;
        }
        pwkr->grfic = GrficFromAlo(palo, pwkr->field0C);
        LOW *ploTest = palo;
        if (ploTest->FAbsorbWkr(pwkr, ploTest) != 0) {
            pwkr->ploAbsorbed = palo;
            WKR *pwkrCopy = (WKR *)PvAllocSlotheapImpl(B_003E15A8);
            *pwkrCopy = *pwkr;
            pwkrCopy->field4C = g_2dded0;
            ClearDle__FP3DLE(&pwkrCopy->dle);
            AppendDlEntry(&B_003E15C0, pwkrCopy);
            if (pwkr->grfic & 0xF8) {
                aargs[0] = palo;
                aargs[1] = pwkr->plo;
                aargs[2] = pwkr;
                palo->PostMessage(0xB, aargs, palo);
                pwkr->plo->PostMessage(0xB, aargs, pwkr->plo);
                aargs2[0] = &palo;
                aargs2[1] = &pwkr->field0C;
                pwkr->plo->HandleSpliceEvent(0xA, 1, 2, aargs2, 0);
                aargs2[0] = pwkr;
                palo->HandleSpliceEvent(0xB, 1, 2, aargs2, 0);
            }
            return palo;
        }
        palo = *(LOW **)((char *)palo + 0x10);
    }
    return 0;
}
}
