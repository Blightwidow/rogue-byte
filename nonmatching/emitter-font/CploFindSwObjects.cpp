// SPDX-License-Identifier: GPL-3.0-or-later
// Declarations copied from src/emitter-font/PdlFromSwOid_file.cpp (the whole file this function lands in).
struct Entry { char pad[12]; };
extern "C" Entry *PdlFromSwOid(char *base, int oid);
extern "C" Entry *func_0015E3C0(char *base, int oid);

struct LO_15E3E8 {
    int oid;
    LO_15E3E8 *pnext;
    char pad0[0x10 - 0x8];
    LO_15E3E8 *paloParent;
    char pad1[0x28 - 0x14];
    union {
        unsigned long grf;
        struct { int unk28; signed char depth; };
    };
};

extern "C" void MatchSwObject(void *psw, LO_15E3E8 *plo, LO_15E3E8 *ploMatch, unsigned grffso, LO_15E3E8 *ploContext,
                              LO_15E3E8 *plst, int cploMax, int *pcploMatch, LO_15E3E8 **aplo, int *pipsl);

// An object in the world's oid hash chains (PdlFromSwOid): its parent at 0x10, oid at 0x18, next in the chain at 0x1C, the
// depth MatchSwObject reads at 0x2C and the object it matches against at 0x3C.
struct LO_15E678 {
    char pad0[0x10];
    LO_15E678 *paloParent;
    int pad14;
    int oid;
    LO_15E678 *ploNextOid;
    char pad20[0xC];
    signed char depth;
    char pad2D[0xF];
    LO_15E3E8 *ploMatch;
};

// An entry of the second hash table (func_0015E3C0): a reference from another object.
struct LINK_15E678 {
    int pad0;
    LO_15E3E8 *ploMatch;
    int oid;
    LINK_15E678 *plinkNext;
    LO_15E3E8 *plo;
};

// Search state: MatchSwObject gets &cploMatch and &ipsl; plstContext is reloaded from the frame after the calls.
// The first word is never read or written, but retail's frame has it (sp+0x10, the state at 0x14..0x1F).
struct FIND_15E678 { int unused; int cploMatch; int ipsl; LO_15E678 *plstContext; };

extern LO_15E3E8 *B_003E139C;

// Retail calls PdlFromSwOid and func_0015E3C0 twice each and keeps only the second result, so the source calls them twice.
// fAll is an ordinary local that gets no register (all nine callee-saved ones are taken) and lives in a spill slot.
extern "C" int CploFindSwObjects(char *psw, int grffso, int oid, LO_15E678 *ploContext, LO_15E3E8 *plst, int cploMax,
                                 LO_15E3E8 **aplo)
{
    FIND_15E678 find;
    int fAll;
    LO_15E678 *plo;
    if (oid == -1 || (ploContext == 0 && (grffso & 0xFF) != 5))
        return 0;
    if (plst == 0) {
        if (ploContext != 0)
            plst = ploContext->ploMatch;
        else
            plst = B_003E139C;
    }
    find.cploMatch = 0;
    switch (grffso & 0xFF) {
    case 1:
    case 3:
    case 4: {
        plo = ploContext;
        find.plstContext = plo;
        int depth = 0;
        fAll = grffso & 0x200;
        for (; plo; plo = plo->paloParent) {
            depth++;
            plo->depth = depth;
        }
        find.ipsl = 0x7FFFFFFF;
        break;
    }
    default:
        find.plstContext = 0;
        fAll = grffso & 0x200;
        break;
    }
    PdlFromSwOid(psw, oid);
    for (plo = *(LO_15E678 **)PdlFromSwOid(psw, oid); plo; plo = plo->ploNextOid) {
        if (plo->oid == oid)
            MatchSwObject(psw, (LO_15E3E8 *)plo, plo->ploMatch, grffso, (LO_15E3E8 *)ploContext, plst, cploMax,
                          &find.cploMatch, aplo, &find.ipsl);
    }
    func_0015E3C0(psw, oid);
    for (LINK_15E678 *plink = *(LINK_15E678 **)func_0015E3C0(psw, oid); plink; plink = plink->plinkNext) {
        if (plink->oid == oid) {
            if (plink->plo) {
                if (((LO_15E678 *)plink->plo)->oid == oid) {
                    int iplo;
                    for (iplo = 0; iplo < find.cploMatch; iplo++)
                        if (aplo[iplo] == plink->plo)
                            break;
                    if (iplo < find.cploMatch)
                        continue;
                }
                MatchSwObject(psw, plink->plo, plink->ploMatch, grffso, (LO_15E3E8 *)ploContext, plst, cploMax,
                              &find.cploMatch, aplo, &find.ipsl);
            }
        }
    }
    for (plo = find.plstContext; plo; plo = plo->paloParent)
        plo->depth = 0;
    if (fAll == 0 && cploMax < find.cploMatch)
        find.cploMatch = cploMax;
    return find.cploMatch;
}
