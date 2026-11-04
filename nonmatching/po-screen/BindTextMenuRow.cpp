#include "sly2.h"
struct MENUFRAME { int citem; char *aitem; int unk8; int unkC; int unk10; int iitemSel; int unk18; };
struct MENUITEM { int idString; char pad[0x1C]; };
extern "C" {
extern int B_003D9EF4;
extern MENUFRAME B_003D9EDC[];
extern char B_003DD490[];
char *PchzStringFromId(void *, int);
char *strcpy(char *, const char *);
void BindTextMenuRow(char *pchzDest, int irow)
{
    MENUFRAME *pframe = &B_003D9EDC[B_003D9EF4];
    if (pframe->citem == 0) return;
    int iitemBase = pframe->iitemSel - 3;
    int iitem = irow + iitemBase;
    while (iitem < 0) iitem += pframe->citem;
    iitem = iitem % pframe->citem;
    strcpy(pchzDest, PchzStringFromId(B_003DD490, ((MENUITEM *)pframe->aitem)[iitem].idString));
}
}
