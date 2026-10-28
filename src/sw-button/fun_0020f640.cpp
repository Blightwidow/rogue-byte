struct ALLOCREQ { int cb; int align; };
struct CBIS;
extern "C" int B_003E1C54;
extern "C" int B_003E1C30;
extern "C" void Align__18CBinaryInputStreami(CBIS *, int);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void CBinaryInputStream_Read_thunk(CBIS *, int, void *);
extern "C" void CBinaryInputStream_Skip(CBIS *, int);
extern "C" void func_001EA568(void *);
extern "C" void UploadBitmaps__FiP3GSB(void *);
extern "C" void func_00170828(void *);
void func_0020F640(void *gsb, CBIS *bis)
{
    Align__18CBinaryInputStreami(bis, 0x10);
    if (B_003E1C54) {
        char frame[16];
        CStackFrame_Construct(frame);
        ALLOCREQ req;
        ALLOCREQ *preq = &req;
        req.cb = B_003E1C30;
        preq->align = 0x10;
        void *p = PvAllocStackImpl__Fi(preq);
        CBinaryInputStream_Read_thunk(bis, B_003E1C30, p);
        func_001EA568(p);
        UploadBitmaps__FiP3GSB(gsb);
        CStackFrame_Destructor(frame, 2);
    } else {
        CBinaryInputStream_Skip(bis, B_003E1C30);
        func_00170828(gsb);
    }
}
