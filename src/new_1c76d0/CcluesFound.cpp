// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

struct SAVEPATH
{
    int csym;
    short *asym;
    int field8[2];
};

struct LEVELPATH
{
    int field0;
    short *asym;
};

struct SAVENODE
{
    unsigned short sym;
    unsigned short field2[2];
    unsigned short inodeFirstChild;
    unsigned short inodeNext;
};

struct SWD
{
    char field0[0x3A18];
    char save[4];
    char *nodes;
    char symtab[4];
};

void CopyAb(void *destination, void *source, unsigned int count);

extern "C" {
int IdCurrentLevel();
LEVELPATH *func_002109B8(int idLevel);
int FFindSaveVar(void *save, SAVEPATH *path, SAVENODE **pnode);
unsigned *PvFindSaveVar(void *save, SAVEPATH *path, void *defaultValue);
int SymidFindSymtab(void *symtab, const char *name);
extern SWD B_003DD490;
extern char B_003D4A60[];
extern const char RO_002A7788[];
}

// CopyAb is declared `void`: retail's CopyAb uses $v0 only as scratch and returns nothing, and a `void *` return made the call set a dead
// $v0 (score 4). The locals are real (an array, a SAVEPATH, a node pointer), no padding struct.
int CcluesFound()
{
    int idLevel = IdCurrentLevel();
    if (idLevel == -1)
        return 0;
    short asym[5];
    SAVEPATH path;
    SAVENODE *pnodeLevel;
    int count = 0;
    LEVELPATH *plevel = func_002109B8(idLevel);
    CopyAb(asym, plevel->asym, 6);
    path.csym = 3;
    path.asym = asym;
    FFindSaveVar(B_003DD490.save, &path, &pnodeLevel);
    path.csym = 5;
    asym[4] = SymidFindSymtab(B_003DD490.symtab, RO_002A7788);
    unsigned inode = pnodeLevel->inodeFirstChild;
    while (inode != 0) {
        SAVENODE *pnode = (SAVENODE *)(B_003DD490.nodes + inode * 10);
        asym[3] = pnode->sym;
        unsigned bits = *PvFindSaveVar(B_003DD490.save, &path, B_003D4A60);
        while (bits != 0) {
            bits &= bits - 1;
            count++;
        }
        inode = pnode->inodeNext;
    }
    return count;
}
