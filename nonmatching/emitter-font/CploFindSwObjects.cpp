// SPDX-License-Identifier: GPL-3.0-or-later
struct OBJ { char pad0[0x10]; OBJ *pnext; int pad14; int oid; OBJ *pnextOid; char pad20[0xC]; char index; char pad2d[0xF]; int value; };
struct Link { int pad0; int arg; int oid; Link *pnext; OBJ *pobj; };
extern "C" {
char *PdlFromSwOid(char *, int);
Link **func_0015E3C0(char *, int);
void MatchSwObject(char *, OBJ *, int, int, OBJ *, int, int, int *, int *, int *);
}
// Search state at sp+0x10: retail passes &count (0x14) and &best (0x18) to MatchSwObject and keeps plist (0x1C) and
// flag (0x20) beside them; the word at 0x10 is never touched but retail's frame has it.
struct Locals { int unused; int count; int best; OBJ *plist; int flag; };
extern int B_003E139C;

// Retail calls PdlFromSwOid and func_0015E3C0 twice each and keeps only the second result (a list-head macro evaluated
// twice), so the source calls them twice. The duplicate check in the link loop reads loc.count both as the loop bound and
// in the test after it, with no separate `count > 0` guard: retail's `blez` is the rotated for-loop's own entry test
// (score 22 -> 8). Still differs (score 8): retail computes the 0x200 flag into $v1 after `pnode = pobj0` and stores it
// after plist; ours computes it into $v0 first, and the two later reloads of loc.flag are $v1 in retail, $v0 here.
extern "C" int CploFindSwObjects(char *psw, int grf, int oid, OBJ *pobj0, int limit, int max, int *pfound)
{
    Locals loc;
    OBJ *pnode;
    if (oid == -1 || (pobj0 == 0 && (grf & 0xFF) != 5))
        return 0;
    if (limit == 0) {
        if (pobj0 != 0)
            limit = pobj0->value;
        else
            limit = B_003E139C;
    }
    loc.count = 0;
    int kind = grf & 0xFF;
    if (kind == 1 || (kind != 0 && kind < 5 && kind >= 3)) {
        pnode = pobj0;
        loc.plist = pnode;
        loc.flag = grf & 0x200;
        int index = 0;
        for (; pnode; pnode = pnode->pnext) {
            index++;
            pnode->index = index;
        }
        loc.best = 0x7FFFFFFF;
    } else {
        loc.plist = 0;
        loc.flag = grf & 0x200;
    }
    PdlFromSwOid(psw, oid);
    for (pnode = *(OBJ **)PdlFromSwOid(psw, oid); pnode; pnode = pnode->pnextOid) {
        if (pnode->oid == oid)
            MatchSwObject(psw, pnode, pnode->value, grf, pobj0, limit, max, &loc.count, pfound, &loc.best);
    }
    func_0015E3C0(psw, oid);
    for (Link *plink = *func_0015E3C0(psw, oid); plink; plink = plink->pnext) {
        if (plink->oid == oid) {
            if (plink->pobj) {
                if (plink->pobj->oid == oid) {
                    int found;
                    for (found = 0; found < loc.count; found++)
                        if (pfound[found] == (int)plink->pobj)
                            break;
                    if (found < loc.count)
                        continue;
                }
                MatchSwObject(psw, plink->pobj, plink->arg, grf, pobj0, limit, max, &loc.count, pfound, &loc.best);
            }
        }
    }
    for (pnode = loc.plist; pnode; pnode = pnode->pnext)
        pnode->index = 0;
    if (loc.flag == 0 && max < loc.count)
        loc.count = max;
    return loc.count;
}
