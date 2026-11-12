// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
struct SAVEVARS;
struct SAVEPATH;
struct GLOBALS_1D8D80 { char pad0[0x3B2C]; SAVEPATH *akey[11]; };
extern "C" {
extern GLOBALS_1D8D80 B_003DD490;
extern SAVEVARS B_003E0EA8;
void *CStackFrame_Construct(void *, int);
void CStackFrame_Destructor(void *, int);
int FSaveDataMatchesLayout(SAVEVARS *, char *);
CRef RefGetSaveValue(SAVEVARS *, SAVEPATH *, char *);
CRef RefSetGameSaveValue(SAVEPATH *, CRef &, char *);
void StoreAudioModeInSave(void);
void *memset(void *, int, unsigned int);
}
static inline CRef GetSaveValue(SAVEPATH *ppath, char *pbSave)
{
    return RefGetSaveValue(&B_003E0EA8, ppath, pbSave);
}
static inline void SetGameSaveValue(SAVEPATH *ppath, CRef ref, char *pbSave)
{
    RefSetGameSaveValue(ppath, ref, pbSave);
}
extern "C" void ResetSaveKeepingOptions(char *pbSave, int fKeepOptions)
{
    char frame[0x10];
    CStackFrame_Construct(frame, fKeepOptions);
    {
    GLOBALS_1D8D80 *pglobals = &B_003DD490;
    SAVEPATH *apath[11] = { pglobals->akey[0], pglobals->akey[7], pglobals->akey[10], pglobals->akey[8], pglobals->akey[9],
        pglobals->akey[1], pglobals->akey[2], pglobals->akey[3], pglobals->akey[4], pglobals->akey[5], pglobals->akey[6] };
    CRef aref[11];
    if (fKeepOptions) {
        if (!FSaveDataMatchesLayout(&B_003E0EA8, pbSave))
            fKeepOptions = 0;
        if (fKeepOptions) {
            for (unsigned int index = 0; index < 11; index++)
                aref[index] = GetSaveValue(apath[index], pbSave);
        }
    }
    memset(pbSave, 0, 0x5400);
    StoreAudioModeInSave();
    if (fKeepOptions) {
        for (unsigned int index = 0; index < 11; index++)
            SetGameSaveValue(apath[index], aref[index], pbSave);
    }
    }
    CStackFrame_Destructor(frame, 2);
}
