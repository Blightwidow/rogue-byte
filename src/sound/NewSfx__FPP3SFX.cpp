struct ALLOCREQ_1FAF70 { int cb; int cbAlign; };
extern "C" {
char *PvAllocSwClearImpl__Fi(ALLOCREQ_1FAF70 *);
char *NewSfx__FPP3SFX(void) {
    ALLOCREQ_1FAF70 req;
    req.cb = 0x14;
    req.cbAlign = 0x10;
    char *obj = PvAllocSwClearImpl__Fi(&req);
    *(int *)(obj + 0) = -1;
    *(float *)(obj + 4) = 300.0f;
    *(float *)(obj + 8) = 3000.0f;
    *(float *)(obj + 0xC) = 1.0f;
    return obj;
}
}
