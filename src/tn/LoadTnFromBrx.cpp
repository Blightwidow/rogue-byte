struct REQ { int size; int align; };
struct PA { int size; int align; int cplo; unsigned long **aplo; };
struct TN {
    char pad[0xE4]; char geom[0x18]; char bspc[0xF0 - 0xFC + 0x18 + 0x0];
};
struct TNX {
    char pad[0xE4]; int geom; char pad2[0xFC - 0xE8]; int bspc; char pad3[0x10C - 0x100];
    unsigned long *curve; int stepCount; int steps; int stepsWorld; int stepsFixed;
    char pad4[0x164 - 0x120]; int flags;
};
extern "C" {
void LoadXfmBaseFromBrx(void *, void *);
void CBinaryInputStream_ReadGeom(void *, void *);
void CBinaryInputStream_ReadBspc(void *, void *, void *);
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(REQ *);
void *PvAllocSwCopyImpl__FiPv(REQ *, void *);
void func_00221818(void *, int);
void func_00221940(void *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, void *);
void InitPloarray(PA *);
void LoadPloarrayFromBrx(void *, void *, PA *);
}

extern "C" void LoadTnFromBrx(TNX *tn, void *bis)
{
    char frame[0x10];
    PA pa;
    int align = 0x10;
    int *geom = &tn->geom;
    LoadXfmBaseFromBrx(tn, bis);
    CBinaryInputStream_ReadGeom(bis, geom);
    CBinaryInputStream_ReadBspc(bis, geom, &tn->bspc);
    CStackFrame_Construct(frame);
    REQ *req = (REQ *)&pa;
    req->size = 0x240;
    req->align = align;
    tn->steps = (int)PvAllocStackImpl__Fi(req);
    func_00221818(tn, 0x30);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(tn, bis);
    func_00221940(tn);
    req->size = tn->stepCount * 0x90;
    req->align = align;
    void *world = PvAllocSwCopyImpl__FiPv(req, (void *)tn->steps);
    tn->stepsFixed = 1;
    tn->steps = (int)world;
    tn->stepsWorld = (int)world;
    InitPloarray(&pa);
    LoadPloarrayFromBrx(tn, bis, &pa);
    if (pa.cplo != 0) {
      if (pa.cplo == 1) {
        unsigned long *curve = *pa.aplo;
        tn->curve = curve;
        curve[5] |= 0x200000000000000UL;
    } }
    if (tn->curve == 0)
        tn->flags &= ~2;
    CStackFrame_Destructor(frame, 2);
}
