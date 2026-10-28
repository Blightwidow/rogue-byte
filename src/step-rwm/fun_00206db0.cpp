extern "C" {
extern char B_003DD490[];
extern int D_002C3D10[];
int CploFindSwObjectsByClass(void *, int, int, int, int, int);
void AddGuardIgnoredClass(void *, int);
}
void func_00206DB0(void *g)
{
    for (unsigned i = 0; i < 5; i++) {
        int cid = D_002C3D10[i];
        if (CploFindSwObjectsByClass(B_003DD490, 0x605, cid, 0, 0, 0) != 0)
            AddGuardIgnoredClass(g, cid);
    }
}
