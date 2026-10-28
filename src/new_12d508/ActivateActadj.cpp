// SPDX-License-Identifier: GPL-3.0-or-later
struct VTE { short delta; short index; void (*fn)(void *); };
struct VT { char pad[8]; VTE slot0; };
struct ACT { char pad[0x18]; VT *pvt; };
struct ACTADJ { char pad0[0x10]; ACT *pactNext; int unk14; int unk18; ACT *pactBase; };
extern "C" void ActivateActadj(ACTADJ *pactadj)
{
    ACT *pact = pactadj->pactNext;
    pactadj->pactBase = pact;
    if (pact != 0) {
        VTE *pentry = &pact->pvt->slot0;
        pentry->fn((char *)pact + pentry->delta);
    }
}
