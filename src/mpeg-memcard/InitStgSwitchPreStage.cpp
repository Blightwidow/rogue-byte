struct AllocReq_1BB9B8 { int cb; int cbAlign; };
extern "C" void *PvAllocStackImpl__Fi(AllocReq_1BB9B8 *);

void InitStgSwitchPreStage(char *arg0) {
    *(int *)(arg0 + 0x15C) = -1;
    char *base = *(char **)(arg0 + 0x164);
    *(int *)(base - 0x10) = -1;
    char *stage = base - 0x10;
    *(int *)(stage + 0x4) = 1;
    if (*(void **)(stage + 0xC) == 0) {
        AllocReq_1BB9B8 req;
        req.cb = 0x200;
        req.cbAlign = 0x10;
        *(void **)(stage + 0xC) = PvAllocStackImpl__Fi(&req);
    }
}
