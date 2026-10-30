struct SAVEPATH_143410 { int csym; short *asym; int pad[2]; };
struct FINDRES_143410 { unsigned char pad[6]; unsigned short inodeFirstChild; unsigned short inodeNext; };
struct FindSlot_143410 { FINDRES_143410 *p; int pad[3]; };
struct CRef_143410 { int type; int value; int pad[2]; };
struct AllocArg_143410 { int cb; int align; int pad[2]; };
struct SaveNode_143410 { unsigned short sym; unsigned short pad[3]; unsigned short inodeNext; };
struct SaveWorld_143410 { char pad[0x3A18]; char save[4]; char *nodes; };
extern "C" {
void CRef_Destruct(CRef_143410 *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
int FFindSaveVar(void *, SAVEPATH_143410 *, FINDRES_143410 **);
SAVEPATH_143410 *PvAllocStackImpl__Fi(AllocArg_143410 *);
void RefGetSaveValue(CRef_143410 *, void *, SAVEPATH_143410 *, void *);
short SymidFindSymtab(void *, const char *);
void __as__4CRefRC4CRef(CRef_143410 *, CRef_143410 *);
struct Symtab_143410 { char save[8]; char symtab[4]; };
extern Symtab_143410 B_003E0EA8;
extern char B_003D4A60[];
extern SaveWorld_143410 B_003DD490;
extern const char RO_002A4D88[];
extern const char RO_002A4D90[];
extern const char RO_002A4D98[];
extern const char RO_002A4DA0[];
SAVEPATH_143410 *PpathFindBootyOid(int oid) {
    short asym[8];
    SAVEPATH_143410 path;
    FindSlot_143410 pnodeEpisode;
    FindSlot_143410 pnodeLevel;
    CRef_143410 current;
    CRef_143410 value;
    AllocArg_143410 alloc;
    Symtab_143410 *world = &B_003E0EA8;
    path.csym = 0;
    path.asym = asym;
    asym[0] = SymidFindSymtab(world->symtab, RO_002A4D88);
    asym[2] = SymidFindSymtab(world->symtab, RO_002A4D90);
    asym[4] = SymidFindSymtab(world->symtab, RO_002A4D98);
    asym[5] = SymidFindSymtab(world->symtab, RO_002A4DA0);
    path.csym = 1;
    FFindSaveVar(world->save, &path, &pnodeEpisode.p);
    unsigned inodeLevel = pnodeEpisode.p->inodeFirstChild;
    while (inodeLevel != 0) {
        SaveNode_143410 *nodeLevel = (SaveNode_143410 *)(B_003DD490.nodes + inodeLevel * 10);
        path.csym = 3;
        asym[1] = nodeLevel->sym;
        if (FFindSaveVar(B_003DD490.save, &path, &pnodeLevel.p) != 0) {
            unsigned inodeBooty = pnodeLevel.p->inodeFirstChild;
            while (inodeBooty != 0) {
                SaveNode_143410 *nodeBooty = (SaveNode_143410 *)(B_003DD490.nodes + inodeBooty * 10);
                int index = 0;
                current.type = -1;
                asym[3] = nodeBooty->sym;
                do {
                    asym[6] = index;
                    path.csym = 7;
                    RefGetSaveValue(&value, B_003E0EA8.save, &path, B_003D4A60);
                    __as__4CRefRC4CRef(&current, &value);
                    CRef_Destruct(&value);
                    index++;
                    if (current.value == oid) {
                        alloc.cb = 8;
                        alloc.align = 0x10;
                        SAVEPATH_143410 *copy = PvAllocStackImpl__Fi(&alloc);
                        CopyAb__FPvT0Ui(copy, &path, 8);
                        value.type = path.csym * 2;
                        value.value = 0x10;
                        copy->asym = (short *)PvAllocStackImpl__Fi((AllocArg_143410 *)&value);
                        CopyAb__FPvT0Ui(copy->asym, path.asym, path.csym * 2);
                        CRef_Destruct(&current);
                        return copy;
                    }
                } while (index < 15);
                CRef_Destruct(&current);
                inodeBooty = nodeBooty->inodeNext;
            }
        }
        inodeLevel = nodeLevel->inodeNext;
    }
    return 0;
}
}
