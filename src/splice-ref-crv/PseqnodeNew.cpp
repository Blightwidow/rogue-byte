struct DL { void *pfirst; void *plast; int ibDle; };
struct SVT { char pad0[8]; short d8; short i8; void (*fn8)(char *); };
struct OWNER { char pad[0x50]; int crec; char *arec; };
struct SEQNODE {
    int unk0; int unk4; int unk8; SVT *vt; int unk10; OWNER *powner; OWNER *pownerRoot; int plo;
    char pad[0x28 - 0x20]; char *prec; char *precEnd;
    char pad2[0xEC - 0x30]; int pamb;
};
struct REC { char pad[0x10]; int oid; };
extern char B_003E1560;
extern char B_003DD490;
extern char D_002D8C08;
extern "C" {
void *PvAllocSlotheapImpl(void *);
void *memset(void *, int, unsigned);
void *PloFindSwObject_thunk(void *, int, int, int);
void PrependDlEntry(void *, void *);
}

SEQNODE *PseqnodeNew(OWNER *powner, REC *prec, SEQNODE *pparent)
{
    SEQNODE *pseqnode = (SEQNODE *)PvAllocSlotheapImpl(&B_003E1560);
    memset(pseqnode, 0, 0xF0);
    pseqnode->unk0 = 0;
    pseqnode->unk4 = 0;
    pseqnode->vt = (SVT *)&D_002D8C08;
    pseqnode->pamb = 0;
    pseqnode->powner = powner;
    if (pparent != 0)
        pseqnode->pownerRoot = pparent->pownerRoot;
    else
        pseqnode->pownerRoot = powner;
    int oid = prec->oid;
    if (oid != -1)
        pseqnode->plo = (int)PloFindSwObject_thunk(&B_003DD490, 5, oid, 0);
    pseqnode->prec = (char *)prec;
    void *pdl = (char *)powner + 0x5C;
    char *precLast = powner->arec + (powner->crec * 0x50 - 0x50);
    int cdepth = 1;
    for (char *precScan = (char *)prec + 0x50; precScan <= precLast; precScan += 0x50) {
        switch (*(int *)precScan) {
        case 0:
            cdepth++;
            break;
        case 1:
            cdepth--;
            if (cdepth == 0) {
                pseqnode->precEnd = precScan;
                goto done;
            }
            break;
        }
    }
    pseqnode->precEnd = pseqnode->prec;
done:
    PrependDlEntry(pdl, pseqnode);
    pseqnode->vt->fn8((char *)pseqnode + pseqnode->vt->d8);
    return pseqnode;
}
