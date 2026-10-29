struct AllocReqVolbtn_149398 {
    int size;
    int align;
};

extern "C" void PostLoLoad(char *);
extern "C" void PostBtnLoad(char *);
extern "C" void SetVolbtnButtons(char *, int);
extern "C" void *PvAllocSwImpl__Fi(AllocReqVolbtn_149398 *);

void CVolbtn_PostLoad(char *arg0) {
    AllocReqVolbtn_149398 req;

    PostLoLoad(arg0);
    PostBtnLoad(arg0 + 0x130);
    SetVolbtnButtons(arg0, 0);
    if (*(int *)(arg0 + 0x2C8) != 0) {
        req.size = 0x100;
        req.align = 0x10;
        *(void **)(arg0 + 0x2C4) = PvAllocSwImpl__Fi(&req);
    }
}
