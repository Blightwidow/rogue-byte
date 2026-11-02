struct OBJ { char pad0[0x10]; OBJ *pnext; int pad14; int oid; OBJ *pnextOid; char pad20[0xC]; char index; char pad2d[0xF]; int value; };
struct Link { int pad0; int arg; int oid; Link *pnext; OBJ *pobj; };
struct Entry { OBJ *pobj; char pad[8]; };
struct Link2 { Link *plink; };
extern "C" {
char *PdlFromSwOid(char *, int);
Link **func_0015E3C0(char *, int);
void MatchSwObject(char *, OBJ *, int, int, OBJ *, int, int, int *, int *, int *);
}
struct Locals { int unused; int count; int best; OBJ *plist; int flag; };
extern int B_003E139C;
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
            OBJ *pobj = plink->pobj;
            if (pobj) {
                if (pobj->oid == oid && loc.count > 0) {
                    int i = 0;
                    for (; i < loc.count; i++)
                        if (pfound[i] == (int)pobj) break;
                    if (i < loc.count) continue;
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
