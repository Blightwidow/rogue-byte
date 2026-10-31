struct ALLOCREQ_1F0128 { int cb; int cbAlign; };
extern "C" {
void *PvAllocSwImpl__Fi(ALLOCREQ_1F0128 *);

void func_001F0128(char *arg0, int arg1, int arg2, int arg3) {
    ALLOCREQ_1F0128 req;
    req.cb = 0xC;
    req.cbAlign = 0x10;
    int *obj = (int *)PvAllocSwImpl__Fi(&req);
    *(void **)(arg0 + 0x74) = obj;
    obj[0] = arg1;
    obj[1] = arg2;
    obj[2] = arg3;
}
}
