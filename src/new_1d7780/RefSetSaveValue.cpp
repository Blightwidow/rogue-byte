// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
struct SAVEVARREC { short symid; signed char savek; unsigned char cElement; unsigned short ib; unsigned short irecChild; unsigned short irecNext; };
struct SAVEVARS { int crec; SAVEVARREC *arec; };
struct SAVEPATH { int csym; unsigned short *asymid; };
struct SAVEVARLOC { SAVEVARREC *prec; int iElement; };
struct CLQ { float x, y, z, w; } __attribute__((aligned(16)));
struct LM { float gMin, gMax; };
struct SMP { float a, b, c; };
extern "C" int FFindSaveVar(SAVEVARS *psavevars, SAVEPATH *ppath, SAVEVARLOC *psavevarloc);
CRef RefSetSaveValue(SAVEVARS *psavevars, SAVEPATH *ppath, CRef *pref, char *pbBase)
{
    CRef ref;
    ref.SetTag(TAGK_Void);
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
        case 9:
        case 10:
            ((int *)pb)[savevarloc.iElement] = pref->m_tag.m_n;
            break;
        case 3:
            ((float *)pb)[savevarloc.iElement] = pref->m_tag.m_g;
            break;
        case 4:
            if (prec->cElement != 0) {
                int ibit = savevarloc.iElement;
                pb += ibit / 8;
                unsigned char mask = 1 << (ibit % 8);
                if (pref->m_tag.m_bool != 0)
                    *pb |= mask;
                else
                    *pb &= ~mask;
            } else
                *(int *)pb = pref->m_tag.m_bool;
            break;
        case 5:
            ((VECTOR *)pb)[savevarloc.iElement] = *pref->m_tag.m_pvector;
            break;
        case 6:
            ((CLQ *)pb)[savevarloc.iElement] = *pref->m_tag.m_pclq;
            break;
        case 7:
            ((LM *)pb)[savevarloc.iElement] = *pref->m_tag.m_plm;
            break;
        case 8:
            ((SMP *)pb)[savevarloc.iElement] = *pref->m_tag.m_psmp;
            break;
        }
        return ref;
    }
}
