// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
struct SAVEVARREC { short symid; signed char savek; unsigned char cElement; unsigned short ib; unsigned short irecChild; unsigned short irecNext; };
struct SAVEVARS { int crec; SAVEVARREC *arec; };
struct SAVEPATH { int csym; unsigned short *asymid; };
struct SAVEVARLOC { SAVEVARREC *prec; int iElement; };
extern "C" {
int FFindSaveVar(SAVEVARS *psavevars, SAVEPATH *ppath, SAVEVARLOC *psavevarloc);
void CRef_SetF32(CRef *, float);
void CRef_SetVectorPtr(CRef *, VECTOR *);
void CRef_SetClqPtr(CRef *, CLQ *);
void CRef_SetLmPtr(CRef *, LM *);
void CRef_SetSmpPtr(CRef *, SMP *);
}
CRef RefGetSaveValue(SAVEVARS *psavevars, SAVEPATH *ppath, char *pbBase)
{
    CRef ref;
    ref.m_tagk = TAGK_Nil;
    SAVEVARLOC savevarloc;
    if (!FFindSaveVar(psavevars, ppath, &savevarloc))
        return ref;
    SAVEVARREC *prec = savevarloc.prec;
    if (prec->savek == -1)
        return ref;
    {
        unsigned char *pb = (unsigned char *)pbBase + prec->ib;
        switch (prec->savek) {
        case 0:
        case 1:
        case 2:
        case 10:
            ref.SetS32(((int *)pb)[savevarloc.iElement]);
            break;
        case 3:
            CRef_SetF32(&ref, ((float *)pb)[savevarloc.iElement]);
            break;
        case 4:
            if (prec->cElement != 0)
            {
                int ibit = savevarloc.iElement;
                pb += ibit / 8;
                unsigned char mask = 1 << (ibit % 8);
                ref.SetBool((*pb & mask) != 0);
            }
            else
                ref.SetBool(*(int *)pb);
            break;
        case 5:
            CRef_SetVectorPtr(&ref, (VECTOR *)pb + savevarloc.iElement);
            break;
        case 6:
            CRef_SetClqPtr(&ref, (CLQ *)(pb + savevarloc.iElement * 16));
            break;
        case 7:
            CRef_SetLmPtr(&ref, (LM *)(pb + savevarloc.iElement * 8));
            break;
        case 8:
            CRef_SetSmpPtr(&ref, (SMP *)(pb + savevarloc.iElement * 12));
            break;
        case 9:
            ref.SetS32(((int *)pb)[savevarloc.iElement]);
            break;
        }
        return ref;
    }
    return ref;
}
