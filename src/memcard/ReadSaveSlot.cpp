#include "sly2.h"
struct SAVE;
struct SLOTFILEINFO { int unk0; int unk4; int cb; int grf; };
struct SLOT { char pad[0x5408]; char pad2[0x544C - 0x5408]; int cb; int grf; };
extern "C" void BuildSlotFilePath(SAVE *, SLOT *, char *);
extern "C" int FindMemcardFile(SAVE *, char *, void *);
int ReadMemcardFile(SAVE *, char *, void *, int);
int ReadSaveSlot(SAVE *psave, SLOT *pslot)
{
    char achzPath[0x50];
    int nError;
    memset(pslot, 0, 0x5464);
    BuildSlotFilePath(psave, pslot, achzPath);
    nError = FindMemcardFile(psave, achzPath, &pslot->pad[0x5408]);
    if (nError != 0)
        return nError;
    if ((pslot->grf & 0xD4) != 4)
        return 0x14;
    if (pslot->cb != 0x5408)
        return 0x1C;
    return ReadMemcardFile(psave, achzPath, pslot, 0x5408);
}
