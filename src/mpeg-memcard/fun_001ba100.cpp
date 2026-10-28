struct O { int a; int cid; };
int CidGetBasic(int);
int func_001BA100(void *unused, O *o) {
    return CidGetBasic(o->cid) == 0x62;
}
