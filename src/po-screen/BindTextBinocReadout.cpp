/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SW { char pad[1]; };
struct JT { char pad[0xF20]; int binocPhase; char pad2[0xF3C - 0xF24]; float gValue; };
extern "C" {
extern SW B_003DD490;
extern const char RO_STR_002A8AB8[];
extern const char RO_STR_002A8AC0[];
extern const char RO_STR_002A8AC8[];
extern const char RO_STR_002A8AD0[];
extern const char RO_STR_002A8AD8[];
extern float g_2de3b8;
extern float g_2de514;
void *PpoSwFocusBase(SW *);
int FIsBasicDerivedFrom(void *, int);
int sprintf(char *, const char *, ...);
double fptodp(float);
}

void BindTextBinocReadout(char *pchzDest)
{
    JT *pjt = (JT *)PpoSwFocusBase(&B_003DD490);
    if (pjt == 0)
        return;
    if (FIsBasicDerivedFrom(pjt, 0x34) == 0)
        return;
    float gValue;
    switch (pjt->binocPhase) {
    case 0:
        gValue = g_2de3b8 * pjt->gValue;
        break;
    case 1:
        gValue = g_2de514 * pjt->gValue;
        break;
    }
    if (FIsBasicDerivedFrom(pjt, 0x35) != 0) {
        sprintf(pchzDest, RO_STR_002A8AB8, (int)gValue);
    } else if (FIsBasicDerivedFrom(pjt, 0x37) != 0) {
        sprintf(pchzDest, RO_STR_002A8AC0, fptodp(gValue));
    } else if (FIsBasicDerivedFrom(pjt, 0x36) != 0) {
        int nValue = (int)gValue;
        if (nValue < 4)
            sprintf(pchzDest, RO_STR_002A8AC8);
        else if (nValue < 8)
            sprintf(pchzDest, RO_STR_002A8AD0);
        else
            sprintf(pchzDest, RO_STR_002A8AD8);
    }
}
