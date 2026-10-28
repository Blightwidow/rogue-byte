// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
enum TAGK { TAGK_None = 0 };
struct CRef { int tagk; int n; void SetTag(TAGK); };
struct CPair { int pad0; int pad4; CRef ref; CPair *next; };
extern "C" {
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void CRef_SetBasic(CRef *, int);
void PairHandle_Assign(CPair **, CPair *);
CPair *PpairNew();
void bevy_splice_value_list_ref(CRef *, CPair *);
}
extern "C" CRef *RefFromAplo(CRef *pret, int cplo, int *aplo)
{
    if (cplo == 0) {
        pret->SetTag(TAGK_None);
        return pret;
    }
    CRef refList;
    refList.tagk = -1;
    CPair *pprev = 0;
    if (cplo > 0) {
        int index = cplo;
        int *pplo = aplo;
        do {
            CPair *ppair = PpairNew();
            if (pprev != 0) {
                PairHandle_Assign(&pprev->next, ppair);
            } else {
                bevy_splice_value_list_ref(&refList, ppair);
            }
            int plo = *pplo;
            pprev = ppair;
            pplo++;
            CRef_SetBasic(&ppair->ref, plo);
            index--;
        } while (index != 0);
    }
    CRef_CopyConstruct(pret, &refList);
    CRef_Destruct(&refList);
    return pret;
}
