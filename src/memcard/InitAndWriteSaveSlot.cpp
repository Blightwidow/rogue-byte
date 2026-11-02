#include "sly2.h"
struct SAVE;
struct SLOT;
extern "C" void BuildSlotFilePath(SAVE *, SLOT *, char *);
extern "C" int WriteMemcardFile(SAVE *, char *, SLOT *, int);
extern "C" void ResetSaveKeepingOptions(SLOT *, int);

extern "C" int InitAndWriteSaveSlot(SAVE *psave, SLOT *pslot)
{
    char achzPath[0x50];
    ResetSaveKeepingOptions(pslot, 0);
    BuildSlotFilePath(psave, pslot, achzPath);
    return WriteMemcardFile(psave, achzPath, pslot, 0x5408);
}
