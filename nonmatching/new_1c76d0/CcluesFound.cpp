#include "sly2.h"
struct SAVEPATH { int csym; short *asym; int pad[2]; };
struct NODE { unsigned short sym; char pad[4]; unsigned short inodeFirstChild; unsigned short inodeNext; };
struct LEVELPATH { int unk0; short *asym; };
struct FIND { char pad[6]; };
struct SAVENODE10 { unsigned short sym; unsigned short pad[3]; unsigned short inodeNext; };
struct FINDRES { unsigned char pad[6]; unsigned short inodeFirstChild; };
struct Locals { short asym[8]; SAVEPATH path; FINDRES *pnode; };
extern "C" {
int IdCurrentLevel();
LEVELPATH *func_002109B8(int);
void *CopyAb__FPvT0Ui(void *, void *, unsigned);
int FFindSaveVar(void *, SAVEPATH *, FINDRES **);
unsigned *PvFindSaveVar(void *, SAVEPATH *, void *);
int SymidFindSymtab(void *, const char *);
struct SWD { char pad[0x3A18]; char save[4]; char *nodes; char symtab[4]; };
extern SWD B_003DD490;
extern char B_003D4A60[];
extern const char RO_002A7788[];
}
int CcluesFound()
{
    int idLevel = IdCurrentLevel();
    if (idLevel == -1)
        return 0;
    Locals l;
    int count = 0;
    LEVELPATH *plevel = func_002109B8(idLevel);
    CopyAb__FPvT0Ui(l.asym, plevel->asym, 6);
    l.path.csym = 3;
    l.path.asym = l.asym;
    FFindSaveVar(B_003DD490.save, &l.path, &l.pnode);
    l.path.csym = 5;
    l.asym[4] = SymidFindSymtab(B_003DD490.symtab, RO_002A7788);
    unsigned inode = l.pnode->inodeFirstChild;
    while (inode != 0) {
        char *nodes = B_003DD490.nodes;
        unsigned short *pnode = (unsigned short *)(nodes + inode * 10);
        l.asym[3] = pnode[0];
        unsigned bits = *PvFindSaveVar(B_003DD490.save, &l.path, B_003D4A60);
        while (bits != 0) {
            bits &= bits - 1;
            count++;
        }
        inode = pnode[4];
    }
    return count;
}
